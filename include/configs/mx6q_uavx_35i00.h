/*
 * Copyright (C) 2017 UAVX.
 *
 * Author: Radoslaw Przybysz <przybyszradek@gmail.com>
 *
 * Configuration settings for the Freescale i.MX6Q UAVX board 35ixx.
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef __MX6Q_UAVX_35I00_CONFIG_H
#define __MX6Q_UAVX_35I00_CONFIG_H

#ifdef CONFIG_SPL
#define CONFIG_SPL_LIBCOMMON_SUPPORT
#define CONFIG_SPL_MMC_SUPPORT
#include "imx6_spl.h"
#endif

#define CONFIG_MACH_TYPE		5082
#define CONFIG_MXC_UART_BASE	UART1_BASE
#define CONFIG_CONSOLE_DEV		"ttymxc0"
#define CONFIG_MMCROOT			"/dev/mmcblk1p2"
#define CONFIG_SATAROOT			"/dev/sda2"

#if defined(CONFIG_DDR_SIZE) 
#define PHYS_SDRAM_SIZE         CONFIG_DDR_SIZE
#else
#define PHYS_SDRAM_SIZE         SZ_2G
#warning "Using default SDRAM size"
#endif

#define VIDEO_ARGS        "${video_args}"
#define VIDEO_ARGS_SCRIPT "run video_args_script; "

#include "mx6q_uavx_35i00_common.h"

#define CONFIG_SYS_FSL_USDHC_NUM	2

#undef CONFIG_CMD_PCI
#ifdef CONFIG_CMD_PCI
#define CONFIG_PCI
#define CONFIG_PCI_PNP
#define CONFIG_PCI_SCAN_SHOW
#define CONFIG_PCIE_IMX
#define CONFIG_PCIE_IMX_PERST_GPIO	IMX_GPIO_NR(7, 12)
#define CONFIG_PCIE_IMX_POWER_GPIO	IMX_GPIO_NR(3, 19)
#endif

/* I2C Configs */
#define CONFIG_CMD_I2C
#define CONFIG_SYS_I2C
#define CONFIG_SYS_I2C_MXC
#define CONFIG_SYS_I2C_MXC_I2C1		/* enable I2C bus 1 */
#define CONFIG_SYS_I2C_MXC_I2C2		/* enable I2C bus 2 */
#define CONFIG_SYS_I2C_MXC_I2C3		/* enable I2C bus 3 */
#define CONFIG_SYS_I2C_SPEED		  100000

/* USB Configs */
#define CONFIG_CMD_USB

#ifdef CONFIG_CMD_USB
#define CONFIG_USB_EHCI
#define CONFIG_USB_EHCI_MX6
#define CONFIG_USB_STORAGE
#define CONFIG_EHCI_HCD_INIT_AFTER_RESET
#define CONFIG_USB_HOST_ETHER
#define CONFIG_USB_ETHER_ASIX
#define CONFIG_MXC_USB_PORTSC		(PORT_PTS_UTMI | PORT_PTS_PTW)
#define CONFIG_MXC_USB_FLAGS		0
#define CONFIG_USB_MAX_CONTROLLER_COUNT	2 /* Enabled USB controller number */
#endif

#ifdef CONFIG_MX6Q
#define CONFIG_CMD_SATA
#endif

/*
 * SATA Configs
 */
#ifdef CONFIG_CMD_SATA
#define CONFIG_DWC_AHSATA
#define CONFIG_SYS_SATA_MAX_DEVICE	1
#define CONFIG_DWC_AHSATA_PORT_ID	0
#define CONFIG_DWC_AHSATA_BASE_ADDR	SATA_ARB_BASE_ADDR
#define CONFIG_LBA48
#define CONFIG_LIBATA
#endif

#undef CONFIG_CMD_NET
#undef CONFIG_CMD_PING
#undef CONFIG_CMD_DNS
#undef CONFIG_CMD_CDP
#undef CONFIG_CMD_SNTP
#undef CONFIG_CMD_LINK_LOCAL
#undef CONFIG_CMD_RARP

#undef CONFIG_SPL_ETH_SUPPORT

#endif                      
