/*
 * ambhw/nand_combo.h
 *
 * Author: Cao Rongrong <rrcao@ambarella.com>
 *
 * Copyright (c) 2016 Ambarella, Inc.
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

#ifndef __PLAT_AMBARELLA_NAND_COMBO_H__
#define __PLAT_AMBARELLA_NAND_COMBO_H__

#include <plat/chip.h>

/* ==========================================================================*/

#define FIO_OFFSET			0x2000
#define FIO_BASE			(AHB_BASE + FIO_OFFSET)
#define FIO_REG(x)			(FIO_BASE + (x))

/* Flash I/O Subsystem */
#define FIO_CTRL_OFFSET			0x00
#define FIO_RAW_INT_STATUS_OFFSET	0x04
#define FIO_CTRL2_OFFSET		0x08
#define FIO_INT_ENABLE_OFFSET		0x0C
#define FIO_INT_STATUS_OFFSET		0x10
#define FIO_ECC_RPT_CFG_OFFSET		0xA0
#define FIO_ECC_RPT_STATUS_OFFSET	0xA4
#define FIO_ECC_RPT_STATUS2_OFFSET	0xA8

#define FIO_CTRL_REG			FIO_REG(0x00)
#define FIO_RAW_INT_STATUS_REG		FIO_REG(0x04)
#define FIO_CTRL2_REG			FIO_REG(0x08)
#define FIO_INT_ENABLE_REG		FIO_REG(0x0C)
#define FIO_INT_STATUS_REG		FIO_REG(0x10)
#define FIO_ECC_RPT_CFG_REG		FIO_REG(0xA0)
#define FIO_ECC_RPT_STATUS_REG		FIO_REG(0xA4)
#define FIO_ECC_RPT_STATUS2_REG		FIO_REG(0xA8)

/* NAND Flash Controller */
#define NAND_CTRL_OFFSET		0x120
#define NAND_CMD_OFFSET			0x124
#define NAND_TIMING0_OFFSET		0x128
#define NAND_TIMING1_OFFSET		0x12c
#define NAND_TIMING2_OFFSET		0x130
#define NAND_TIMING3_OFFSET		0x134
#define NAND_TIMING4_OFFSET		0x138
#define NAND_TIMING5_OFFSET		0x13c
#define NAND_STATUS_OFFSET		0x140
#define NAND_ID_OFFSET			0x144
#define NAND_COPY_ADDR_OFFSET		0x148
#define NAND_EXT_CTRL_OFFSET		0x15c
#define NAND_EXT_ID_OFFSET		0x160
#define NAND_TIMING6_OFFSET		0x164

#define NAND_CC_OFFSET			0x170
#define NAND_CC_WORD_OFFSET		0x174
#define NAND_CP_ADDR_H_OFFSET		0x17C
#define NAND_CC_DAT0_OFFSET		0x180
#define NAND_CC_DAT1_OFFSET		0x184
#define NAND_CC_DAT2_OFFSET		0x188
#define NAND_CC_DAT3_OFFSET		0x18C
#define NAND_CC_DAT4_OFFSET		0x190
#define NAND_CC_DAT5_OFFSET		0x194
#define NAND_CC_DAT6_OFFSET		0x198
#define NAND_CC_DAT7_OFFSET		0x19C

#define SPINAND_CTRL_OFFSET		0x1A0
#define SPINAND_CC1_OFFSET		0x1A4
#define SPINAND_CC2_OFFSET		0x1A8
#define SPINAND_DONE_PATTERN_OFFSET	0x1AC
#define SPINAND_ERR_PATTERN_OFFSET	0x1B0
#define SPINAND_TIMING0_OFFSET		0x1C0
#define SPINAND_TIMING1_OFFSET		0x1C4
#define SPINAND_TIMING2_OFFSET		0x1C8
#define SPINAND_TIMING3_OFFSET		0x1CC

