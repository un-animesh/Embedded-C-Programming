/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Animesh Kumar (Adapted for Nucleo-F411RE User Button PC13)
 * @brief          : Professional implementation of Volatile ISR button handling using PC13.
 ******************************************************************************
 */

#include <stdint.h>
#include <stdio.h>

/* Global shared volatile variables between main code and ISR */
uint8_t volatile g_button_pressed = 0;
uint32_t g_button_press_count = 0;

/* Function Prototype */
 void button_init(void);

/* Peripheral Register Base Addresses and Offsets for STM32F411RE User Button (PC13) */
uint32_t volatile *const pClkCtrlReg           		= (uint32_t*) (0x40023800 + 0x30); // RCC_AHB1ENR (Bit 2 for GPIOC)
uint32_t volatile *const pClkCtrlRegApb2       		= (uint32_t*) (0x40023800 + 0x44); // RCC_APB2ENR (Bit 14 for SYSCFG)
uint32_t volatile *const pGPIOCModeReg         		= (uint32_t*) (0x40020800 + 0x00); // GPIOC_MODER
uint32_t volatile *const pSYSCFG_EXTICR4      		= (uint32_t*) (0x40013800 + 0x14); // SYSCFG_EXTICR4 (for EXTI lines 12-15)
uint32_t volatile *const pEXTIMaskReg          		= (uint32_t*) (0x40013C00 + 0x00); // EXTI_IMR
uint32_t volatile *const pEXTTFallEdgeCtrlReg  		= (uint32_t*) (0x40013C00 + 0x0C); // EXTI_FTSR (Falling edge for active-low button)
uint32_t volatile *const pEXTTIPendReg         		= (uint32_t*) (0x40013C00 + 0x14); // EXTI_PR
uint32_t volatile *const pNVICIRQEnReg1       		= (uint32_t*) 0xE000E104;          // NVIC_ISER1 (Handles IRQ 32-63, EXTI15_10 is IRQ 40)

/**
 * @brief  Main application entry point.
 * @param  None
 * @retval int
 */
int main(void)
{
    button_init();

    while(1)
    {
        /* Disable interrupt temporarily during flag check to ensure atomicity */
        *pEXTIMaskReg &= ~(1 << 13);

        if(g_button_pressed)
        {
            /* Simple software delay for button debouncing */
            for(uint32_t volatile i = 0; i < 500000 / 2; i++);

            g_button_press_count++;
            printf("User Button is pressed : %lu\n",g_button_press_count);

            g_button_pressed = 0;
        }

        /* Enable interrupt back */
        *pEXTIMaskReg |= (1 << 13);
    }
}

/**
 * @brief  Initializes GPIOC Pin 13 as an external interrupt source for the User Button.
 * @param  None
 * @retval None
 */
 void button_init(void)
{
    /* 1. Enable clock for GPIOC peripheral in AHB1 (Bit 2) */
    *pClkCtrlReg |= (1 << 2);

    /* 2. Configure PC13 as Input Mode (MODER13 = 00 -> bits 27:26) */
    *pGPIOCModeReg &= ~(3 << (13 * 2));

    /* 3. Enable clock for SYSCFG in APB2 (Bit 14) */
    *pClkCtrlRegApb2 |= (1 << 14);

    /* 4. Configure SYSCFG EXTI4 to map EXTI Line 13 to Port C (Port C = 2 -> bits 7:4 in EXTICR4) */
    *pSYSCFG_EXTICR4 &= ~(0xF << 4); // Clear bits for EXTI13
    *pSYSCFG_EXTICR4 |=  (0x2 << 4); // Set port C (2) for EXTI13

    /* 5. Configure Falling Edge Trigger for EXTI Line 13 (Since B1 button pulls low on press) */
    *pEXTTFallEdgeCtrlReg |= (1 << 13);

    /* 6. Enable Interrupt Mask for EXTI Line 13 */
    *pEXTIMaskReg |= (1 << 13);

    /* 7. Enable EXTI15_10 interrupt in NVIC (IRQ position 40 -> ISER1 bit 8) */
    *pNVICIRQEnReg1 |= (1 << (40 - 32));
}

/**
 * @brief  Interrupt Service Routine for EXTI Lines 15 to 10 (handles Line 13).
 * @param  None
 * @retval None
 */
void EXTI15_10_IRQHandler(void)
{
    /* Check if the trigger came specifically from EXTI Line 13 */
    if (*pEXTTIPendReg & (1 << 13))
    {
        /* Set flag indicating button press event */
        g_button_pressed = 1;

        /* Clear the pending bit for EXTI Line 13 by writing 1 to it */
        *pEXTTIPendReg |= (1 << 13);
    }
}
