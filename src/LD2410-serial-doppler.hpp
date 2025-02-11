// LD2410 / LD2410C - doppler radar with more advanced serial data
// Used with https://www.amazon.com/EC-Buying-HLK-LD2410-Presence-Millimeter/dp/B0BXDLHHH2/ref=pd_ci_mcx_mh_mcx_views_0_title

// WIP

#include <Arduino.h>

#define pin_Tx 32
#define pin_Rx 33

float Velocity();


//

void Setup() {
  Serial.begin(256000);
  Serial.println("Setup sequence initialized");

  Serial.println("Booted and Setup Successfully");
}

void Loop() {
  //Serial.println(digitalRead(pin_DATA));
  delay(1);
}


//

float Velocity() {
  return false;
}
