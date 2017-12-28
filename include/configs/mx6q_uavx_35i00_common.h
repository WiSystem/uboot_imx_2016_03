/*
 * Copyright (C) 2017 UAVX.
 *
 * Author: Radoslaw Przybysz <przybyszradek@gmail.com>
 *
 * Configuration settings for the Freescale i.MX6Q UAVX board 35i00.
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef __MX6Q_UAVX_35I00_COMMON_CONFIG_H
#define __MX6Q_UAVX_35I00_COMMON_CONFIG_H

#include "mx6_common.h"

#define CONFIG_IMX_THERMAL

/* Size of malloc() pool */
#define CONFIG_SYS_MALLOC_LEN		(10 * SZ_1M)

#define CONFIG_BOARD_EARLY_INIT_F
#define CONFIG_BOARD_LATE_INIT

#define CONFIG_MXC_UART

/* MMC Configs */
#define CONFIG_SYS_FSL_ESDHC_ADDR      0
#define CONFIG_MMC
#define CONFIG_CMD_MMC
#define CONFIG_GENERIC_MMC
#define CONFIG_BOUNCE_BUFFER
#define CONFIG_CMD_FAT
#define CONFIG_FAT_WRITE
#define CONFIG_CMD_EXT2
#define CONFIG_CMD_EXT4
#define CONFIG_CMD_EXT4_WRITE
#define CONFIG_DOS_PARTITION

#define CONFIG_CMD_SF

#ifdef CONFIG_CMD_SF
#define CONFIG_SPI_FLASH_SST
#define CONFIG_SPI_FLASH_SST26
#define CONFIG_MXC_SPI
#define CONFIG_SF_DEFAULT_BUS		2
#define CONFIG_SF_DEFAULT_CS		1
#define CONFIG_SF_DEFAULT_SPEED		20000000
#define CONFIG_SF_DEFAULT_MODE		SPI_MODE_0
#endif

/* Command definition */
#define CONFIG_CMD_BMODE

#ifdef CONFIG_SUPPORT_EMMC_BOOT
#define EMMC_ENV \
	"emmcdev=1\0" \
	"update_emmc_firmware=" \
		"if test ${ip_dyn} = yes; then " \
			"setenv get_cmd dhcp; " \
		"else " \
			"setenv get_cmd tftp; " \
		"fi; " \
		"if ${get_cmd} ${update_sd_firmware_filename}; then " \
			"if mmc dev ${emmcdev} 1; then "	\
				"setexpr fw_sz ${filesize} / 0x200; " \
				"setexpr fw_sz ${fw_sz} + 1; "	\
				"mmc write ${loadaddr} 0x2 ${fw_sz}; " \
			"fi; "	\
		"fi\0"
#else
#define EMMC_ENV ""
#endif

#define CONFIG_ENV_VARS_UBOOT_RUNTIME_CONFIG

#ifndef VIDEO_ARGS
#define VIDEO_ARGS ""
#endif

#ifndef VIDEO_ARGS_SCRIPT
#define VIDEO_ARGS_SCRIPT ""
#endif


/* Env settings */
#define CONFIG_ENV_DEFAULT_UBT_FILE         "u-boot-" "UAVX" ".imx"
#define CONFIG_ENV_DEFAULT_IMG_FILE         "zImage-" "UAVX" 
#define CONFIG_ENV_DEFAULT_FDT_FILE                   "UAVX" ".dtb"
#define CONFIG_ENV_DEFAULT_SCR_FILE         "boot-"   "UAVX" ".scr"

