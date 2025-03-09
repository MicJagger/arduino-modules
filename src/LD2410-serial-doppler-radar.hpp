// LD2410 / LD2410C - doppler radar with more advanced serial data
// Used with https://www.amazon.com/EC-Buying-HLK-LD2410-Presence-Millimeter/dp/B0BXDLHHH2/ref=pd_ci_mcx_mh_mcx_views_0_title

// yes using F() on ESP-32 is controversial apparently but who cares

#include <Arduino.h>

#include <ld2410.h>

#define pin_RADAR_Tx 19
#define pin_RADAR_Rx 18

#define SERIAL_RADAR Serial1

ld2410 radar;
uint32_t lastRead = 0;
// time in ms for each loop
uint32_t loopTime = 50;

inline int CheckStationaryTarget();
inline int CheckMovingTarget();


//

void Setup() {
  Serial.begin(115200);
  Serial.println("Setup Sequence Initialized");

  //radar.debug(Serial); // Show radar debug on monitor
  SERIAL_RADAR.begin(256000, SERIAL_8N1, pin_RADAR_Tx, pin_RADAR_Rx);
  Serial.print(F("Tx to Radar's Rx is "));
  Serial.println(pin_RADAR_Rx);
  Serial.print(F("Rx to Radar's Tx is "));
  Serial.println(pin_RADAR_Tx);
  delay(100);

  Serial.println(F("Initializing LD2410"));
  if (radar.begin(SERIAL_RADAR)) {
    Serial.print(F("Firmware version: "));
    Serial.print(radar.firmware_major_version);
    Serial.print('.'); // do not use F() on character
    Serial.print(radar.firmware_minor_version);
    Serial.print('.');
    Serial.println(radar.firmware_bugfix_version, HEX);
  }
  else {
    Serial.println(F("Failed to initialize radar, halting"));
    while (true) {

    }
  }

  Serial.println(F("Changing Sensitivity Settings"));
  radar.setMaxValues(8, 8, loopTime);
  radar.setGateSensitivityThreshold(1, 100, 100);

  Serial.println(F("Settings Applied, Restarting Radar"));
  radar.requestRestart();

  Serial.println(F("Setup Sequence Complete"));
}


void Loop() {
  radar.read();
  if (millis() - lastRead > loopTime) {
    CheckStationaryTarget();
    Serial.print(F(" ||| "));
    CheckMovingTarget();
    Serial.println();
    lastRead = millis();
  }
}


// 

inline int CheckStationaryTarget() {
  if (radar.stationaryTargetDetected()) {
    Serial.print(F("Still target: "));
    Serial.print(radar.stationaryTargetDistance());
    Serial.print(F("cm | energy: "));
    Serial.print(radar.stationaryTargetEnergy());
    return true;
  }
  Serial.print(F("No stationary target"));
  return false;
}

inline int CheckMovingTarget() {
  if (radar.movingTargetDetected()) {
    Serial.print(F("Moving target: "));
    Serial.print(radar.movingTargetDistance());
    Serial.print(F("cm | energy:"));
    Serial.print(radar.movingTargetEnergy());
    return true;
  }
  Serial.print(F("No moving target"));
  return false;
}
