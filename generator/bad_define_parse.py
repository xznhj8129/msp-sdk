#!/usr/bin/env python3
"""
Usage:
    python bad_define_parse.py
    python bad_define_parse.py --input all_defines.h --output inav_defines.py
    python bad_define_parse.py --verbose

Convert object-like C preprocessor constants into concrete Python literals.
Unsupported, conditional, cyclic, or externally dependent constants are
written as None instead of emitting unevaluable Python expressions.

Requires pycparser.
"""

from __future__ import annotations

import argparse
import ast
import os
import operator
import re
from pathlib import Path
from typing import Any, Mapping, Optional

from pycparser import c_ast, c_parser
from pycparser.plyparser import ParseError


IN_FILE = Path("all_defines.h")
OUT_FILE = Path("inav_defines.py")

DEFINE_RE = re.compile(r"^\s*#\s*define\s+([A-Za-z_]\w*)(?:\s+(.*?))?\s*$")
FUNC_LIKE_RE = re.compile(r"^\s*#\s*define\s+([A-Za-z_]\w*)\(")
SOURCE_RE = re.compile(r"^//\s+(.+\.[ch])\s*$")
TYPEDEF_RE = re.compile(r"\btypedef\b(?P<body>.*?);", re.DOTALL)
CAST_NAME_RE = re.compile(r"\(\s*(?:const\s+|volatile\s+)?([A-Za-z_]\w*)\s*\)")

INTEGER_TYPES = {
    "_Bool": (1, False),
    "bool": (1, False),
    "char": (8, True),
    "signed char": (8, True),
    "unsigned char": (8, False),
    "short": (16, True),
    "short int": (16, True),
    "signed short": (16, True),
    "signed short int": (16, True),
    "unsigned short": (16, False),
    "unsigned short int": (16, False),
    "int": (32, True),
    "signed": (32, True),
    "signed int": (32, True),
    "unsigned": (32, False),
    "unsigned int": (32, False),
    "long": (32, True),
    "long int": (32, True),
    "signed long": (32, True),
    "signed long int": (32, True),
    "unsigned long": (32, False),
    "unsigned long int": (32, False),
    "long long": (64, True),
    "long long int": (64, True),
    "signed long long": (64, True),
    "signed long long int": (64, True),
    "unsigned long long": (64, False),
    "unsigned long long int": (64, False),
    "int8_t": (8, True),
    "uint8_t": (8, False),
    "int16_t": (16, True),
    "uint16_t": (16, False),
    "int32_t": (32, True),
    "uint32_t": (32, False),
    "int64_t": (64, True),
    "uint64_t": (64, False),
    "intptr_t": (32, True),
    "uintptr_t": (32, False),
    "ptrdiff_t": (32, True),
    "size_t": (32, False),
}

BINARY_OPERATORS = {
    "+": operator.add,
    "-": operator.sub,
    "*": operator.mul,
    "<<": operator.lshift,
    ">>": operator.rshift,
    "|": operator.or_,
    "&": operator.and_,
    "^": operator.xor,
}

COMPARISON_OPERATORS = {
    "==": operator.eq,
    "!=": operator.ne,
    "<": operator.lt,
    "<=": operator.le,
    ">": operator.gt,
    ">=": operator.ge,
}


class UnresolvedExpression(ValueError):
    pass


def strip_block_comments(text: str) -> str:
    return re.sub(r"/\*.*?\*/", "", text, flags=re.DOTALL)


def strip_line_comment(text: str) -> str:
    return text.split("//", 1)[0]


def join_backslash_lines(text: str) -> str:
    output = []
    buffered = ""
    for line in text.splitlines():
        if line.rstrip().endswith("\\"):
            buffered += line.rstrip()[:-1] + " "
            continue
        output.append(buffered + line)
        buffered = ""
    if buffered:
        output.append(buffered)
    return "\n".join(output)


