/*
 * arch/arm/plat-ambarella/include/plat/irq.h
 *
 * Author: Anthony Ginger <hfjiang@ambarella.com>
 *
 * Copyright (C) 2004-2010, Ambarella, Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 *
 */

#ifndef __PLAT_AMBARELLA_IRQ_H__
#define __PLAT_AMBARELLA_IRQ_H__

#ifdef CONFIG_AMBARELLA_VIC

#include <plat/chip.h>

/* ==========================================================================*/
#if (CHIP_REV == S3L)
#define VIC_INSTANCES			(3)
#define VIC_SUPPORT_CPU_OFFLOAD		(2)
#define VIC_SUPPORT_REPRIORITIZE	(1)
#elif (CHIP_REV == S2L)
#define VIC_INSTANCES			(3)
#define VIC_SUPPORT_CPU_OFFLOAD		(1)
#define VIC_SUPPORT_REPRIORITIZE	(1)
#elif (CHIP_REV == S3)
#define VIC_INSTANCES			(4)
#define VIC_SUPPORT_CPU_OFFLOAD		(2)
#define VIC_SUPPORT_REPRIORITIZE	(1)
#else
#error "Not supported!"
#endif

#if (VIC_SUPPORT_CPU_OFFLOAD == 2)
#if (CHIP_REV == S3)
#define VIC_NULL_PRI_IRQ_VAL		(0x00000060)
#else
#define VIC_NULL_PRI_IRQ_VAL		(0xffffffff)
#endif
#define VIC_NULL_PRI_IRQ_FIX		(0)
#endif

#if (CHIP_REV == S3L)
#define AHBSP_PRI_IRQ_C0_OFFSET		0x38
#define AHBSP_PRI_IRQ_C1_OFFSET		-1 /* not supported */
#else
#define AHBSP_PRI_IRQ_C0_OFFSET		0x3C
#define AHBSP_PRI_IRQ_C1_OFFSET		0x40
#endif
#define AHBSP_PRI_IRQ_C0_REG		AHB_SCRATCHPAD_REG(AHBSP_PRI_IRQ_C0_OFFSET)
#define AHBSP_PRI_IRQ_C1_REG		AHB_SCRATCHPAD_REG(AHBSP_PRI_IRQ_C1_OFFSET)

#if (CHIP_REV == S3) || (CHIP_REV == S3L)
#define VIC_2NDGEN_BITASSIGNMENT	(1)
#endif

/* ==========================================================================*/
#define VIC0_OFFSET			0x3000
#define VIC1_OFFSET			0x10000
#define VIC2_OFFSET			0x1C000
#define VIC3_OFFSET			0x11000

#define VIC0_BASE			(AHB_BASE + VIC0_OFFSET)
#define VIC1_BASE			(AHB_BASE + VIC1_OFFSET)
#define VIC2_BASE			(AHB_BASE + VIC2_OFFSET)
#define VIC3_BASE			(AHB_BASE + VIC3_OFFSET)

#define VIC0_REG(x)			(VIC0_BASE + (x))
#define VIC1_REG(x)			(VIC1_BASE + (x))
#define VIC2_REG(x)			(VIC2_BASE + (x))
#define VIC3_REG(x)			(VIC3_BASE + (x))
#define VIC_REG(irq, x)			((irq) < VIC0_INT_VEC(NR_VIC_IRQ_SIZE) ? VIC0_REG((x)) : \
					 (irq) < VIC1_INT_VEC(NR_VIC_IRQ_SIZE) ? VIC1_REG((x)) : \
					 (irq) < VIC2_INT_VEC(NR_VIC_IRQ_SIZE) ? VIC2_REG((x)) : \
					 VIC3_REG((x)))

/* ==========================================================================*/
#define NR_VIC_IRQ_SIZE			(32)

#if defined(CONFIG_ARM_GIC)
#define VIC_IRQ(x)			((x) + 32)
#define NR_SPI_IRQS			(256)
#define SGI_INT_VEC(x)			(x)
#define PPI_INT_VEC(x)			(x)
#define SPI_INT_VEC(x)			(x)
#else
#define VIC_IRQ(x)			(x)
#endif

