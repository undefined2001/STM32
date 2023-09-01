/*
 * stm32f103xx.h
 *
 *  Created on: Aug 21, 2023
 *  Author: Asraful Islam Taj
 *  Testing GitHub
 */

#ifndef INC_STM32F103XX_H_
#define INC_STM32F103XX_H_
#include<stdint.h>
#define __vo volatile




//Address of Memories
#define FLASH_BASEADDR                0x08000000U
#define SRAM1_BASEADDR                0x20000000U
#define SRAM                          SRAM1_BASEADDR
#define ROM                           0x1FFFF000U

//Address of Peripherals

#define PERIPH_BASEADDR               0x40000000U
#define APB1PERIPH_BASEADDR           PERIPH_BASE
#define APB2PERIPH_BASEADDR           0x40010000U
#define AHBPERIPH_BASEADDR            0x40018000U
#define RCC_BASEADDR                  0x40021000U

//Base Address of peripheral of APB2 BUS

#define GPIOA_BASEADDR               (APB2PERIPH_BASEADDR + 0x0800)
#define GPIOB_BASEADDR				 (APB2PERIPH_BASEADDR + 0x0C00)
#define GPIOC_BASEADDR               (APB2PERIPH_BASEADDR + 0x1000)
#define GPIOD_BASEADDR               (APB2PERIPH_BASEADDR + 0x1400)
#define GPIOE_BASEADDR               (APB2PERIPH_BASEADDR + 0x1800)
#define GPIOF_BASEADDR               (APB2PERIPH_BASEADDR + 0x1C00)
#define GPIOG_BASEADDR               (APB2PERIPH_BASEADDR + 0x2000)

#define USART1_BASEADDR              (APB2PERIPH_BASEADDR + 0x3800)
#define SPI1_BASEADDR                (APB2PERIPH_BASEADDR + 0x3000)
#define EXTI_BASEADDR                (APB2PERIPH_BASEADDR + 0x0400)

//Base Address of Peripherals of APB1 BUS

#define I2C1_BASEADDR                (APB1PERIPH_BASEADDR + 0x5400)
#define I2C2_BASEADDR                (APB1PERIPH_BASEADDR + 0x5800)

#define SPI2_BASEADDR                (APB1PERIPH_BASEADDR + 0x3C00)
#define SPI3_BASEADDR                (APB1PERIPH_BASEADDR + 0x3800)

#define USART2_BASEADDR              (APB1PERIPH_BASEADDR + 0x4400)
#define USART3_BASEADDR              (APB1PERIPH_BASEADDR + 0x4800)
#define UART4_BASEADDR               (APB1PERIPH_BASEADDR + 0x4C00)
#define UART5_BASEADDR               (APB1PERIPH_BASEADDR + 0x5000)





//GPIO Peripherals Structure
typedef struct{
	__vo uint32_t CR[2];   //[0] for control register low [1] for control register high
	__vo uint32_t IDR;
	__vo uint32_t ODR;
	__vo uint32_t BSRR;
	__vo uint32_t BRR;
	__vo uint32_t LCKR;
}GPIO_RegDef_t;

//THis is RCC Struct
typedef struct{
	__vo uint32_t CR;                //OFFSET 0x000
	__vo uint32_t CFGR;              //OFFSET 0x004
	__vo uint32_t CIR;               //OFFSET 0x008
	__vo uint32_t APB2RSTR;          //OFFSET 0x00C
	__vo uint32_t APB1RSTR;          //OFFSET 0x010
	__vo uint32_t AHBENR;            //OFFSET 0x014
	__vo uint32_t APB2ENR;           //OFFSET 0x018
	__vo uint32_t APB1ENR;           //OFFSET 0X01C
	__vo uint32_t BDCR;              //OFFSET 0x020
	__vo uint32_t CSR;               //OFFEST 0x024
	__vo uint32_t AHBSTR;            //OFFEST 0x028
	__vo uint32_t CFGR2;             //OFFEST 0x02C
}RCC_RegDef_t;