def collect_typedefs(text: str, source_base: Path) -> dict[str, str]:
    typedefs = {
        "bool": "_Bool",
        "int8_t": "signed char",
        "uint8_t": "unsigned char",
        "int16_t": "short",
        "uint16_t": "unsigned short",
        "int32_t": "int",
        "uint32_t": "unsigned int",
        "int64_t": "long long",
        "uint64_t": "unsigned long long",
        "intptr_t": "int",
        "uintptr_t": "unsigned int",
        "ptrdiff_t": "int",
        "size_t": "unsigned int",
    }
    source_paths = {
        source_base / match.group(1)
        for line in text.splitlines()
        if (match := SOURCE_RE.match(line))
    }
    for source_path in source_paths:
        if not source_path.is_file():
            continue
        source = strip_block_comments(source_path.read_text(encoding="utf-8", errors="ignore"))
        for match in TYPEDEF_RE.finditer(source):
            body = re.sub(r"\s+", " ", match.group("body").strip())
            pointer_name = re.search(r"\(\s*\*\s*([A-Za-z_]\w*)\s*\)", body)
            if pointer_name:
                continue
            name_match = re.search(r"([A-Za-z_]\w*)\s*(?:\[[^\]]*\])?\s*$", body)
            if not name_match:
                continue
            name = name_match.group(1)
            declaration = body[:name_match.start()].strip()
            if declaration.startswith("enum ") or declaration.startswith("enum{") or " enum " in declaration:
                typedefs[name] = "int"
                continue
            if declaration.startswith("struct ") or declaration.startswith("union "):
                continue
            if re.fullmatch(r"(?:const\s+|volatile\s+)*(?:signed\s+|unsigned\s+|short\s+|long\s+)*[A-Za-z_]\w*", declaration):
                typedefs[name] = re.sub(r"\b(?:const|volatile)\b", "", declaration).strip()
    return typedefs


def extract_defines(text: str) -> tuple[dict[str, Optional[str]], dict[str, str]]:
    macros: dict[str, Optional[str]] = {}
    reasons: dict[str, str] = {}
    source = "<unknown>"
    for line in text.splitlines():
        source_match = SOURCE_RE.match(line)
        if source_match:
            source = source_match.group(1)
            continue
        if FUNC_LIKE_RE.match(line):
            continue
        match = DEFINE_RE.match(line)
        if not match:
            continue
        name, raw_expression = match.group(1), match.group(2)
        expression = strip_line_comment(raw_expression or "").strip() or None
        if name not in macros:
            macros[name] = expression
            reasons[name] = f"source={source}"
            continue
        if macros[name] != expression:
            macros[name] = None
            reasons[name] = f"conflicting definitions; latest source={source}"
    return macros, reasons


def _resolve_type_name(type_name: str, typedefs: Mapping[str, str]) -> str:
    seen = set()
    while type_name in typedefs:
        if type_name in seen:
            raise UnresolvedExpression(f"cyclic typedef={type_name}")
        seen.add(type_name)
        type_name = typedefs[type_name]
    return re.sub(r"\s+", " ", type_name).strip()


def _apply_cast(value: Any, type_name: str, typedefs: Mapping[str, str]) -> Any:
    resolved_type = _resolve_type_name(type_name, typedefs)
    if resolved_type in ("float", "double", "long double"):
        return float(value)
    layout = INTEGER_TYPES.get(resolved_type)
    if layout is None:
        raise UnresolvedExpression(f"unsupported cast={type_name}")
    bits, signed = layout
    if bits == 1:
        return int(bool(value))
    result = int(value) & ((1 << bits) - 1)
    if signed and result & (1 << (bits - 1)):
        result -= 1 << bits
    return result


def _parse_integer_literal(value: str) -> int:
    literal = re.sub(r"[uUlL]+$", "", value)
    if re.fullmatch(r"0[0-7]+", literal):
        return int(literal, 8)
    return int(literal, 0)