#define VIC0_INT_VEC(x)			(VIC_IRQ(x) + NR_VIC_IRQ_SIZE * 0)
#define VIC1_INT_VEC(x)			(VIC_IRQ(x) + NR_VIC_IRQ_SIZE * 1)
#define VIC2_INT_VEC(x)			(VIC_IRQ(x) + NR_VIC_IRQ_SIZE * 2)
#define VIC3_INT_VEC(x)			(VIC_IRQ(x) + NR_VIC_IRQ_SIZE * 3)

#ifndef NR_SPI_IRQS
#define NR_VIC_IRQS			(VIC_INSTANCES * NR_VIC_IRQ_SIZE)
#define GPIO_INT_VEC(x)			(NR_VIC_IRQS + x)
#else
#define NR_VIC_IRQS			NR_SPI_IRQS
#define GPIO_INT_VEC(x)			(NR_SPI_IRQS + x)
#endif

#ifndef CONFIG_AMBARELLA_EXT_IRQ_NUM
#define CONFIG_AMBARELLA_EXT_IRQ_NUM	(64)
#endif
#define EXT_IRQ(x)			GPIO_INT_VEC(AMBGPIO_SIZE + x)

#define NR_IRQS				EXT_IRQ(CONFIG_AMBARELLA_EXT_IRQ_NUM)

/* ==========================================================================*/
#define VIC_IRQ_STA_OFFSET			(0x00)
#define VIC_FIQ_STA_OFFSET			(0x04)
#define VIC_RAW_STA_OFFSET			(0x08)
#define VIC_INT_SEL_OFFSET			(0x0c)
#define VIC_INTEN_OFFSET			(0x10)
#define VIC_INTEN_CLR_OFFSET			(0x14)
#define VIC_SOFTEN_OFFSET			(0x18)
#define VIC_SOFTEN_CLR_OFFSET			(0x1c)
#define VIC_PROTEN_OFFSET			(0x20)
#define VIC_SENSE_OFFSET			(0x24)
#define VIC_BOTHEDGE_OFFSET			(0x28)
#define VIC_EVENT_OFFSET			(0x2c)
#define VIC_INT_PTR0_OFFSET			(0x30)
#define VIC_INT_PTR1_OFFSET			(0x34)
#define VIC_EDGE_CLR_OFFSET			(0x38)
#define VIC_INT_SEL_INT_OFFSET			(0x3c)
#define VIC_INT_SEL_CLR_INT_OFFSET		(0x40)
#define VIC_INT_EN_INT_OFFSET			(0x44)
#define VIC_INT_EN_CLR_INT_OFFSET		(0x48)
#define VIC_SOFT_INT_INT_OFFSET			(0x4c)
#define VIC_SOFT_INT_CLR_INT_OFFSET		(0x50)
#define VIC_INT_SENSE_INT_OFFSET		(0x54)
#define VIC_INT_SENSE_CLR_INT_OFFSET		(0x58)
#define VIC_INT_BOTHEDGE_INT_OFFSET		(0x5c)
#define VIC_INT_BOTHEDGE_CLR_INT_OFFSET		(0x60)
#define VIC_INT_EVT_INT_OFFSET			(0x64)
#define VIC_INT_EVT_CLR_INT_OFFSET		(0x68)
#define VIC_INT_PENDING_OFFSET			(0x6c)
#define VIC_INT_RE_PRIORITIZE_EN_OFFSET		(0x70)
#define VIC_INT_PRIORITY_0_OFFSET		(0x74)
#define VIC_INT_PRIORITY_1_OFFSET		(0x78)
#define VIC_INT_PRIORITY_2_OFFSET		(0x7c)
#define VIC_INT_PRIORITY_3_OFFSET		(0x80)
#define VIC_INT_PRIORITY_4_OFFSET		(0x84)
#define VIC_INT_PRIORITY_5_OFFSET		(0x88)
#define VIC_INT_DELAY_EN_OFFSET			(0x8c)
#define VIC_INT_DELAY_OFFSET			(0x90)
#define VIC_INT_PENDING_C1_REG			(0x94)
#define VIC_INT_EDGE_CLR_OFFSET			(0x98)

