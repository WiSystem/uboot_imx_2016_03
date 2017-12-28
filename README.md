# About
This is a source code of uBoot for UAVX board.

# Download source code
    git clone https://github.com/Radoslaw-Przybysz/uboot_imx.git
    cd uboot_imx

# Install & select cross compiler

### If you do not have any compiler installed (or you are not sure)
    sudo apt-get install gcc-arm-linux-gnueabihf
    export CROSS_COMPILE=arm-linux-gnueabihf-
	
	or 
	
	git clone https://github.com/Radoslaw-Przybysz/gcc-arm-linux-gnueabihf-4.7
	export CROSS_COMPILE=$PWD/gcc-arm-linux-gnueabihf-4.7/bin/arm-linux-gnueabihf-

# Setup Architecture
    export ARCH=arm

# Build 
Here are instructions how to compile the source code

    make distclean
	
	# One of 
	make mx6q_uavx_35i00_defconfig
	make mx6q_uavx_37i00_defconfig

    make
