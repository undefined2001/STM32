/*
 * stm32f103xx_driver.h
 *
 *  Created on: Aug 21, 2023
 *      Author: Asraful Islam Taj
 */

#ifndef INC_STM32F103XX_GPIO_H_
#define INC_STM32F103XX_GPIO_H_
#include "stm32f103xx.h"

#define ENABLE                      1
#define DISABLE                     0
#define SET                         1
#define RESET                       0

//This are for Mode
#define GPIO_INPUT                  0
#define GPIO_OUTPUT_MEDIUM_SPEED    1
#define GPIO_OUTPUT_LOW_SPEED       2
#define GPIO_OUTPUT_HIGH_SPEED      3

//This Configuration Only Applies in Input Mode
#define GPIO_IN_ANALOGE_MODE        0
#define GPIO_IN_FLOATING_INPUT      1
#define GPIO_IN_PUPD                2

//This Configuration Applies in Output Mode
#define GPIO_OUT_PP                 0
#define GPIO_OUT_OD                 1
#define AFIO_OUT_PP                 2
#define AFIO_OUT_OD                 3



//Value to Write in GPIO Pin
#define GPIO_HIGH                   1
#define GPIO_LOW                    0


//Pull Up and Pull down
#define PULL_DOWN                   0
#define PULL_UP                     1

typedef struct{
	uint8_t GPIO_PinNumber;
	uint8_t GPIO_PinMode;
	uint8_t GPIO_PinConf;
	uint8_t GPIO_PUPD;
}GPIO_PinConfig_t;


typedef struct{
	GPIO_RegDef_t * pGPIOx;
	GPIO_PinConfig_t GPIO_PinConfig;
}GPIO_Handle_t;


//Init and Deinit
void GPIO_Init(GPIO_Handle_t *pGPIOhandle);
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx);

//CLock Control
void GPIO_Clock_Control(GPIO_RegDef_t *pGPIOx, uint8_t value);

//Read and Write
uint8_t GPIO_Read_Pin(GPIO_RegDef_t *pGPIOx, uint8_t pinNumber);

uint8_t GPIO_Read_Port(GPIO_RegDef_t *pGPIOx);


void GPIO_Write_Pin(GPIO_RegDef_t *pGPIOx, uint8_t pinNumber, uint8_t Value);
void GPIO_Write_Port(GPIO_RegDef_t *pGPIOx, uint8_t Value);
void GPIO_Toggle_Pin(GPIO_RegDef_t *pGPIOx, uint8_t pinNumber);

//Interrupt handling
void GPIO_IRQConfig(void);
void GPIO_IRQHandling(void);

#endif /* INC_STM32F103XX_GPIO_H_ */
