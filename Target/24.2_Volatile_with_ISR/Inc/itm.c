/*
 * itm.c
 *
 *  Created on: 24-Oct-2026
 *      Author: animesh
 */


#include <stdint.h>

#define ITM_STIM0 (*(volatile uint32_t *)0xE0000000U)
#define ITM_TER   (*(volatile uint32_t *)0xE0000E00U)
#define ITM_TCR   (*(volatile uint32_t *)0xE0000E80U)

int __io_putchar(int ch)
{
    if ((ITM_TCR & 1U) && (ITM_TER & 1U))
    {
        while (ITM_STIM0 == 0U)
        {
            /* Wait until the stimulus port is ready */
        }

        ITM_STIM0 = (uint32_t)ch;
    }

    return ch;
}


