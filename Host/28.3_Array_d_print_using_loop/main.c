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
	uint8_t someData[10] ={0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};

	printf("Content of the Array is:\n");

	for(uint8_t i = 0; i < 10; i++){
		printf("%#x\t",someData[i]);
	}

	printf("\n\n");

	for(uint8_t i = 0; i < 10; i++){
		someData[i]=0x45;
		printf("%#x\t",someData[i]);
	}

	return 0;
}
