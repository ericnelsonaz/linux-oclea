/*
 * arch/arm/plat-ambarella/include/plat/pwm.h
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

#ifndef __PLAT_AMBARELLA_PWM_H__
#define __PLAT_AMBARELLA_PWM_H__

#include <plat/chip.h>

/* ==========================================================================*/

#define PWM_INSTANCES			4

#if (CHIP_REV == S2L) || (CHIP_REV == S3) || (CHIP_REV == S3L) || \
	(CHIP_REV == S5) || (CHIP_REV == S5L)
#define PWM0_OFFSET			0x8000
#else
#define PWM0_OFFSET			0x4000
#endif
#define PWM1_OFFSET			0xC000
#define PWM2_OFFSET			0xD000

/* ==========================================================================*/
#define PWM_CONTROL_OFFSET		0x00
#define	PWM_ENABLE_OFFSET		0x04
#define PWM_MODE_OFFSET			0x08
#define PWM_CONTROL1_OFFSET		0x0c

#define PWM_B0_ENABLE_OFFSET		0x04
#define PWM_B1_ENABLE_OFFSET		0x0c
#define PWM_C0_ENABLE_OFFSET		0x14
#define PWM_C1_ENABLE_OFFSET		0x1c
#define PWM_B0_DATA1_OFFSET		0x20
#define PWM_B1_DATA1_OFFSET		0x24
#define PWM_C0_DATA1_OFFSET		0x28
#define PWM_C1_DATA1_OFFSET		0x2c

#define PWM_CLK_SRC_BIT			(0x1 << 31)
#define PWM_INV_EN_BIT			(0x1 << 31)
#define PWM_DIVIDER_MASK		(0x7ffffffe)
#define PWM_PWM_EN_BIT			(0x1)

#define PWM_PWM_TICKS_MAX_BITS		16
#define PWM_ST_TICKS_MAX_BITS		16

#endif /* __PLAT_AMBARELLA_PWM_H__ */

