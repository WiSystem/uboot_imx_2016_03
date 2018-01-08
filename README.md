# Download source code
    git clone https://github.com/WiSystem/uboot_imx_2016_03.git
    cd uboot_imx_2016_03

# Install cross compiler
    sudo apt-get install gcc-arm-linux-gnueabihf

## Select cross compiler
    export CROSS_COMPILE=arm-linux-gnueabihf-
	
## Setup Architecture
    export ARCH=arm

## Clean 
    make distclean
	
## Select defconfig 
    make mx6q_uavx_35i00_defconfig  [or]
    make mx6q_uavx_37i00_defconfig

## Build 
    make
    
# Help  

## Save uboot to SPI memory  [i.mx6]
     
    1. Write u-boot.imx to SD card, just copy 
    
    2. Insert cart to i.MX6 and load data to ram 
        uboot => fatload mmc 0:1 0x10800000 /u-boot.imx    
        where mmc 0:1 
        0 -> first SD card slot 
        1 -> first partition FAT12
        
    3. Write new uboot to SPI memory 
        uboot => sf probe 0
        uboot => sf erase 0 0xC0000
        uboot => sf write 0x10800000 0x400 0x80000

    4. Reset by power cycle or by uboot
        uboot => reset
    