#define NAND_CTRL_REG			FIO_REG(0x120)
#define NAND_CMD_REG			FIO_REG(0x124)
#define NAND_TIMING0_REG		FIO_REG(0x128)
#define NAND_TIMING1_REG		FIO_REG(0x12c)
#define NAND_TIMING2_REG		FIO_REG(0x130)
#define NAND_TIMING3_REG		FIO_REG(0x134)
#define NAND_TIMING4_REG		FIO_REG(0x138)
#define NAND_TIMING5_REG		FIO_REG(0x13c)
#define NAND_STATUS_REG			FIO_REG(0x140)
#define NAND_ID_REG			FIO_REG(0x144)
#define NAND_COPY_ADDR_REG		FIO_REG(0x148)
#define NAND_EXT_CTRL_REG		FIO_REG(0x15c)
#define NAND_EXT_ID_REG			FIO_REG(0x160)
#define NAND_TIMING6_REG		FIO_REG(0x164)

#define NAND_CC_REG			FIO_REG(0x170)
#define NAND_CC_WORD_REG		FIO_REG(0x174)
#define NAND_CP_ADDR_H_REG		FIO_REG(0x17C)
#define NAND_CC_DAT0_REG		FIO_REG(0x180)
#define NAND_CC_DAT1_REG		FIO_REG(0x184)
#define NAND_CC_DAT2_REG		FIO_REG(0x188)
#define NAND_CC_DAT3_REG		FIO_REG(0x18C)
#define NAND_CC_DAT4_REG		FIO_REG(0x190)
#define NAND_CC_DAT5_REG		FIO_REG(0x194)
#define NAND_CC_DAT6_REG		FIO_REG(0x198)
#define NAND_CC_DAT7_REG		FIO_REG(0x19C)

#define SPINAND_CTRL_REG		FIO_REG(0x1A0)
#define SPINAND_CC1_REG			FIO_REG(0x1A4)
#define SPINAND_CC2_REG			FIO_REG(0x1A8)
#define SPINAND_DONE_PATTERN_REG	FIO_REG(0x1AC)
#define SPINAND_ERR_PATTERN_REG		FIO_REG(0x1B0)
#define SPINAND_TIMING0_REG		FIO_REG(0x1C0)
#define SPINAND_TIMING1_REG		FIO_REG(0x1C4)
#define SPINAND_TIMING2_REG		FIO_REG(0x1C8)
#define SPINAND_TIMING3_REG		FIO_REG(0x1CC)


/* FDMA Engine */
#define FDMA_SP_MEM_ADDR_OFFSET		0x204
#define FDMA_MN_CTRL_OFFSET		0x300
#define FDMA_MN_MEM_ADDR_OFFSET		0x304
#define FDMA_MN_STATUS_OFFSET		0x30c
#define FDMA_MN_DESC_ADDR_OFFSET	0x380
#define FDMA_DSM_CTRL_OFFSET		0x3a0

#define FDMA_SP_MEM_ADDR_REG		FIO_REG(0x204)
#define FDMA_MN_CTRL_REG		FIO_REG(0x300)
#define FDMA_MN_MEM_ADDR_REG		FIO_REG(0x304)
#define FDMA_MN_STATUS_REG		FIO_REG(0x30c)
#define FDMA_MN_DESC_ADDR_REG		FIO_REG(0x380)
#define FDMA_DSM_CTRL_REG		FIO_REG(0x3a0)

/*
 * Bitwise Definition for Flash I/O Subsystem
 */

/* FIO_CTRL_REG */
#define FIO_CTRL_SKIP_BLANK_ECC		0x00000080
#define FIO_CTRL_ECC_BCH_ENABLE		0x00000040
#define FIO_CTRL_ECC_BCH8		0x00000020 /* this bit is RO */
#define FIO_CTRL_RDERR_STOP		0x00000008
#define FIO_CTRL_RANDOM_READ		0x00000002

/* FIO_CTRL2_REG */
#define FIO_CTRL2_SPINAND		0x00000002

/* FIO_RAW_INT_STATUS_REG */
/* FIO_INT_ENABLE_REG */
/* FIO_INT_STATUS_REG */
#define FIO_INT_ECC_RPT_UNCORR		0x00000020
#define FIO_INT_ECC_RPT_THRESH		0x00000010
#define FIO_INT_AXI_BUS_ERR		0x00000004
#define FIO_INT_SND_LOOP_TIMEOUT	0x00000002
#define FIO_INT_OPERATION_DONE		0x00000001

