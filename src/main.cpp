#include <Arduino.h>

const int pin_DATA = 15;

void setup() {
  Serial.println("Setup sequence initialized");
  Serial.begin(115200);

  pinMode(pin_DATA, INPUT);

  Serial.println("Booted and Setup Successfully");
}

void loop() {
  Serial.println(digitalRead(pin_DATA));
  delay(50);
}
