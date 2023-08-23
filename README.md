# STM32

This is a repository for STM32 Blue Pill bare-metal coding, and the MCU is STM32F103C8T6.

## 1. About GPIO (General Purpose Input Output)

A microcontroller has many GPIO pins and a few GPIO ports. Basically, a GPIO pin refers to a single pin, whereas a GPIO port refers to a group of pins.

**For Example:**  
GPIOB1, GPIOB2, GPIOB3 - Here 1, 2, and 3 are the pin numbers of different pins, but GPIOB is the common port for all 3 pins. For an STM32 MCU, there can be several pins like GPIOA, GPIOB, GPIOC, ..., GPIOH.

## 2. GPIO Registers

### Configuration Registers High/Low (GPIOx_CRL/CRH)

Here CRL controls pin 0-7 and CRH controls pin 8-15. For this microcontroller CRL and CRH consists of 
Two parts each of them is 2 bits.
**For Example**
00 00 here first 2 bits for configuration and second 2 bits for mode
<div style="display:flex;">
<table>
  <tr>
    <th colspan="4" style="text-align:center;">Mode</th>
  </tr>
  <tr>
    <th colspan="2">Value</th>
    <th colspan="2">Definition</th>
  </tr>
  <tr>
    <td colspan="2">00</td>
    <td colspan="2">Input mode (reset state)</td>
  </tr>
  <tr>
    <td colspan="2">01</td>
    <td colspan="2"> Output mode, max speed 10 MHz</td>
  </tr>
  <tr>
    <td colspan="2">10</td>
    <td colspan="2"> Output mode, max speed 2 MHz</td>
  </tr>
  <tr>
    <td colspan="2">11</td>
    <td colspan="2"> Output mode, max speed 50 MHz</td>
  </tr>
</table>
<table>
  <tr>
    <th colspan="8" style="text-align:center;">Configuration</th>
  </tr>
  <tr>
    <th colspan="2">Mode</th>
    <th colspan="2">Value</th>
    <th colspan="2" style="text-align:center;">Definition</th>
  </tr>
   <tr>
    <td rowspan="4">Input</td>
    <td colspan="2">00</td>
    <td colspan="2">Analog Mode</td>
  </tr>
  <tr>
    <td colspan="2">01</td>
    <td colspan="2">Floating input (reset state)</td>
  </tr>
  <tr>
    <td colspan="2">10</td>
    <td colspan="2">Input with pull-up / pull-down</td>
  </tr>
  <tr>
    <td colspan="2">11</td>
    <td colspan="2">Reserved</td>
  </tr>
  <tr>
    <td rowspan="4">Output</td>
    <td colspan="2">00</td>
    <td colspan="2">General purpose output push-pull</td>
  </tr>
  <tr>
    <td colspan="2">01</td>
    <td colspan="2">General purpose output Open-drain</td>
  </tr>
  <tr>
    <td colspan="2">10</td>
    <td colspan="2">Alternate function output Push-pull</td>
  </tr>
  <tr>
    <td colspan="2">11</td>
    <td colspan="2">Alternate function output Open-drain</td>
  </tr>
 
</table>
</div>



### Input Data Register(GPIOx_IDR)

This Register Holds the value of The pin when its input mode. So by reading this register we can check the input value 

### Output Data Register(GPIOx_ODR)

This register is for making a pin high or low also known as push or pull. If we write 1 to a particular bit position the correponding pin will be High State or if we write 0 the corresponding pin will be in Low State

### Bit Set/Reset Register(GPIOx_BSRR)

This Register can do both Set or Reset it consits of 32 bits. First 0-15 bits for Set and secont 16-31 for Reset by writing on 1 the Set bit we can make a pin value High(1) or by writing 1 to the reset bit we can make a pin Low(0). Additionally, if we don't need to do anything we can keep the set and reset bit 0.

### Bit Reset Register(GPIOx_BRR)

This Register is For Reset a Particular GPIO Pin. We can reset(0) a particular pin by Writing 1 to the pin or If we want to do nothing we can keep it 0.

### Configuration Lock Register (GPIOx_LCKR)

The Output Data Register (ODR) allows you to write values to output pins.

