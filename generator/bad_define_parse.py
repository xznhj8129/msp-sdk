#!/usr/bin/env python3
"""
Read all_defines.h, parse #define constants, and write defines.py.

- Keeps object-like macros with simple arithmetic (+ - * // % << >> & | ^ ~, parentheses) and identifiers.
- Empty defines become NAME = None.
- Skips function-like macros and unusable junk (sizeof/alignof/typeof/offsetof/ARRAYLEN, casts, ->, ., [], {}, and any IDENT(...)).
- Converts / to // and strips C integer suffixes (U, UL, LL).
- Preserves references where safe and orders them topologically when possible.
- Critically: never emits an arithmetic expression if any dependency is unknown or None. In that case it writes NAME = None.
- After writing defines.py, attempts to exec it; on NameError, prepends the missing name as NAME = None and retries until it runs.

Hardcoded I/O:
  input:  all_defines.h
  output: inav_defines.py
"""

import re
from collections import defaultdict
from pathlib import Path
import sys

IN_FILE = Path("all_defines.h")
OUT_FILE = Path("inav_defines.py")

DEFINE_RE = re.compile(r'^\s*#\s*define\s+([A-Za-z_]\w*)(?:\s+(.*?))?\s*$')
# Function-like macros require the '(' to appear immediately after the name (no whitespace).
FUNC_LIKE_RE = re.compile(r'^\s*#\s*define\s+([A-Za-z_]\w*)\(')
IDENT_RE = re.compile(r'[A-Za-z_]\w*')
CALL_IN_RHS_RE = re.compile(r'\b[A-Za-z_]\w*\s*\(')  # foo( ... )

INT_WITH_SUFFIX_RE = re.compile(r'''
    (?P<num>
        0[xX][0-9A-Fa-f]+
        |0[bB][01]+
        |0[oO][0-7]+
        |\d+
    )
    (?P<suf>[uUlL]+)?
''', re.VERBOSE)

ALLOWED_TOKENS_RE = re.compile(r'^[\s0-9A-Fa-fxXbo()+\-*%<>&|^~/_.\'":]*$')

FORBIDDEN_SNIPPETS = [
    'sizeof', 'alignof', 'typeof', 'offsetof', 'ARRAYLEN',
    '->', '{', '}', '[', ']'
]
# Strip simple casts like (uint8_t) or (float), not plain parenthesized identifiers.
CAST_RE = re.compile(r'\(\s*(?:u?int[0-9_]*|float|double|char|long|short)[^)]*\)\s*', re.IGNORECASE)

# Force some known-problematic names to None unconditionally.
FORCE_NONE = {
    'FIXED_WING_LEVEL_TRIM_CONTROLLER_LIMIT',
}

def strip_block_comments(text: str) -> str:
    return re.sub(r'/\*.*?\*/', '', text, flags=re.S)

def strip_line_comment(s: str) -> str:
    # Avoid treating integer division '//' as a comment; only strip if it doesn't look like numeric op.
    if re.search(r'\d\s*//\s*\d', s):
        return s
    return s.split('//', 1)[0]

def join_backslash_lines(text: str) -> str:
    lines = text.splitlines()
    out = []
    buf = ''
    for ln in lines:
        if ln.rstrip().endswith('\\'):
            buf += ln.rstrip()[:-1]
        else:
            out.append(buf + ln)
            buf = ''
    if buf:
        out.append(buf)
    return '\n'.join(out)

def normalize_expr(expr: str) -> str:
    s = expr.strip()
    s = strip_line_comment(s)
    # strip float suffixes on literals (allow embedded in expressions)
    s = re.sub(r'(?P<num>(?:\d+\.\d*|\.\d+|\d+)(?:[eE][-+]?\d+)?)[fF]\b', r'\g<num>', s)
    s = re.sub(r'(?<!/)/(?!/)', '//', s)
    if 'sizeof' not in s.lower():
        # strip simple casts like (uint8_t) or (float)
        s = CAST_RE.sub('', s)
    s = re.sub(r'BIT\s*\(\s*([0-9]+)\s*\)', lambda m: f"(1<<{m.group(1)})", s)
    s = INT_WITH_SUFFIX_RE.sub(lambda m: m.group('num'), s)
    # normalize leading-zero integer literals (e.g. 05 -> 5)
    s = re.sub(r'\b0[0-9]+', lambda m: str(int(m.group(0), 10)), s)
    s = re.sub(r'\s+', ' ', s).strip()
    had_parens = s.startswith('(') and s.endswith(')')
    while s.startswith('(') and s.endswith(')'):
        s = s[1:-1].strip()
    if s.endswith(';'):
        s = s[:-1].rstrip()
    if s.lower().endswith('f') and is_float_literal(s):
        s = s[:-1]
    if had_parens and not (s.startswith('(') and s.endswith(')')):
        s = f"({s})"
    return s

