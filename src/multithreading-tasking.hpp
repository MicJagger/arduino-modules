#include <Arduino.h>

TaskHandle_t task0;
TaskHandle_t task1;

void Task0(void* parameter);
void Task1(void* parameter);


// 

void Setup() {
  Serial.begin(115200);
  Serial.println("Setup Sequence Initialized");

  // creates a task that is pinned to a chosen core, and runs independently
  xTaskCreatePinnedToCore(
    Task0,      // function name
    "Task0",    // name
    10000,      // stack size
    NULL,       // parameter(s)
    1,          // priority
    &task0,     // handle
    0);         // core to pin to
  
  delay(100);

  // technically not necessary with normal loop() code running on core 1
  xTaskCreatePinnedToCore(Task1, "Task1", 10000, NULL, 1, &task1, 1);
  delay(100);

  Serial.println("Booted and Setup Successfully");
}

void Loop() {
  
}


// 

void Task0(void* parameter) {
  while (true) {
    Serial.print("Task0 - core ");
    Serial.println(xPortGetCoreID());
    delay(1000);
  }
}

void Task1(void* parameter) {
  while (true) {
    Serial.print("Task1 - core ");
    Serial.println(xPortGetCoreID());
    delay(1050);
  }
}