/* FIO_ECC_RPT_CFG_REG */
#define FIO_ECC_RPT_ERR_NUM_TH(x)	((x) << 16)

/* FIO_ECC_RPT_STATUS_REG */
#define FIO_ECC_RPT_ERR_DET		0x80000000
#define FIO_ECC_RPT_CORR_FAIL		0x40000000
#define FIO_ECC_RPT_CORR_FAIL_OV	0x20000000
#define FIO_ECC_RPT_MAX_ERR_NUM(v)	(((v) >> 20) & 0xf)
#define FIO_ECC_RPT_BLK_ADDR(v)		((v) & 0xffff)

/* FIO_ECC_RPT_STATUS2_REG */
#define FIO_ECC_RPT_UNCORR_BLK_ADDR(v)	((v) & 0xffff)


/*
 * Bitwise Definition for NAND Flash Controller
 */

/* NAND_CTRL_REG */
#define NAND_CTRL_A33_32(x)		((x) << 28)
#define NAND_CTRL_SPARE_ADDR		0x08000000
#define NAND_CTRL_P3			0x01000000
#define NAND_CTRL_I4			0x00800000
#define NAND_CTRL_WAS			0x00000400
#define NAND_CTRL_WP			0x00000200
#define NAND_CTRL_SIZE_8G		0x00000070
#define NAND_CTRL_SIZE_4G		0x00000060
#define NAND_CTRL_SIZE_2G		0x00000050
#define NAND_CTRL_SIZE_1G		0x00000040
#define NAND_CTRL_SIZE_512M		0x00000030
#define NAND_CTRL_SIZE_256M		0x00000020
#define NAND_CTRL_SIZE_128M		0x00000010
#define NAND_CTRL_SIZE_64M		0x00000000

/* NAND_CMD_REG */
#define NAND_CMD_A31_4(x)		((x) & 0xfffffff0)
#define NAND_CMD_CMD(c)			((c) & 0xf)
#define NAND_AMB_CMD_RESET		0x2
#define NAND_AMB_CMD_READID		0xa
#define NAND_AMB_CMD_READSTATUS		0xc
#define NAND_AMB_CMD_READ		0xe
#define NAND_AMB_CMD_PROGRAM		0xf
/* custom command definition, used only by software */
#define NAND_CMD_IS_CC(c)		((c) & 0xf0)
#define NAND_AMB_CMD(c)			(NAND_CMD_IS_CC(c) ? 0 : NAND_CMD_CMD(c))
#define NAND_AMB_CC_RESET		(0x10 | NAND_AMB_CMD_RESET)
#define NAND_AMB_CC_READID		(0x20 | NAND_AMB_CMD_READID)
#define NAND_AMB_CC_READSTATUS		(0x30 | NAND_AMB_CMD_READSTATUS)
#define NAND_AMB_CC_ERASE		(0x40)
#define NAND_AMB_CC_READ		(0x50 | NAND_AMB_CMD_READ)
#define NAND_AMB_CC_PROGRAM		(0x60 | NAND_AMB_CMD_PROGRAM)
#define NAND_AMB_CC_GETFEATURE		(0x70)
#define NAND_AMB_CC_SETFEATURE		(0x80)
#define NAND_AMB_CC_READ_PARAM		(0xec)

/* NAND_EXT_CTRL_REG */
#define NAND_EXT_CTRL_4K_PAGE		0x02000000
#define NAND_EXT_CTRL_DEV_SZ3		0x01000000
#define NAND_EXT_CTRL_I5		0x00800000
#define NAND_EXT_CTRL_SPARE_2X		0x00000001

/* NAND_CC_REG */
#define NAND_CC_TERMINATE_CE		0x80000000
#define NAND_CC_DATA_SRC_DMA		0x00400000
#define NAND_CC_ADDR2_NI		0x00080000
#define NAND_CC_ADDR1_NI		0x00040000
#define NAND_CC_ADDR_SRC(x)		((x) << 16)
#define NAND_CC_CMD1(x)			((x) << 14)
#define NAND_CC_ADDR_CYCLE(x)		((x) << 11)
#define NAND_CC_CMD2(x)			((x) << 9)
#define NAND_CC_RW_READ			0x00000100
#define NAND_CC_RW_WRITE		0x00000080
#define NAND_CC_WAIT_RB			0x00000020
#define NAND_CC_WAIT_TWHR		0x00000040
#define NAND_CC_DATA_CYCLE(x)		(((x) - 1) << 0)

