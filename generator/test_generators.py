#!/usr/bin/env python3
"""
Usage:
    python -m unittest test_generators.py
"""

import tempfile
import unittest
from pathlib import Path

from bad_define_parse import collect_typedefs, resolve_defines
from gen_msp_header import field_decl


class GeneratorTests(unittest.TestCase):
    def test_enum_annotation_keeps_wire_integer_type(self):
        declaration = field_decl(
            {
                "name": "mode",
                "ctype": "uint8_t",
                "enum": "exampleMode_e",
            }
        )
        self.assertEqual(declaration, "    uint8_t mode;  // Enum: exampleMode_e")

    def test_typedef_cast_resolves_from_annotated_source(self):
        with tempfile.TemporaryDirectory() as directory:
            source_root = Path(directory)
            (source_root / "sensor.h").write_text("typedef int8_t VL53L1X_ERROR;\n")
            typedefs = collect_typedefs("// sensor.h\n", source_root)
            values, reasons = resolve_defines(
                {"VL53L1_WARNING_ZONE_CAL_MISSING_SAMPLES": "((VL53L1X_ERROR) - 35)"},
                typedefs,
                {},
            )
        self.assertEqual(values["VL53L1_WARNING_ZONE_CAL_MISSING_SAMPLES"], -35)
        self.assertNotIn("VL53L1_WARNING_ZONE_CAL_MISSING_SAMPLES", reasons)


if __name__ == "__main__":
    unittest.main()
