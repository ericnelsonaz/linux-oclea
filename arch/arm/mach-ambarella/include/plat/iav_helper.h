/*
 * arch/arm/plat-ambarella/include/plat/service.h
 *
 * Author: Cao Rongrong <rrcao@ambarella.com>
 *
 * Copyright (C) 2012-2016, Ambarella, Inc.
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

#ifndef __PLAT_AMBARELLA_SERVICE_H
#define __PLAT_AMBARELLA_SERVICE_H

#ifndef __ASSEMBLER__

/*===========================================================================*/

extern void ambcache_clean_range(void *addr, unsigned int size);
extern void ambcache_inv_range(void *addr, unsigned int size);

/*===========================================================================*/

unsigned long get_ambarella_iavmem_phys(void);
unsigned int get_ambarella_iavmem_size(void);

/*===========================================================================*/

extern int ambpriv_i2c_update_addr(const char *name, int bus, int addr);

/*===========================================================================*/

#endif /* __ASSEMBLER__ */

#endif

