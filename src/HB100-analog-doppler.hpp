// HB100 - doppler radar with analog output
// Used with https://www.amazon.com/PAMEENCOS-HB100-Microwave-Wireless-10-525GHz/dp/B0CNQYM2F1/ref=pd_ci_mcx_mh_mcx_views_1_title

// WIP

#include <Arduino.h>

#define pin_ANALOG

float Velocity();


//

void Setup() {
  Serial.begin(115200);
  Serial.println("Setup sequence initialized");

  //pinMode(pin_ANALOG, INPUT);

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
