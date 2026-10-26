/*
 * main.c
 *
 *  Created on: 26-Oct-2026
 *      Author: animesh
 */

#include<stdio.h>
#include<stdint.h>


struct dataSet{
	char data1;
	int data2;
	char data3;
	short data4;
};
int main(){
	struct dataSet data;
	data.data1 = 0x11;
	data.data2  = 0xFFFFEEEE;
	data.data3 = 0x22;
	data.data4 = 0xABCD;

	uint8_t *ptr;

	ptr = (uint8_t*) &data;     //struct dataSet *

	uint32_t totalSize = sizeof(struct dataSet);

	printf("Memory Address 		Content \n");
	printf("================================\n");

	for (uint8_t i = 0; i <totalSize; i++)
	{
		printf("%u  		 %X\n",ptr ,*ptr);
		ptr++;
	}

	printf("\nTotal Memory consumed by this variable is:%u bits.",totalSize);


	getchar();

	return 0;
}

