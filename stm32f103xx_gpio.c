/*
 * stm32f103xx.c
 *
 *  Created on: Aug 21, 2023
 *  @author: Asraful Islam Taj
 */

#include "stm32f103xx_gpio.h"


void GPIO_Init(GPIO_Handle_t *pGPIOhandle)
{
    uint8_t temp = (pGPIOhandle->GPIO_PinConfig.GPIO_PinNumber / 8);
    uint8_t temp2 = (pGPIOhandle->GPIO_PinConfig.GPIO_PinNumber % 8);

    pGPIOhandle->pGPIOx->CR[temp] &= ~(0xF << temp2 * 4);
    pGPIOhandle->pGPIOx->CR[temp] |= (pGPIOhandle->GPIO_PinConfig.GPIO_PinConf) << ((temp2 * 4) + 2);

    if (pGPIOhandle->GPIO_PinConfig.GPIO_PUPD == PULL_UP)
    {
         pGPIOhandle->pGPIOx->ODR |= (1 << pGPIOhandle->GPIO_PinConfig.GPIO_PinNumber);
    }
    else if (pGPIOhandle->GPIO_PinConfig.GPIO_PUPD == PULL_DOWN)
    {
         pGPIOhandle->pGPIOx->ODR &= ~(1 << pGPIOhandle->GPIO_PinConfig.GPIO_PinNumber);
    }

    if (pGPIOhandle->GPIO_PinConfig.GPIO_PinMode == GPIO_OUTPUT)
    {
        pGPIOhandle->pGPIOx->CR[temp] |= (pGPIOhandle->GPIO_PinConfig.GPIO_PinMode + pGPIOhandle->GPIO_PinConfig.GPIO_Speed) << (temp2 * 4);
    }
    else
    {
        if (pGPIOhandle->GPIO_PinConfig.GPIO_PinMode == GPIO_IT_FT)
        {
            EXTI->FTSR |= (1 << pGPIOhandle->GPIO_PinConfig.GPIO_PinNumber);
            EXTI->RTSR &= ~(1 << pGPIOhandle->GPIO_PinConfig.GPIO_PinNumber);
        }
        else if (pGPIOhandle->GPIO_PinConfig.GPIO_PinMode == GPIO_IT_RT)
        {
            EXTI->RTSR |= (1 << pGPIOhandle->GPIO_PinConfig.GPIO_PinNumber);
            EXTI->FTSR &= ~(1 << pGPIOhandle->GPIO_PinConfig.GPIO_PinNumber);
        }
        else if (pGPIOhandle->GPIO_PinConfig.GPIO_PinMode == GPIO_IT_FRT)
        {
            EXTI->RTSR |= (1 << pGPIOhandle->GPIO_PinConfig.GPIO_PinNumber);
            EXTI->FTSR |= (1 << pGPIOhandle->GPIO_PinConfig.GPIO_PinNumber);
        }
        uint8_t temp1 = (pGPIOhandle->GPIO_PinConfig.GPIO_PinNumber / 4);
        uint8_t temp2 = (pGPIOhandle->GPIO_PinConfig.GPIO_PinNumber % 4);

        uint8_t portcode = GPIO_BASE_ADDR_TO_CODE(pGPIOhandle->pGPIOx);
        AFIO_PCLK_EN();
        AFIO->EXTICR[temp1] = portcode << (temp2 * 4);
        EXTI->IMR |= (1 << pGPIOhandle->GPIO_PinConfig.GPIO_PinNumber);
    }
}


void GPIO_DeInit(GPIO_RegDef_t *pGPIOx)
{
}

