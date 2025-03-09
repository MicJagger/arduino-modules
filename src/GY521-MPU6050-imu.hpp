// GY-521 / MPU-6050 - IMU / Accelerometer & Gyroscope
// Used with https://www.amazon.com/EC-Buying-Accelerometer-Gyroscope-Module16-Bit/dp/B0B3D6D1KD/ref=pd_ci_mcx_mh_mcx_views_0_title

#include <Arduino.h>
#include "Wire.h"

#define MPU_ADDRESS 0x68 // I2C address for MPU-6050 - If AD0 == HIGH then I2C address == 0x69

// options

// either 1, 2, 4, or 8
// represents +-2g, +-4g, +-8g, +-16g
float scaleAccelerationValue = 2;

// either 1, 2, 4, or 8
// represents +=250d/s, +-500d/s, +-1000d/s, +-2000d/s
float scaleGyroscopeValue = 4;

// raw values

int16_t accelerometerX;
int16_t accelerometerY;
int16_t accelerometerZ;
int16_t gyroscopeX;
int16_t gyroscopeY;
int16_t gyroscopeZ;
int16_t temperature;

// processed values

float aX;
float aY;
float aZ;
float gX;
float gY;
float gZ;
float temp;

inline float RawAccelerationToGs(int16_t acceleration) {
  return (float)acceleration * scaleAccelerationValue / (float)16384;
}

inline float RawGyroscopeToDegrees(int16_t gyro) {
  return (float)gyro * scaleGyroscopeValue / (float)131;
}

void Scale(float scaleValue);

void RecordVariables();

void ConvertAccelerations();
void ConvertGyroscopes();
void ConvertTemperature();

void PrintAcceleration();
void PrintGyroscope();


//

void Setup() {
  Serial.begin(115200);
  Serial.println("Setup Sequence Initialized");

  // Enable device
  Wire.begin();
  Wire.beginTransmission(MPU_ADDRESS);
  Wire.write(MPU_ADDRESS);
  Wire.write(0x00);
  Wire.endTransmission();

  // Configure Accelerometers
  Wire.beginTransmission(MPU_ADDRESS);
  Wire.write(0x1C);
  Scale(scaleAccelerationValue);
  Wire.endTransmission();

  // Configure Gyroscope
  Wire.beginTransmission(MPU_ADDRESS);
  Wire.write(0x1B);
  Scale(scaleGyroscopeValue);
  Wire.endTransmission();

  Serial.println("Booted and Setup Successfully");
}

void Loop() {
  RecordVariables();

  ConvertAccelerations();
  ConvertGyroscopes();
  ConvertTemperature();

  PrintAcceleration();
  Serial.print(" ||| ");
  PrintGyroscope();
  Serial.print(" ||| Temp: ");
  Serial.print(String(temp, 5));
  Serial.println();
  
  delay(100);
}


//

void Scale(float scaleValue) {
  if (scaleValue == 1) {
    Wire.write(0x00);
  }
  else if (scaleValue == 2) {
    Wire.write(0x08);
  }
  else if (scaleValue == 4) {
    Wire.write(0x10);
  }
  else if (scaleValue == 8) {
    Wire.write(0x18);
  }
  else {
    Serial.println("IMPROPER SCALE VALUE, HALTING");
    while (true) {
        
    }
  }
}

void RecordVariables() {
  Wire.beginTransmission(MPU_ADDRESS);
  Wire.write(0x3B);
  Wire.endTransmission();

  Wire.requestFrom(MPU_ADDRESS, 14);

  accelerometerX = Wire.read() << 8 | Wire.read();
  accelerometerY = Wire.read() << 8 | Wire.read();
  accelerometerZ = Wire.read() << 8 | Wire.read();

  temperature = Wire.read() << 8 | Wire.read();

  gyroscopeX = Wire.read() << 8 | Wire.read();
  gyroscopeY = Wire.read() << 8 | Wire.read();
  gyroscopeZ = Wire.read() << 8 | Wire.read();

  Wire.endTransmission();
}

void ConvertAccelerations() {
  aX = RawAccelerationToGs(accelerometerX);
  aY = RawAccelerationToGs(accelerometerY);
  aZ = RawAccelerationToGs(accelerometerZ);
}

void ConvertGyroscopes() {
  gX = RawGyroscopeToDegrees(gyroscopeX);
  gY = RawGyroscopeToDegrees(gyroscopeY);
  gZ = RawGyroscopeToDegrees(gyroscopeZ);
}

void ConvertTemperature() {
  temp = (float)temperature / 340.00 + 36.53;
}

void PrintAcceleration() {
  Serial.print("aX: ");
  Serial.print(String(aX, 5));
  Serial.print(" | aY: ");
  Serial.print(String(aY, 5));
  Serial.print(" | aZ: ");
  Serial.print(String(aZ, 5));
}

void PrintGyroscope() {
  Serial.print("gX: ");
  Serial.print(String(gX, 5));
  Serial.print(" | gY: ");
  Serial.print(String(gY, 5));
  Serial.print(" | gZ: ");
  Serial.print(String(gZ, 5));
}
