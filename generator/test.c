// C compilation test for the public MSP headers.
#include <msp_messages.h>

_Static_assert(sizeof(escSensorData_t) == 16, "escSensorData_t wire layout changed");
_Static_assert(sizeof(dronecanNodeStatus_t) == 7, "dronecanNodeStatus_t wire layout changed");
_Static_assert(sizeof(MSP_NAV_POSHOLD_reply_t) == 13, "enum metadata changed the MSP wire layout");
_Static_assert(sizeof(MSP2_INAV_ESC_TELEM_reply_t) == 17, "variable ESC placeholder layout changed");
_Static_assert(sizeof(MSP2_INAV_DRONECAN_NODES_reply_t) == 8, "variable DroneCAN placeholder layout changed");

int main(void)
{
    MSP_FC_VERSION_reply_t version = { 9, 1, 0 };
    return version.fcVersionMajor == 9 ? 0 : 1;
}
