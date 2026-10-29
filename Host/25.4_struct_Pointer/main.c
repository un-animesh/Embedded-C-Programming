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

	printf("Before: Data.data1 = %X\n",data.data1);

	struct dataSet *pdata;

	pdata = &data;

	pdata -> data1 = 0x55;

	printf("After: Data.data1 = %X\n",data.data1);

	getchar();

	return 0;
}

