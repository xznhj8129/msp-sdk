# MSP SDK
Unified SDK for INAV:
* Python
* Arduino/PIO
* C++

# Work in progress

## Authoritative generator

`./build_c.sh` is the only supported C/C++ generation entry point. It invokes
`generator/gen_all.sh`, and that script names every active generator explicitly.
Superseded experiments are quarantined under `.old/`, preserving their former
relative paths. The quarantine is ignored except for its README and is never a
build input.

Artifact ownership is deliberately narrow:

* `include/` is the only public C/C++ include tree.
* `generator/all_defines.h` and `generator/inav_defines.py` are the define
  generator's explicit outputs.
* `build/generator/` contains compiled demos and diagnostics.
* Active generators do not write duplicate JSON or C headers into `generator/`.

Run the full sync, generation, compile, and demo from any directory:

```bash
./build_c.sh
```

The default INAV checkout is the sibling `inav/` directory. Select another
checkout with:

```bash
./build_c.sh --inav-dir ../other-inav
```

## Description:
This is a chimera of multiple different projects that need to be fused to grow from the same root:
* Python: mspapi2 (most developped)
* Arduino: MSP-Arduino (second most developped)
* C/C++: not developped yet. derived from MSP-Arduino? Or would MSP-Arduino derive from shared definitions?
* Generator: from msp_documentation testing, generates C headers from MSP spec

├── arduinolib
│   └── Arduino/PlatformIO library
├── pythonlib
│   └── Python library 
├── clib
│   └── C library 
├── generator <- active generators and define outputs
│   ├── all_defines.h (generated define intermediate)
│   ├── bad_define_parse.py (generates import-safe Python constants from all_defines.h)
│   ├── gen_all.sh (current C/C++ header build script, priority)
│   ├── gen_all_enums.py
│   ├── gen_msp_header.py
│   ├── get_inav_defines.py (collects object-like defines from INAV source)
│   └── etc
├── include <- the single public C/C++ include tree, refreshed by build_c.sh
│   ├── all_enums.h
│   ├── bitarray.c (pulled from inav for sameness)
│   ├── bitarray.h (pulled from inav for sameness)
│   ├── inav_enums.json
│   ├── msp_messages.json
│   ├── msp_protocol.h
│   ├── msp_protocol_v2_common.h
│   ├── msp_protocol_v2_inav.h
│   ├── msp_protocol_v2_sensor.h
│   ├── msp_protocol_v2_sensor_msg.h
│   └── etc 
├── build.sh <- script that fetches all necessary headers and specs from INAV, then run the script(s) in generator to generate the derivative libraries to be placed in their respective lib
├── LICENSE
├── build_c.sh <- runs the C header generator
├── .old <- ignored quarantine; never used by generation
├── build_py.sh <- runs the python lib generator
├── LICENSE
└── README.md

`generator/all_defines.h`: annotated define input for the Python constant generator.

`include/all_enums.h`: enums referenced by the MSP schema, plus `boxId_e`
because it defines the current active-mode bitmask width.

`include/msp_messages.h`: generated MSP wire structs. Enum annotations do not
replace their fixed-width wire integer types.

`include/msp_stub_types.h`: wire support structs not represented by
`inav_enums.json`.

`include/msp_types.h`: constants and support-type aggregation required by the
generated message header.

Goals:
* From canon INAV source and MSP spec, generate headers for MSP messages that can be used in any C, C++ or Arduino project, like Mavlink does
* From the same canon INAV source and MSP spec, generate a Python library for MSP messages
* For C/C++, when something can be directly taken from INAV source, it probably should be
* One Enter generation 



## Generation process:

### INAV
Seperate from the SDK, in inav/docs/development/msp: gen_docs.sh generates documentation and headers
* msp_messages.json is canon MSP spec, manually updated
* all_eums.h is created from source parsing
* inav_enums.json is created from all_enums.h

### Reference Generator
* copy necessary headers from inav/src to include/
* copy JSON definitions from inav/docs/development/msp to include/
* generate public headers in include/
* compile against include/ only, so stale generator-local headers cannot mask
  public include failures


C-lib needs:
* msp_messages.h
* msp_types.h
* msp_protocol_*.h

Arduino-lib needs:
* msp_messages.h
* msp_types.h
* msp_protocol_*.h

Python mspapi2 needs:
* msp_messages.json
* inav_enums.json
* inav_defines.py

### Python define generation

Normally `build_c.sh` runs this. For define-only work, from `generator/`:

```bash
python -m pip install -r requirements-defines.txt
python get_inav_defines.py --inav-root ../../inav/src/main --output all_defines.h
python bad_define_parse.py --input all_defines.h --output inav_defines.py
```

`get_inav_defines.py` records the source file for each collected macro in
`all_defines.h`. `bad_define_parse.py` reads those source files to discover
typedef aliases, parses object-like macro expressions as C, and writes only
concrete Python literals or `None`. Conflicting preprocessor branches,
external dependencies, function-like macros, and unsupported compiler
extensions are never guessed. Use `--verbose` to print the reason for each
unresolved value.
