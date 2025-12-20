# MSP SDK
Unified SDK for INAV:
* Python
* Arduino/PIO
* C++

# WIP, does not work yet


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