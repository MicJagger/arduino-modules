// Analog Doppler-Radar Detector for HB100
// "Tested" on https://www.amazon.com/PAMEENCOS-HB100-Microwave-Wireless-10-525GHz/dp/B0CNQYM2F1/ref=pd_ci_mcx_mh_mcx_views_1_title

#include <Arduino.h>

//const int pin_DATA = 15;

bool Detected();


//

void setup() {
  Serial.begin(115200);
  Serial.println("Setup sequence initialized");

  //pinMode(pin_DATA, INPUT);

  Serial.println("Booted and Setup Successfully");
}

void loop() {
  //Serial.println(digitalRead(pin_DATA));
  delay(1);
}


//

bool Detected() {
  return false;
}
