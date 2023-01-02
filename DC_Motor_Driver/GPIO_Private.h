/*
 * GPIO_Private.h
 *
 *  Created on: Dec 1, 2022
 *      Author: DELL
 */

#ifndef GPIO_PRIVATE_H_
#define GPIO_PRIVATE_H_


/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define NUM_OF_PORTS           4
#define NUM_OF_PINS_PER_PORT   8


//from data sheet
#define GPIO_DDRA *((volatile uint8*)0x3A)
#define GPIO_PORTA *((volatile uint8*)0x3B)
#define GPIO_PINA *((volatile uint8*)0x39)

#define GPIO_DDRB *((volatile uint8*)0x37)
#define GPIO_PORTB *((volatile uint8*)0x38)
#define GPIO_PINB *((volatile uint8*)0x36)

#define GPIO_DDRC *((volatile uint8*)0x34)
#define GPIO_PORTC *((volatile uint8*)0x35)
#define GPIO_PINC *((volatile uint8*)0x33)

#define GPIO_DDRD *((volatile uint8*)0x31)
#define GPIO_PORTD *((volatile uint8*)0x32)
#define GPIO_PIND *((volatile uint8*)0x30)


#endif /* GPIO_PRIVATE_H_ */