/* ==========================================================================*/
#if (CHIP_REV == S2L)
#define USBVBUS_IRQ			VIC0_INT_VEC(0)
#define VOUT_IRQ			VIC0_INT_VEC(1)
#define VIN_IRQ				VIC0_INT_VEC(2)
#define CODE_VDSP_0_IRQ			VIC0_INT_VEC(3)
#define USBC_IRQ			VIC0_INT_VEC(4)
#define USB_CHARGE_IRQ			VIC0_INT_VEC(5)
#define SD2CD_IRQ			VIC0_INT_VEC(6)
#define I2STX_IRQ			VIC0_INT_VEC(7)
#define I2SRX_IRQ			VIC0_INT_VEC(8)
#define UART0_IRQ			VIC0_INT_VEC(9)
#define GPIO0_IRQ			VIC0_INT_VEC(10)
#define GPIO1_IRQ			VIC0_INT_VEC(11)
#define TIMER1_IRQ			VIC0_INT_VEC(12)
#define TIMER2_IRQ			VIC0_INT_VEC(13)
#define TIMER3_IRQ			VIC0_INT_VEC(14)
#define DMA_IRQ				VIC0_INT_VEC(15)
#define FIOCMD_IRQ			VIC0_INT_VEC(16)
#define FIODMA_IRQ			VIC0_INT_VEC(17)
#define SD_IRQ				VIC0_INT_VEC(18)
#define IDC_IRQ				VIC0_INT_VEC(19)
#define SD3_IRQ				VIC0_INT_VEC(20)
#define WDT_IRQ				VIC0_INT_VEC(21)
#define IRIF_IRQ			VIC0_INT_VEC(22)
#define SD1CD_IRQ			VIC0_INT_VEC(23)
#define SD0CD_IRQ			VIC0_INT_VEC(24)
#define UART1_IRQ			VIC0_INT_VEC(25)
#define MOTOR_IRQ			VIC0_INT_VEC(26)
#define ETH_IRQ				VIC0_INT_VEC(27)
#define USB_CONNECT_CHANGE_IRQ		VIC0_INT_VEC(28)
#define GPIO3_IRQ			VIC0_INT_VEC(29)
#define GPIO2_IRQ			VIC0_INT_VEC(30)

#define ETH_PMT_IRQ			VIC1_INT_VEC(0)
#define DMA_FIOS_IRQ			VIC1_INT_VEC(1)
#define ADC_LEVEL_IRQ			VIC1_INT_VEC(2)
#define SSI_MASTER0_IRQ			VIC1_INT_VEC(3)
#define IDC3_IRQ			VIC1_INT_VEC(4)
#define SSI_MASTER1_IRQ			VIC1_INT_VEC(5)
#define SSI_SLAVE_IRQ			VIC1_INT_VEC(6)
#define USB_EHCI_IRQ			VIC1_INT_VEC(7)
#define HDMI_IRQ			VIC1_INT_VEC(8)
#define FIOS_ECC_IRQ			VIC1_INT_VEC(9)
#define VOUT_TV_SYNC_IRQ		VIC1_INT_VEC(10)
#define VOUT_LCD_SYNC_IRQ		VIC1_INT_VEC(11)
#define USB_OHCI_IRQ			VIC1_INT_VEC(12)
#define NOR_SPI				VIC1_INT_VEC(13)
#define ORC_VOUT0_IRQ			VIC1_INT_VEC(14)
#define GDMA_IRQ			VIC1_INT_VEC(18)
#define IDC2_IRQ			VIC1_INT_VEC(19)
#define SD2_IRQ				VIC1_INT_VEC(20)
#define IDSP_PIP_VSYNC_IRQ		VIC1_INT_VEC(21)
#define IDSP_PIP_SOF_IRQ		VIC1_INT_VEC(22)
#define IDSP_PIP_MVSYNC_IRQ		VIC1_INT_VEC(23)
#define IDSP_PIP_LAST_PIXEL_IRQ		VIC1_INT_VEC(24)
#define IDSP_PIP_DVSYNC_IRQ		VIC1_INT_VEC(25)
#define VDSP_PIP_CODING_IRQ		VIC1_INT_VEC(26)
#define TIMER4_IRQ			VIC1_INT_VEC(27)
#define TIMER5_IRQ			VIC1_INT_VEC(28)
#define TIMER6_IRQ			VIC1_INT_VEC(29)
#define TIMER7_IRQ			VIC1_INT_VEC(30)
#define TIMER8_IRQ			VIC1_INT_VEC(31)

