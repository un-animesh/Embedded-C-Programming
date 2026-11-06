/*
 * main.c
 *
 *  Created on: 02-Nov-2026
 *      Author: animesh
 */

#include<stdio.h>
#include<stdint.h>

int main()
{
//	int len = 10;
	/*VLA = Variable length Array*/
//	uint8_t someData[len];
	uint8_t someData[10] ={0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};

	printf("Before: 2nd data item= %#X\n",*(someData+1));

//	*(someData+1) = 0x91;
	someData[1]=0x91;

	printf("After: 2nd data item= %#X\n",*(someData+1));

	return 0;
}
