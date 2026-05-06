#!/usr/bin/env python3
"""
Produce a minimal header containing only the defines/enums actually referenced
by the generated MSP structs in `msp_structs.h`.

Writes `msp_types.h` next to the inputs.
"""

from __future__ import annotations

import re
from pathlib import Path
from typing import Dict, List, Set, Tuple

ROOT = Path(__file__).resolve().parent
GEN_HEADER = ROOT / "msp_structs.h"
ALL_ENUMS = ROOT / "all_enums.h"
ALL_DEFINES = ROOT / "all_defines.h"
OUT_HEADER = ROOT / "msp_types.h"


IDENT_RE = re.compile(r"\b([A-Za-z_]\w*)\b")
ENUM_BLOCK_RE = re.compile(
    r"(typedef\s+enum\b.*?\}\s*(?P<name>[A-Za-z_]\w*)\s*;)",
    re.DOTALL,
)
STRUCT_BLOCK_RE = re.compile(
    r"(typedef\s+struct\b.*?\}\s*(?P<name>[A-Za-z_]\w*)\s*;)",
    re.DOTALL,
)
DEFINE_RE = re.compile(r"^\s*#\s*define\s+([A-Za-z_]\w*)\b.*$", re.MULTILINE)


def collect_used_idents(text: str) -> Set[str]:
    return set(IDENT_RE.findall(text))


def strip_comments(text: str) -> str:
    # Remove /* ... */ and // ... comments
    text = re.sub(r"/\*.*?\*/", "", text, flags=re.DOTALL)
    text = re.sub(r"//.*", "", text)
    return text


def parse_enum_blocks(text: str) -> Dict[str, str]:
    found: Dict[str, str] = {}
    for m in ENUM_BLOCK_RE.finditer(text):
        block = m.group(1)
        name = m.group("name")
        found[name] = block.strip()
    return found


def parse_defines(text: str) -> Dict[str, str]:
    out: Dict[str, str] = {}
    for line in text.splitlines():
        m = DEFINE_RE.match(line)
        if not m:
            continue
        name = m.group(1)
        out[name] = line.rstrip()
    return out

def parse_struct_blocks(text: str) -> Dict[str, str]:
    found: Dict[str, str] = {}
    for m in STRUCT_BLOCK_RE.finditer(text):
        block = m.group(1)
        name = m.group("name")
        found[name] = block.strip()
    return found


def main() -> None:
    gen_text = strip_comments(GEN_HEADER.read_text())
    enums_text = strip_comments(ALL_ENUMS.read_text())
    defines_text = strip_comments(ALL_DEFINES.read_text())

    used = collect_used_idents(gen_text)
    enums = parse_enum_blocks(enums_text)
    structs = parse_struct_blocks(enums_text)  # some typedef structs live here too
    defines = parse_defines(defines_text)

    keep_enums: List[str] = []
    enum_tokens: Set[str] = set()
    keep_structs: List[str] = []

    # include defines needed by gen text or by kept enums/structs
    needed_tokens = set(used) | enum_tokens
    keep_defines: Dict[str, str] = {}
    # closure: keep any defines referenced by values of kept defines
    pending: Set[str] = set(name for name in defines if name in needed_tokens)
    while pending:
        name = pending.pop()
        if name in keep_defines:
            continue
        line = defines.get(name)
        if not line:
            continue
        keep_defines[name] = line
        tokens = collect_used_idents(line)
        for tok in tokens:
            if tok in defines and tok not in keep_defines:
                pending.add(tok)

    out_lines: List[str] = []
    out_lines.append("// Auto-generated minimal types needed by msp_structs.h")
    out_lines.append("#pragma once")
    out_lines.append("#include <stdint.h>")
    out_lines.append('#include "msp_stub_types.h"')
    out_lines.append("")
    if keep_defines:
        out_lines.append("// Defines")
        for name, line in keep_defines.items():
            out_lines.append(line)
        out_lines.append("")
    # enums/structs intentionally omitted: supplied by all_enums.h and msp_structs.h

    OUT_HEADER.write_text("\n".join(out_lines))


if __name__ == "__main__":
    main()