#define IDSP_VIN_MVSYNC_IRQ		VIC2_INT_VEC(0)
#define IDSP_VIN_VSYNC_IRQ		VIC2_INT_VEC(1)
#define IDSP_VIN_SOF_IRQ		VIC2_INT_VEC(2)
#define IDSP_VIN_DVSYNC_IRQ		VIC2_INT_VEC(3)
#define IDSP_VIN_LAST_PIXEL_IRQ		VIC2_INT_VEC(4)
#define L2CC_INTR_IRQ			VIC2_INT_VEC(21)
#define MD5_IRQ				VIC2_INT_VEC(22)
#define DES_IRQ				VIC2_INT_VEC(23)
#define AES_IRQ				VIC2_INT_VEC(24)
#define SHA1_IRQ			VIC2_INT_VEC(25)
#define USB_DIGITAL_ID_CHANGE_IRQ	VIC2_INT_VEC(27)
#define PMU_IRQ				VIC2_INT_VEC(28)
#define L2CC_DECERR_IRQ			VIC2_INT_VEC(29)
#define L2CC_SLVERR_IRQ			VIC2_INT_VEC(30)
#define L2CC_ECNTR_IRQ			VIC2_INT_VEC(31)

/* ==========================================================================*/
#elif (CHIP_REV == S3)
#define IPI00_IRQ			VIC0_INT_VEC(0)
#define IPI01_IRQ			VIC0_INT_VEC(1)
#define IPI02_IRQ			VIC0_INT_VEC(2)
#define IPI03_IRQ			VIC0_INT_VEC(3)
#define IPI04_IRQ			VIC0_INT_VEC(4)
#define IPI05_IRQ			VIC0_INT_VEC(5)
#define IPI06_IRQ			VIC0_INT_VEC(6)
#define TIMER1_IRQ			VIC0_INT_VEC(7)
#define TIMER2_IRQ			VIC0_INT_VEC(8)
#define TIMER3_IRQ			VIC0_INT_VEC(9)
#define TIMER4_IRQ			VIC0_INT_VEC(10)
#define TIMER5_IRQ			VIC0_INT_VEC(11)
#define TIMER6_IRQ			VIC0_INT_VEC(12)
#define TIMER7_IRQ			VIC0_INT_VEC(13)
#define TIMER8_IRQ			VIC0_INT_VEC(14)
#define PMU_IRQ				VIC0_INT_VEC(15)
#define IPI10_IRQ			VIC0_INT_VEC(16)
#define IPI11_IRQ			VIC0_INT_VEC(17)
#define IPI12_IRQ			VIC0_INT_VEC(18)
#define IPI13_IRQ			VIC0_INT_VEC(19)
#define IPI14_IRQ			VIC0_INT_VEC(20)
#define IPI15_IRQ			VIC0_INT_VEC(21)
#define IPI16_IRQ			VIC0_INT_VEC(22)
#define TIMER11_IRQ			VIC0_INT_VEC(23)
#define TIMER12_IRQ			VIC0_INT_VEC(24)
#define TIMER13_IRQ			VIC0_INT_VEC(25)
#define TIMER14_IRQ			VIC0_INT_VEC(26)
#define TIMER15_IRQ			VIC0_INT_VEC(27)
#define TIMER16_IRQ			VIC0_INT_VEC(28)
#define TIMER17_IRQ			VIC0_INT_VEC(29)
#define TIMER18_IRQ			VIC0_INT_VEC(30)
#define PMU1_IRQ			VIC0_INT_VEC(31)

