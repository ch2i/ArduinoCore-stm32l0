/*
 * Copyright (c) 2017-2018 Thomas Roell.  All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal with the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 *  1. Redistributions of source code must retain the above copyright notice,
 *     this list of conditions and the following disclaimers.
 *  2. Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimers in the
 *     documentation and/or other materials provided with the distribution.
 *  3. Neither the name of Thomas Roell, nor the names of its contributors
 *     may be used to endorse or promote products derived from this Software
 *     without specific prior written permission.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
 * CONTRIBUTORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * WITH THE SOFTWARE.
 */

#ifndef _VARIANT_CH2I_MURATA_STM32L082CZ_
#define _VARIANT_CH2I_MURATA_STM32L082CZ_

/*----------------------------------------------------------------------------
 *        Definitions
 *----------------------------------------------------------------------------*/

#define STM32L0_CONFIG_LSECLK             32768
#define STM32L0_CONFIG_HSECLK             0
#define STM32L0_CONFIG_SYSOPT             0

#define STM32L0_CONFIG_PIN_VBUS           STM32L0_GPIO_PIN_PA8

#define STM32L0_CONFIG_PIN_VBAT           STM32L0_GPIO_PIN_PA5
#define STM32L0_CONFIG_CHANNEL_VBAT       STM32L0_ADC_CHANNEL_5
#define STM32L0_CONFIG_VBAT_PERIOD        40
#define STM32L0_CONFIG_VBAT_SCALE         ((float)1.27)

#define STM32L0_CONFIG_PIN_GNSS_ENABLE    STM32L0_GPIO_PIN_PB2
#define STM32L0_CONFIG_PIN_GNSS_BACKUP    STM32L0_GPIO_PIN_PA4
#define STM32L0_CONFIG_PIN_GNSS_PPS       STM32L0_GPIO_PIN_PB7
#define STM32L0_CONFIG_PIN_GNSS_RX        STM32L0_GPIO_PIN_PA10_USART1_RX
#define STM32L0_CONFIG_PIN_GNSS_TX        STM32L0_GPIO_PIN_PA9_USART1_TX

#define USBCON

/** Master clock frequency */
#define VARIANT_MCK                       F_CPU

/*----------------------------------------------------------------------------
 *        Headers
 *----------------------------------------------------------------------------*/

#ifdef __cplusplus
#include "USBAPI.h"
#include "Uart.h"
#endif // __cplusplus

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

/*----------------------------------------------------------------------------
 *        Pins
 *----------------------------------------------------------------------------*/

// Number of pins defined in PinDescription array
#define PINS_COUNT           (25u)
#define NUM_DIGITAL_PINS     (16u)
#define NUM_ANALOG_INPUTS    (5u)
#define NUM_ANALOG_OUTPUTS   (2u)

// LEDs
#define PIN_LED_10           (10u)

#define PIN_LED              PIN_LED_10
#define LED_BUILTIN          PIN_LED_10

/*
 * Analog pins
 */
#define PIN_A0               (16ul)
#define PIN_A1               (17ul)
#define PIN_A2               (18ul)
#define PIN_A3               (19ul)
#define PIN_A4               (20ul)
#define PIN_DAC0             (16ul)
#define PIN_DAC1             (17ul)

static const uint8_t A0  = PIN_A0;
static const uint8_t A1  = PIN_A1;
static const uint8_t A2  = PIN_A2;
static const uint8_t A3  = PIN_A3;
static const uint8_t A4  = PIN_A4;
static const uint8_t DAC0 = PIN_DAC0;
static const uint8_t DAC1 = PIN_DAC1;

#define ADC_RESOLUTION          12
#define DAC_RESOLUTION          12

/*
 * Serial interfaces
 */

#define SERIAL_INTERFACES_COUNT 4

#define PIN_SERIAL1_RX       (0ul)
#define PIN_SERIAL1_TX       (1ul)

#define PIN_SERIAL2_RX       (19ul)
#define PIN_SERIAL2_TX       (18ul)

#define PIN_SERIAL3_RX       (8ul)
#define PIN_SERIAL3_TX       (9ul)

/*
 * Wire Interfaces
 */
#define WIRE_INTERFACES_COUNT 1

#define PIN_WIRE_SDA         (14u)
#define PIN_WIRE_SCL         (15u)

static const uint8_t SDA = PIN_WIRE_SDA;
static const uint8_t SCL = PIN_WIRE_SCL;

/*
 * USB Interface
 */
#define PIN_USB_DM           (22ul)
#define PIN_USB_DP           (23ul)
#define PIN_USB_VBUS         (24ul)

#define PWM_INSTANCE_COUNT    2

#ifdef __cplusplus
}
#endif

/*----------------------------------------------------------------------------
 *        Arduino objects - C++ only
 *----------------------------------------------------------------------------*/

#ifdef __cplusplus
extern CDC  SerialUSB;
extern Uart Serial1;
extern Uart Serial2;
extern Uart Serial3;
#endif

// These serial port names are intended to allow libraries and architecture-neutral
// sketches to automatically default to the correct port name for a particular type
// of use.  For example, a GPS module would normally connect to SERIAL_PORT_HARDWARE_OPEN,
// the first hardware serial port whose RX/TX pins are not dedicated to another use.
//
// SERIAL_PORT_MONITOR        Port which normally prints to the Arduino Serial Monitor
//
// SERIAL_PORT_USBVIRTUAL     Port which is USB virtual serial
//
// SERIAL_PORT_LINUXBRIDGE    Port which connects to a Linux system via Bridge library
//
// SERIAL_PORT_HARDWARE       Hardware serial port, physical RX & TX pins.
//
// SERIAL_PORT_HARDWARE_OPEN  Hardware serial ports which are open for use.  Their RX & TX
//                            pins are NOT connected to anything by default.
#define SERIAL_PORT_USBVIRTUAL      SerialUSB
#define SERIAL_PORT_MONITOR         SerialUSB
#define SERIAL_PORT_GNSS            Serial1
#define SERIAL_PORT_HARDWARE1       Serial1
#define SERIAL_PORT_HARDWARE2       Serial2
#define SERIAL_PORT_HARDWARE3       Serial3
#define SERIAL_PORT_HARDWARE_OPEN2  Serial2
#define SERIAL_PORT_HARDWARE_OPEN3  Serial3

// Alias Serial to SerialUSB
#define Serial                      SerialUSB

#ifdef LED_BUILTIN
#undef LED_BUILTIN 
#endif
#define LED_BUILTIN (13u)
#define LED_RED     (13u)

#if defined (BOARD_V10)
#define LED_GRN     (9u)
#define LED_BLU     (8u)
#define BAT_ENABLE  (2u)
#define ONEWIREBUS 4
#define ONEWIREPWR 3
#elif defined (BOARD_V10a)
#define LED_GRN     A3
#define LED_BLU     A2
#define BAT_ENABLE  (10u)
#define ONEWIREBUS 4
#define ONEWIREPWR 3
#elif defined (BOARD_ED_V10)
#define LED_GRN     	A3
#define LED_BLU     	A2
#define BAT_ENABLE  	(10u)
#define ONEWIREBUS 4
#define ONEWIREPWR 5
#define BAT_ANALOG_EXT  A0
#endif

#define BTN_ACTION  (2u)
#define BAT_ANALOG 	A1

#define LORA_DIO4   (11u) // D11

#endif /* _VARIANT_CH2I_MURATA_STM32L082CZ_ */
