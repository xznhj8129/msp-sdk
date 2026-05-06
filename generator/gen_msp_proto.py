#!/usr/bin/env python3
"""
Usage:
  python gen_msp_proto.py path/to/msp_messages.json path/to/inav_enums.json -o path/to/msp_messages.proto
"""

import argparse
import ast
import json
import re
import sys
from collections import OrderedDict
from pathlib import Path


SCALAR_TYPE_MAP = {
    "uint8_t": "uint32",
    "int8_t": "int32",
    "uint16_t": "uint32",
    "int16_t": "int32",
    "uint32_t": "uint32",
    "int32_t": "int32",
    "uint64_t": "uint64",
    "int64_t": "int64",
    "float": "float",
}

OPAQUE_C_TYPES = {
    "boxBitmask_t",
    "escSensorData_t",
    "ledConfig_t",
}

PROTO_RESERVED = {
    "syntax",
    "import",
    "package",
    "option",
    "message",
    "enum",
    "service",
    "rpc",
    "returns",
    "repeated",
    "optional",
    "required",
    "oneof",
    "map",
    "reserved",
    "extensions",
    "extend",
    "to",
    "max",
    "true",
    "false",
    "string",
    "bytes",
    "float",
    "double",
    "bool",
}

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


def snake_case(name: str, fallback: str) -> str:
    name = re.sub(r"([a-z0-9])([A-Z])", r"\1_\2", name)
    name = re.sub(r"[^0-9A-Za-z_]+", "_", name)
    name = re.sub(r"_+", "_", name).strip("_").lower()
    if not name:
        name = fallback
    if name[0].isdigit():
        name = f"{fallback}_{name}"
    if name in PROTO_RESERVED:
        name = f"{name}_field"
    return name


def type_name(name: str, fallback: str) -> str:
    name = re.sub(r"[^0-9A-Za-z_]+", "_", name).strip("_")
    name = re.sub(r"_+", "_", name)
    if not name:
        name = fallback
    if name[0].isdigit():
        name = f"{fallback}_{name}"
    return name


def comment_lines(text: str) -> list[str]:
    return [line.rstrip() for line in (text or "").splitlines() if line.strip()]


def append_comments(lines: list[str], texts: list[str], indent: str) -> None:
    for text in texts:
        for line in comment_lines(text):
            lines.append(f"{indent}// {line}")


def eval_enum_expression(expr: str, names: dict[str, int]) -> int:
    def _eval(node: ast.AST) -> int:
        if isinstance(node, ast.Expression):
            return _eval(node.body)
        if isinstance(node, ast.Constant):
            if isinstance(node.value, bool):
                return int(node.value)
            if isinstance(node.value, (int, float)):
                return int(node.value)
            if isinstance(node.value, str) and len(node.value) == 1:
                return ord(node.value)
            raise ValueError(f"Unsupported constant {node.value!r}")
        if isinstance(node, ast.UnaryOp):
            return UNARY_OPS[type(node.op)](_eval(node.operand))
        if isinstance(node, ast.BinOp):
            return BIN_OPS[type(node.op)](_eval(node.left), _eval(node.right))
        if isinstance(node, ast.Name):
            return names[node.id]
        raise ValueError(f"Unsupported expression {ast.dump(node)}")

    return _eval(ast.parse(expr, mode="eval"))


def iter_payload_fields(payload: object):
    if isinstance(payload, list):
        for entry in payload:
            if not isinstance(entry, dict):
                continue
            yield entry
            if isinstance(entry.get("payload"), list):
                yield from iter_payload_fields(entry["payload"])


def collect_used_enums(messages: OrderedDict[str, dict]) -> set[str]:
    used_enums: set[str] = set()
    for message in messages.values():
        for side in ("request", "reply"):
            section = message.get(side)
            if section:
                for entry in iter_payload_fields(section.get("payload")):
                    if entry.get("enum"):
                        used_enums.add(entry["enum"])
        variants = message.get("variants") or {}
        for variant in variants.values():
            for side in ("request", "reply"):
                section = variant.get(side)
                if section:
                    for entry in iter_payload_fields(section.get("payload")):
                        if entry.get("enum"):
                            used_enums.add(entry["enum"])
    return used_enums


