/*
 * main.c
 *
 *  Created on: 29-Oct-2026
 *      Author: animesh
 */


#include<stdio.h>
#include<stdint.h>

struct packet
{
	uint32_t crc		:2;
	uint32_t status		:1;
	uint32_t payload	:12;
	uint32_t battery	:3;
	uint32_t sensor		:3;
	uint32_t longAddr	:8;
	uint32_t shortAddr	:2;
	uint32_t addrMode	:1;
};

void wait_for_user ();

int main(){

	uint32_t packet_rData;
	printf("Enter the 32 bit data:\n");
	scanf("%X",&packet_rData);

	struct packet packet_fData;

	packet_fData.crc 		=(uint8_t)(packet_rData & 0x3);
	packet_fData.status		=(uint8_t)(((packet_rData) >> 2) & 0x1);
	packet_fData.payload	=(uint16_t)(((packet_rData) >> 3) & 0xFFF);
	packet_fData.battery	=(uint8_t)(((packet_rData) >> 15) & 0x7);
	packet_fData.sensor		=(uint8_t)(((packet_rData) >> 18) & 0x7);
	packet_fData.longAddr	=(uint8_t)(((packet_rData) >> 21) & 0xFF);
	packet_fData.shortAddr	=(uint8_t)(((packet_rData) >> 29) & 0x3);
	packet_fData.addrMode	=(uint8_t)(((packet_rData) >> 31) & 0x1);

	printf("CRC: %#X\n",packet_fData.crc);
	printf("Status: %#X\n",packet_fData.status);
	printf("Payload: %#X\n",packet_fData.payload);
	printf("Battery: %#X\n",packet_fData.battery);
	printf("Sensor: %#X\n",packet_fData.sensor);
	printf("Long Address: %#X\n",packet_fData.longAddr);
	printf("Short Address: %#X\n",packet_fData.shortAddr);
	printf("Address Mode: %#X\n",packet_fData.addrMode);

	printf("Size of struct is:%d bytes\n",(uint8_t)sizeof(struct packet));

	wait_for_user ();
	return 0;

}

void wait_for_user (void){
	printf("\nPress enter to Exit\n");
	while(getchar() != '\n')
	{
		/*just*/
	}
	getchar();
}
