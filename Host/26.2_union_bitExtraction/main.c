/*
 * main.c
 *
 *  Created on: 29-Oct-2026
 *      Author: animesh
 */

#include<stdio.h>
#include<stdint.h>

union packet
{
	uint32_t packetVal;

	struct
	{
		uint32_t crc		:2;
		uint32_t status		:1;
		uint32_t payload	:12;
		uint32_t battery	:3;
		uint32_t sensor		:3;
		uint32_t longAddr	:8;
		uint32_t shortAddr	:2;
		uint32_t addrMode	:1;
	}packetData;

};

int main(){

	union packet abcd;
	printf("Enter 32 bit data:\n");
	scanf("%X",&abcd.packetVal);

	printf("CRC : %#X\n",abcd.packetData.crc);
	printf("Status : %#X\n",abcd.packetData.status);
	printf("Payload : %#X\n",abcd.packetData.payload);
	printf("Battery : %#X\n",abcd.packetData.battery);
	printf("Sensor : %#X\n",abcd.packetData.sensor);
	printf("Long Address : %#X\n",abcd.packetData.longAddr);
	printf("Short Address : %#X\n",abcd.packetData.shortAddr);
	printf("Address Mode : %#X\n",abcd.packetData.addrMode);

	getchar();

	return 0;
}

