/*
 *  Created on: Aug 21, 2023
 *  @file: stm3203xx.h
 *  @brief: This is the MCU specific header file contain all the register info of the MCU
 *  @mcu: STM32F103C8T6
 *  @author: Asraful Islam Taj
 */

#ifndef INC_STM32F103XX_H_
#define INC_STM32F103XX_H_
#include<stdint.h>
#define __vo volatile


//Architecture Related Things

//Here goes NVIC Related Register

#define NO_PR_BITS_IMPLEMENTED        4

#define NVIC_PR_BASE_ADDR             (uint32_t*)0xE000E400

//ISER(Interrupt Set-Enable Register)
#define NVIC_ISER0                    (uint32_t*)0xE000E100
#define NVIC_ISER1                    (uint32_t*)0xE000E104
#define NVIC_ISER2                    (uint32_t*)0xE000E108
#define NVIC_ISER3                    (uint32_t*)0xE000E10C


//ICER(Interrupt Clear-Enable Register
#define NVIC_ICER0                    (uint32_t*)0XE000E180
#define NVIC_ICER1                    (uint32_t*)0XE000E184
#define NVIC_ICER2                    (uint32_t*)0XE000E188
#define NVIC_ICER3                    (uint32_t*)0XE000E18C



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

#define AFIO_BASE_ADDR               APB2PERIPH_BASEADDR

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

//This is AFIO Register Struct
typedef struct{
	__vo uint32_t EVCR;
	__vo uint32_t MAPR;
	__vo uint32_t EXTICR[4];
	__vo uint32_t MAPR2;
}AFIO_RegDef_t;

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
#define AFIO_PCLK_EN()               (RCC->APB2ENR |= (1 << 0))

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


//EXTI(External Interrupt Controller)  Definition
#define EXTI                    ((EXTI_RegDef_t*)EXTI_BASEADDR)

//IRQ(Interrupt Request) Number
#define IRQ_NO_EXTI0            6
#define IRQ_NO_EXTI1            7
#define IRQ_NO_EXTI2            8
#define IRQ_NO_EXTI3            9
#define IRQ_NO_EXTI4            10
#define IRQ_NO_EXTI9_5          23
#define IRQ_NO_EXTI15_10        40

//AFIO(Alternate Function Input Output) Definition
#define AFIO                    ((AFIO_RegDef_t*)AFIO_BASE_ADDR)

#define GPIO_BASE_ADDR_TO_CODE(x) ((x == GPIOA)? 0 :\
		                          (x == GPIOB) ? 1 :\
				                  (x == GPIOC) ? 2 :\
						          (x == GPIOD) ? 3 :\
								  (x == GPIOE) ? 4 :0)


#include "stm32f103xx_gpio.h"

#endif /* INC_STM32F103XX_H_ */
