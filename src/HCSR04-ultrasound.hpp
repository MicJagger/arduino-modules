// HC-SR04 Ultrasonic Sensor - simple ultrasound range finder

#include <Arduino.h>

#define pin_TRIGGER 18
#define pin_ECHO 19


//

void Setup() {
  Serial.println("Setup sequence initialized");

  pinMode(pin_TRIGGER, OUTPUT);
  pinMode(pin_ECHO, INPUT);

  Serial.println("Booted and Setup Successfully");
}

void Loop() {
  // trigger the pin
  digitalWrite(pin_TRIGGER, LOW);
	delayMicroseconds(2);
	digitalWrite(pin_TRIGGER, HIGH);
	delayMicroseconds(10);
	digitalWrite(pin_TRIGGER, LOW);

  // wait for response
  float duration = pulseIn(pin_ECHO, HIGH);

  // distance = time * speed of sound
  float distance = (duration * 0.343) / 2;
  // pulseIn returns microseconds, so multiply by .343 to get millimeters

  // output
  Serial.print("Distance: ");
	Serial.println(distance);
	delay(50);
}


//


