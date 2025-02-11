# esp32-modules
ESP-32 code for interacting with various modules \

## Important
Ensure that you fill in the #include "___.hpp" in main.cpp to the code that you would like to run \
Since these devices are limiting, this is set up so that main.cpp runs Setup() and Loop(), with the .hpp files being refactored as such \
This way the code is modular to load one file of code at a time and change it quickly for recompilation and testing