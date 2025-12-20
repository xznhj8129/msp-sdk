#!/usr/bin/env python3
"""
Generate `inav_enums.json` by scanning MSP message payload definitions for enum
usage and exporting the corresponding definitions from `all_enums.h`.
"""

from __future__ import annotations

import argparse
import ast
import importlib.util
import json
import re
import sys
from collections import OrderedDict
from pathlib import Path
from typing import Dict, Iterable, Iterator, Mapping, MutableMapping, Optional, Set


ROOT = Path(__file__).resolve().parent
ALL_ENUMS_PATH = ROOT / "all_enums.h"
MSP_MESSAGES_PATH = ROOT / "../docs" / "msp_messages.json"
H_TO_ENUM_PATH = ROOT / "../cgen_test" / "h_to_enum.py"
DEFAULT_OUTPUT_PATH = ROOT / "inav_enums.json"
_H_TO_ENUM_MODULE: Optional[object] = None
CAST_PATTERN = re.compile(
    r"\(\s*(?:const\s+)?(?:struct\s+)?[A-Za-z_]\w*(?:\s*\*)?\s*\)"
)
INT_SUFFIX_PATTERN = re.compile(r"\b(0[xX][0-9a-fA-F]+|\d+)[uUlL]+\b")
FLOAT_SUFFIX_PATTERN = re.compile(r"(?<=\d)[fF]\b")


def load_h_to_enum_module():
    global _H_TO_ENUM_MODULE
    if _H_TO_ENUM_MODULE is None:
        spec = importlib.util.spec_from_file_location(
            "inav_h_to_enum", H_TO_ENUM_PATH
        )
        if spec is None or spec.loader is None:
            raise RuntimeError(f"Unable to load parser from {H_TO_ENUM_PATH}")
        module = importlib.util.module_from_spec(spec)
        spec.loader.exec_module(module)  # type: ignore[attr-defined]
        _H_TO_ENUM_MODULE = module
    return _H_TO_ENUM_MODULE


def load_all_enum_data():
    module = load_h_to_enum_module()
    enums, _defines = module.extract_data_from_header(str(ALL_ENUMS_PATH))
    return enums


def prepare_expression(expr: str) -> str:
    cleaned = CAST_PATTERN.sub("", expr)
    cleaned = INT_SUFFIX_PATTERN.sub(r"\1", cleaned)
    cleaned = FLOAT_SUFFIX_PATTERN.sub("", cleaned)
    return cleaned.strip()


def resolve_enum_members(
    enum_name: str,
    members: Iterable[Iterable[str]],
    symbol_table: Dict[str, int],
) -> "OrderedDict[str, int]":
    resolved: "OrderedDict[str, int]" = OrderedDict()
    current_value = -1
    for raw_member in members:
        if len(raw_member) < 2:
            continue
        name = raw_member[0]
        expr = raw_member[1] or ""
        expr = expr.strip()
        if expr:
            expr = prepare_expression(expr)
            context = dict(symbol_table)
            context.update(resolved)
            try:
                value = eval_enum_expression(expr, context)
            except EnumExpressionError as exc:
                raise EnumExpressionError(
                    f"{enum_name}.{name}: {exc}"
                ) from exc
        else:
            value = current_value + 1
        resolved[name] = value
        symbol_table[name] = value
        current_value = value
    return resolved


class EnumExpressionError(ValueError):
    """Raised when an enum value expression cannot be evaluated."""


BIN_OPS = {
    ast.Add: lambda a, b: a + b,
    ast.Sub: lambda a, b: a - b,
    ast.Mult: lambda a, b: a * b,
    ast.Div: lambda a, b: a // b,
    ast.FloorDiv: lambda a, b: a // b,
    ast.Mod: lambda a, b: a % b,
    ast.BitOr: lambda a, b: a | b,
    ast.BitAnd: lambda a, b: a & b,
    ast.BitXor: lambda a, b: a ^ b,
    ast.LShift: lambda a, b: a << b,
    ast.RShift: lambda a, b: a >> b,
}
UNARY_OPS = {
    ast.UAdd: lambda a: +a,
    ast.USub: lambda a: -a,
    ast.Invert: lambda a: ~a,
}


def eval_enum_expression(expr: str, names: Mapping[str, int]) -> int:
    """Safely evaluate a simple integer expression used in enum assignments."""

    def _eval(node: ast.AST) -> int:
        if isinstance(node, ast.Expression):
            return _eval(node.body)
        if isinstance(node, ast.Constant):
            value = node.value
            if isinstance(value, bool):
                return int(value)
            if isinstance(value, (int, float)):
                return int(value)
            if isinstance(value, str) and len(value) == 1:
                return ord(value)
            raise EnumExpressionError(f"Unsupported constant {value!r} in {expr}")
        if isinstance(node, ast.UnaryOp):
            op_type = type(node.op)
            if op_type not in UNARY_OPS:
                raise EnumExpressionError(f"Unsupported unary operator {op_type}")
            return UNARY_OPS[op_type](_eval(node.operand))
        if isinstance(node, ast.BinOp):
            op_type = type(node.op)
            if op_type not in BIN_OPS:
                raise EnumExpressionError(f"Unsupported binary operator {op_type}")
            left = _eval(node.left)
            right = _eval(node.right)
            return BIN_OPS[op_type](left, right)
        if isinstance(node, ast.Name):
            if node.id not in names:
                raise EnumExpressionError(f"Unknown identifier {node.id!r} in {expr}")
            return names[node.id]
        raise EnumExpressionError(f"Unsupported expression {ast.dump(node)} in {expr}")

    tree = ast.parse(expr, mode="eval")
    return _eval(tree)


