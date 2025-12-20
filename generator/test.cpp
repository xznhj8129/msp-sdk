// Minimal demo: pack/unpack a couple of MSP messages and show layout/bytes.
#include "msp_types.h"
#include "msp_messages.h"

#include <cstdio>
#include <cstring>

struct NonPackedExample {
    uint8_t a;
    uint16_t b;
};

static void dump_bytes(const char *label, const uint8_t *data, size_t len) {
    std::printf("%s (len=%zu):", label, len);
    for (size_t i = 0; i < len; i++) {
        std::printf(" %02X", data[i]);
    }
    std::printf("\n");
}

int main() {
    // Example 1: packed MSP_FC_VERSION_reply_t (no padding)
    MSP_FC_VERSION_reply_t ver{};
    ver.fcVersionMajor = 6;
    ver.fcVersionMinor = 2;
    ver.fcVersionPatch = 1;

    uint8_t buf_ver[sizeof(ver)];
    std::memcpy(buf_ver, &ver, sizeof(ver));
    dump_bytes("MSP_FC_VERSION packed bytes", buf_ver, sizeof(ver));
    std::printf("sizeof(MSP_FC_VERSION_reply_t)=%zu\n", sizeof(ver));

    MSP_FC_VERSION_reply_t ver_unpacked{};
    std::memcpy(&ver_unpacked, buf_ver, sizeof(ver_unpacked));
    std::printf("unpacked version: %u.%u.%u\n",
                ver_unpacked.fcVersionMajor,
                ver_unpacked.fcVersionMinor,
                ver_unpacked.fcVersionPatch);

    // Example 2: packed MSP_FC_VARIANT_reply_t
    MSP_FC_VARIANT_reply_t variant{};
    std::memcpy(variant.fcVariantIdentifier, "INAV", 4);
    uint8_t buf_variant[sizeof(variant)];
    std::memcpy(buf_variant, &variant, sizeof(variant));
    dump_bytes("MSP_FC_VARIANT packed bytes", buf_variant, sizeof(variant));
    std::printf("fcVariantIdentifier=\"%c%c%c%c\"\n",
                variant.fcVariantIdentifier[0],
                variant.fcVariantIdentifier[1],
                variant.fcVariantIdentifier[2],
                variant.fcVariantIdentifier[3]);

    // Example 3: contrast packed vs non-packed padding
    NonPackedExample np{};
    np.a = 0x11;
    np.b = 0x2233;
    std::printf("sizeof(NonPackedExample)=%zu (shows padding); sizeof(packed MSP_FC_VERSION)=%zu\n",
                sizeof(np), sizeof(ver));

    uint8_t buf_np[sizeof(np)];
    std::memcpy(buf_np, &np, sizeof(np));
    dump_bytes("NonPackedExample bytes (note padding)", buf_np, sizeof(np));

    return 0;
}