#define CONFIG_EXTRA_ENV_SETTINGS \
	"script="   CONFIG_ENV_DEFAULT_SCR_FILE "\0" \
	"image="    "zImage" "\0" \
	"fdt_file=" CONFIG_ENV_DEFAULT_FDT_FILE "\0" \
	"fdt_addr=0x18000000\0" \
	"boot_fdt=try\0" \
	"console=" CONFIG_CONSOLE_DEV "\0" \
	"dfuspi=dfu 0 sf 0:0:10000000:0\0" \
	"dfu_alt_info_spl=spl raw 0x400\0" \
	"dfu_alt_info_img=u-boot raw 0x10000\0" \
	"dfu_alt_info=spl raw 0x400\0" \
	"fdt_high=0xffffffff\0" \
	"initrd_high=0xffffffff\0" \
	"mmcdev=0\0" \
	"mmcpart=1\0" \
	"satadev=0\0" \
	"satapart=1\0" \
	"mmcroot=" CONFIG_MMCROOT " rootwait rw\0" \
	"sataroot=" CONFIG_SATAROOT " rootwait rw\0" \
	"spidev=" __stringify(CONFIG_ENV_SPI_BUS) "\0" \
	"spics=" __stringify(CONFIG_ENV_SPI_CS) "\0" \
	"update_set_filename=" \
		"if test ${upd_uboot}; then; else " \
			"setenv upd_uboot " CONFIG_ENV_DEFAULT_UBT_FILE  "; " \
		"fi; " \
		"if test ${upd_kernel}; then; else " \
			"setenv upd_kernel " CONFIG_ENV_DEFAULT_IMG_FILE "; " \
		"fi; " \
		"if test ${upd_fdt}; then; else " \
			"setenv upd_fdt    " CONFIG_ENV_DEFAULT_FDT_FILE "; " \
		"fi; " \
		"if test ${upd_script}; then; else " \
			"setenv upd_script " CONFIG_ENV_DEFAULT_SCR_FILE "; " \
		"fi\0" \
	EMMC_ENV	  \
	"video_args_hdmi=setenv video_args $video_args video=mxcfb0:dev=hdmi,1024x600M@60,if=RGB24\0" \
	"video_args_lvds=setenv video_args $video_args video=mxcfb3:dev=ldb,LDB-XGA,if=RGB666\0" \
	"video_args_lcd=setenv video_args $video_args video=mxcfb3:dev=lcd,CLAA-WVGA,if=RGB666\0" \
	"video_interfaces=hdmi\0" \
	"video_args_script=" \
		"for v in ${video_interfaces}; do " \
			"run video_args_${v}; " \
			"setexpr fb $fb + 1; " \
		"done\0" \
	"mmcargs=setenv bootargs console=${console},${baudrate} " \
		"root=${mmcroot} " \
		VIDEO_ARGS "\0" \
	"sataargs=setenv bootargs console=${console},${baudrate} " \
		"root=${sataroot} " \
		VIDEO_ARGS "\0" \
	"loadbootscript=" \
		"fatload mmc ${mmcdev}:${mmcpart} ${loadaddr} ${script};\0" \
	"bootscript=echo Running bootscript from mmc ...; " \
		"source\0" \
	"loadimage=fatload mmc ${mmcdev}:${mmcpart} ${loadaddr} ${image}\0" \
	"loadfdt=fatload mmc ${mmcdev}:${mmcpart} ${fdt_addr} ${fdt_file}\0" \
	"sataloadimage=fatload sata ${satadev}:${satapart} ${loadaddr} ${image}\0" \
	"sataloadfdt=fatload sata ${satadev}:${satapart} ${fdt_addr} ${fdt_file}\0" \
	"mmcboot=" \
		VIDEO_ARGS_SCRIPT \
		"run mmcargs; " \
		"if test ${boot_fdt} = yes || test ${boot_fdt} = try; then " \
			"if run loadfdt; then " \
				"bootz ${loadaddr} - ${fdt_addr}; " \
			"else " \
				"if test ${boot_fdt} = try; then " \
					"bootz; " \
				"else " \
					"echo WARN: Cannot load the DT; " \
				"fi; " \
			"fi; " \
		"else " \
			"bootz; " \
		"fi;\0" \
	"bootmmc=echo Booting from MMC ...; " \
		"run findfdt;" \
		"mmc dev ${mmcdev};" \
		"if mmc rescan; then " \
			"if run loadbootscript; then " \
			"run bootscript; " \
			"else " \
				"if run loadimage; then " \
					"run mmcboot; " \
				"fi; " \
			"fi; " \
		"fi;\0" \
	"bootsata=echo Booting from SATA ...; " \
		VIDEO_ARGS_SCRIPT \
		"run findfdt; " \
		"run sataargs; " \
		"if sata init; then " \
			"if test ${boot_fdt} = yes || test ${boot_fdt} = try; then " \
				"if run sataloadimage; then " \
					"if run sataloadfdt; then " \
						"bootz ${loadaddr} - ${fdt_addr}; " \
					"else " \
						"if test ${boot_fdt} = try; then " \
							"bootz; " \
						"else " \
							"echo WARN: Cannot load the DT; " \
						"fi; " \
					"fi; " \
				"else echo WARN: Cannot load the image; " \
				"fi; " \
			"else " \
				"bootz; " \
			"fi; " \
		"fi;\0" \
	"findfdt="\
		"if test $fdt_file = undefined; then " \
			"if test $board_name = iMX6-UAVX && test $board_rev = MX6Q; then " \
				"setenv fdt_file imx6q-UAVX.dtb; fi; " \
			"if test $board_name = iMX6-UAVX && test $board_rev = MX6DL; then " \
				"setenv fdt_file imx6dl-UAVX.dtb; fi; " \
			"if test $fdt_file = undefined; then " \
				"echo WARNING: Could not determine dtb to use; fi; " \
		"fi;\0" \
	"led="\
		"i2c dev 1;"\
		"i2c mw 0x66 0x00 0x00;"\
		"i2c mw 0x66 0x01 0x00;"\
		"i2c mw 0x66 0x02 0x00;"\
		"i2c mw 0x66 0x03 0x8F;\0"\

