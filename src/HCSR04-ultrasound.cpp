// Simple Ultrasound Range Finder for HC-SR04 Ultrasonic Sensor

#include <Arduino.h>

const int pin_TRIGGER = 32;
const int pin_ECHO = 33;


//

void setup() {
  Serial.begin(115200);
  Serial.println("Setup sequence initialized");

  pinMode(pin_TRIGGER, OUTPUT);
  pinMode(pin_ECHO, INPUT);

  Serial.println("Booted and Setup Successfully");
}

void loop() {
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


