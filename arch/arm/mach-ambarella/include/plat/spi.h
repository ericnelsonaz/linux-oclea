/*
 * arch/arm/plat-ambarella/include/plat/spi.h
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

#ifndef __PLAT_AMBARELLA_SPI_H__
#define __PLAT_AMBARELLA_SPI_H__

#include <linux/spi/spi.h>
#include <plat/chip.h>

/* ==========================================================================*/
#if (CHIP_REV == S2L) || (CHIP_REV == S3L) || (CHIP_REV == S3) || (CHIP_REV == S5)
#define SPI_AHB_INSTANCES			2
#elif (CHIP_REV == S5L)
#define SPI_AHB_INSTANCES			3
#elif (CHIP_REV == CV1) || (CHIP_REV == CV2FS) || (CHIP_REV == CV5)
#define SPI_AHB_INSTANCES			6
#else
#define SPI_AHB_INSTANCES			4
#endif

#define SPI_AHB_SLAVE_INSTANCES			1

#if (CHIP_REV == S2L) || (CHIP_REV == S3L) || (CHIP_REV == S3) || \
	(CHIP_REV == S5) || (CHIP_REV == S5L)
#define SPI0_OFFSET			0x20000
#define SPI1_OFFSET			0x21000
#define SPI2_OFFSET			0x22000
#define SPI_SLAVE_OFFSET		0x26000
#elif (CHIP_REV == CV2FS)
#define SPI0_OFFSET			0x11000
#define SPI1_OFFSET			0x12000
#define SPI2_OFFSET			0x13000
#define SPI3_OFFSET			0x14000
#define SPI4_OFFSET			0x34000
#define SPI5_OFFSET			0x35000
#define SPI_SLAVE_OFFSET		0x10000
#elif (CHIP_REV == CV5)
#define SPI0_OFFSET			0x11000
#define SPI1_OFFSET			0x12000
#define SPI2_OFFSET			0x13000
#define SPI3_OFFSET			0x14000
#define SPI4_OFFSET			0x25000
#define SPI5_OFFSET			0x26000
#define SPI_SLAVE_OFFSET		0x10000
#else
#define SPI0_OFFSET			0x11000
#define SPI1_OFFSET			0x12000
#define SPI2_OFFSET			0x13000
#define SPI3_OFFSET			0x14000
#define SPI4_OFFSET			0x15000
#define SPI5_OFFSET			0x1C000
#define SPI_SLAVE_OFFSET		0x10000
#endif

#define SPI0_BASE			(AHB_N_BASE + SPI0_OFFSET)
#define SPI1_BASE			(AHB_N_BASE + SPI1_OFFSET)
#define SPI2_BASE			(AHB_N_BASE + SPI2_OFFSET)
#define SPI3_BASE			(AHB_N_BASE + SPI3_OFFSET)
#define SPI4_BASE			(AHB_N_BASE + SPI4_OFFSET)
#define SPI5_BASE			(AHB_N_BASE + SPI5_OFFSET)
#define SPI_SLAVE_BASE			(AHB_N_BASE + SPI_SLAVE_OFFSET)
#define SPI0_REG(x)			(SPI0_BASE + (x))
#define SPI1_REG(x)			(SPI1_BASE + (x))
#define SPI2_REG(x)			(SPI2_BASE + (x))
#define SPI3_REG(x)			(SPI3_BASE + (x))
#define SPI4_REG(x)			(SPI4_BASE + (x))
#define SPI5_REG(x)			(SPI5_BASE + (x))
#define SPI_SLAVE_REG(x)		(SPI_SLAVE_BASE + (x))

/* ==========================================================================*/
#define SPI_MASTER1			0
#define SPI_MASTER2			1
#define SPI_MASTER3			2
#define SPI_MASTER4			3
#define SPI_MASTER5			4
#define SPI_MASTER6			5

/* ==========================================================================*/
/* SPI_FIFO_SIZE */
#define SPI_DATA_FIFO_SIZE_16		0x10
#define SPI_DATA_FIFO_SIZE_32		0x20
#define SPI_DATA_FIFO_SIZE_64		0x40
#define SPI_DATA_FIFO_SIZE_128		0x80

/****************************************************/
/* Controller registers definitions                 */
/****************************************************/

#define SPI_CTRLR0_OFFSET		0x00
#define SPI_CTRLR1_OFFSET		0x04
#define SPI_SSIENR_OFFSET		0x08
#define SPI_MWCR_OFFSET			0x0c // no PRM explain it and no code use it. should be commented after check
#define SPI_SER_OFFSET			0x10
#define SPI_BAUDR_OFFSET		0x14
#define SPI_TXFTLR_OFFSET		0x18
#define SPI_RXFTLR_OFFSET		0x1c
#define SPI_TXFLR_OFFSET		0x20
#define SPI_RXFLR_OFFSET		0x24
#define SPI_SR_OFFSET			0x28
#define SPI_IMR_OFFSET			0x2c
#define SPI_ISR_OFFSET			0x30
#define SPI_RISR_OFFSET			0x34
#define SPI_TXOICR_OFFSET		0x38
#define SPI_RXOICR_OFFSET		0x3c
#define SPI_RXUICR_OFFSET		0x40
#define SPI_MSTICR_OFFSET		0x44	/* clear @CV2FS */
#define SPI_ICR_OFFSET			0x48
#define SPI_DMAC_OFFSET			0x4c
#define SPI_FAULTINJECT_OFFSET		0x50	/* Introduced @CV2FS */
#define SPI_IDR_OFFSET			0x58
#define SPI_VERSION_ID_OFFSET		0x5c
#define SPI_DR_OFFSET			0x60

