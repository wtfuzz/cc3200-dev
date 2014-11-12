#!/bin/sh

# Install cross compilers
sudo apt-get install gcc-arm-none-eabi binutils-arm-none-eabi libnewlib-arm-none-eabi libnewlib-dev libnewlib-doc

# NOTE: This will overwrite the gdb manpages. https://bugs.launchpad.net/ubuntu/+source/gdb-arm-none-eabi/+bug/1267680
sudo apt-get -o Dpkg::Options::="--force-overwrite" install gdb-arm-none-eabi

# Install openocd
sudo apt-get install openocd