def _parse_constant(node: c_ast.Constant) -> Any:
    if node.type == "string":
        return ast.literal_eval(node.value)
    if node.type == "char":
        value = ast.literal_eval(node.value)
        if len(value) != 1:
            raise UnresolvedExpression(f"multi-character literal={node.value}")
        return ord(value)
    if node.type in ("float", "double"):
        return float(re.sub(r"[fFlL]+$", "", node.value))
    if "int" in node.type:
        return _parse_integer_literal(node.value)
    raise UnresolvedExpression(f"unsupported constant type={node.type}")


def _c_divide(left: Any, right: Any) -> Any:
    if isinstance(left, int) and isinstance(right, int):
        quotient = abs(left) // abs(right)
        return -quotient if (left < 0) != (right < 0) else quotient
    return left / right


def _c_modulo(left: Any, right: Any) -> Any:
    return left - (_c_divide(left, right) * right)


def _typename(node: c_ast.Typename) -> str:
    current = node.type
    while not isinstance(current, c_ast.IdentifierType):
        if not hasattr(current, "type"):
            raise UnresolvedExpression(f"unsupported cast node={type(current).__name__}")
        current = current.type
    return " ".join(current.names)


def evaluate_node(node: c_ast.Node, values: Mapping[str, Any], typedefs: Mapping[str, str]) -> Any:
    if isinstance(node, c_ast.Constant):
        return _parse_constant(node)
    if isinstance(node, c_ast.ID):
        if node.name == "true":
            return 1
        if node.name in ("false", "NULL"):
            return 0
        if node.name not in values or values[node.name] is None:
            raise UnresolvedExpression(f"dependency={node.name}")
        return values[node.name]
    if isinstance(node, c_ast.Cast):
        return _apply_cast(evaluate_node(node.expr, values, typedefs), _typename(node.to_type), typedefs)
    if isinstance(node, c_ast.UnaryOp):
        value = evaluate_node(node.expr, values, typedefs)
        if node.op == "+":
            return +value
        if node.op == "-":
            return -value
        if node.op == "~":
            return ~value
        if node.op == "!":
            return int(not value)
        raise UnresolvedExpression(f"unsupported unary operator={node.op}")
    if isinstance(node, c_ast.BinaryOp):
        if node.op == "&&":
            left = evaluate_node(node.left, values, typedefs)
            return int(bool(left) and bool(evaluate_node(node.right, values, typedefs)))
        if node.op == "||":
            left = evaluate_node(node.left, values, typedefs)
            return int(bool(left) or bool(evaluate_node(node.right, values, typedefs)))
        left = evaluate_node(node.left, values, typedefs)
        right = evaluate_node(node.right, values, typedefs)
        operation = BINARY_OPERATORS.get(node.op)
        if operation is not None:
            return operation(left, right)
        comparison = COMPARISON_OPERATORS.get(node.op)
        if comparison is not None:
            return int(comparison(left, right))
        if node.op == "/":
            return _c_divide(left, right)
        if node.op == "%":
            return _c_modulo(left, right)
        raise UnresolvedExpression(f"unsupported binary operator={node.op}")
    if isinstance(node, c_ast.TernaryOp):
        condition = evaluate_node(node.cond, values, typedefs)
        branch = node.iftrue if condition else node.iffalse
        return evaluate_node(branch, values, typedefs)
    if isinstance(node, c_ast.FuncCall) and isinstance(node.name, c_ast.ID):
        arguments = node.args.exprs if node.args is not None else []
        if node.name.name == "BIT" and len(arguments) == 1:
            return 1 << evaluate_node(arguments[0], values, typedefs)
        if node.name.name in ("UINT8_C", "UINT16_C", "UINT32_C", "UINT64_C", "INT8_C", "INT16_C", "INT32_C", "INT64_C") and len(arguments) == 1:
            return evaluate_node(arguments[0], values, typedefs)
        raise UnresolvedExpression(f"unsupported function={node.name.name}")
    raise UnresolvedExpression(f"unsupported syntax={type(node).__name__}")