def is_func_like_define(line: str) -> bool:
    return bool(FUNC_LIKE_RE.match(line))

def is_unusable(rhs: str) -> bool:
    if any(tok in rhs for tok in FORBIDDEN_SNIPPETS):
        return True
    if CAST_RE.search(rhs):
        return True
    if CALL_IN_RHS_RE.search(rhs):
        return True
    if '?' in rhs or ',' in rhs:
        return True
    return False

def is_simple_ident(rhs: str) -> bool:
    s = rhs.strip()
    # Allow optional wrapping parens around a single identifier.
    while s.startswith('(') and s.endswith(')'):
        s = s[1:-1].strip()
    return bool(re.fullmatch(r'[A-Za-z_]\w*', s))

def is_numeric_literal(rhs: str) -> bool:
    return bool(re.fullmatch(r'(0[xX][0-9A-Fa-f]+|0[bB][01]+|0[oO][0-7]+|\d+)', rhs.strip()))
def is_float_literal(rhs: str) -> bool:
    return bool(re.fullmatch(r'\(?\s*[-+]?(?:\d+\.\d*|\.\d+|\d+)(?:[eE][-+]?\d+)?f?\s*\)?', rhs.strip(), flags=re.IGNORECASE))
def is_string_literal(rhs: str) -> bool:
    rhs = rhs.strip()
    return (
        (rhs.startswith('"') and rhs.endswith('"'))
        or (rhs.startswith("'") and rhs.endswith("'"))
    )

def is_operator_expr(rhs: str) -> bool:
    s = rhs.strip()
    # Strip outer parens
    while s.startswith('(') and s.endswith(')'):
        s = s[1:-1].strip()
    if is_simple_ident(s) or is_numeric_literal(s) or is_float_literal(s):
        return False
    # Any operator symbol means it's arithmetic/bitwise, which will evaluate in class body.
    return bool(re.search(r'[+\-*/%<>&|^~()]', s))

def extract_defines(text: str):
    macros = {}
    sources = {}
    current_source = None
    for line in text.splitlines():
        if line.startswith("// "):
            current_source = line[3:].strip()
        m_fun = FUNC_LIKE_RE.match(line)
        if m_fun:
            print(f"Skipping function-like define: {m_fun.group(1)} at {current_source}")
            continue
        m = DEFINE_RE.match(line)
        if not m:
            continue
        name, rhs = m.group(1), m.group(2)

        if name in FORCE_NONE:
            print(f"Forcing {name} = None at {current_source}")
            macros[name] = None
            sources[name] = current_source
            continue

        if rhs is None or not strip_line_comment(rhs).strip():
            print(f"Empty define: {name} -> None at {current_source}")
            macros[name] = None
            sources[name] = current_source
            continue

        rhs = normalize_expr(rhs)
        if is_string_literal(rhs):
            macros[name] = rhs
            sources[name] = current_source
            continue
        if is_unusable(rhs):
            print(f"Skipping unusable define: {name} = {rhs} at {current_source}")
            continue

        tmp = IDENT_RE.sub('', rhs)
        if not ALLOWED_TOKENS_RE.match(tmp):
            print(f"Skipping disallowed tokens: {name} = {rhs} at {current_source}")
            continue

        if name in macros and macros[name] != rhs:
            prev_src = sources.get(name)
            print(f"Overwriting define {name}: {macros[name]} ({prev_src}) -> {rhs} ({current_source})")
        macros[name] = rhs
        sources[name] = current_source
    return macros

def dependency_graph(macros: dict):
    names = set(macros.keys())
    deps = {}
    for k, v in macros.items():
        if v is None or is_string_literal(str(v)) or is_float_literal(str(v)) or is_numeric_literal(str(v)):
            deps[k] = set()
        else:
            deps[k] = set(IDENT_RE.findall(v)) & names
    return deps

def topo_sort(macros: dict, deps: dict):
    indeg = {k: len(deps[k]) for k in macros}
    rev = defaultdict(set)
    for k, ds in deps.items():
        for d in ds:
            rev[d].add(k)
    order = []
    from collections import deque as dq
    q = dq([k for k, d in indeg.items() if d == 0])
    while q:
        u = q.popleft()
        order.append(u)
        for v in rev[u]:
            indeg[v] -= 1
            if indeg[v] == 0:
                q.append(v)
    leftover = [k for k, d in indeg.items() if d > 0]
    return order, leftover

