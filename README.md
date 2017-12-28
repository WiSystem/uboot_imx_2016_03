# About
This is a source code of uBoot for UAVX board.

# Download source code
    git clone https://github.com/WiSystem/uboot_imx_2016_03.git
    cd uboot_imx

# Install & select cross compiler

### If you do not have any compiler installed (or you are not sure)
    sudo apt-get install gcc-arm-linux-gnueabihf
    export CROSS_COMPILE=arm-linux-gnueabihf-
	
# Setup Architecture
    export ARCH=arm

# Clean 
    make distclean
	
# Select one of them
-	make mx6q_uavx_35i00_defconfig
-	make mx6q_uavx_37i00_defconfig

# Build 
    make
