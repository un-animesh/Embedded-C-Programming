/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Animesh (STM32F411RE)
 * @brief          : Here we can understand the packed and unpacked data storages
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2026 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include<stdio.h>
#include<stdint.h>

struct updataSet{		//Unpacked Dataset
	char data1;
	int data2;
	char data3;
	short data4;
};

struct pdataSet{		//Packed Dataset
	char data5;
	int data6;
	char data7;
	short data8;
}__attribute__((packed));

struct updataSet dataup;

struct pdataSet datap;

int main(){

	/* Unpacked Data set */
	dataup.data1 	= 0x11;
	dataup.data2  	= 0xFFFFEEEE;
	dataup.data3 	= 0x22;
	dataup.data4 	= 0xABCD;

	/* Packed Data set */
	datap.data5 	= 0x11;
	datap.data6  	= 0xFFFFEEEE;
	datap.data7 	= 0x22;
	datap.data8 	= 0xABCD;

	/* View in disassembly */

	for (;;);
}
