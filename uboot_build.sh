#!/bin/bash

clear

git pull -v --progress  "origin"

export CROSS_COMPILE=arm-linux-gnueabihf-
export ARCH=arm

make


