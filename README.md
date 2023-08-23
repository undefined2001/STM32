# STM32

This is a repository for STM32 Blue Pill bare-metal coding, and the MCU is STM32F103C8T6.

## 1. About GPIO (General Purpose Input Output)

A microcontroller has many GPIO pins and a few GPIO ports. Basically, a GPIO pin refers to a single pin, whereas a GPIO port refers to a group of pins.

**For Example:**  
GPIOB1, GPIOB2, GPIOB3 - Here 1, 2, and 3 are the pin numbers of different pins, but GPIOB is the common port for all 3 pins. For an STM32 MCU, there can be several pins like GPIOA, GPIOB, GPIOC, ..., GPIOH.

### Control Register CRL/CRH

These registers are for configuring in the desired mode.

**Paragraph 1:**  
These registers are for configuring in the desired mode.