/* SPINAND_CTRL_REG */
#define SPINAND_CTRL_SCKMODE_3		0x80000000
#define SPINAND_CTRL_FLOW_CTRL		0x40000000
#define SPINAND_CTRL_PS_SEL_5		0x10000000
#define SPINAND_CTRL_PS_SEL_6		0x20000000
#define SPINAND_CTRL_PS_SEL_7		0x30000000
#define SPINAND_CTRL_PS_SEL_MASK	0x30000000
#define SPINAND_CTRL_MAX_CMD_LOOP	0x0003ffff

/* SPINAND_CC1_REG/SPINAND_CC2_REG */
#define SPINAND_CC1_AUTO_WE		0x80000000 /* SPINAND CC1 only */
#define SPINAND_CC_AUTO_STSCHK		0x40000000
#define SPINAND_CC2_ENABLE		0x04000000 /* SPINAND CC2 only */
#define SPINAND_CC_DATA_SRC_DMA		0x00400000
#define SPINAND_CC_DUMMY_ADDR_NUM(x)	((x) << 19)
#define SPINAND_CC_DUMMY_DATA_NUM(x)	((x) << 16)
#define SPINAND_CC_LANE_TYPE(x)		((x) << 14)
#define SPINAND_CC_ADDR_CYCLE(x)	((x) << 11)
#define SPINAND_CC_ADDR_SRC(x)		((x) << 9)
#define SPINAND_CC_RW_READ		0x00000100
#define SPINAND_CC_RW_WRITE		0x00000080
#define SPINAND_LANE_NUM(x)		(((x) / 2) << 5)
#define SPINAND_CC_DATA_CYCLE(x)	(((x) - 1) << 0) /* non-DMA only */

/* NAND_CC_WORD_REG */
#define NAND_CC_WORD_CMD1VAL0(c)	((c) & 0xff)
#define NAND_CC_WORD_CMD1VAL1(c)	(((c) & 0xff) << 8)
#define NAND_CC_WORD_CMD2VAL0(c)	(((c) & 0xff) << 16)
#define NAND_CC_WORD_CMD2VAL1(c)	(((c) & 0xff) << 24)

/* SPINAND_DONE_PATTERN_REG */
#define SPINAND_DONE_PATTERN		(0x1 << 16)

/* SPINAND_ERR_PATTERN_REG */
#define SPINAND_ERR_PATTERN			((0x2c << 16) | 0x2c)
#define SPINAND_PRG_ERR_PATTERN		((0x8 << 16) | 0x8)
#define SPINAND_READ_ERR_PATTERN	((0x20 << 16) | 0x20)
#define SPINAND_ERASE_ERR_PATTERN	((0x4 << 16) | 0x4)

/*
 * Bitwise Definition for FDMA Engine
 */

/* FDMA_MN_CTRL_REG */
#define FDMA_CTRL_ENABLE		0x80000000
#define FDMA_CTRL_DESC_MODE		0x40000000
#define FDMA_CTRL_WRITE_MEM		0x20000000
#define FDMA_CTRL_READ_MEM		0x00000000
#define FDMA_CTRL_BLK_SIZE_32B		0x02000000
#define FDMA_CTRL_BLK_SIZE_64B		0x03000000
#define FDMA_CTRL_BLK_SIZE_128B		0x04000000
#define FDMA_CTRL_BLK_SIZE_256B		0x05000000
#define FDMA_CTRL_BLK_SIZE_512B		0x06000000
#define FDMA_CTRL_BLK_SIZE_1024B	0x07000000