def iter_payload_fields(payload: object) -> Iterator[MutableMapping[str, object]]:
    if isinstance(payload, list):
        for entry in payload:
            if isinstance(entry, MutableMapping):
                yield entry
                nested = entry.get("payload")
                if nested is not None:
                    yield from iter_payload_fields(nested)


def collect_enums_from_section(section: object) -> Set[str]:
    enums: Set[str] = set()
    if isinstance(section, MutableMapping):
        payload = section.get("payload")
    else:
        payload = section
    for field in iter_payload_fields(payload):
        enum_name = field.get("enum")
        if enum_name:
            enums.add(enum_name)
    return enums


def collect_enums_from_message(message: MutableMapping[str, object]) -> Set[str]:
    enums: Set[str] = set()
    for key in ("request", "reply"):
        enums.update(collect_enums_from_section(message.get(key)))
    variants = message.get("variants")
    if isinstance(variants, MutableMapping):
        for variant in variants.values():
            if isinstance(variant, MutableMapping):
                enums.update(collect_enums_from_message(variant))
    return enums


def collect_used_enum_names(messages: Mapping[str, object]) -> Set[str]:
    names: Set[str] = set()
    for message in messages.values():
        if isinstance(message, MutableMapping):
            names.update(collect_enums_from_message(message))
    return names


def load_messages(path: Path) -> Dict[str, object]:
    with path.open("r", encoding="utf-8") as fp:
        return json.load(fp)


def build_enum_export(used_enum_names: Iterable[str]) -> "OrderedDict[str, Dict[str, int]]":
    raw_enums = load_all_enum_data()
    symbol_table: Dict[str, int] = {"true": 1, "false": 0}
    resolved_enums: Dict[str, "OrderedDict[str, int]"] = {}
    failures: Dict[str, str] = {}

    for enum_name, members in raw_enums.items():
        try:
            resolved = resolve_enum_members(enum_name, members, symbol_table)
        except EnumExpressionError as exc:
            failures[enum_name] = str(exc)
            continue
        resolved_enums[enum_name] = resolved

    export: "OrderedDict[str, Dict[str, int]]" = OrderedDict()
    missing: Set[str] = set()
    for name in sorted(set(used_enum_names)):
        enum_def = resolved_enums.get(name)
        if enum_def is None:
            missing.add(name)
            continue
        export[name] = enum_def

    if missing:
        missing_not_extracted = sorted(name for name in missing if name not in raw_enums)
        missing_failed = sorted(name for name in missing if name in failures)
        missing_unknown = sorted(
            name for name in missing if name not in missing_not_extracted and name not in missing_failed
        )

        if missing_not_extracted:
            print(
                "Warning: enums referenced by MSP but not found in all_enums.h extraction: "
                + ", ".join(missing_not_extracted),
                file=sys.stderr,
            )

        if missing_failed:
            details = ", ".join(f"{name} ({failures[name]})" for name in missing_failed)
            print(
                "Warning: enums extracted but failed to resolve expressions: " + details,
                file=sys.stderr,
            )

        if missing_unknown:
            print(
                "Warning: Missing definitions for enums (unknown cause): "
                + ", ".join(missing_unknown),
                file=sys.stderr,
            )

    return export


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description="Generate inav_enums.json from all_enums.h and msp_messages.json",
    )
    parser.add_argument(
        "-o",
        "--output",
        type=Path,
        default=DEFAULT_OUTPUT_PATH,
        help=f"Where to write the JSON output (default: {DEFAULT_OUTPUT_PATH})",
    )
    parser.add_argument(
        "--stdout",
        action="store_true",
        help="Print JSON to stdout instead of writing to a file",
    )
    return parser.parse_args()


def main() -> None:
    args = parse_args()
    messages = load_messages(MSP_MESSAGES_PATH)
    used_enum_names = collect_used_enum_names(messages)
    export = build_enum_export(used_enum_names)

    output_json = json.dumps(export, indent=2)
    if args.stdout:
        print(output_json)
        return

    output_path = args.output if args.output.is_absolute() else (ROOT / args.output)
    output_path.write_text(output_json + "\n", encoding="utf-8")
    try:
        dest = output_path.relative_to(ROOT)
    except ValueError:
        dest = output_path
    print(f"Wrote {len(export)} enums to {dest}")


if __name__ == "__main__":
    try:
        main()
    except EnumExpressionError as exc:
        print(f"Error while parsing enum expressions: {exc}", file=sys.stderr)
        sys.exit(1)
