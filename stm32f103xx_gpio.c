/*
 * stm32f103xx.c
 *
 *  Created on: Aug 21, 2023
 *      Author: Asraful Islam Taj
 */

#include "stm32f103xx_gpio.h"

void GPIO_Init(GPIO_Handle_t *pGPIOhandle){
	if(pGPIOhandle->GPIO_PinConfig.GPIO_PinMode > GPIO_INPUT){
		uint8_t temp = pGPIOhandle->GPIO_PinConfig.GPIO_PinNumber / 8;
		uint8_t temp2 = pGPIOhandle->GPIO_PinConfig.GPIO_PinNumber % 8;
		pGPIOhandle->pGPIOx->CR[temp] &= ~(0xF << temp2 * 4);
		pGPIOhandle->pGPIOx->CR[temp] |= (pGPIOhandle->GPIO_PinConfig.GPIO_PinConf + pGPIOhandle->GPIO_PinConfig.GPIO_PinMode) << temp2 * 4;
	}else{

	}

}
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx){

}

//CLock Control
void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnorDi){

};

//Read and Write
uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t pinNumber){
	return 1;
}
uint8_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx){
	return 1;
}
void GPIO_Write(GPIO_RegDef_t *pGPIOx, uint8_t pinNumber, uint8_t Value){
	if(Value == GPIO_HIGH){
		pGPIOx->BSRR |= (1 << pinNumber);
	}else if(Value == GPIO_LOW){
		pGPIOx->BSRR |= (1 << (pinNumber + 16));
	}
}
void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint8_t Value){

}
void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t pinNumber){

}
