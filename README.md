# Nim ESP32 - Hello Network

Example repo for using Nim with ESP32 on FreeRTOS & LwIP. 

# Building

Install the `github.com/elcritch/devel-basic-freertos-network` Nim branch from my fork of Nim. Then goto the `nim/` folder and do a `make`. This will generate Nim C output files using a local Makefile (not part of the ESP-IDF build system). 

Afterwords, do a `make menuconfig` in the main folder. You don't need to run a `make menuconfig` everytime after updating Nim, but only when Nim outputs a new Nim C file (e.g. you pull in a new Nim library, etc). This could be cleaned up in the future I'm sure. 

Once the generated Nim sources are registered with ESP-IDF's build system, then all you need to do is the standard `idf.py build` and upload steps. 

# Info

Here's the Nim Forum thread: https://forum.nim-lang.org/t/6345

The primary branch I'm using is here: https://github.com/elcritch/Nim/tree/devel-basic-freertos-network

There's a PR for Nim, but not sure how long before FreeRTOS will be in a standard devel build.  

To use it, checkout the `devel-basic-freertos-network` branch, then rebuild and install Nim using the standard `build_all.sh` script. I use ASDF so it's pretty easy to add another remote repo. Beware, only ARC works as the other GC's need another memory backend. It's easy to add, but I removed it until the main FreeRTOS options are added in upstream. 

