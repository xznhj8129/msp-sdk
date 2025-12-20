#!/usr/bin/env python3
import datetime
import re
from pathlib import Path

BASE = Path('../inav/src/main')
SUBDIRS = [
    'navigation',
    'sensors',
    'programming',
    'rx',
    'telemetry',
    'io',
    'flight',
    'fc',
]

def strip_comments(text: str) -> str:
    # Remove /* ... */ block comments and // line comments
    text = re.sub(r'/\*.*?\*/', '', text, flags=re.DOTALL)
    text = re.sub(r'//.*', '', text)
    return text

def extract_defines_with_conditionals(text: str):
    """
    Extract #define lines, preserving surrounding conditionals:
      #if, #ifdef, #ifndef, #elif, #else, #endif
    Only emits wrappers that actually contain at least one #define.
    Handles multi-line defines with trailing backslashes.

    Fixes the bug where the first define appears in an #else/#elif branch:
    we now emit the original opening #if... and then the active branch header.
    """
    text = strip_comments(text)
    lines = text.splitlines()

    define_re = re.compile(r'^\s*#\s*define\b')
    if_re     = re.compile(r'^\s*#\s*if(n?def)?\b')   # #if, #ifdef, #ifndef
    elif_re   = re.compile(r'^\s*#\s*elif\b')
    else_re   = re.compile(r'^\s*#\s*else\b')
    endif_re  = re.compile(r'^\s*#\s*endif\b')

    out = []
    defines_count = 0

    # Each stack frame tracks nesting state.
    # Fields:
    #   open: the initial #if/#ifdef/#ifndef line
    #   emitted_open: have we emitted the 'open' line yet
    #   current_branch: the current branch header (#if... initially, then #elif/#else)
    #   emitted_current_branch: have we emitted the current_branch header yet
    #   had_output: has any #define been emitted inside this frame
    stack = []

    def ensure_opened_for_all_levels():
        """
        Ensure that for every open frame we have emitted the correct headers.
        If a frame hasn't printed anything yet and we're currently in an
        #else/#elif branch, we must first emit the original #if... and then
        the active branch header.
        """
        for frame in stack:
            if not frame['emitted_open']:
                out.append(frame['open'].rstrip() + '\n')
                frame['emitted_open'] = True
                # If we are still on the opening branch, mark it emitted too.
                if frame['current_branch'] == frame['open']:
                    frame['emitted_current_branch'] = True
            if not frame['emitted_current_branch']:
                out.append(frame['current_branch'].rstrip() + '\n')
                frame['emitted_current_branch'] = True

    def mark_output_in_all_levels():
        for frame in stack:
            frame['had_output'] = True

    i = 0
    n = len(lines)
    while i < n:
        line = lines[i]

        if if_re.match(line):
            stack.append({
                'open': line.rstrip(),
                'emitted_open': False,
                'current_branch': line.rstrip(),          # starts as the opening branch
                'emitted_current_branch': False,
                'had_output': False,
            })
            i += 1
            continue

        if elif_re.match(line) or else_re.match(line):
            if stack:
                frame = stack[-1]
                # Switch to new branch. Do not emit yet; we will emit on demand.
                frame['current_branch'] = line.rstrip()
                frame['emitted_current_branch'] = False
            i += 1
            continue

        if endif_re.match(line):
            if stack:
                frame = stack.pop()
                if frame['had_output']:
                    # Only close if we actually opened in the output
                    # (emitted_open will be True whenever had_output is True, by construction)
                    out.append('#endif\n')
            i += 1
            continue

        if define_re.match(line):
            # Capture multi-line define with trailing backslashes
            block = [line.rstrip()]
            while block[-1].rstrip().endswith('\\') and i + 1 < n:
                i += 1
                block.append(lines[i].rstrip())

            ensure_opened_for_all_levels()
            for l in block:
                out.append(l + '\n')
            #out.append('\n')  # spacer
            defines_count += 1
            mark_output_in_all_levels()

            i += 1
            continue

        # Anything else: ignore
        i += 1

    # Close any still-open frames that actually produced output but for which
    # we never saw the corresponding #endif in this file slice.
    while stack:
        frame = stack.pop()
        if frame['had_output'] and frame['emitted_open']:
            out.append('#endif\n')

    return out, defines_count

all_out_lines = []
total_defines = 0
file_hits = 0

for sd in SUBDIRS:
    root = BASE / sd
    if not root.is_dir():
        continue
    for fn in root.rglob('*'):
        if fn.suffix in ('.c', '.h'):
            txt = fn.read_text(errors='ignore')
            extracted, count = extract_defines_with_conditionals(txt)
            if count > 0:
                file_hits += 1
                all_out_lines.append(f"\n// {fn}\n")
                all_out_lines.extend(extracted)
                if not (all_out_lines and all_out_lines[-1].endswith('\n\n')):
                    all_out_lines.append('\n')
                total_defines += count

with open('all_defines.h', 'w') as out:
    out.write(f"// Consolidated defines - generated on {datetime.datetime.now()}\n\n")
    out.writelines(all_out_lines)

print(f"Found {total_defines} #define entries across {file_hits} files. Wrote all_defines.h.")
