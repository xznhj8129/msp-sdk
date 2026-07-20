# Generator map

The supported C/C++ pipeline is `gen_all.sh`. Its direct dependencies are:

* `get_inav_defines.py`
* `bad_define_parse.py`
* `gen_all_enums.py`
* `gen_msp_header.py`
* `test.c`
* `test.cpp`
* `test_generators.py`

The pipeline reads canonical MSP JSON and protocol headers from the selected
INAV checkout, refreshes the public `../include/` tree, writes define outputs
to this directory, and writes binaries and diagnostics to
`../build/generator/`.

Historical experiments are quarantined under `../.old/`, preserving their
former relative paths. Nothing in `.old/` is a build input.

The Proto and YAML generators remain here for their downstream consumers even
though `gen_all.sh` does not currently invoke them.

Do not copy generated JSON, enum headers, message headers, or type headers into
this directory. Their public location is `../include/`.
