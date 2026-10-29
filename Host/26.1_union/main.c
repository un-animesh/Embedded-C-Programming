/*
 * main.c
 *
 *  Created on: 29-Oct-2026
 *      Author: animesh
 */

#include <stdio.h>
#include <stdint.h>

union address{
	uint16_t shortAddr;
	uint32_t longAddr;
};

int main()
{
	union address addr;

	addr.shortAddr = 0x4567;
	addr.longAddr = 0x1234ABCD;

	printf("Short Address %#X\n",addr.shortAddr);
	printf("Long Address %#X\n",addr.longAddr);

	getchar();

	return 0;
}
