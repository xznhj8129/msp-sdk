# MSP SDK

A multi-language SDK for INAV's MultiWii Serial Protocol (MSP). The protocol
definitions — wire structs, enums, constants, and the message schema — are
generated directly from INAV source code, and each language library is built
on top of that single generated snapshot. One source of truth, one generator,
independently usable libraries.

## Components

| Component | Location | Description |
|-----------|----------|-------------|
| Generator | `generator/` | Parses INAV sources and the canonical MSP schema, regenerates `include/` |
| Snapshot | `include/` | Canonical generated headers + JSON schema, shared by all libraries |
| Python | `pythonlib/` | `mspapi2` — codec, typed API, serial/TCP/UDP transports, interactive shell |
| Arduino | `arduinolib/` | Arduino/PlatformIO library — low-level MSP v2 framing + high-level INAV API |
| C/C++ | `include/` | The generated headers are directly usable; a compiled `clib/` is planned |

## Repository layout

```
msp_sdk/
├── build_all.sh          # orchestration: generate / test / package / release
├── build_c.sh            # C/C++ header pipeline only (wrapper)
├── generator/            # INAV → shared generated artifacts
├── include/              # canonical generated protocol snapshot (committed)
├── arduinolib/           # standalone Arduino library
│   ├── src/              #   msp_interface.*, inav_api.*
│   ├── src/generated/    #   staged generated headers
│   ├── examples/
│   └── tests/esp32/      #   PlatformIO build test
├── pythonlib/            # standalone Python package (src layout)
│   ├── src/mspapi2/
│   │   └── lib/          #   staged schema, enums, defines, version
│   ├── tests/
│   └── examples/
├── inav/                 # SDK-managed INAV clone (untracked build input)
└── plan.md               # monorepo design notes
```

## Quick start

```bash
./build_all.sh generate   # sync INAV → regenerate include/ → stage into the libs
./build_all.sh test       # C/C++ header compile + demos, Python unit tests
./build_all.sh package    # dist/: Python wheel + sdist, Arduino library zip
./build_all.sh release    # generate + test + package
```

Add `--with-arduino` to `test` to also compile the Arduino example for ESP32
with PlatformIO.

## INAV source

Generation requires an INAV checkout. By default the SDK manages its own:
`generator/sync_inav.sh` clones `https://github.com/xznhj8129/inav.git`
(branch `mavlink_multiport2`) into `./inav/`. The clone is git-ignored and
safe to delete at any time; the scripts recreate it when missing.

```bash
./build_all.sh generate                       # use (or create) the ./inav clone
./build_all.sh generate --update-inav         # hard-reset the clone to the remote branch
./build_all.sh generate --inav-branch 9.0.1   # different branch of the default remote
./build_all.sh generate --inav-repo URL       # different remote
./build_all.sh generate --inav-dir ../inav    # your own checkout; never modified
```

Every generated snapshot is stamped with the INAV version parsed from the
checkout (`pythonlib/src/mspapi2/lib/inav_version.py`), and the schema itself
carries a version (`version` field in `msp_messages.json`). Generate from the
INAV version that matches your target firmware — a stale schema misdecodes
newer firmware, and vice versa.

## Artifact flow

`include/` is the canonical snapshot. `generate` copies (never symlinks) the
relevant parts into each package:

| Canonical artifact  | C/C++ | Arduino | Python |
|---------------------|-------|---------|--------|
| `msp_protocol*.h`   | yes   | yes     | –      |
| `msp_messages.h`    | yes   | yes     | –      |
| `msp_types.h`       | yes   | yes     | –      |
| `msp_messages.json` | opt.  | –       | yes    |
| `inav_enums.json`   | opt.  | –       | yes    |
| `inav_defines.py`   | –     | –       | yes    |

Generated artifacts are committed: installing the Python or Arduino package
does not require an INAV checkout or the generator toolchain.

## Further reading

* `arduinolib/README.md` — Arduino library usage and API
* `pythonlib/README.md` — Python library usage and API
* `generator/README.md` — generator pipeline internals
* `plan.md` — monorepo design rationale