def resolve_used_enums(enum_data: OrderedDict[str, dict], used_enums: set[str]):
    resolved: OrderedDict[str, dict] = OrderedDict()
    missing: list[str] = []

    for enum_name in sorted(used_enums):
        if enum_name not in enum_data:
            missing.append(enum_name)
            continue

        members = []
        symbols = {"true": 1, "false": 0}
        for member_name, raw_value in enum_data[enum_name].items():
            if member_name == "_source":
                continue

            expr = raw_value
            condition = None
            if isinstance(raw_value, list):
                expr = raw_value[0]
                if len(raw_value) > 1 and raw_value[1]:
                    condition = raw_value[1]

            if expr == "":
                continue

            value = eval_enum_expression(str(expr), symbols)
            symbols[member_name] = value
            members.append(
                {
                    "name": type_name(member_name, "ENUM_VALUE"),
                    "value": value,
                    "condition": condition,
                    "raw_name": member_name,
                }
            )

        resolved[enum_name] = {
            "source": enum_data[enum_name].get("_source", ""),
            "members": members,
        }

    return resolved, missing


def proto_scalar_type(entry: dict, available_enums: set[str]) -> tuple[str, bool, list[str]]:
    ctype = entry["ctype"]
    enum_name = entry.get("enum")
    notes: list[str] = []

    if ctype == "Varies":
        notes.append("Polymorphic MSP field emitted as bytes.")
        return "bytes", False, notes

    if entry.get("array"):
        if ctype == "char":
            return "string", False, notes
        if enum_name and enum_name in available_enums:
            return type_name(enum_name, "EnumType"), True, notes
        if ctype == "uint8_t":
            return "bytes", False, notes
        if ctype in SCALAR_TYPE_MAP:
            return SCALAR_TYPE_MAP[ctype], True, notes
        if ctype in OPAQUE_C_TYPES:
            notes.append(f"Opaque MSP type `{ctype}` emitted as repeated bytes.")
            return "bytes", True, notes
        notes.append(f"Unknown MSP array element type `{ctype}` emitted as repeated bytes.")
        return "bytes", True, notes

    if enum_name and enum_name in available_enums:
        return type_name(enum_name, "EnumType"), False, notes
    if enum_name and enum_name not in available_enums:
        notes.append(
            f"Enum `{enum_name}` referenced in msp_messages.json but missing from inav_enums.json; emitted as `{SCALAR_TYPE_MAP.get(ctype, 'bytes')}`."
        )
    if ctype in SCALAR_TYPE_MAP:
        return SCALAR_TYPE_MAP[ctype], False, notes
    if ctype in OPAQUE_C_TYPES:
        notes.append(f"Opaque MSP type `{ctype}` emitted as bytes.")
        return "bytes", False, notes
    if ctype == "char":
        return "string", False, notes
    notes.append(f"Unknown MSP type `{ctype}` emitted as bytes.")
    return "bytes", False, notes


def field_comments(entry: dict, extra_notes: list[str]) -> list[str]:
    comments: list[str] = []
    if entry.get("desc"):
        comments.append(entry["desc"])
    if entry.get("units"):
        comments.append(f"Units: {entry['units']}")
    if entry.get("bitmask"):
        comments.append("Bitmask field.")
    if entry.get("value") is not None:
        comments.append(f"Fixed value in MSP payload: {entry['value']}.")
    if entry.get("optional"):
        comments.append("Optional field in the MSP payload.")
    if entry.get("array"):
        if entry.get("array_size_define"):
            comments.append(f"MSP fixed length: {entry['array_size_define']}.")
        elif entry.get("array_size"):
            comments.append(f"MSP fixed length: {entry['array_size']}.")
        else:
            comments.append("MSP variable-length array.")
    comments.extend(extra_notes)
    return comments


def unique_name(name: str, used_names: set[str]) -> str:
    if name not in used_names:
        used_names.add(name)
        return name
    index = 2
    while f"{name}_{index}" in used_names:
        index += 1
    unique = f"{name}_{index}"
    used_names.add(unique)
    return unique


