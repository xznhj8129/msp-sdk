/*
  MSP.h - Arduino library for MSP V2 protocol (focused on INAV)

  Based on original work by Fabrizio Di Vittorio (fdivitto2013@gmail.com)
  Extended and refactored for wider INAV MSP support.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#pragma once

#include <Arduino.h>
#include <Stream.h>
#include "generated/msp_messages.h"
#include "generated/msp_protocol.h"
#include "generated/msp_protocol_v2_common.h"
#include "generated/msp_protocol_v2_inav.h"
#include "generated/msp_protocol_v2_sensor.h"
#include "generated/msp_protocol_v2_sensor_msg.h"

class MSPIntf {
  public:
    // --- Constructor & Basic Setup ---
    MSPIntf();
    void begin(Stream &stream, uint32_t timeout = 500);
    void reset(); // Clears serial buffer

    // --- Low Level MSP Communication ---
    void send(uint16_t messageID, const void *payload = nullptr, uint16_t size = 0);
    bool recv(uint16_t *messageID, void *payload, uint16_t maxSize, uint16_t *recvSize = nullptr);
    bool waitFor(uint16_t messageID, void *payload, uint16_t maxSize, uint16_t *recvSize = nullptr);
    bool request(uint16_t messageID, void *payload, uint16_t maxSize, uint16_t *recvSize = nullptr);
    bool command(uint16_t messageID, const void *payload = nullptr, uint16_t size = 0, bool waitACK = true);

    // --- High Level Functions ---

    // Version & Board Info
    bool requestApiVersion(MSP_API_VERSION_reply_t *reply);
    bool requestFcVariant(MSP_FC_VARIANT_reply_t *reply);
    bool requestFcVersion(MSP_FC_VERSION_reply_t *reply);
    bool requestBoardInfo(MSP_BOARD_INFO_reply_t *reply, char *targetNameBuf = nullptr, uint8_t targetNameBufLen = 0); // Handles variable length name
    bool requestBuildInfo(MSP_BUILD_INFO_reply_t *reply);
    bool requestUID(MSP_UID_reply_t *reply);
    bool requestCraftName(MSP_NAME_reply_t *reply);
    bool setCraftName(const char *name);

    // Status
    bool requestStatus(MSP_STATUS_reply_t *reply); // Legacy status
    bool requestStatusEx(MSP_STATUS_EX_reply_t *reply); // Extended V1 status
    bool requestInavStatus(MSP2_INAV_STATUS_reply_t *reply); // Recommended modern status
    bool isArmed(); // Checks armed status based on last requestInavStatus

    // Sensor Data
    bool requestRawIMU(MSP_RAW_IMU_reply_t *reply);
    bool requestAttitude(MSP_ATTITUDE_reply_t *reply);
    bool requestAltitude(MSP_ALTITUDE_reply_t *reply);
    bool requestSonarAltitude(MSP_SONAR_ALTITUDE_reply_t *reply); // Rangefinder
    bool requestAirspeed(MSP2_INAV_AIR_SPEED_reply_t *reply); // Pitot/Estimated

    // GPS & Navigation
    bool requestRawGPS(MSP_RAW_GPS_reply_t *reply);
    bool requestCompGPS(MSP_COMP_GPS_reply_t *reply); // Distance/Direction to home
    bool requestNavStatus(MSP_NAV_STATUS_reply_t *reply);
    bool setHeading(int16_t headingDeg); // Sets MAGHOLD target

    // Waypoints & Missions
    bool requestWaypointInfo(MSP_WP_GETINFO_reply_t *reply);
    bool requestWaypoint(uint8_t index, MSP_WP_reply_t *reply);
    bool setWaypoint(const MSP_SET_WP_request_t *wp);
    bool commandMissionLoad(uint8_t missionId = 0);
    bool commandMissionSave(uint8_t missionId = 0);

    // Modes
    bool requestBoxIDs(uint8_t *boxIds, uint16_t maxIds, uint16_t *count); // Get permanent IDs
    // getActiveModes is complex due to bitmask size, better handled in sketch using requestInavStatus
    bool requestModeRanges(MSP_MODE_RANGES_reply_t *ranges, uint16_t maxRanges, uint16_t *count); // Get mode activation ranges

    // RC & Motors
    bool requestRcChannels(MSP_RC_reply_t *reply, uint8_t expectedChannels); // Specify max channels expected
    bool commandRawRC(const int16_t *channels, uint8_t channelCount);
    bool requestMotorOutputs(MSP_MOTOR_reply_t *reply);
    bool commandMotorOutputs(const uint16_t *motorValues); // For motor testing

    // Configuration
    // We will *not* implement configuration messages
    bool requestNavPosholdConfig(MSP_NAV_POSHOLD_reply_t *reply);
    //bool setNavPosholdConfig(const MSP_NAV_POSHOLD_reply_t *config);
    bool requestVoltageMeterConfig(MSP_VOLTAGE_METER_CONFIG_reply_t *reply); // Legacy
    //bool setVoltageMeterConfig(const MSP_VOLTAGE_METER_CONFIG_reply_t *config); // Legacy
    bool requestBatteryConfig(MSP2_INAV_BATTERY_CONFIG_reply_t *reply); // Modern
    //bool setBatteryConfig(const msp2_inav_battery_config_t *config); // Modern
    bool requestSensorConfig(MSP_SENSOR_CONFIG_reply_t *reply);
    //bool setSensorConfig(const MSP_SENSOR_CONFIG_reply_t *config);

    // Battery & Power
    bool requestBatteryState(MSP_BATTERY_STATE_reply_t *reply);
    bool requestAnalog(MSP2_INAV_ANALOG_reply_t *reply); // Modern analog data

    // Calibration
    /*bool commandAccCalibration();
    bool commandMagCalibration();
    bool commandResetConfig(); // Reset to defaults
    bool commandEepromWrite(); // Save current config*/
    // Hell no

    // Programming Framework (Example)
    bool requestGvarStatus(MSP2_INAV_GVAR_STATUS_reply_t *reply);
    bool requestLogicConditionsStatus(MSP2_INAV_LOGIC_CONDITIONS_STATUS_reply_t *reply);


  private:
    Stream *_stream = nullptr;
    uint32_t _timeout = 500;
    uint32_t _last_status_arming_flags = 0; // Cache for isArmed()

    static uint8_t crc8_dvb_s2(uint8_t crc, unsigned char a);
};
