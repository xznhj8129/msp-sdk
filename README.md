# MSP SDK
Unified SDK for INAV:
* Python
* Arduino/PIO
* C++

# WIP, does not work yet

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
├── generator <- holds scripts to generate all derivative libraries and headers from the files in include/ 
│   ├── cgen_test <- unstructured drop-in of previous experimentation to generate C headers, look in here only as last resort
│   │   └── many files here are duplicated, stale or already moved where they might belong more 
│   ├── all_defines.h
│   ├── bad_define_parse.py
│   ├── gen_all.sh (current C/C++ header build script, priority)
│   ├── gen_msp_header.py
│   ├── get_all_inav_enums_h.py (shouldn't be there, only rely on inav/docs/development/msp generations)
│   ├── get_inav_defines.py ()
│   ├── new_get_inav_enums.py (shouldn't be there, only rely on inav/docs/development/msp generations)
│   └── etc
├── include <- all necessary spec and header files, pulled from INAV source directly, with noted version and build/branch number. Some files may be stale.
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
├── build_py.sh <- runs the python lib generator
├── LICENSE
└── README.md

all_defines.h: literally all the defines i could find in the INAV source code
all_enums.h: literally all the enums i could find in the INAV source code
msp_messages.h: header of MSP message structs generates from msp_messages.json
msp_stub_types.h: ad-hoc band-aid fallback stub definitions for MSP support types not present in all_defines or all_enums (why?)
msp_types.h: consolidated header of all types (structs and defines) absolutely required by the MSP library

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