// CLock Control
void GPIO_Clock_Control(GPIO_RegDef_t *pGPIOx, uint8_t value)
{
	if (value == ENABLE)
	{
		if (pGPIOx == GPIOA)
		{
			GPIOA_PCLK_EN();
		}
		else if (pGPIOx == GPIOB)
		{
			GPIOB_PCLK_EN();
		}
		else if (pGPIOx == GPIOC)
		{
			GPIOC_PCLK_EN();
		}
		else if (pGPIOx == GPIOD)
		{
			GPIOD_PCLK_EN();
		}
		else if (pGPIOx == GPIOE)
		{
			GPIOE_PCLK_EN();
		}
	}else if(value == DISABLE){
		if (pGPIOx == GPIOA)
		{
			GPIOA_PCLK_DI();
		}
		else if (pGPIOx == GPIOB)
		{
			GPIOB_PCLK_DI();
		}
		else if (pGPIOx == GPIOC)
		{
			GPIOC_PCLK_DI();
		}
		else if (pGPIOx == GPIOD)
		{
			GPIOD_PCLK_DI();
		}
		else if (pGPIOx == GPIOE)
		{
			GPIOE_PCLK_DI();
		}
	}
};



/*
 * This Function is User to Read Value from a Particular Pin
 * It shifts the value of Corresponding Input Data Registers to LSB and Compare/Mask with
 * 0x00000001 which means all the bits are zero except the 0th(LSB) bit.
 * if value from IDR is 1 then 1 & 1 = 1
 * if value from IDR is 0 then 0 & 1 = 0
 */
uint8_t GPIO_Read_Pin(GPIO_RegDef_t *pGPIOx, uint8_t pinNumber)
{
	uint8_t value = (uint8_t)(pGPIOx->IDR >> pinNumber) & 0x00000001;
	return value;
}
uint8_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx)
{
	return 1;
}



/*
 * This Function Basically Write to an Pin either 0 or 1
 * We can also call that set or reset
 * It writes by manipulating Bit set/reset register since 0 to 15 are
 * set bit and 15 to 31 is reset so by adding 16 to a pin number we can
 * get the corresponding reset bit of a pin
 */

void GPIO_Write_Pin(GPIO_RegDef_t *pGPIOx, uint8_t pinNumber, uint8_t Value)
{
	if (Value == GPIO_HIGH)
	{
		pGPIOx->BSRR |= (1 << pinNumber);
	}
	else if (Value == GPIO_LOW)
	{
		pGPIOx->BSRR |= (1 << (pinNumber + 16));
	}
}

void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint8_t Value)
{
}
void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t pinNumber)
{
}



void GPIO_IRQInterruptConfig(uint8_t IRQ_Number, uint8_t value)
{
    if (value == ENABLE)
    {
        if (IRQ_Number <= 31)
        {
            *NVIC_ISER0 |= (1 << IRQ_Number);
        }
        else if (IRQ_Number > 31 && IRQ_Number < 64)
        {
            *NVIC_ISER1 |= (1 << (IRQ_Number % 32));
        }
        else if (IRQ_Number > 63 && IRQ_Number < 96)
        {
            *NVIC_ISER2 |= (1 << (IRQ_Number % 64));
        }
    }
    else
    {
        if (IRQ_Number <= 31)
        {
            *NVIC_ICER0 |= (1 << IRQ_Number);
        }
        else if (IRQ_Number > 31 && IRQ_Number < 64)
        {
            *NVIC_ICER1 |= (1 << (IRQ_Number % 32));
        }
        else if (IRQ_Number > 63 && IRQ_Number < 96)
        {
            *NVIC_ICER2 |= (1 << (IRQ_Number % 64));
        }
    }
}

void GPIO_IRQPriorityConfig(uint8_t IRQ_Number, uint8_t IRQ_Priority){
	uint8_t iprx = IRQ_Number / 4;
	uint8_t iprx_section = IRQ_Number % 4;
	uint8_t shift_amount =  (iprx_section * 8) + (8 - NO_PR_BITS_IMPLEMENTED);


	*(NVIC_PR_BASE_ADDR + iprx * 4) |= (IRQ_Priority << shift_amount);


}

void GPIO_IRQHandling(uint8_t PinNumber){
	if(EXTI->PR & (1U << PinNumber)){
		EXTI->PR |= (1U << PinNumber);
	}
}









