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

void displayMemberElement(struct dataSet data);

int main(){
	struct dataSet data;
	data.data1 = 0x11;
	data.data2  = 0xFFFFEEEE;
	data.data3 = 0x22;
	data.data4 = 0xABCD;

	/* Parsing the Address */
//	displayMemberElement(&data);

	/* Parsing the value */
	displayMemberElement(data);

	getchar();

	return 0;
}

void displayMemberElement(struct dataSet data)
{
//	printf("data: %X\n",data -> data1);
//	printf("data: %X\n",data -> data2);
//	printf("data: %X\n",data -> data3);
//	printf("data: %X\n",data -> data4);

	printf("data: %X\n",data.data1);
	printf("data: %X\n",data.data2);
	printf("data: %X\n",data.data3);
	printf("data: %X\n",data.data4);
}

