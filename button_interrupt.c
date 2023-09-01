/*
 *  Created on: Aug 21, 2023
 *  @file: button_interrupt.c
 *  @brief: This Code is Written to check the interrupt Functionality Working or Not
 *  @author: Asraful Islam Taj
 */


#include "stm32f103xx.h"

void delay(volatile uint32_t count)
{
    while (count--)
        ;
}

uint8_t Button_Pin = 8;
uint8_t Led_One_Pin = 6;
uint8_t Led_Two_Pin = 13;

int main()
{

    GPIO_Handle_t Button;
    Button.pGPIOx = GPIOB;
    Button.GPIO_PinConfig.GPIO_PinNumber = Button_Pin;
    Button.GPIO_PinConfig.GPIO_PinMode = GPIO_IT_FT;
    Button.GPIO_PinConfig.GPIO_PinConf = GPIO_IN_PUPD;
    Button.GPIO_PinConfig.GPIO_PUPD = PULL_UP;

    GPIO_Handle_t Led_One;
    Led_One.pGPIOx = GPIOB;
    Led_One.GPIO_PinConfig.GPIO_PinNumber = Led_One_Pin;
    Led_One.GPIO_PinConfig.GPIO_PinMode = GPIO_OUTPUT;
    Led_One.GPIO_PinConfig.GPIO_Speed = GPIO_SPEED_HIGH;
    Led_One.GPIO_PinConfig.GPIO_PinConf = GPIO_OUT_PP;

    GPIO_Handle_t Led_Two;
    Led_Two.pGPIOx = GPIOC;
    Led_Two.GPIO_PinConfig.GPIO_PinNumber = Led_Two_Pin;
    Led_Two.GPIO_PinConfig.GPIO_PinMode = GPIO_OUTPUT;
    Led_Two.GPIO_PinConfig.GPIO_Speed = GPIO_SPEED_HIGH;
    Led_Two.GPIO_PinConfig.GPIO_PinConf = GPIO_OUT_PP;

    GPIO_Clock_Control(GPIOB, ENABLE);
    GPIO_Clock_Control(GPIOC, ENABLE);
    GPIO_Init(&Button);
    GPIO_Init(&Led_One);
    GPIO_Init(&Led_Two);

    GPIO_IRQPriorityConfig(IRQ_NO_EXTI9_5, 0);
    GPIO_IRQInterruptConfig(IRQ_NO_EXTI9_5, ENABLE);

    GPIO_Write_Pin(GPIOC, 13, GPIO_HIGH);

    while (1)
    {
        GPIO_Write_Pin(GPIOB, Led_One_Pin, GPIO_LOW);
        delay(1000000);
        GPIO_Write_Pin(GPIOB, Led_One_Pin, GPIO_HIGH);
        delay(1000000);
    }

    return 0;
}

void EXTI9_5_IRQHandler(void)
{
    GPIO_IRQHandling(Button_Pin);
    GPIO_Write_Pin(GPIOC, Led_Two_Pin, GPIO_LOW);
    delay(5000000);
    GPIO_Write_Pin(GPIOC, Led_Two_Pin, GPIO_HIGH);
}