def parse_expression(expression: str, typedefs: Mapping[str, str]) -> c_ast.Node:
    expression = strip_line_comment(expression).strip()
    if expression.endswith(";"):
        expression = expression[:-1].rstrip()
    cast_names = {
        match.group(1)
        for match in CAST_NAME_RE.finditer(expression)
        if match.group(1) in typedefs
    }
    declarations = " ".join(f"typedef long long {name};" for name in sorted(cast_names))
    translation_unit = f"{declarations} long long __macro_value(void) {{ return {expression}; }}"
    parsed = c_parser.CParser().parse(translation_unit)
    function = parsed.ext[-1]
    return function.body.block_items[0].expr


def resolve_defines(
    macros: Mapping[str, Optional[str]],
    typedefs: Mapping[str, str],
    initial_reasons: Mapping[str, str],
) -> tuple[dict[str, Any], dict[str, str]]:
    values = {name: None for name in macros}
    reasons = dict(initial_reasons)
    pending: dict[str, c_ast.Node] = {}
    for name, expression in macros.items():
        if expression is None:
            continue
        try:
            pending[name] = parse_expression(expression, typedefs)
        except ParseError as exc:
            reasons[name] = f"unsupported C expression: {exc}; expression={expression!r}"

    while pending:
        progress = False
        for name, tree in list(pending.items()):
            try:
                value = evaluate_node(tree, values, typedefs)
            except UnresolvedExpression as exc:
                reasons[name] = f"{exc}; expression={macros[name]!r}"
                continue
            except (ArithmeticError, TypeError, ValueError) as exc:
                reasons[name] = f"{type(exc).__name__}: {exc}; expression={macros[name]!r}"
                del pending[name]
                continue
            if not isinstance(value, (int, float, str, bytes)):
                reasons[name] = f"unsupported result type={type(value).__name__}"
                del pending[name]
                continue
            values[name] = value
            reasons.pop(name, None)
            del pending[name]
            progress = True
        if not progress:
            break
    return values, reasons


def write_python(output_path: Path, values: Mapping[str, Any], source_path: Path) -> None:
    lines = [
        "# Auto-generated from C object-like macros.",
        f"# Source: {source_path}",
        "# Unsupported or configuration-dependent values are None.",
        "# flake8: noqa",
        "",
        "",
        "class InavDefines:",
    ]
    for name, value in values.items():
        lines.append(f"    {name} = {value!r}")
    lines.append("")
    generated = "\n".join(lines)
    compile(generated, str(output_path), "exec")
    temporary_path = output_path.with_suffix(output_path.suffix + ".tmp")
    temporary_path.write_text(generated, encoding="utf-8")
    temporary_path.replace(output_path)


def main(argv: Optional[list[str]] = None) -> int:
    parser = argparse.ArgumentParser(description="Generate Python literals from object-like C macros")
    parser.add_argument("--input", type=Path, default=IN_FILE)
    parser.add_argument("--output", type=Path, default=OUT_FILE)
    parser.add_argument("--verbose", action="store_true")
    args = parser.parse_args(argv)

    raw = join_backslash_lines(strip_block_comments(args.input.read_text(encoding="utf-8", errors="ignore")))
    typedefs = collect_typedefs(raw, args.input.parent)
    macros, extraction_reasons = extract_defines(raw)
    if not macros:
        raise RuntimeError(f"No object-like macros found in {args.input}")
    values, reasons = resolve_defines(macros, typedefs, extraction_reasons)
    source_path = Path(os.path.relpath(args.input, args.output.parent))
    write_python(args.output, values, source_path)

    resolved_count = sum(value is not None for value in values.values())
    print(
        f"Wrote {args.output}: macros={len(values)} resolved={resolved_count} "
        f"unresolved={len(values) - resolved_count} typedefs={len(typedefs)}"
    )
    if args.verbose:
        for name in values:
            if values[name] is None:
                print(f"Unresolved {name}: {reasons[name]}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