/* FDMA_MN_STATUS_REG */
#define FDMA_STATUS_DESC_BUS_ERR	0x40000000
#define FDMA_STATUS_DESC_ADDR_ERR	0x20000000
#define FDMA_STATUS_DESC_DMA_DONE	0x10000000
#define FDMA_STATUS_DESC_1ST_DONE	0x08000000
#define FDMA_STATUS_DMA_BUS_ERR		0x02000000
#define FDMA_STATUS_DMA_ADDR_ERR	0x00800000
#define FDMA_STATUS_DMA_DONE		0x00400000
#define FDMA_STATUS_XFER_COUNT(n)	((n) & 0x003fffff)

/* FDMA_DSM_CTRL_REG */
#define FDMA_DSM_SPARE_JP_SIZE_16B	0x04
#define FDMA_DSM_SPARE_JP_SIZE_32B	0x05
#define FDMA_DSM_SPARE_JP_SIZE_64B	0x06
#define FDMA_DSM_SPARE_JP_SIZE_128B	0x07
#define FDMA_DSM_SPARE_JP_SIZE_256B	0x08
#define FDMA_DSM_MAIN_JP_SIZE_512B	0x90
#define FDMA_DSM_MAIN_JP_SIZE_2KB	0xb0
#define FDMA_DSM_MAIN_JP_SIZE_4KB	0xc0

/* ==========================================================================*/

#define SPINAND_CMD_RESET		0xff
#define SPINAND_CMD_GET_FEATURE		0x0f
#define SPINAND_CMD_SET_FEATURE		0x1f
#define SPINAND_CMD_PAGE_READ		0x13
#define SPINAND_CMD_READ_CACHE		0x03
#define SPINAND_CMD_READ_CACHE_X2	0x3b
#define SPINAND_CMD_READ_CACHE_X4	0x6b
#define SPINAND_CMD_BLK_ERASE		0xd8
#define SPINAND_CMD_PROG_EXEC		0x10
#define SPINAND_CMD_PROG_LOAD		0x02
#define SPINAND_CMD_PROG_LOAD_X4	0x32
#define SPINAND_CMD_READ_ID		0x9f
#define SPINAND_CMD_WR_DISABLE		0x04
#define SPINAND_CMD_WR_ENABLE		0x06


/* ==========================================================================*/

/* NAND_TIM0_REG (NAND mode) */
#define NAND_TIM0_TCLS(x)		((x) << 24)
#define NAND_TIM0_TALS(x)		((x) << 16)
#define NAND_TIM0_TCS(x)		((x) << 8)
#define NAND_TIM0_TDS(x)		(x)

/* NAND_TIM1_REG (NAND mode) */
#define NAND_TIM1_TCLH(x)		((x) << 24)
#define NAND_TIM1_TALH(x)		((x) << 16)
#define NAND_TIM1_TCH(x)		((x) << 8)
#define NAND_TIM1_TDH(x)		(x)

/* NAND_TIM2_REG (NAND mode) */
#define NAND_TIM2_TWP(x)		((x) << 24)
#define NAND_TIM2_TWH(x)		((x) << 16)
#define NAND_TIM2_TWB(x)		((x) << 8)
#define NAND_TIM2_TRR(x)		(x)

/* NAND_TIM3_REG (NAND mode) */
#define NAND_TIM3_TRP(x)		((x) << 24)
#define NAND_TIM3_TREH(x)		((x) << 16)
#define NAND_TIM3_TRB(x)		((x) << 8)
#define NAND_TIM3_TCEH(x)		(x)

/* NAND_TIM4_REG (NAND mode) */
#define NAND_TIM4_TRDELAY(x)		((x) << 24)
#define NAND_TIM4_TCLR(x)		((x) << 16)
#define NAND_TIM4_TWHR(x)		((x) << 8)
#define NAND_TIM4_TIR(x)		(x)

/* NAND_TIM5_REG (NAND mode) */
#define NAND_TIM5_TWW(x)		((x) << 16)
#define NAND_TIM5_TRHZ(x)		((x) << 8)
#define NAND_TIM5_TAR(x)		(x)

/* NAND_TIM6_REG (NAND mode) */
#define NAND_TIM6_TRHW(x)		((x) << 16)
#define NAND_TIM6_TADL(x)		((x) << 8)
#define NAND_TIM6_TCRL(x)		(x)

/* ==========================================================================*/

#endif