//This Struct is For EXTI
typedef struct{
	__vo uint32_t IMR;
	__vo uint32_t EMR;
	__vo uint32_t RTSR;
	__vo uint32_t FTSR;
	__vo uint32_t SWIER;
	__vo uint32_t PR;
}EXTI_RegDef_t;

//GPIO Peripherals Definition
#define GPIOA                        ((GPIO_RegDef_t *)GPIOA_BASEADDR)
#define GPIOB                        ((GPIO_RegDef_t *)GPIOB_BASEADDR)
#define GPIOC                        ((GPIO_RegDef_t *)GPIOC_BASEADDR)
#define GPIOD                        ((GPIO_RegDef_t *)GPIOD_BASEADDR)
#define GPIOE                        ((GPIO_RegDef_t *)GPIOE_BASEADDR)
#define GPIOF                        ((GPIO_RegDef_t *)GPIOF_BASEADDR)
#define GPIOG                        ((GPIO_RegDef_t *)GPIOG_BASEADDR)

//RCC Peripherals Definition
#define RCC                          ((RCC_RegDef_t *)RCC_BASEADDR)


//Clock Enable Macros
#define GPIOA_PCLK_EN()              (RCC->APB2ENR |= (1 << 2))
#define GPIOB_PCLK_EN()              (RCC->APB2ENR |= (1 << 3))
#define GPIOC_PCLK_EN()              (RCC->APB2ENR |= (1 << 4))
#define GPIOD_PCLK_EN()              (RCC->APB2ENR |= (1 << 5))
#define GPIOE_PCLK_EN()              (RCC->APB2ENR |= (1 << 6))

#define SPI1_PCLK_EN()               (RCC->APB2ENR |= (1 << 12))
#define SPI2_PCLK_EN()               (RCC->APB1ENR |= (1 << 14))
#define SPI3_PCLK_EN()               (RCC->APB1ENR |= (1 << 15))

#define I2C1_PCLK_EN()               (RCC->APB1ENR |= (1 << 21))
#define I2C2_PCLK_EN()               (RCC->APB1ENR |= (1 << 22))


#define USART1_PCLK_EN()             (RCC->APB2ENR |= (1 << 14))
#define USART2_PCLK_EN()             (RCC->APB1ENR |= (1 << 17))
#define USART3_PCLK_EN()             (RCC->APB1ENR |= (1 << 18))
#define UART4_PCLK_EN()              (RCC->APB1ENR |= (1 << 19))
#define UART5_PCLK_EN()              (RCC->APB1ENR |= (1 << 20))


//Clock Disable Macros
#define GPIOA_PCLK_DI()         (RCC->APB2ENR &= ~(1 << 2))
#define GPIOB_PCLK_DI()         (RCC->APB2ENR &= ~(1 << 3))
#define GPIOC_PCLK_DI()         (RCC->APB2ENR &= ~(1 << 4))
#define GPIOD_PCLK_DI()         (RCC->APB2ENR &= ~(1 << 5))
#define GPIOE_PCLK_DI()         (RCC->APB2ENR &= ~(1 << 6))

#define SPI1_PCLK_DI()          (RCC->APB2ENR &= ~(1 << 12))
#define SPI2_PCLK_DI()          (RCC->APB1ENR &= ~(1 << 14))
#define SPI3_PCLK_DI()          (RCC->APB1ENR &= ~(1 << 15))

#define I2C1_PCLK_DI()          (RCC->APB1ENR &= ~(1 << 21))
#define I2C2_PCLK_DI()          (RCC->APB1ENR &= ~(1 << 22))

#define USART1_PCLK_DI()        (RCC->APB2ENR &= ~(1 << 14))
#define USART2_PCLK_DI()        (RCC->APB1ENR &= ~(1 << 17))
#define USART3_PCLK_DI()        (RCC->APB1ENR &= ~(1 << 18))
#define UART4_PCLK_DI()         (RCC->APB1ENR &= ~(1 << 19))
#define UART5_PCLK_DI()         (RCC->APB1ENR &= ~(1 << 20))


//EXTI Definition
#define EXTI                    ((EXTI_RegDef_t *)EXTI_BASEADDR)


#include "stm32f103xx_gpio.h"

#endif /* INC_STM32F103XX_H_ */
