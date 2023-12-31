/*
 * arch/arm/plat-ambarella/include/mach/io.h
 *
 * Author: Anthony Ginger <hfjiang@ambarella.com>
 *
 * Copyright (C) 2004-2009, Ambarella, Inc.
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

#ifndef __ASM_ARCH_IO_H
#define __ASM_ARCH_IO_H

/* ==========================================================================*/
#include <mach/hardware.h>

/* ==========================================================================*/
#define IO_SPACE_LIMIT		0xffffffff

#define __io(a)			((void __iomem *)(a))
#define __mem_pci(a)		(a)

/* ==========================================================================*/

#ifndef IOMEM
#define IOMEM(x)	((void __force __iomem *)(x))
#endif

/* ==========================================================================*/
#ifndef __ASSEMBLER__

#define amba_writel(r, v)	writel((v), (void __iomem *)(r))
#define amba_readl(r)		readl((void __iomem *)(r))
#define amba_setbitsl(p, mask)	amba_writel((p),(amba_readl(p) | (mask)))
#define amba_clrbitsl(p, mask)	amba_writel((p),(amba_readl(p) & ~(mask)))

#endif /* __ASSEMBLER__ */
/* ==========================================================================*/

#endif

