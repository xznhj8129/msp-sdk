# MSP SDK for INAV — Arduino library

Arduino/PlatformIO library for talking to INAV flight controllers over the
MultiWii Serial Protocol (MSP v2). Part of the
[msp_sdk](https://github.com/xznhj8129/msp-sdk) monorepo.

**Work in progress — use at your own risk.**

The wire-protocol headers under `src/generated/` are produced directly from
INAV sources by the msp_sdk generator. Do not edit them by hand; regenerate
with `./build_all.sh generate` from the SDK root.

## Layout

```
arduinolib/
├── library.properties
├── src/
│   ├── msp_interface.h/.cpp   # low-level MSP v2 framing (send/recv/request/command)
│   ├── inav_api.h/.cpp        # high-level INAV API, SI units
│   └── generated/             # generated wire protocol headers (from INAV source)
├── examples/
│   └── inav_demo/             # connection, FC info, mission upload, telemetry
└── tests/
    └── esp32/                 # PlatformIO project building the example
```

## Usage

Include the high-level API:

```cpp
#include <inav_api.h>

InavAPI inav;
inav.Init(Serial2, 500);

inav_status st{};
if (inav.get_status(st)) {
    // st.armed, st.cycleTime_us, ...
}
```

Or the low-level interface for messages without high-level wrappers:

```cpp
#include <msp_interface.h>

MSPIntf msp;
msp.begin(Serial2);
MSP_STATUS_reply_t status{};
msp.request(MSP_STATUS, &status, sizeof(status));
```

Message structs (`MSP_*_reply_t`, `MSP_SET_*_t`, ...) and enums come from the
generated headers, which mirror `inav/src/main/msp/msp_protocol*.h` and the
canonical MSP message schema.

## Important considerations

* **Unit conversion:** INAV and MSP sometimes use fractions of units
  (deci-degrees, centimeters, cm/s). The high-level `InavAPI` converts to SI
  units (degrees, meters, m/s).
* **Blocking communication:** `recv`, `waitFor`, and `request` block up to the
  configured timeout (default 500 ms).
* **RC override:** sending RC commands via MSP bypasses the RC receiver. Use
  with extreme caution.
* **Configuration changes:** `set*` functions modify RAM only. Call
  `commandEepromWrite()` to persist.

## Compatibility

* **Hardware:** developed and tested on ESP32; should work on other
  Arduino-compatible boards with `Stream` support and sufficient resources.
* **Firmware:** INAV with MSP v2 support. The generated headers target a
  specific INAV snapshot; regenerate against your firmware's INAV version if
  needed.

## License

Based on code originally licensed under the GNU Lesser General Public License
v2.1 or later. See source file headers for details.
