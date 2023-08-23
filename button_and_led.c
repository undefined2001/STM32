#include "stm32f103xx.h"

void delay(volatile uint32_t count) {
    while (count--);
}

int main() {
	uint16_t LedPin = 13;

    GPIOB_PCLK_EN();
    GPIOC_PCLK_EN();

    //Initialising GPIOB
    GPIOB->CRL = 0x00;
    GPIOB->ODR = 0x0C;
    GPIOB->IDR = 0x08;
    GPIOB->BSRR = 0x10;

    //Initialising GPIOC
    GPIOC->CRH = 0x04;
    GPIOC->ODR = 0x0C;
    GPIOC->BSRR = 0x10;

    //Clearing and Setting the bits for BUILT_IN LED on  GPIOC
    GPIOC->CRH &= ~(0xF << 20);
    GPIOC->CRH |= (1 << 20);

    //Clearing and Setting the bits for BUTTON on Pin6 of GPIOB
    GPIOB->CRL &= ~(0xF << 24);
    GPIOB->CRL |= (1 << 27);

    //Configuring Pull-up
    GPIOB->BSRR |= (1 << 6);




    while (1) {
    	//Checking the input value on GPIOB6
    	if(!(GPIOB->IDR & (1 << 6))){
    		GPIOC->BSRR |= (1 << 29);
    	}else{
    		GPIOC->BSRR |= (1 << LedPin);
    	}
    }

    return 0;
}
