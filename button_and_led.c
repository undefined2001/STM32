#include "stm32f103xx.h"

void delay(volatile uint32_t count) {
    while (count--);
}

int main() {
	uint16_t LedPin = 13;
	uint16_t ButtonPin = 6;


    GPIO_Handle_t GPIOPORTC;
    GPIOPORTC.pGPIOx = GPIOC;
    GPIOPORTC.GPIO_PinConfig.GPIO_PinNumber = LedPin;
    GPIOPORTC.GPIO_PinConfig.GPIO_PinMode = GPIO_OUTPUT_HIGH_SPEED;
    GPIOPORTC.GPIO_PinConfig.GPIO_PinConf = GPIO_OUT_PP;


    GPIO_Handle_t GPIOPORTB;
    GPIOPORTB.pGPIOx = GPIOB;
    GPIOPORTB.GPIO_PinConfig.GPIO_PinNumber = ButtonPin;
    GPIOPORTB.GPIO_PinConfig.GPIO_PinMode = GPIO_INPUT;
    GPIOPORTB.GPIO_PinConfig.GPIO_PinConf = GPIO_IN_PUPD;
    GPIOPORTB.GPIO_PinConfig.GPIO_PUPD = PULL_UP;


    GPIO_Clock_Control(GPIOB, ENABLE);
    GPIO_Clock_Control(GPIOC, ENABLE);
    GPIO_Init(&GPIOPORTB);
    GPIO_Init(&GPIOPORTC);




    while (1) {
    	if(GPIO_Read_Pin(GPIOB, ButtonPin)){
    		GPIO_Write_Pin(GPIOC, LedPin, GPIO_HIGH);
    	}else{
    		GPIO_Write_Pin(GPIOC, LedPin, GPIO_LOW);
    	}
    }

    return 0;
}