#define CONFIG_BOOTCOMMAND \
	"run bootmmc;"

#define CONFIG_ARP_TIMEOUT     200UL

#define CONFIG_SYS_MEMTEST_START       0x10000000
#define CONFIG_SYS_MEMTEST_END         0x10010000
#define CONFIG_SYS_MEMTEST_SCRATCH     0x10800000

#define CONFIG_STACKSIZE               (128 * 1024)

/* Physical Memory Map */
#define CONFIG_NR_DRAM_BANKS           1
#define PHYS_SDRAM                     MMDC0_ARB_BASE_ADDR

#define CONFIG_SYS_SDRAM_BASE          PHYS_SDRAM
#define CONFIG_SYS_INIT_RAM_ADDR       IRAM_BASE_ADDR
#define CONFIG_SYS_INIT_RAM_SIZE       IRAM_SIZE

#define CONFIG_SYS_INIT_SP_OFFSET \
	(CONFIG_SYS_INIT_RAM_SIZE - GENERATED_GBL_DATA_SIZE)
#define CONFIG_SYS_INIT_SP_ADDR \
	(CONFIG_SYS_INIT_RAM_ADDR + CONFIG_SYS_INIT_SP_OFFSET)

/* Environment organization */
#define CONFIG_ENV_SIZE			(8 * 1024)

#define CONFIG_ENV_IS_IN_SPI_FLASH

#if defined(CONFIG_ENV_IS_IN_MMC)
#define CONFIG_ENV_OFFSET		(6 * 64 * 1024)
#define CONFIG_SYS_MMC_ENV_DEV		0
#elif defined(CONFIG_ENV_IS_IN_SPI_FLASH)
#define CONFIG_ENV_OFFSET		(768 * 1024)
#define CONFIG_ENV_SECT_SIZE		(8 * 1024)
#define CONFIG_ENV_SPI_BUS		CONFIG_SF_DEFAULT_BUS
#define CONFIG_ENV_SPI_CS		CONFIG_SF_DEFAULT_CS
#define CONFIG_ENV_SPI_MODE		CONFIG_SF_DEFAULT_MODE
#define CONFIG_ENV_SPI_MAX_HZ		CONFIG_SF_DEFAULT_SPEED
#endif

/* Framebuffer */
#if 0
#define CONFIG_VIDEO
#define CONFIG_VIDEO_IPUV3
#define CONFIG_CFB_CONSOLE
#define CONFIG_VGA_AS_SINGLE_DEVICE
#define CONFIG_SYS_CONSOLE_IS_IN_ENV
#define CONFIG_SYS_CONSOLE_OVERWRITE_ROUTINE
#define CONFIG_VIDEO_BMP_RLE8
#define CONFIG_SPLASH_SCREEN
#define CONFIG_SPLASH_SCREEN_ALIGN
#define CONFIG_BMP_16BPP
#define CONFIG_VIDEO_LOGO
#define CONFIG_VIDEO_BMP_LOGO
#define CONFIG_IPUV3_CLK 260000000
#define CONFIG_IMX_HDMI
#define CONFIG_IMX_VIDEO_SKIP
#endif

#ifndef CONFIG_SPL
#define CONFIG_CI_UDC
#define CONFIG_USBD_HS
#define CONFIG_USB_GADGET_DUALSPEED

#define CONFIG_USB_GADGET
#define CONFIG_CMD_USB_MASS_STORAGE
#define CONFIG_USB_FUNCTION_MASS_STORAGE
#define CONFIG_USB_GADGET_DOWNLOAD
#define CONFIG_USB_GADGET_VBUS_DRAW	2

#define CONFIG_G_DNL_VENDOR_NUM		0x0525
#define CONFIG_G_DNL_PRODUCT_NUM	0xa4a5
#define CONFIG_G_DNL_MANUFACTURER	"FSL"

#define CONFIG_USB_FUNCTION_FASTBOOT
#define CONFIG_CMD_FASTBOOT
#define CONFIG_ANDROID_BOOT_IMAGE
#define CONFIG_FASTBOOT_BUF_ADDR   CONFIG_SYS_LOAD_ADDR
#define CONFIG_FASTBOOT_BUF_SIZE   0x07000000

/* USB Device Firmware Update support */
#define CONFIG_CMD_DFU
#define CONFIG_USB_FUNCTION_DFU
#define CONFIG_DFU_MMC
#define CONFIG_DFU_SF
#endif

#endif                         /* __MX6Q_UAVX_35I00_COMMON_CONFIG_H */
