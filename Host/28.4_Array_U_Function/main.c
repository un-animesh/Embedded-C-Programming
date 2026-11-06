/*
 * main.c
 *
 *  Created on: 05-Nov-2026
 *      Author: animesh
 */

#include<stdio.h>
#include<stdint.h>

void array_display(uint8_t const *const pArray, uint32_t nItem);

int main()
{
	uint8_t someData[10] ={0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};

	for(uint8_t i = 0; i < 10; i++){
		someData[i] = i;
	}

	uint32_t nItem = sizeof(someData) / sizeof(uint8_t);
	array_display(someData + 2, nItem - 2);		//From second elements

	return 0;
}

void array_display(uint8_t const *const pArray, uint32_t nItem)
{
	printf("Content of the Array is:\n");
	for (uint32_t i = 0; i < nItem; i ++)
	{
	printf("%#x\t",pArray [i])	;
	}
}
