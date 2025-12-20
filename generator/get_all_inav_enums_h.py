#!/usr/bin/env python3
import argparse
import datetime
import re
from pathlib import Path

SUBDIRS = [
    'common',
    'blackbox',
    'navigation',
    'sensors',
    'programming',
    'rx',
    'telemetry',
    'io',
    'flight',
    'fc',
    'drivers',
    'build',
]
SKIP_ENUMS = {
    'fw_autotune_rate_adjustment_e',
}

def collect_members(chunk: str):
    members = []
    for part in chunk.split(','):
        token = part.strip()
        if not token:
            continue
        lhs = token.split('=')[0].strip()
        if not lhs:
            continue
        m = re.match(r'([A-Za-z_]\w*)', lhs)
        if m:
            members.append(m.group(1))
    return members

def strip_comments(text: str) -> str:
    text = re.sub(r'/\*.*?\*/', '', text, flags=re.DOTALL)   # block comments
    text = re.sub(r'//.*', '', text)                         # line comments
    return text

def extract_enums(fn: str, text: str, seen: set[str], seen_members: set[str]):
    src = strip_comments(text)
    out = []

    # typedef enum { ... } Alias;
    i = 0
    while True:
        m = re.search(r'\btypedef\s+enum\b', src[i:])
        if not m: break
        start = i + m.start()
        # try to capture an optional tag between 'typedef enum' and '{'
        after_enum = src[i + m.end():]
        tag_match = re.match(r'\s+([A-Za-z_]\w*)', after_enum)
        tag_name = tag_match.group(1) if tag_match else None
        lb = src.find('{', i + m.end())
        if lb == -1: break
        depth = 0
        k = lb
        while k < len(src):
            if src[k] == '{': depth += 1
            elif src[k] == '}':
                depth -= 1
                if depth == 0:
                    semi = src.find(';', k)
                    if semi == -1: break
                    tail = src[k+1:semi]
                    alias = re.findall(r'\b([A-Za-z_]\w*)\b', tail)
                    names = []
                    if tag_name:
                        names.append(tag_name)
                    if alias:
                        names.append(alias[0])
                    # collect member names
                    members = collect_members(src[lb+1:k])
                    if names and not any(n in seen for n in names) and not any(n in SKIP_ENUMS for n in names):
                        if any(m in seen_members for m in members):
                            i = semi + 1
                            break
                        seen.update(names)
                        seen_members.update(members)
                        body = src[lb+1:k].strip()
                        nl_body = "\n" + body + "\n"
                        if tag_name and alias:
                            rebuilt = f"typedef enum {tag_name} {{{nl_body}}} {alias[0]};"
                        elif alias:
                            rebuilt = f"typedef enum {{{nl_body}}} {alias[0]};"
                        else:
                            rebuilt = src[start:semi+1].strip()
                        out += [f'// {fn}\n', rebuilt + '\n\n']
                    i = semi + 1
                    break
            k += 1
        else:
            break

    # enum Tag { ... };  → also emit typedef enum Tag Tag;
    i = 0
    while True:
        m = re.search(r'\benum\s+([A-Za-z_]\w*)\s*{', src[i:])
        if not m: break
        start = i + m.start()
        tag = m.group(1)
        lb = src.find('{', i + m.end() - 1)
        if lb == -1: break
        depth = 0
        k = lb
        while k < len(src):
            if src[k] == '{': depth += 1
            elif src[k] == '}':
                depth -= 1
                if depth == 0:
                    semi = src.find(';', k)
                    if semi == -1: break
                    members = collect_members(src[lb+1:k])
                    if tag not in seen and tag not in SKIP_ENUMS:
                        if not any(m in seen_members for m in members):
                            seen.add(tag)
                            seen_members.update(members)
                            body = src[lb+1:k].strip()
                            nl_body = "\n" + body + "\n"
                            block = f"enum {tag} {{{nl_body}}};"
                            out += [
                                f'// {fn}\n',
                                block + '\n',
                                f'typedef enum {tag} {tag};\n\n'
                            ]
                    i = semi + 1
                    break
            k += 1
        else:
            break

    return out



all_enums = []
seen = set()
seen_members = set()
def parse_args():
    parser = argparse.ArgumentParser(description='Collect all enums from INAV sources.')
    parser.add_argument(
        '--inav-root',
        default='../inav/src/main',
        help="Path to the INAV 'src/main' directory (default: %(default)s)",
    )
    return parser.parse_args()


args = parse_args()
base_dir = Path(args.inav_root).expanduser()
for sd in SUBDIRS:
    root = base_dir / sd
    if not root.is_dir():
        continue
    for fn in root.rglob('*'):
        if fn.suffix in ('.c', '.h'):
            txt = fn.read_text(errors='ignore')
            ret = extract_enums(fn, txt, seen, seen_members)
            all_enums.extend(ret)

with open('all_enums.h', 'w') as out:
    out.write(f"// Consolidated enums — generated on {datetime.datetime.now()}\n\n")
    out.writelines(all_enums)

print(f"Found {len(all_enums)} enums. Wrote all_enums.h.")
