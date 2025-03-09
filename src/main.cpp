#include <Arduino.h>

// just set the include file here to the file that you would like
// their setup() and loop() has been renamed to Setup() and Loop()
// that way you can quickly change this #include to the code you would like to load
#include "HB100-analog-doppler.hpp"
// also ensure you change the monitor_speed in platformio.ini if necessary

// "do not touch these"

void setup() {
  Setup();
}

void loop() {
  Loop();
}

// some nice QOL:
// python -m esptool --chip esp32 erase_flash
