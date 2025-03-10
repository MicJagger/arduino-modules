# esp32-modules
ESP32 code for interacting with various modules \
Most if not all of this should work on an Arduino as well \
This is not meant to be anywhere near complete, but rather an educational repo for a reference on how to use many common modules, as well as features such as tasking for multithreading

## Install and Run
1. ``git clone --recurse-submodules {URL}`` in a directory of your choosing
2. Decide on a specific module of feature to use / test
3. Go into main.cpp, and fill in ``#include "___.hpp"`` with the file name of your choice
4. Save main.cpp and flash to ESP32 (or other microcontroller)

## Other
This is set up so that main.cpp runs Setup() and Loop(), with the .hpp files being refactored to essentially be their own main.cpp but with the refactored function names \
This way the code is modular to load one file of code at a time and change it quickly for recompilation and testing \
This repository also contains submodules, such as the ld2410 library that I do not take credit for \

This will not build unless you change the ``#include`` in main.cpp. \
Of course, you are free to use the code in another project, bypassing the need to use it in this way.
