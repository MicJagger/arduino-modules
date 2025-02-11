// LD2410C - doppler radar with more advanced serial data
// Used with https://www.amazon.com/EC-Buying-HLK-LD2410-Presence-Millimeter/dp/B0BXDLHHH2/ref=pd_ci_mcx_mh_mcx_views_0_title

// WIP

#include <Arduino.h>

#define pin_Tx 32
#define pin_Rx 33

bool Detected();


//

void Setup() {
  Serial.println("Setup sequence initialized");

  //pinMode(pin_DATA, INPUT);

  Serial.println("Booted and Setup Successfully");
}

void Loop() {
  //Serial.println(digitalRead(pin_DATA));
  delay(1);
}


//

bool Detected() {
  return false;
}
