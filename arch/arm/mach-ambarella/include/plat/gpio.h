/*
 * arch/arm/plat-ambarella/include/plat/gpio.h
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

#ifndef __PLAT_AMBARELLA_GPIO_H__
#define __PLAT_AMBARELLA_GPIO_H__

#include <plat/chip.h>

/* ==========================================================================*/
#if (CHIP_REV == S2L)
#define GPIO_INSTANCES			4
#define GPIO_MAX_LINES			114
#elif (CHIP_REV == S3L)
#define GPIO_INSTANCES			4
#define GPIO_MAX_LINES			121
#elif (CHIP_REV == S3)
#define GPIO_INSTANCES			7
#define GPIO_MAX_LINES			201
#elif (CHIP_REV == S5)
#define GPIO_INSTANCES			5
#define GPIO_MAX_LINES			132
#elif (CHIP_REV == S5L)
#define GPIO_INSTANCES			5
#define GPIO_MAX_LINES			139
#elif (CHIP_REV == S6LM)
#define GPIO_INSTANCES			3
#define GPIO_MAX_LINES			86
#elif (CHIP_REV == CV1)
#define GPIO_INSTANCES			7
#define GPIO_MAX_LINES			218
#elif (CHIP_REV == CV22)
#define GPIO_INSTANCES			5
#define GPIO_MAX_LINES			160
#elif (CHIP_REV == CV2)
#define GPIO_INSTANCES			6
#define GPIO_MAX_LINES			166
#elif (CHIP_REV == CV25)
#define GPIO_INSTANCES			4
#define GPIO_MAX_LINES			108
#elif (CHIP_REV == CV2FS)
#define GPIO_INSTANCES			4
#define GPIO_MAX_LINES			103
#elif (CHIP_REV == CV28)
#define GPIO_INSTANCES			3
#define GPIO_MAX_LINES			93
#elif (CHIP_REV == CV5)
#define GPIO_INSTANCES			5
#define GPIO_MAX_LINES			139
#else
#error "Not supported!"
#endif

/* ==========================================================================*/
#if (CHIP_REV == S2L) || (CHIP_REV == S3) || (CHIP_REV == S3L) || \
	(CHIP_REV == S5) || (CHIP_REV == S5L)
#define GPIO0_OFFSET			0x9000
#define GPIO1_OFFSET			0xA000
#define GPIO2_OFFSET			0xE000
#define GPIO3_OFFSET			0x10000
#define GPIO4_OFFSET			0x11000
#define GPIO5_OFFSET			0xD000
#define GPIO6_OFFSET			0x14000
#elif (CHIP_REV == CV2FS)
#define GPIO0_OFFSET			0x10000
#define GPIO1_OFFSET			0x11000
#define GPIO2_OFFSET			0x12000
#define GPIO3_OFFSET			0x13000
#elif (CHIP_REV == CV5)
#define GPIO0_OFFSET			0x13000
#define GPIO1_OFFSET			0x14000
#define GPIO2_OFFSET			0x15000
#define GPIO3_OFFSET			0x16000
#define GPIO4_OFFSET			0x17000
#else
#define GPIO0_OFFSET			0x3000
#define GPIO1_OFFSET			0x4000
#define GPIO2_OFFSET			0x5000
#define GPIO3_OFFSET			0x6000
#define GPIO4_OFFSET			0x7000
#define GPIO5_OFFSET			0x8000
#define GPIO6_OFFSET			0x9000
#endif

#define GPIO0_BASE			(APB_BASE + GPIO0_OFFSET)
#define GPIO1_BASE			(APB_BASE + GPIO1_OFFSET)
#define GPIO2_BASE			(APB_BASE + GPIO2_OFFSET)
#define GPIO3_BASE			(APB_BASE + GPIO3_OFFSET)
#define GPIO4_BASE			(APB_BASE + GPIO4_OFFSET)
#define GPIO5_BASE			(APB_BASE + GPIO5_OFFSET)
#define GPIO6_BASE			(APB_BASE + GPIO6_OFFSET)

#define GPIO0_REG(x)			(GPIO0_BASE + (x))
#define GPIO1_REG(x)			(GPIO1_BASE + (x))
#define GPIO2_REG(x)			(GPIO2_BASE + (x))
#define GPIO3_REG(x)			(GPIO3_BASE + (x))
#define GPIO4_REG(x)			(GPIO4_BASE + (x))
#define GPIO5_REG(x)			(GPIO5_BASE + (x))
#define GPIO6_REG(x)			(GPIO6_BASE + (x))

/* ==========================================================================*/
#if (CHIP_REV == S2L) || (CHIP_REV == S3) || (CHIP_REV == S3L) || \
	(CHIP_REV == S5) || (CHIP_REV == S5L)
