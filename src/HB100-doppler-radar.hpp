// HB100 - doppler radar
// Used with https://www.amazon.com/PAMEENCOS-HB100-Microwave-Wireless-10-525GHz/dp/B0CNQYM2F1/ref=pd_ci_mcx_mh_mcx_views_1_title

// has not yet been tested with the radar itself, only with a 2.5V waveform generator from 10hz to 5000hz

#include <Arduino.h>

#define pin_INPUT 23

// number of full wavelengths to be averaged - higher values for higher frequencies and higher accuracy
#define SAMPLE_SIZE 1
// for checking that the highest frequency in a sample is within this times as high as the lowest frequency
// ensures a 10,000 hz doesn't get averaged with a 10 hz value to return 5,005 hz
#define CONSISTENCY_MULTIPLIER 3.0

double Frequency();
inline double Velocity(double frequency, double receiverSpeed);
// the esp32 technically doesn't have hardware support for doubles but I do not care

// quick estimate for velocity that is accurate well within 0.1% when within bounds of [1, 10,000] hertz, and no receiver speed
inline double QuickVelocity(double frequency);

// uses pulseIn() function, makes it slow at low frequencies (eg @ 10hz with SAMPLE_SIZE = 2, ~600ms / output when it should be ~200ms)
double Frequency_pulseIn();


//

void Setup() {
  Serial.begin(115200);
  Serial.println("Setup Sequence Initialized");

  pinMode(pin_INPUT, INPUT);

  Serial.println("Booted and Setup Successfully");
}

void Loop() {
  double frequency = Frequency();
  double velocity = Velocity(frequency, 0); // or QuickVelocity(frequency);
  Serial.println(velocity);
}


//

unsigned long startTime = micros();

// uses while loops instead of pulseIn(), far faster at low frequencies
double Frequency() {
  unsigned long durations[SAMPLE_SIZE];
  for (int i = 0; i < SAMPLE_SIZE; i++) {
    while (digitalRead(pin_INPUT) == LOW) {

    }
    while (digitalRead(pin_INPUT) == HIGH) {

    }
    durations[i] = micros() - startTime;
    startTime = micros();
  }

  double frequency = 0;
  
  if (SAMPLE_SIZE > 1) {
    // check consistency
    unsigned long maxDuration = 0;
    unsigned long minDuration = 1000000;
    for (int i = 0; i < SAMPLE_SIZE; i++) {
      if (durations[i] > maxDuration) {
        maxDuration = durations[i];
      }
      if (durations[i] < minDuration) {
        minDuration = durations[i];
      }
    }
    if (maxDuration > (minDuration * CONSISTENCY_MULTIPLIER)) {
      return 0;
    }

    // average results
    for (int i = 0; i < SAMPLE_SIZE; i++) {
      frequency += durations[i];
    }
  }
  else {
    frequency = durations[0];
  }

  frequency = SAMPLE_SIZE * 1000000 / frequency;
  return frequency;
}

inline double Velocity(double frequency, double receiverSpeed) {
  return (10525000000.0 * (299702547.0 + receiverSpeed)) / (10525000000.0 - frequency) - 299702547.0;
}

// at low frequencies (1 hz - 10+ khz), approximately linear
inline double QuickVelocity(double frequency) {
  return frequency * 0.0284753;
}


// pulseIn version (could be useful)

double Frequency_pulseIn() {
  double durations[SAMPLE_SIZE];
  for (int i = 0; i < SAMPLE_SIZE; i++) {
    durations[i] = 0;
    durations[i] += pulseIn(pin_INPUT, HIGH);
    durations[i] += pulseIn(pin_INPUT, LOW);
  }

  double frequency = 0;
  
  if (SAMPLE_SIZE > 1) {
    // check consistency
    double maxDuration = 0;
    double minDuration = 1000000;
    for (int i = 0; i < SAMPLE_SIZE; i++) {
      if (durations[i] > maxDuration) {
        maxDuration = durations[i];
      }
      if (durations[i] < minDuration) {
        minDuration = durations[i];
      }
    }
    #define CONSISTENCY_MULTIPLIER 3.0
    if (maxDuration > (minDuration * CONSISTENCY_MULTIPLIER)) {
      return 0;
    }

    // average results
    for (int i = 0; i < SAMPLE_SIZE; i++) {
      frequency += durations[i];
    }
  }
  else {
    frequency = durations[0];
  }

  frequency = SAMPLE_SIZE * 1000000 / frequency;
  return frequency;
}