#define IDSP_VIN_STAT_IRQ		VIC1_INT_VEC(0)
#define IDSP_VIN_MVSYNC_IRQ		VIC1_INT_VEC(1)
#define IDSP_VIN_VSYNC_IRQ		VIC1_INT_VEC(2)
#define IDSP_VIN_SOF_IRQ		VIC1_INT_VEC(3)
#define IDSP_VIN_DVSYNC_IRQ		VIC1_INT_VEC(4)
#define IDSP_VIN_LAST_PIXEL_IRQ		VIC1_INT_VEC(5)
#define IDSP_PIP_STAT_IRQ		VIC1_INT_VEC(6)
#define IDSP_PIP_MVSYNC_IRQ		VIC1_INT_VEC(7)
#define IDSP_PIP_VSYNC_IRQ		VIC1_INT_VEC(8)
#define IDSP_PIP_SOF_IRQ		VIC1_INT_VEC(9)
#define IDSP_PIP_DVSYNC_IRQ		VIC1_INT_VEC(10)
#define IDSP_PIP_LAST_PIXEL_IRQ		VIC1_INT_VEC(11)
#define VOUT_TV_SYNC_IRQ		VIC1_INT_VEC(12)
#define VOUT_LCD_SYNC_IRQ		VIC1_INT_VEC(13)
#define CODE_VDSP_0_IRQ			VIC1_INT_VEC(14)
#define CODE_VDSP_1_IRQ			VIC1_INT_VEC(15)
#define CODE_VDSP_2_IRQ			VIC1_INT_VEC(16)
#define CODE_VDSP_3_IRQ			VIC1_INT_VEC(17)
#define CODE_VDSP_4_IRQ			VIC1_INT_VEC(18)
#define CODE_VDSP_5_IRQ			VIC1_INT_VEC(19)
#define CODE_VDSP_6_IRQ			VIC1_INT_VEC(20)
#define CODE_VDSP_7_IRQ			VIC1_INT_VEC(21)
#define VIN_IRQ				VIC1_INT_VEC(22)
#define ORC_VOUT0_IRQ			VIC1_INT_VEC(23)
#define VOUT_IRQ			VIC1_INT_VEC(24)
#define VDSP_ORC_BKPT_IRQ		VIC1_INT_VEC(25)
#define VDSP_EORC0_BKPT_IRQ		VIC1_INT_VEC(26)
#define VDSP_DORC_BRPT_IRQ		VIC1_INT_VEC(27)
#define VDSP_PIP_CODING_IRQ		VIC1_INT_VEC(28)
#define FDET_IRQ			VIC1_INT_VEC(29)
#define TIMER10_IRQ			VIC1_INT_VEC(30)
#define TIMER9_IRQ			VIC1_INT_VEC(31)

#define CANC_IRQ			VIC2_INT_VEC(0)
#define ETH_IRQ				VIC2_INT_VEC(1)
#define USB_EHCI_IRQ			VIC2_INT_VEC(2)
#define USB_OHCI_IRQ			VIC2_INT_VEC(3)
#define USBC_IRQ			VIC2_INT_VEC(4)
#define DMA_IRQ				VIC2_INT_VEC(5)
#define DMA_FIOS_IRQ			VIC2_INT_VEC(6)
#define FIOS_ECC_IRQ			VIC2_INT_VEC(7)
#define FIOCMD_IRQ			VIC2_INT_VEC(8)
#define FIODMA_IRQ			VIC2_INT_VEC(9)
#define GDMA_IRQ			VIC2_INT_VEC(10)
#define SD3_IRQ				VIC2_INT_VEC(11)
#define SD2_IRQ				VIC2_INT_VEC(12)
#define SD_IRQ				VIC2_INT_VEC(13)
#define NOR_SPI				VIC2_INT_VEC(14)
#define SSI_MASTER1_IRQ			VIC2_INT_VEC(15)
#define SSI_MASTER0_IRQ			VIC2_INT_VEC(16)
#define SSI_SLAVE_IRQ			VIC2_INT_VEC(17)
#define UART1_IRQ			VIC2_INT_VEC(18)
#define IDC3_IRQ			VIC2_INT_VEC(19)
#define IDC2_IRQ			VIC2_INT_VEC(20)
#define IDC_IRQ				VIC2_INT_VEC(21)
#define IRIF_IRQ			VIC2_INT_VEC(22)
#define I2STX_IRQ			VIC2_INT_VEC(23)
#define I2SRX_IRQ			VIC2_INT_VEC(24)
#define IDC_SLAVE_IRQ			VIC2_INT_VEC(25)
#define HIF_ARM2_IRQ			VIC2_INT_VEC(26)
#define HIF_ARM1_IRQ			VIC2_INT_VEC(27)
#define TS_CH1_RX_IRQ			VIC2_INT_VEC(28)
#define TS_CH0_RX_IRQ			VIC2_INT_VEC(29)
#define TS_CH1_TX_IRQ			VIC2_INT_VEC(30)
#define TS_CH0_TX_IRQ			VIC2_INT_VEC(31)

