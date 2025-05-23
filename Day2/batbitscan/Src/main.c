/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2025 STMicroelectronics.
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
    uint32_t *rcc = (uint32_t*) 0x40023844;
    uint32_t *adc1 = (uint32_t*) 0x40012004;
    //bat xung clock
    *rcc |=(1<<8);
    // bat bit so 8
    *adc1 |=(1<<8);
	for(;;);
}
