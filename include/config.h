/*

The MIT License (MIT)

Copyright (c) 2016 Hubert Denkmair

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.

*
*
* Some board-specific defines here, such as :
* - USB strings
* - LED pin assignments and polarity
* - other special pins to control CAN transceivers.
*
* CAN_S_PIN: Some CAN transceivers (e.g. TJA1050) have a "Silent mode in which the transmitter is disabled";
* enabled with this 'S' pin. If undefined, the corresponding code will be disabled.
*
* TERM_Pin: Add support for an externally controlled terminating resistor
*
*/

#pragma once

#define CAN_QUEUE_SIZE				 (64 * NUM_CAN_CHANNEL)

#define USBD_VID					 0x1d50
#define USBD_PID_FS					 0x606f
#define USBD_LANGID_STRING			 1033
#define USBD_CONFIGURATION_STRING_FS GIT_HASH
#define USBD_INTERFACE_STRING_FS	 "gs_usb interface"

#define USBD_PRODUCT_STRING_FS	 "usb2can3 gs_usb"
#define USBD_MANUFACTURER_STRING "custom"
#define DFU_INTERFACE_STRING_FS	 "usb2can3 firmware upgrade interface"

#define TIM2_CLOCK_SPEED		 48000000
/* 1. 把 CAN 改为 CAN1 */
#define CAN_INTERFACE			 CAN1
#define CAN_INTERFACE2			 CAN2
#define CAN_INTERFACE3			 CAN3

/* 2. 补充收发器控制的占位宏（骗过 legacy.c 编译）*/
/* 如果你的板子真有待机(Standby)引脚或终端电阻切换引脚，填真实的；
   如果没有，就像下面这样随便写一个不用的引脚(比如 PA0)占位即可 */
#define nCANSTBY_Port			 GPIOA
#define nCANSTBY_Pin			 GPIO_PIN_0
#define nCANSTBY_Active_High	 0

#define CAN_S_GPIO_Port			 GPIOA
#define CAN_S_Pin				 GPIO_PIN_0

#define TERM_GPIO_Port			 GPIOA
#define TERM_Pin				 GPIO_PIN_0
#define TERM_Active_High		 0
#define CAN_CLOCK_SPEED			 48000000

#define NUM_CAN_CHANNEL			 3
#define CONFIG_CAN_FILTER		 1

#define LEDRX_GPIO_Port			 GPIOC
#define LEDRX_Pin				 GPIO_PIN_13 /* green */
#define LEDRX_Mode				 GPIO_MODE_OUTPUT_PP
#define LEDRX_Active_High		 1

#define LEDTX_GPIO_Port			 GPIOC
#define LEDTX_Pin				 GPIO_PIN_14 /* blue */
#define LEDTX_Mode				 GPIO_MODE_OUTPUT_PP
#define LEDTX_Active_High		 0
