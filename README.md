# STM32

This is a repository for STM32 Blue Pill bare-metal coding, and the MCU is STM32F103C8T6.

## 1. About GPIO (General Purpose Input Output)

A microcontroller has many GPIO pins and a few GPIO ports. Basically, a GPIO pin refers to a single pin, whereas a GPIO port refers to a group of pins.

**For Example:**  
GPIOB1, GPIOB2, GPIOB3 - Here 1, 2, and 3 are the pin numbers of different pins, but GPIOB is the common port for all 3 pins. For an STM32 MCU, there can be several pins like GPIOA, GPIOB, GPIOC, ..., GPIOH.

## 2. GPIO Registers

#### Configuration Registers High/Low (CRL/CRH)

Here CRL controls pin 0-7 and CRH controls pin 8-15. For this microcontroller CRL and CRH consists of 
Two parts each of them is 2 bits.
**For Example**
00 00 here first 2 bits for configuration and second 2 bits for mode
<table>
  <tr>
    <th colspan="2">Mode</th>
    <th colspan="2">Configuration</th>
  </tr>
  <tr>
    <th>Value</th>
    <th>Definition</th>
    <th>Value</th>
    <th>Definition</th>
  </tr>
  <tr>
    <td>...</td>
    <td>...</td>
    <td>...</td>
    <td>...</td>
  </tr>
  <!-- Add more rows as needed -->
</table>

#### Subsection 1

These registers control the behavior of individual pins within a GPIO port.

#### Subsection 2

You can use these registers to set pins as input or output and configure additional features like pull-up/pull-down resistors.

### Data Registers (IDR/ODR)

These registers allow you to read input values from GPIO pins and write output values to GPIO pins.

#### Subsection 1

The Input Data Register (IDR) holds the current state of input pins.

#### Subsection 2

The Output Data Register (ODR) allows you to write values to output pins.