#define USBVBUS_IRQ			VIC3_INT_VEC(0)
#define USB_DIGITAL_ID_CHANGE_IRQ	VIC3_INT_VEC(1)
#define USB_CONNECT_CHANGE_IRQ		VIC3_INT_VEC(2)
#define USB_CHARGE_IRQ			VIC3_INT_VEC(3)
#define SD2CD_IRQ			VIC3_INT_VEC(4)
#define SD1CD_IRQ			VIC3_INT_VEC(5)
#define SD0CD_IRQ			VIC3_INT_VEC(6)
#define ADC_LEVEL_IRQ			VIC3_INT_VEC(7)
#define HDMI_IRQ			VIC3_INT_VEC(8)
#define WDT_IRQ				VIC3_INT_VEC(9)
#define SLIM_IRQ			VIC3_INT_VEC(10)
#define ETH_PMT_IRQ			VIC3_INT_VEC(11)
#define UART0_IRQ			VIC3_INT_VEC(12)
#define MOTOR_IRQ			VIC3_INT_VEC(13)
#define SHA1_IRQ			VIC3_INT_VEC(14)
#define AES_IRQ				VIC3_INT_VEC(15)
#define DES_IRQ				VIC3_INT_VEC(16)
#define MD5_IRQ				VIC3_INT_VEC(17)
#define L2CC_INTR_IRQ			VIC3_INT_VEC(18)
#define L2CC_INTR1_IRQ			VIC3_INT_VEC(19)
#define AXI_SWI_IRQ			VIC3_INT_VEC(20)
#define AXI_SWI1_IRQ			VIC3_INT_VEC(21)
#define GPIO6_IRQ			VIC3_INT_VEC(22)
#define GPIO5_IRQ			VIC3_INT_VEC(23)
#define GPIO4_IRQ			VIC3_INT_VEC(24)
#define GPIO3_IRQ			VIC3_INT_VEC(25)
#define GPIO2_IRQ			VIC3_INT_VEC(26)
#define GPIO1_IRQ			VIC3_INT_VEC(27)
#define GPIO0_IRQ			VIC3_INT_VEC(28)
#define DMIC_IRQ			VIC3_INT_VEC(29)
#define TIMER20_IRQ			VIC3_INT_VEC(30)
#define TIMER19_IRQ			VIC3_INT_VEC(31)

/* ==========================================================================*/
#elif (CHIP_REV == S3L)
#define TIMER1_IRQ			VIC0_INT_VEC(0)
#define TIMER2_IRQ			VIC0_INT_VEC(1)
#define TIMER3_IRQ			VIC0_INT_VEC(2)
#define TIMER4_IRQ			VIC0_INT_VEC(3)
#define TIMER5_IRQ			VIC0_INT_VEC(4)
#define TIMER6_IRQ			VIC0_INT_VEC(5)
#define TIMER7_IRQ			VIC0_INT_VEC(6)
#define AXI_SOFT_IRQ(x)			VIC0_INT_VEC((x) + 7)	/* 0 <= x <= 13 */
#define AXI_SW_IRQ0			VIC0_INT_VEC(21)
#define AXI_SW_IRQ1			VIC0_INT_VEC(22)
#define PMU_IRQ				VIC0_INT_VEC(23)
#define L2CC_INTR_IRQ			VIC0_INT_VEC(24)
#define L2CC_DECERR_IRQ			VIC0_INT_VEC(25)
#define L2CC_SLVERR_IRQ			VIC0_INT_VEC(26)
#define L2CC_ECNTR_IRQ			VIC0_INT_VEC(27)
#define MD5_IRQ				VIC0_INT_VEC(28)
#define DES_IRQ				VIC0_INT_VEC(29)
#define AES_IRQ				VIC0_INT_VEC(30)
#define SHA1_IRQ			VIC0_INT_VEC(31)

