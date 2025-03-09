# esp32-modules
ESP32 code for interacting with various modules \
Most if not all of this should work on an Arduino as well \
This is not meant to be anywhere near complete, but rather an educational repo for a reference on how to use many common modules, or features like tasking for multithreading

## Important
Ensure that you fill in the #include "___.hpp" in main.cpp to the code that you would like to run \
Since these devices are limiting, this is set up so that main.cpp runs Setup() and Loop(), with the .hpp files being refactored as such \
This way the code is modular to load one file of code at a time and change it quickly for recompilation and testing \
There are also some submodules, such as the ld2410 library that I do not take credit for