#define GPIO_PAD_PULL_OFFSET		0x15000
#elif (CHIP_REV == CV1) || (CHIP_REV == CV2)
#define GPIO_PAD_PULL_OFFSET		0x1000
#elif (CHIP_REV == CV5)
#define GPIO_PAD_PULL_OFFSET		0x2f000
#else
#define GPIO_PAD_PULL_OFFSET		0x22000
#endif
#define GPIO_PAD_PULL_BASE		(APB_BASE + GPIO_PAD_PULL_OFFSET)
#define GPIO_PAD_PULL_REG(x)		(GPIO_PAD_PULL_BASE + (x))

#if (CHIP_REV == S2L) || (CHIP_REV == S3) || (CHIP_REV == S3L) || \
	(CHIP_REV == S5) || (CHIP_REV == S5L) || (CHIP_REV == CV1) || \
	(CHIP_REV == CV2)

#define GPIO_PAD_PULL_EN_0_OFFSET	0x80
#define GPIO_PAD_PULL_EN_1_OFFSET	0x84
#define GPIO_PAD_PULL_EN_2_OFFSET	0x88
#define GPIO_PAD_PULL_EN_3_OFFSET	0x8C
#define GPIO_PAD_PULL_EN_4_OFFSET	0x90
#define GPIO_PAD_PULL_EN_5_OFFSET	0x100
#define GPIO_PAD_PULL_EN_6_OFFSET	0x104

#define GPIO_PAD_PULL_DIR_0_OFFSET	0x94
#define GPIO_PAD_PULL_DIR_1_OFFSET	0x98
#define GPIO_PAD_PULL_DIR_2_OFFSET	0x9C
#define GPIO_PAD_PULL_DIR_3_OFFSET	0xA0
#define GPIO_PAD_PULL_DIR_4_OFFSET	0xA4
#define GPIO_PAD_PULL_DIR_5_OFFSET	0x10C
#define GPIO_PAD_PULL_DIR_6_OFFSET	0x110

#define GPIO_PAD_PULL_EN_OFFSET(bank)	((bank) >= 5 ? \
					(0x100 + (((bank) - 5) * 4)) : \
					(0x80 + ((bank) * 4)))
#define GPIO_PAD_PULL_DIR_OFFSET(bank)	((bank) >= 5 ? \
					(0x10C + (((bank) - 5) * 4)) : \
					(0x94 + ((bank) * 4)))

#define GPIO_PAD_PULL_EN_REL_OFFSET(b)	((b)<5 ? (b)*4 : 0x80 + ((b)-5)*4)
#define GPIO_PAD_PULL_DIR_REL_OFFSET(b)	((b)<5 ? 0x14 + (b)*4 : 0x8c + ((b)-5)*4)

#elif (CHIP_REV == CV5)

#define GPIO_PAD_PULL_EN_0_OFFSET	0x68
#define GPIO_PAD_PULL_EN_1_OFFSET	0x6C
#define GPIO_PAD_PULL_EN_2_OFFSET	0x70
#define GPIO_PAD_PULL_EN_3_OFFSET	0x74
#define GPIO_PAD_PULL_EN_4_OFFSET	0x78

#define GPIO_PAD_PULL_DIR_0_OFFSET	0x7C
#define GPIO_PAD_PULL_DIR_1_OFFSET	0x80
#define GPIO_PAD_PULL_DIR_2_OFFSET	0x84
#define GPIO_PAD_PULL_DIR_3_OFFSET	0x88
#define GPIO_PAD_PULL_DIR_4_OFFSET	0x8C

#define GPIO_PAD_PULL_EN_OFFSET(bank)	(0x68 + ((bank) * 4))
#define GPIO_PAD_PULL_DIR_OFFSET(bank)	(0x7C + ((bank) * 4))

#define GPIO_PAD_PULL_EN_REL_OFFSET(b)	((b)*4)
#define GPIO_PAD_PULL_DIR_REL_OFFSET(b)	(0x14 + (b)*4)

#else

#define GPIO_PAD_PULL_EN_0_OFFSET	0x14
#define GPIO_PAD_PULL_EN_1_OFFSET	0x18
#define GPIO_PAD_PULL_EN_2_OFFSET	0x1C
#define GPIO_PAD_PULL_EN_3_OFFSET	0x20
#define GPIO_PAD_PULL_EN_4_OFFSET	0x24
#define GPIO_PAD_PULL_EN_5_OFFSET	0x28
#define GPIO_PAD_PULL_EN_6_OFFSET	0x2C

