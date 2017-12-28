#!/bin/bash

clear

git pull -v --progress  "origin"

export CROSS_COMPILE=arm-linux-gnueabihf-
export ARCH=arm

make clean
make distclean
make mx6q_uavx_37i00_defconfig
make

