/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Animesh Kumar (STM32F411RE)
 * @brief          : Get input from Keypad(8x8) and print via the SWV
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
#include <stdio.h>

void delay(void)
{
    for (uint32_t i = 0; i < 1000000; i++);
}

int main(void)
{
    uint32_t volatile *const pClkCntrlReg = (uint32_t *)(0x40023800 + 0x30);
    uint32_t volatile *const pGPIOC_moder = (uint32_t *)(0x40020800 + 0x00);
    uint32_t volatile *const pGPIOC_pupdr = (uint32_t *)(0x40020800 + 0x0C);
    uint32_t volatile *const pGPIOC_idr = (uint32_t *)(0x40020800 + 0x10);
    uint32_t volatile *const pGPIOC_odr = (uint32_t *)(0x40020800 + 0x14);

    //	1. Turn on the clock cycle for the GPIOC peripherals
    *pClkCntrlReg |= (1 << 2);

    //	2. Configure PC5,PC6,PC8,PC9 as OUPUT (rows)
    *pGPIOC_moder &= ~((3 << 2 * 5) | (3 << 2 * 6) | (3 << 2 * 8) | (3 << 2 * 9)); // Clear
    *pGPIOC_moder |= ((1 << 2 * 5) | (1 << 2 * 6) | (1 << 2 * 8) | (1 << 2 * 9));  // SET

    //	3. Configure PC0,PC1,PC2,PC3 as INPUT (columns)
    *pGPIOC_moder &= ~(0xFF);

    //	4. Enable internal PUllUPRegister
    *pGPIOC_pupdr &= ~(0xFF); // Clear
    *pGPIOC_pupdr |= (0x55);  // SET to pull up

    while (1)
    {
        //	5. Make all Rows HIGH
        *pGPIOC_odr |= ((1 << 5) | (1 << 6) | (1 << 8) | (1 << 9));

        //	6. Make R1 Low (PC5)
        *pGPIOC_odr &= ~(1 << 5);

        //	Scan columns check c1 PC0 is low or High
        if (!(*pGPIOC_idr & (0x1)))
        {
            printf("1\t\n");
            delay();
        }
        //	Scan columns check c2 PC1 is low or High
        if (!(*pGPIOC_idr & (0x1) << 1))
        {
            printf("2\t\n");
            delay();
        }
        //	Scan columns check c3 PC2 is low or High
        if (!(*pGPIOC_idr & (0x1) << 2))
        {
            printf("3\t\n");
            delay();
        }
        //	Scan columns check c4 PC3 is low or High
        if (!(*pGPIOC_idr & (0x1) << 3))
        {
            printf("A\t\n");
            delay();
        }

        //	5. Make all Rows HIGH
        *pGPIOC_odr |= ((1 << 5) | (1 << 6) | (1 << 8) | (1 << 9));

        //	6. Make R2 Low (PC6)
        *pGPIOC_odr &= ~(1 << 6);
        //	Scan columns check c1 PC0 is low or High
        if (!(*pGPIOC_idr & (0x1)))
        {
            printf("4\t\n");
            delay();
        }
        //	Scan columns check c2 PC1 is low or High
        if (!(*pGPIOC_idr & (0x1) << 1))
        {
            printf("5\t\n");
            delay();
        }
        //	Scan columns check c3 PC2 is low or High
        if (!(*pGPIOC_idr & (0x1) << 2))
        {
            printf("6\t\n");
            delay();
        }
        //	Scan columns check c4 PC3 is low or High
        if (!(*pGPIOC_idr & (0x1) << 3))
        {
            printf("B\t\n");
            delay();
        }
        //	5. Make all Rows HIGH
        *pGPIOC_odr |= ((1 << 5) | (1 << 6) | (1 << 8) | (1 << 9));

        //	6. Make R1 Low (PC8)
        *pGPIOC_odr &= ~(1 << 8);

        //	Scan columns check c1 PC0 is low or High
        if (!(*pGPIOC_idr & (0x1)))
        {
            printf("7\t\n");
            delay();
        }
        //	Scan columns check c2 PC1 is low or High
        if (!(*pGPIOC_idr & (0x1) << 1))
        {
            printf("8\t\n");
            delay();
        }
        //	Scan columns check c3 PC2 is low or High
        if (!(*pGPIOC_idr & (0x1) << 2))
        {
            printf("9\t\n");
            delay();
        }
        //	Scan columns check c4 PC3 is low or High
        if (!(*pGPIOC_idr & (0x1) << 3))
        {
            printf("C\t\n");
            delay();
        }
        //	5. Make all Rows HIGH
        *pGPIOC_odr |= ((1 << 5) | (1 << 6) | (1 << 8) | (1 << 9));

        //	6. Make R1 Low (PC9)
        *pGPIOC_odr &= ~(1 << 9);

        //	Scan columns check c1 PC0 is low or High
        if (!(*pGPIOC_idr & (0x1)))
        {
            printf("*\t\n");
            delay();
        }
        //	Scan columns check c2 PC1 is low or High
        if (!(*pGPIOC_idr & (0x1) << 1))
        {
            printf("0\t\n");
            delay();
        }
        //	Scan columns check c3 PC2 is low or High
        if (!(*pGPIOC_idr & (0x1) << 2))
        {
            printf("#\t\n");
            delay();
        }
        //	Scan columns check c4 PC3 is low or High
        if (!(*pGPIOC_idr & (0x1) << 3))
        {
            printf("D\t\n");
            delay();
        }
    }
}
