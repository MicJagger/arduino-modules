// Simple Binary Version
// For LD2410C
// "Tested" on https://www.amazon.com/EC-Buying-HLK-LD2410-Presence-Millimeter/dp/B0BXDLHHH2/ref=pd_ci_mcx_mh_mcx_views_0_title

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
