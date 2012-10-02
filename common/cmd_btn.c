/*
 * Copyright 2000-2009
 * Wolfgang Denk, DENX Software Engineering, wd@denx.de.
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

#include <common.h>
#include <command.h>

int do_button(cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[])
{
	int i;
	unsigned temp;

	printf("button test\n");

        // tary, 2011-08-02
        temp = REG(GPIO_BANK4_REG_DIR_ADDR);
        temp |= (0x07 << (16 + 10));
        REG(GPIO_BANK4_REG_DIR_ADDR) = temp;

	for (i = 0; i < 1; i++) {
		temp = REG(GPIO_BANK4_REG_INDATA_ADDR);
		printf("GPIO = 0x%.1X\n", (~temp >> 26) & 0x7);
		udelay(10000);
	}

	return 0;
}

U_BOOT_CMD(
	button,	CONFIG_SYS_MAXARGS,	1,	do_button,
	"button",
	"[args..]\n"
);

