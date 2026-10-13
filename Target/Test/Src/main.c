/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Animesh Kumar
 * @brief          : This is used for the testing purpose of any code.
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

#include <stdint.h>

int main(void)
{
	uint32_t *pClkCtrlReg = (uint32_t*) 0x40023830;

	uint32_t *pGPIOA_MODER = (uint32_t*) 0x40020000;
	uint32_t *pGPIOA_ODR = (uint32_t*) 0x40020014;

	uint32_t *pGPIOA_IDR = (uint32_t*) 0x40020010;
	uint32_t *pGPIOA_PUPDR = (uint32_t*) 0x4002000C;

//	1. Enable the clock GPIOA peripheral situated in AHB1
	*pClkCtrlReg |=(1 << 0);

//	2. Clear PA5 and set it as Output mode
	*pGPIOA_MODER &= ~(3 << 5*2);	// Clear
	*pGPIOA_MODER |= (1 << 5*2);	// Set

	*pGPIOA_MODER &= ~(3 << 1*2);

	*pGPIOA_PUPDR |=(2 << 1*2);

	while(1)
	{
		if(*pGPIOA_IDR & 0x2)
		{
			*pGPIOA_ODR |= (1 << 5*1);	//PA5 is High
		}
		else
		{
			*pGPIOA_ODR &= ~(1 << 5*1);
		}

	}

}
