# Generator

The generator turns an INAV checkout into the shared artifacts every SDK
library is built from. The supported pipeline is `gen_all.sh` (usually driven
via `../build_all.sh generate`).

## Inputs and outputs

| Input (from the INAV checkout) | Generated artifact |
|--------------------------------|--------------------|
| `src/main/msp/msp_protocol*.h` | `../include/msp_protocol*.h` (copied verbatim) |
| `docs/development/msp/msp_messages.json` | `../include/msp_messages.h`, staged to pythonlib |
| `docs/development/msp/inav_enums.json` | `../include/all_enums.h`, staged to pythonlib |
| `src/main/**/*.h` object-like macros | `all_defines.h` → `inav_defines.py` (here and staged to pythonlib) |
| `src/main/common/bitarray.*` | `../include/bitarray.*` (copied verbatim) |
| INAV `CMakeLists.txt` | `inav_version.py` (staged to pythonlib by `build_all.sh`) |

Public outputs live in `../include/` — never copy generated JSON, enum
headers, message headers, or type headers into this directory. Binaries and
diagnostics go to `../build/generator/`.

## Pipeline (`gen_all.sh`)

1. **Sync** (`../include/sync.sh`): copies the canonical JSON schema, enum
   JSON, protocol headers, and bitarray from the INAV checkout into
   `../include/`.
2. **Defines** (`get_inav_defines.py`, `bad_define_parse.py`): collects
   object-like macros from INAV sources into `all_defines.h`, then resolves
   them (with `pycparser`, see `requirements-defines.txt`) into import-safe
   Python constants in `inav_defines.py`. Unresolvable macros (conflicting
   branches, external dependencies, function-like macros) become `None` —
   never guessed. `--verbose-defines` prints the reason per macro.
3. **Headers** (`gen_all_enums.py`, `gen_msp_header.py`): renders
   `all_enums.h` (schema-referenced enums plus `boxId_e`) and
   `msp_messages.h` (packed wire structs) from the JSON schema.
4. **Checks**: `py_compile` + `test_generators.py` unit tests, then strict
   (`-Wall -Wextra -Werror`) C11 and C++17 compiles of `test.c`/`test.cpp`
   against `../include/` only, and runs the resulting demos.

## INAV checkout (`sync_inav.sh`)

Without `--inav-dir`, generation uses the SDK-managed clone at `../inav/`,
creating it from the network when missing. Defaults: repo
`https://github.com/xznhj8129/inav.git`, branch `mavlink_multiport2`.
`--update` hard-resets the clone to the remote branch (discards anything
local in it). The clone is git-ignored and safe to delete at any time.

## Notes

* Historical experiments are quarantined under `../.old/`; nothing there is a
  build input.
* The Proto and YAML generators (`gen_msp_proto.py`, `gen_enum_yaml.py`,
  `msp_to_yaml.py`) are kept for downstream consumers but are not invoked by
  `gen_all.sh`.
