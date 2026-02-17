#!/usr/bin/env python3
"""
Generate a flat `all_enums.h` from `inav_enums.json`.

Usage:
  python gen_all_enums_from_json.py ../docs/inav_enums.json -o all_enums.h
"""
import argparse
import json
from datetime import datetime
from pathlib import Path


def main():
    parser = argparse.ArgumentParser(description="Render enums from JSON into a C header.")
    parser.add_argument("source", help="Path to inav_enums.json")
    parser.add_argument("-o", "--out", default="all_enums.h", help="Output header (default: all_enums.h)")
    args = parser.parse_args()

    src_path = Path(args.source)
    out_path = Path(args.out)

    data = json.loads(src_path.read_text())

    lines = []
    lines.append(f"// Consolidated enums — generated on {datetime.now().isoformat(timespec='seconds')}")
    lines.append("")

    for enum_name, entries in data.items():
        src = entries.get("_source", "").strip()
        if src:
            lines.append(f"// {src}")
        lines.append("typedef enum {")
        for member, value in entries.items():
            if member == "_source":
                continue
            condition_note = ""
            raw_val = value
            if isinstance(raw_val, (list, tuple)):
                if len(raw_val) > 1 and raw_val[1]:
                    condition_note = f" // requires {raw_val[1]}"
                raw_val = raw_val[0] if raw_val else ""
            if raw_val == "":
                lines.append(f"    {member},{condition_note}")
                continue
            lines.append(f"    {member} = {raw_val},{condition_note}")
        lines.append(f"}} {enum_name};")
        lines.append("")

    out_path.write_text("\n".join(lines))


if __name__ == "__main__":
    main()
