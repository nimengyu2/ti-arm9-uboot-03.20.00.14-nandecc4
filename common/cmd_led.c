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

int do_led(cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[])
{
	int i, j;
	unsigned temp;

	printf("led test\n");

        // tary, 2011-08-02
        temp = REG(GPIO_BANK4_REG_DIR_ADDR);
        temp &= ~(0x07 << (16 + 7));
        REG(GPIO_BANK4_REG_DIR_ADDR) = temp;

	for (i = 0; i < 4; i++) {
		temp = REG(GPIO_BANK4_REG_OPDATA_ADDR);
		temp ^= (0x07 << (16 + 7));
		for (j = 0; j < 500; j++) {
			udelay(1000);
		}
		REG(GPIO_BANK4_REG_OPDATA_ADDR) = temp;
		printf("led = 0x%.1X\n", ((temp >> 23) & 0x07));
	}

	return 0;
}

U_BOOT_CMD(
	led,	CONFIG_SYS_MAXARGS,	1,	do_led,
	"led",
	"[args..]\n"
);

