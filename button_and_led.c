#include "stm32f103xx.h"

void delay(volatile uint32_t count) {
    while (count--);
}

int main() {
	uint16_t LedPin = 7;

    GPIOB_PCLK_EN();

    //Configuring the registers for GPIO Port C
    GPIOB->CRL = 0x00;
    GPIOB->ODR = 0x0C;
    GPIOB->IDR = 0x08;
    GPIOB->BSRR = 0x10;

    //Setting the pin 7 of PORTC as Output
    GPIOB->CRL &= ~(0xF << 28);
    GPIOB->CRL |= (1 << 28);

    //Setting Pin 6 Of PORTC as Input
    GPIOB->CRL &= ~(0xF << 24);
    GPIOB->CRL |= (1 << 27);
    //Setting Pin in PULLUP Mode
    GPIOB->ODR |= (1 << 6);




    while (1) {
    	//COMPARING IF THEY ARE ON OR NOT BY DEFAULT THEY ARE ON SINCE WE ARE USING PULLUP
    	if(GPIOB->IDR & (1 << 6)){
    		//Turing on The LED
    		 GPIOB->BSRR |= (1 << 23);
    	}else{
    		//Turning Off the LED
    		GPIOB->BSRR |= (1 << LedPin);
    	}
    }

    return 0;
}
