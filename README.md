# Download source code
    git clone https://github.com/WiSystem/uboot_imx_2016_03.git
    cd uboot_imx_2016_03

# Install 
    sudo apt-get install gcc-arm-linux-gnueabihf

## Select cross compiler
    export CROSS_COMPILE=arm-linux-gnueabihf-
	
## Setup Architecture
    export ARCH=arm

## Clean 
    make distclean
	
## Select defconfig
    make mx6q_uavx_35i00_defconfig
    make mx6q_uavx_37i00_defconfig

## Build 
    make
    
    
