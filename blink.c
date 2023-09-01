/*
 *  Created on: Aug 21, 2023
 *  @file: blink.c
 *  @brief: This Code toggle/blink the built-in led
 *  @author: Asraful Islam Taj
 */

//It Will Blnk The Built in led of BLUEPILL on GPIO port C Pin13


#include "stm32f103xx.h"
#define true 1


void delay(volatile uint32_t count){
    while(count){
        count--;
    }
}

int main(void)
{
    //Enabling the clock for GPIO port C
    GPIOC_PCLK_EN();
    //Setting Value For GPIOC Control Register High
    GPIOC->CR[1] = 0x04;
    //Setting Value For GPIOC Output Data Register
    GPIOC->ODR = 0x0C;

    //Cleaning the 4 bits responsible for Pin Configuration
    GPIOC->CR[1] &= ~(0xF << 20);

    //Setting 20th bit as 1 so the bit from 20-24 will be 00001
    //First 2 bit 00 indicate output push/pull and 01 indicate output in 10MHz speed
    GPIOC->CR[1] |= (1 << 20);

    while(true){
        GPIOC->ODR |= (1 << 13);
        delay(500000);
        GPIOC->ODR &= ~(1 << 13);
        delay(500000);
    }

    return 0;
}