#define GPIO_PAD_PULL_DIR_0_OFFSET	0x30
#define GPIO_PAD_PULL_DIR_1_OFFSET	0x34
#define GPIO_PAD_PULL_DIR_2_OFFSET	0x38
#define GPIO_PAD_PULL_DIR_3_OFFSET	0x3C
#define GPIO_PAD_PULL_DIR_4_OFFSET	0x40
#define GPIO_PAD_PULL_DIR_5_OFFSET	0x44
#define GPIO_PAD_PULL_DIR_6_OFFSET	0x48

#define GPIO_PAD_PULL_EN_OFFSET(bank)	(0x14 + ((bank) * 4))
#define GPIO_PAD_PULL_DIR_OFFSET(bank)	(0x30 + ((bank) * 4))

#define GPIO_PAD_PULL_EN_REL_OFFSET(b)	((b)*4)
#define GPIO_PAD_PULL_DIR_REL_OFFSET(b)	(0x1c + (b)*4)

#endif

/* ==========================================================================*/
#define GPIO_DATA_OFFSET		0x00
#define GPIO_DIR_OFFSET			0x04
#define GPIO_IS_OFFSET			0x08
#define GPIO_IBE_OFFSET			0x0c
#define GPIO_IEV_OFFSET			0x10
#define GPIO_IE_OFFSET			0x14
#define GPIO_AFSEL_OFFSET		0x18
#define GPIO_RIS_OFFSET			0x1c
#define GPIO_MIS_OFFSET			0x20
#define GPIO_IC_OFFSET			0x24
#define GPIO_MASK_OFFSET		0x28
#define GPIO_ENABLE_OFFSET		0x2c

/* ==========================================================================*/
#define IOMUX_REG0_0_OFFSET		0x00
#define IOMUX_REG0_1_OFFSET		0x04
#define IOMUX_REG0_2_OFFSET		0x08
#define IOMUX_REG1_0_OFFSET		0x0c
#define IOMUX_REG1_1_OFFSET		0x10
#define IOMUX_REG1_2_OFFSET		0x14
#define IOMUX_REG2_0_OFFSET		0x18
#define IOMUX_REG2_1_OFFSET		0x1c
#define IOMUX_REG2_2_OFFSET		0x20
#define IOMUX_REG3_0_OFFSET		0x24
#define IOMUX_REG3_1_OFFSET		0x28
#define IOMUX_REG3_2_OFFSET		0x2c
#define IOMUX_REG4_0_OFFSET		0x30
#define IOMUX_REG4_1_OFFSET		0x34
#define IOMUX_REG4_2_OFFSET		0x38
#define IOMUX_REG5_0_OFFSET		0x3c
#define IOMUX_REG5_1_OFFSET		0x40
#define IOMUX_REG5_2_OFFSET		0x44
#define IOMUX_REG6_0_OFFSET		0x48
#define IOMUX_REG6_1_OFFSET		0x4c
#define IOMUX_REG6_2_OFFSET		0x50
#define IOMUX_CTRL_SET_OFFSET		0xf0
#define IOMUX_REG_OFFSET(bank, n)	(((bank) * 0xc) + ((n) * 4))

#if (CHIP_REV == S2L) || (CHIP_REV == S3) || (CHIP_REV == S3L) || \
	(CHIP_REV == S5) || (CHIP_REV == S5L)
#define IOMUX_OFFSET			0x16000
#elif (CHIP_REV == CV2FS)
#define IOMUX_OFFSET			0xE000
#elif (CHIP_REV == CV5)
#define IOMUX_OFFSET			0x10000
#else
#define IOMUX_OFFSET			0x0000
#endif
#define IOMUX_BASE			(APB_BASE + IOMUX_OFFSET)
#define IOMUX_REG(x)			(IOMUX_BASE + (x))

/* ==========================================================================*/
#define GPIO(x)				(x)

#define GPIO_HIGH			1
#define GPIO_LOW			0

#define GPIO_FUNC_SW_INPUT		0
#define GPIO_FUNC_SW_OUTPUT		1
#define GPIO_FUNC_HW			2

#define GPIO_BANK_SIZE			32
#define AMBGPIO_SIZE			(GPIO_INSTANCES * GPIO_BANK_SIZE)

/* ==========================================================================*/

#define PINID_TO_BANK(p)		((p) >> 5)
#define PINID_TO_OFFSET(p)		((p) & 0x1f)

/* ==========================================================================*/

#ifndef __ASSEMBLER__

/* pins alternate function */
enum amb_pin_altfunc {
	AMB_ALTFUNC_GPIO = 0,
	AMB_ALTFUNC_HW_1,
	AMB_ALTFUNC_HW_2,
	AMB_ALTFUNC_HW_3,
	AMB_ALTFUNC_HW_4,
	AMB_ALTFUNC_HW_5,
};

#endif /* __ASSEMBLER__ */
/* ==========================================================================*/

#endif /* __PLAT_AMBARELLA_GPIO_H__ */