def resolve_safe_values(macros: dict, order: list):
    """
    Decide what to write for each macro so import never evaluates arithmetic on None.
    Rules:
      - If name in FORCE_NONE => None
      - If rhs is None => None
      - If rhs is a simple identifier:
            - write the reference as-is (safe even if it is None)
      - If rhs contains any operator:
            - if rhs references any identifier that is not a known macro => None
            - if rhs references any identifier already resolved to None => None
            - else keep the expression
    """
    names = set(macros.keys())
    resolved = {}
    for name in order:
        rhs = macros[name]
        if name in FORCE_NONE:
            resolved[name] = None
            continue
        if rhs is None:
            resolved[name] = None
            continue
        # Simple alias is always safe
        if is_simple_ident(rhs):
            ident = re.fullmatch(r'\(?\s*([A-Za-z_]\w*)\s*\)?', rhs).group(1)
            # If it aliases an unknown external, prefer None so we do not depend on exec-fixer.
            if ident not in names:
                resolved[name] = None
            else:
                resolved[name] = rhs
            continue
        # Literal floats are fine
        if is_float_literal(rhs):
            resolved[name] = rhs
            continue
        if is_string_literal(rhs):
            resolved[name] = rhs
            continue
        if not is_operator_expr(rhs):
            # literal like (123) etc.
            resolved[name] = rhs
            continue
        # Operator expression: check deps
        deps = set(IDENT_RE.findall(rhs))
        deps = {d for d in deps if d.lower() not in {'f', 'u', 'l', 'ul', 'ull'}}  # ignore suffix-like idents
        externals = [d for d in deps if d not in names]
        if externals:
            print(f"Skipping {name} due to external deps {externals}: {rhs}")
            resolved[name] = None
            continue
        any_none = any(resolved.get(d) is None for d in deps if d in resolved)
        if any_none:
            print(f"Skipping {name} due to None dependency in {deps}: {rhs}")
            resolved[name] = None
        else:
            resolved[name] = rhs
    return resolved

def write_python_base(out_path: Path, order, macros, leftover, resolved):
    with out_path.open('w', encoding='utf-8') as f:
        f.write('# Auto-generated from C #defines.\n')
        f.write('# flake8: noqa\n\n')
        # Predeclare any external names that we chose to keep as alias (we currently set those to None instead)
        f.write('\nclass InavDefines:\n')
        for name in order:
            val = resolved[name]
            if val is None:
                f.write(f'    {name} = None\n')
            else:
                f.write(f'    {name} = {val}\n')
        if leftover:
            f.write('\n# Cyclic or unresolved references, left as comments:\n')
            for name in leftover:
                if name not in resolved:
                    f.write(f'    # {name} = {macros[name] if macros[name] is not None else "None"}\n')

def try_exec_and_fix(out_path: Path, max_iters: int = 500):
    """
    Repeatedly exec the file. On NameError, prepend NAME = None and retry.
    Stops when exec succeeds or max_iters hit.
    """
    for _ in range(max_iters):
        code = out_path.read_text(encoding='utf-8')
        try:
            exec(compile(code, str(out_path), 'exec'), {})
            return True
        except NameError as e:
            missing = getattr(e, 'name', None)
            if not missing:
                m = re.search(r"name '([^']+)' is not defined", str(e))
                if m:
                    missing = m.group(1)
            if not missing:
                print(f"Could not extract missing name from NameError: {e}", file=sys.stderr)
                return False
            if re.search(rf'^\s*{re.escape(missing)}\s*=', code, flags=re.M):
                sentinel = f'__MISSING_SENTINEL_{missing}__'
                if sentinel in code:
                    return False
                patched = code.replace('# flake8: noqa', f'# flake8: noqa\n{sentinel} = None')
                out_path.write_text(patched, encoding='utf-8')
                continue
            lines = code.splitlines()
            insert_idx = 0
            if lines and lines[0].startswith('# Auto-generated'):
                insert_idx = 2 if len(lines) > 1 and lines[1].startswith('# flake8') else 1
            lines.insert(insert_idx, f'{missing} = None')
            out_path.write_text('\n'.join(lines) + '\n', encoding='utf-8')
            continue
    print("Max iterations reached while fixing missing names.", file=sys.stderr)
    return False

def main():
    if not IN_FILE.exists():
        print(f"Missing {IN_FILE}", file=sys.stderr)
        sys.exit(1)

    raw = IN_FILE.read_text(encoding='utf-8', errors='ignore')
    raw = strip_block_comments(raw)
    raw = join_backslash_lines(raw)

    macros = extract_defines(raw)
    if not macros:
        print("No usable #define lines found.", file=sys.stderr)
        sys.exit(2)

    deps = dependency_graph(macros)
    order, leftover = topo_sort(macros, deps)
    if not order and leftover:
        print("All macros appear cyclic or invalid; nothing written.", file=sys.stderr)
        sys.exit(3)

    resolved = resolve_safe_values(macros, order)
    resolved["DEBUG32_VALUE_COUNT"] = 8
    write_python_base(OUT_FILE, order, macros, leftover, resolved)

    if try_exec_and_fix(OUT_FILE):
        print(f"Wrote {OUT_FILE} and resolved missing references with None where needed.")
    else:
        print(f"Wrote {OUT_FILE} but could not fully resolve all missing names.", file=sys.stderr)
        sys.exit(4)

if __name__ == '__main__':
    main()