#define SPI_SSIENPOLR_OFFSET		0x260
#define SPI_SCLK_OUT_DLY_OFFSET		0x264
#define SPI_START_BIT_OFFSET		0x268

/* ==========================================================================*/
/* SPI rw mode */
#define SPI_WRITE_READ		0
#define SPI_WRITE_ONLY		1
#define SPI_READ_ONLY		2

/* SPI enable register */
#define SPI_SSIENR_DISABLE	0
#define SPI_SSIENR_ENABLE	1

/* SPI interrupt mask */
#define SPI_TXEIS_MASK		0x00000001
#define SPI_TXOIS_MASK 		0x00000002
#define SPI_RXUIS_MASK 		0x00000004
#define SPI_RXOIS_MASK 		0x00000008
#define SPI_RXFIS_MASK 		0x00000010
#define SPI_FCRIS_MASK 		0x00000100

/* SPI status register */
#define SPI_SR_BUSY		0x00000001
#define SPI_SR_TFNF		0x00000002
#define SPI_SR_TFE		0x00000004
#define SPI_SR_RFNE		0x00000008
#define SPI_SR_RFF		0x00000010
#define SPI_SR_TXE		0x00000020
#define SPI_SR_DCOL		0x00000040

/* SPI dma enable register */
#define SPI_DMAC_RX_EN		0x1
#define SPI_DMAC_TX_EN		0x2

/* SPI Parameters */
#define SPI_DUMMY_DATA		0xffff
#define MAX_QUERY_TIMES		10
#define SPI_POLLING_MAX_WAIT_LOOP 5000000

/* Default SPI settings */
#define SPI_SCPOL		0
#define SPI_SCPH		0
#define SPI_FRF			0
#define SPI_CFS			0x0
#define SPI_DFS			0xf
#define SPI_BAUD_RATE		200000

/* ==========================================================================*/
typedef union {
	struct {
		u32		dfs	: 4;	/* [3:0] */
		u32		frf	: 2;	/* [5:4] */
		u32		scph	: 1;	/* [6] */
		u32		scpol	: 1;	/* [7] */
		u32		tmod	: 2;	/* [9:8] */
		u32		slv_oe	: 1;	/* [10] */
		u32		srl	: 1;	/* [11] */
		u32		reserv1	: 5;	/* [16:12] */
		u32		residue	: 1;	/* [17] */
		u32		tx_lsb	: 1;	/* [18] */
		u32		rx_lsb	: 1;	/* [19] */
		u32		reserv2	: 1;	/* [20] */
		u32		fc_en	: 1;	/* [21] */
		u32		rxd_mg	: 4;	/* [25:22] */
		u32		byte_ws	: 1;	/* [26] */
		u32		hold	: 1;	/* [27] */
		u32		reserv3	: 4;	/* [31:28] */
	} s;
	u32	w;
} spi_ctrl0_reg_t;

typedef union {
	struct {
		u32		busy	: 1;	/* [0] */
		u32		tfnf	: 1;	/* [1] */
		u32		tfe	: 1;	/* [2] */
		u32		rfne	: 1;	/* [3] */
		u32		rff	: 1;	/* [4] */
		u32		txe	: 1;	/* [5] */
		u32		dcol	: 1;	/* [6] */
		u32		reserve	: 25;	/* [31:7] */
	} s;
	u32	w;
} spi_status_reg_t;

/* ==========================================================================*/

#ifndef __ASSEMBLER__

struct ambarella_spi_cfg_info {
	u8	spi_mode;
	u8	cfs_dfs;
	u8	cs_change;
	u32	baud_rate;
};
typedef struct ambarella_spi_cfg_info amba_spi_cfg_t;

typedef struct {
	u8	bus_id;
	u8	cs_id;
	u8	*buffer;
	u32	n_size;	// u16	n_size;
} amba_spi_write_t;

typedef struct {
	u8	bus_id;
	u8	cs_id;
	u8	*buffer;
	u16	n_size;
} amba_spi_read_t;

typedef struct {
	u8	bus_id;
	u8	cs_id;
	u8	*w_buffer;
	u8	*r_buffer;
	u16	w_size;
	u16	r_size;
} amba_spi_write_then_read_t;

typedef struct {
	u8	bus_id;
	u8	cs_id;
	u8	*w_buffer;
	u8	*r_buffer;
	u16	n_size;
} amba_spi_write_and_read_t;

/* ==========================================================================*/
extern int ambarella_spi_write(amba_spi_cfg_t *spi_cfg,
	amba_spi_write_t *spi_write);
extern int ambarella_spi_read(amba_spi_cfg_t *spi_cfg,
	amba_spi_read_t *spi_read);
extern int ambarella_spi_write_then_read(amba_spi_cfg_t *spi_cfg,
	amba_spi_write_then_read_t *spi_write_then_read);
extern int ambarella_spi_write_and_read(amba_spi_cfg_t *spi_cfg,
	amba_spi_write_and_read_t *spi_write_and_read);

#endif /* __ASSEMBLER__ */
/* ==========================================================================*/

#endif /* __PLAT_AMBARELLA_SPI_H__ */

