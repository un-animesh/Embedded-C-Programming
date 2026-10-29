/*
 * main.c
 *
 *  Created on: 26-Oct-2026
 *      Author: animesh
 */


#include<stdio.h>
#include<stdint.h>

struct packet{
	uint8_t crc;
	uint8_t status;
	uint16_t payload;
	uint8_t battery;
	uint8_t sensor;
	uint8_t Long_Address;
	uint8_t Short_Address;
	uint8_t Address_Mode;
}__attribute__((packed));

void wait_for_user_input (void);

int main()
{
	uint32_t packetValue;
	printf("Enter the value in 32bits:\n");
	scanf("%X",&packetValue);


	struct packet packetdata;

	packetdata.crc 				= 	(uint8_t)(packetValue & 0x3); 			// 2 bit
	packetdata.status			=	(uint8_t)((packetValue >> 2) & 0x1);	// 1 bit
	packetdata.payload			=	(uint16_t)((packetValue >> 3) & 0xFFF); // 12 bit
	packetdata.battery			=	(uint8_t)((packetValue >> 15) & 0x7);	// 3 bit
	packetdata.sensor			=	(uint8_t)((packetValue >> 18) & 0x7);	// 3 bit
	packetdata.Long_Address		=	(uint8_t)((packetValue >> 21) & 0xFF);	// 8 bit
	packetdata.Short_Address	=	(uint8_t)((packetValue >> 29) & 0x3);	// 2 bit
	packetdata.Address_Mode		=	(uint8_t)((packetValue >> 31) & 0x1);	// 1 bit

	printf("CRC = %#X\n",packetdata.crc);
	printf("Status = %#X\n",packetdata.status);
	printf("Payload = %#X\n",packetdata.payload);
	printf("Battery = %#X\n",packetdata.battery);
	printf("Sensor = %#X\n",packetdata.sensor);
	printf("Long Address = %#X\n",packetdata.Long_Address);
	printf("Short Address = %#X\n",packetdata.Short_Address);
	printf("Address Mode = %#X\n",packetdata.Address_Mode);

	printf("Size of structure is: %ld",sizeof(packetdata));
	wait_for_user_input();
	return 0;
}

void wait_for_user_input (void)
{
	printf("\nPress enter to exit\n");
	while(getchar() != '\n');
}