def emit_payload_message(lines: list[str], indent: str, payload: list[dict], available_enums: set[str]) -> None:
    used_field_names: set[str] = set()
    repeating_index = 0
    nested_lines: list[str] = []
    field_lines: list[str] = []

    for field_number, entry in enumerate(payload, start=1):
        if "payload" in entry:
            repeating_index += 1
            nested_name = f"RepeatingGroup{repeating_index}"
            repeat_expr = str(entry.get("repeating", "")).strip()
            field_name_seed = snake_case(repeat_expr, f"repeating_group_{repeating_index}")
            field_name = unique_name(f"{field_name_seed}_items", used_field_names)
            append_comments(
                nested_lines,
                [f"MSP repeating block. Repeats {repeat_expr} times." if repeat_expr else "MSP repeating block."],
                indent,
            )
            nested_lines.append(f"{indent}message {nested_name} {{")
            nested_lines.append("")
            emit_payload_message(nested_lines, indent + "  ", entry["payload"], available_enums)
            nested_lines.append(f"{indent}}}")
            nested_lines.append("")
            append_comments(
                field_lines,
                [f"Repeating group. MSP repeats this block {repeat_expr} times." if repeat_expr else "Repeating group."],
                indent,
            )
            field_lines.append(f"{indent}repeated {nested_name} {field_name} = {field_number};")
            field_lines.append("")
            continue

        field_name = unique_name(snake_case(entry["name"], f"field_{field_number}"), used_field_names)
        proto_type, repeated, extra_notes = proto_scalar_type(entry, available_enums)
        comments = field_comments(entry, extra_notes)
        append_comments(field_lines, comments, indent)
        repeated_prefix = "repeated " if repeated else ""
        field_lines.append(f"{indent}{repeated_prefix}{proto_type} {field_name} = {field_number};")
        field_lines.append("")

    lines.extend(nested_lines)
    lines.extend(field_lines)


def message_header_comments(message_name: str, side: str, message: dict, extra: list[str]) -> list[str]:
    comments = [
        f"MSP message `{message_name}` {side} payload.",
        f"MSP code: {message['code']}.",
        f"MSP version: {message['mspv']}.",
    ]
    if message.get("description"):
        comments.append(f"Description: {message['description']}")
    if message.get("notes"):
        comments.append(f"Notes: {message['notes']}")
    if message.get("variable_len"):
        comments.append(f"Variable length: {message['variable_len']}.")
    comments.extend(extra)
    return comments


def emit_simple_message(lines: list[str], message_name: str, side: str, message: dict, payload: list[dict], available_enums: set[str]) -> None:
    proto_message_name = type_name(f"{message_name}_{side.capitalize()}", "MSP_Message")
    append_comments(lines, message_header_comments(message_name, side, message, []), "")
    lines.append(f"message {proto_message_name} {{")
    lines.append("")
    emit_payload_message(lines, "  ", payload, available_enums)
    lines.append("}")
    lines.append("")


def emit_variant_wrapper(lines: list[str], message_name: str, side: str, message: dict, variants: list[tuple[str, dict]], available_enums: set[str]) -> None:
    wrapper_name = type_name(f"{message_name}_{side.capitalize()}", "MSP_Message")
    append_comments(
        lines,
        message_header_comments(message_name, side, message, [f"{len(variants)} schema variants selected by MSP payload shape."]),
        "",
    )
    lines.append(f"message {wrapper_name} {{")
    lines.append("")
    for variant_index, (condition, section) in enumerate(variants, start=1):
        append_comments(lines, [f"Variant condition: {condition}"], "  ")
        lines.append(f"  message Variant{variant_index} {{")
        lines.append("")
        emit_payload_message(lines, "    ", section["payload"], available_enums)
        lines.append("  }")
        lines.append("")
    lines.append("  oneof variant {")
    for variant_index, (condition, _section) in enumerate(variants, start=1):
        append_comments(lines, [condition], "    ")
        lines.append(f"    Variant{variant_index} variant_{variant_index} = {variant_index};")
    lines.append("  }")
    lines.append("}")
    lines.append("")


def emit_command_enum(lines: list[str], messages: OrderedDict[str, dict]) -> None:
    append_comments(lines, ["MSP command identifiers from msp_messages.json."], "")
    lines.append("enum MSP_MessageCode {")
    lines.append("  MSP_MESSAGE_CODE_UNSPECIFIED = 0;")
    for message_name, message in messages.items():
        if message.get("description"):
            append_comments(lines, [message["description"]], "  ")
        lines.append(f"  {type_name(message_name, 'MSP_MESSAGE')} = {message['code']};")
    lines.append("}")
    lines.append("")


