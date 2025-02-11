// HC-SR04 Ultrasonic Sensor - simple ultrasound range finder

#include <Arduino.h>

// just set the include file here to the file that you would like
// their setup() and loop() has been renamed to Setup() and Loop()
// that way you can quickly change this #include to the code you would like to load
#include "HCSR04-ultrasound.hpp"

// "do not touch these"

void setup() {
  Serial.begin(115200);
  Setup();
}

void loop() {
  Loop();
}
