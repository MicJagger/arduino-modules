// doppler radar that outputs simply binary for movement detection
// For https://www.amazon.com/CQRobot-10-525GHz-Microwave-Compatible-Measurement/dp/B089NKGWQQ/ref=pd_ci_mcx_mh_mcx_views_17_title

#include <Arduino.h>

#define pin_DATA 15

int counter = 0;
// should roughly translate to milliseconds that movement must be detected for
int sensitivityLevel = 4;

bool Detected();


//

void Setup() {
  Serial.begin(115200);
  Serial.println("Setup Sequence Initialized");

  pinMode(pin_DATA, INPUT);

  Serial.println("Booted and Setup Successfully");
}

void Loop() {
  Serial.println(Detected());
  delay(1);
}


//

// returns true if the past sensitivityLevel ticks have all detected movement
bool Detected() {
  if (digitalRead(pin_DATA) == 0) {
    counter = 0;
    return false;
  }
  counter++;
  if (counter >= sensitivityLevel) {
    counter = sensitivityLevel;
    return true;
  }
  return false;
}