def emit_enum(lines: list[str], enum_name: str, enum_info: dict) -> None:
    enum_type_name = type_name(enum_name, "EnumType")
    members = enum_info["members"]
    zero_members = [member for member in members if member["value"] == 0]
    non_zero_members = [member for member in members if member["value"] != 0]
    ordered_members = zero_members[:1] + non_zero_members + zero_members[1:]
    if not zero_members:
        ordered_members.insert(
            0,
            {
                "name": f"{snake_case(enum_type_name, 'enum').upper()}_UNSPECIFIED",
                "value": 0,
                "condition": None,
                "raw_name": "",
            },
        )
    allow_alias = len({member["value"] for member in members}) != len(members)

    header = [f"Enum `{enum_name}` used by MSP fields."]
    if enum_info.get("source"):
        header.append(f"Source: {enum_info['source']}")
    append_comments(lines, header, "")
    lines.append(f"enum {enum_type_name} {{")
    if allow_alias:
        lines.append("  option allow_alias = true;")
    for member in ordered_members:
        member_comments = []
        if member["condition"]:
            member_comments.append(f"Condition: {member['condition']}")
        append_comments(lines, member_comments, "  ")
        lines.append(f"  {member['name']} = {member['value']};")
    lines.append("}")
    lines.append("")


def render_proto(messages: OrderedDict[str, dict], resolved_enums: OrderedDict[str, dict], missing_enums: list[str], schema_path: Path, enum_path: Path, package_name: str) -> str:
    lines = [
        "// Auto-generated by gen_msp_proto.py. Do not edit by hand.",
        f"// Source schema: {schema_path}",
        f"// Source enums: {enum_path}",
    ]
    if missing_enums:
        lines.append("// Missing enum definitions were emitted as underlying scalar types:")
        for enum_name in missing_enums:
            lines.append(f"//   - {enum_name}")
    lines.extend(
        [
            "",
            'syntax = "proto3";',
            "",
            f"package {package_name};",
            "",
        ]
    )

    emit_command_enum(lines, messages)

    for enum_name, enum_info in resolved_enums.items():
        emit_enum(lines, enum_name, enum_info)

    available_enums = set(resolved_enums)
    for message_name, message in messages.items():
        if message.get("variants"):
            request_variants = [
                (condition, variant["request"])
                for condition, variant in message["variants"].items()
                if variant.get("request") and variant["request"].get("payload") is not None
            ]
            reply_variants = [
                (condition, variant["reply"])
                for condition, variant in message["variants"].items()
                if variant.get("reply") and variant["reply"].get("payload") is not None
            ]
            if request_variants:
                emit_variant_wrapper(lines, message_name, "request", message, request_variants, available_enums)
            if reply_variants:
                emit_variant_wrapper(lines, message_name, "reply", message, reply_variants, available_enums)
            continue

        if message.get("request") and message["request"].get("payload") is not None:
            emit_simple_message(lines, message_name, "request", message, message["request"]["payload"], available_enums)
        if message.get("reply") and message["reply"].get("payload") is not None:
            emit_simple_message(lines, message_name, "reply", message, message["reply"]["payload"], available_enums)

    return "\n".join(lines).rstrip() + "\n"


def main() -> None:
    parser = argparse.ArgumentParser(description="Generate a proto3 schema from MSP message and enum JSON.")
    parser.add_argument("schema", help="Path to msp_messages.json")
    parser.add_argument("enums", help="Path to inav_enums.json")
    parser.add_argument("-o", "--out", help="Output .proto path")
    parser.add_argument("--package", default="msp", help="Protobuf package name")
    args = parser.parse_args()

    schema_path = Path(args.schema).resolve()
    enum_path = Path(args.enums).resolve()
    output_path = Path(args.out).resolve() if args.out else schema_path.with_suffix(".proto")

    messages = json.loads(schema_path.read_text(encoding="utf-8"), object_pairs_hook=OrderedDict)
    enum_data = json.loads(enum_path.read_text(encoding="utf-8"), object_pairs_hook=OrderedDict)

    used_enums = collect_used_enums(messages)
    resolved_enums, missing_enums = resolve_used_enums(enum_data, used_enums)
    proto_text = render_proto(messages, resolved_enums, missing_enums, schema_path, enum_path, args.package)
    output_path.write_text(proto_text, encoding="utf-8")

    print(f"Wrote {output_path}", file=sys.stderr)
    if missing_enums:
        print(
            "Missing enum definitions in inav_enums.json: " + ", ".join(missing_enums),
            file=sys.stderr,
        )


if __name__ == "__main__":
    main()
