The right approach is a monorepo containing several independently
  packageable libraries. The repository is the shared development and
  release project; it is not itself one universal installable package.

  msp_sdk/
  ├── generator/                 # INAV → shared generated artifacts
  ├── include/                   # canonical generated protocol snapshot
  │
  ├── clib/
  │   ├── CMakeLists.txt
  │   ├── include/msp_sdk/
  │   ├── src/
  │   └── tests/
  │
  ├── arduinolib/
  │   ├── library.properties
  │   ├── src/
  │   │   ├── MSP.h
  │   │   ├── MSP.cpp
  │   │   └── generated/
  │   ├── examples/
  │   └── tests/
  │
  ├── pythonlib/
  │   ├── pyproject.toml
  │   ├── src/mspapi2/
  │   │   └── lib/               # packaged JSON, enums, defines
  │   └── tests/
  │
  ├── packaging/
  │   ├── conan/
  │   ├── vcpkg/
  │   └── platformio/
  │
  ├── test/
  │   └── protocol_vectors/      # shared encode/decode fixtures
  │
  ├── build_all.sh
  └── README.md

  The important distinction is:

  - One repository.
  - One generator and protocol snapshot.
  - Separate package manifests.
  - Separate release artifacts.
  - One coordinated release command.

  ### Artifact flow

  include/ remains the canonical generated snapshot. Packaging copies the
  appropriate parts into each standalone distribution:

   Canonical artifact                  C             Arduino      Python
  ━━━━━━━━━━━━━━━━━━━━  ━━━━━━━━━━━━━━━━━  ━━━━━━━━━━━━━━━━━━  ━━━━━━━━━━
   msp_protocol*.h                   Yes                 Yes          No
  ────────────────────  ─────────────────  ──────────────────  ──────────
   msp_messages.h                    Yes                 Yes          No
  ────────────────────  ─────────────────  ──────────────────  ──────────
   msp_types.h                       Yes                 Yes          No
  ────────────────────  ─────────────────  ──────────────────  ──────────
   msp_messages.json            Optional                  No         Yes
  ────────────────────  ─────────────────  ──────────────────  ──────────
   inav_enums.json              Optional                  No         Yes
  ────────────────────  ─────────────────  ──────────────────  ──────────
   inav_defines.py                    No                  No         Yes
  ────────────────────  ─────────────────  ──────────────────  ──────────
   YAML/Proto                 Downstream          Downstream    Optional
                                packages            packages

  These should be copied during generation or package staging—not
  symlinked. Symlinks tend to break archives, Windows checkouts, Arduino
  tooling, and standalone package builds.

  Generated artifacts should generally be committed. Someone installing
  the Python or Arduino package should not require an INAV checkout,
  pycparser, or the generator toolchain. CI regenerates them and fails if
  regeneration changes the repository unexpectedly.

  ### C library

  clib/ gets its own CMakeLists.txt and produces:

  - libmsp_sdk.a or libmsp_sdk.so
  - installed headers under include/msp_sdk/
  - msp-sdk-config.cmake
  - optionally msp-sdk.pc

  CMake’s installation/export mechanism is specifically intended to
  install targets and reconstruct them for downstream find_package()
  consumers. CMake installation and package documentation
  (https://cmake.org/cmake/help/latest/guide/tutorial/Installation%20Commands%20and%20Concepts.html)

  Eventually, Conan and vcpkg recipes can package that same CMake
  project. They belong under packaging/; they should not define a second
  build system.

  ### Arduino library

  arduinolib/ must be a complete standalone Arduino library folder:

  arduinolib/
  ├── library.properties
  ├── src/
  │   ├── MSP.h
  │   ├── MSP.cpp
  │   └── generated/*.h
  ├── examples/
  └── keywords.txt

  Arduino expects library.properties at the library root and recursively
  compiles files under src/. Only headers directly under src/ are treated
  as the obvious public interface, so generated/internal headers can live
  beneath src/generated/. Official Arduino library specification
  (https://docs.arduino.cc/arduino-cli/library-specification)

  The awkward part is Arduino Library Manager: monorepos are not its
  natural publishing model. I would keep arduinolib/ in the monorepo, but
  publish it through either:

  - A standalone ZIP attached to each release.
  - A mechanically maintained msp-sdk-arduino mirror repository
    containing only arduinolib/.

  That mirror is a publication target, not another source of truth.

  ### Python library

  pythonlib/ is an ordinary modern Python project:

  pythonlib/
  ├── pyproject.toml
  ├── src/
  │   └── mspapi2/
  │       ├── msp_api.py
  │       ├── mspcodec.py
  │       └── lib/
  │           ├── msp_messages.json
  │           ├── inav_enums.json
  │           └── inav_defines.py
  └── tests/

  Build it independently:

  python -m build pythonlib/

  That produces its own wheel and source distribution. Modern Python
  source distributions are rooted around their own pyproject.toml; the
  monorepo root does not need to be a Python package. Python Packaging
  User Guide (https://packaging.python.org/en/latest/flow/)

  A src/ layout also prevents tests from accidentally importing the
  checkout instead of the installed package. Python packaging layout
  guidance
  (https://packaging.python.org/en/latest/discussions/src-layout-vs-flat-layout/)

  ### Root orchestration

  The root script should be boring:

  build_all.sh generate
  build_all.sh test
  build_all.sh package
  build_all.sh release

  Conceptually:

  generate
    ├── refresh include/
    ├── publish headers into clib/
    ├── publish headers into arduinolib/src/generated/
    └── publish Python data into pythonlib/src/mspapi2/lib/

  test
    ├── generator tests
    ├── C tests
    ├── Arduino/PlatformIO tests
    └── Python tests

  package
    ├── dist/msp-sdk-c-0.2.0.tar.gz
    ├── dist/msp-sdk-arduino-0.2.0.zip
    ├── dist/mspapi2-0.2.0.tar.gz
    └── dist/mspapi2-0.2.0-py3-none-any.whl

  Each package must also build independently from its staged directory.
  That proves it isn’t secretly reaching sideways into the monorepo.

  ### Versioning

  For this project, I would initially release everything in lockstep:

  SDK release:       0.2.0
  INAV snapshot:     9.1.0
  MSP schema:        2.1.0
  Git tag:           v0.2.0

  Keep those as distinct values. The SDK version describes your
  libraries; the INAV version describes the protocol snapshot they were
  generated against.

  If the libraries eventually evolve at different rates, switch to
  package-specific tags:

  python-v0.5.0
  arduino-v0.3.0
  c-v0.2.0

  But lockstep is simpler while all three are being established around
  the same generated protocol.

  ### The deepest shared component

  The most valuable shared resource is not necessarily compiled C code.
  It is:

  - The canonical message schema.
  - Generated types and constants.
  - Golden encoded payloads.
  - Expected decoded values.
  - API behavior tests.

  The C, Arduino, and Python implementations can then run the same
  protocol vectors. That catches the dangerous failures: different field
  widths, signedness, array lengths, enum storage, endianness, and
  version drift.

  So the core principle is:

  > Share protocol truth and conformance tests; package runtimes
  > independently.

  That gives you one coherent MSP SDK without forcing Python, Arduino, C,
  and future languages into an unnatural single build or distribution
  format.