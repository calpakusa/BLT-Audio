/**
 * \file
 *
 * \brief SAMD20 Xplained PRO board configuration.
 *
 * Copyright (c) 2012-2013 Atmel Corporation. All rights reserved.
 *
 * \asf_license_start
 *
 * \page License
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. The name of Atmel may not be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * 4. This software may only be redistributed and used in connection with an
 *    Atmel microcontroller product.
 *
 * THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * EXPRESSLY AND SPECIFICALLY DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * \asf_license_stop
 *
 */

#ifndef CONF_BOARD_H_INCLUDED
#define CONF_BOARD_H_INCLUDED

#define LED_Phantom		PIN_PA00
#define AIN_Gain		PIN_PA02
#define AIN_PhPower		PIN_PA03
#define UART_RTS		PIN_PA04
#define UART_CTS		PIN_PA05
#define UART_RXD		PIN_PA06
#define UART_TXD		PIN_PA07
#define SPI_CS_AUDIO	PIN_PA08
#define SPI_CS_BLE		PIN_PA09
#define RELE			IOPORT_CREATE_PIN(PORTA, 16)
#define LED_MIC			IOPORT_CREATE_PIN(PORTA, 17)
#define LED_LINE		IOPORT_CREATE_PIN(PORTA, 18)
#define LED_HBEAT		IOPORT_CREATE_PIN(PORTA, 19)
#define SPI_SCK			IOPORT_CREATE_PIN(PORTA, 22)
#define SPI_MOSI		IOPORT_CREATE_PIN(PORTA, 23)
#define SPI_MISO		IOPORT_CREATE_PIN(PORTA, 24)
#define IN_MIC_SEL		IOPORT_CREATE_PIN(PORTA, 25)
#define IN_LINE_SEL		IOPORT_CREATE_PIN(PORTA, 26)

#define APP_TC			TC0

#endif /* CONF_BOARD_H_INCLUDED */