#define IDSP_VIN_MVSYNC_IRQ		VIC1_INT_VEC(0)
#define IDSP_VIN_VSYNC_IRQ		VIC1_INT_VEC(1)
#define IDSP_VIN_SOF_IRQ		VIC1_INT_VEC(2)
#define IDSP_VIN_DVSYNC_IRQ		VIC1_INT_VEC(3)
#define IDSP_VIN_LAST_PIXEL_IRQ		VIC1_INT_VEC(4)
#define GDMA_IRQ			VIC1_INT_VEC(5)
#define IDSP_PIP_MVSYNC_IRQ		VIC1_INT_VEC(6)
#define IDSP_PIP_VSYNC_IRQ		VIC1_INT_VEC(7)
#define IDSP_PIP_SOF_IRQ		VIC1_INT_VEC(8)
#define IDSP_PIP_DVSYNC_IRQ		VIC1_INT_VEC(9)
#define IDSP_PIP_LAST_PIXEL_IRQ		VIC1_INT_VEC(10)
#define VOUT_TV_SYNC_IRQ		VIC1_INT_VEC(11)
#define VOUT_LCD_SYNC_IRQ		VIC1_INT_VEC(12)
#define CODE_VDSP_0_IRQ			VIC1_INT_VEC(13)
#define CODE_VDSP_1_IRQ			VIC1_INT_VEC(14)
#define CODE_VDSP_2_IRQ			VIC1_INT_VEC(15)
#define CODE_VDSP_3_IRQ			VIC1_INT_VEC(16)
#define GPIO3_IRQ			VIC1_INT_VEC(17)
#define GPIO2_IRQ			VIC1_INT_VEC(18)
#define GPIO1_IRQ			VIC1_INT_VEC(19)
#define GPIO0_IRQ			VIC1_INT_VEC(20)
#define VIN_IRQ				VIC1_INT_VEC(21)
#define VOUT_IRQ			VIC1_INT_VEC(22)
#define ORC_VOUT0_IRQ			VIC1_INT_VEC(23)
#define VDSP_PIP_CODING_IRQ		VIC1_INT_VEC(24)
#define ADC_LEVEL_IRQ			VIC1_INT_VEC(25)
#define HDMI_IRQ			VIC1_INT_VEC(26)
#define WDT_IRQ				VIC1_INT_VEC(27)
#define ETH_PMT_IRQ			VIC1_INT_VEC(28)
#define UART0_IRQ			VIC1_INT_VEC(29)
#define MOTOR_IRQ			VIC1_INT_VEC(30)
#define TIMER8_IRQ			VIC1_INT_VEC(31)

#define PWC_ALRAM			VIC2_INT_VEC(0)
#define ETH_IRQ				VIC2_INT_VEC(1)
#define USB_EHCI_IRQ			VIC2_INT_VEC(2)
#define USB_OHCI_IRQ			VIC2_INT_VEC(3)
#define USBC_IRQ			VIC2_INT_VEC(4)
#define DMA_IRQ				VIC2_INT_VEC(5)
#define DMA_FIOS_IRQ			VIC2_INT_VEC(6)
#define FIOS_ECC_IRQ			VIC2_INT_VEC(7)
#define FIOCMD_IRQ			VIC2_INT_VEC(8)
#define FIODMA_IRQ			VIC2_INT_VEC(9)
#define SD2_IRQ				VIC2_INT_VEC(10) /* SDXC rather than SDIO */
#define SD_IRQ				VIC2_INT_VEC(11)
#define NOR_SPI				VIC2_INT_VEC(12)
#define SSI_MASTER1_IRQ			VIC2_INT_VEC(13)
#define SSI_MASTER0_IRQ			VIC2_INT_VEC(14)
#define SSI_SLAVE_IRQ			VIC2_INT_VEC(15)
#define UART1_IRQ			VIC2_INT_VEC(16)
#define IDC3_IRQ			VIC2_INT_VEC(17)
#define IDC2_IRQ			VIC2_INT_VEC(18)
#define IDC_IRQ				VIC2_INT_VEC(19)
#define IRIF_IRQ			VIC2_INT_VEC(20)
#define I2STX_IRQ			VIC2_INT_VEC(21)
#define I2SRX_IRQ			VIC2_INT_VEC(22)
#define USBVBUS_IRQ			VIC2_INT_VEC(23)
#define USB_DIGITAL_ID_CHANGE_IRQ	VIC2_INT_VEC(24)
#define USB_CONNECT_CHANGE_IRQ		VIC2_INT_VEC(25)
#define USB_CHARGE_IRQ			VIC2_INT_VEC(26)
#define SD2CD_IRQ			VIC2_INT_VEC(27) /* SDXC rather than SDIO */
#define SD0CD_IRQ			VIC2_INT_VEC(28)

/* ==========================================================================*/
#else
#error "Not supported!"
#endif

/* ==========================================================================*/
#define VIRQ_RISING_EDGE	0
#define VIRQ_FALLING_EDGE	1
#define VIRQ_BOTH_EDGES		2
#define VIRQ_LEVEL_LOW		3
#define VIRQ_LEVEL_HIGH		4

#ifndef __ASSEMBLER__

extern void ambvic_sw_set(void __iomem *vic_base, unsigned int vic_irq);
extern void ambvic_sw_clr(void __iomem *vic_base, unsigned int vic_irq);

#endif /* __ASSEMBLER__ */
/* ==========================================================================*/
#endif /* CONFIG_AMBARELLA_VIC */

#endif

