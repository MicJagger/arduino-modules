// simple vibration motor
// For https://www.amazon.com/dp/B07Q1ZV4MJ

#include <Arduino.h>

#define pin_ANALOG 25

void UpAndDown();

void Setup() {
  Serial.begin(115200);
  Serial.println("Setup Sequence Initialized");
  
  pinMode(pin_ANALOG, OUTPUT);

  Serial.println("Booted and Setup Successfully");
}

void Loop() {
  UpAndDown();
}

void UpAndDown() {
  // strength increase
  for (int i = 0; i < 256; i++) {
    analogWrite(pin_ANALOG, i);
    delayMicroseconds(1000000 / 256);
  }
  // strength decrease
  for (int i = 255; i >= 0; i--) {
    analogWrite(pin_ANALOG, i);
    delayMicroseconds(1000000 / 256);
  }
}
