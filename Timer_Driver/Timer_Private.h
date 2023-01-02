/*
 * Timer_Private.h
 *
 *  Created on: 20 Dec 2022
 *      Author: Dell
 */

#ifndef TIMER_PRIVATE_H_
#define TIMER_PRIVATE_H_


/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

//from data sheet
#define TIMER_TCCR0 (*((volatile uint8*)0x53))
#define TIMER_TCNT0 (*((volatile uint8*)0x52))
#define TIMER_OCR0 (*((volatile uint8*)0x5C))

#define TIMER_TIMSK (*((volatile uint8*)0x59))
#define TIMER_TIFR (*((volatile uint8*)0x58))

#define TIMER_TCCR1A (*((volatile uint8*)0x4F))
#define TIMER_TCCR1B (*((volatile uint8*)0x4E))
#define TIMER_TCNT1 (*((volatile uint16*)0x4C))
#define TIMER_OCR1B (*((volatile uint16*)0x48))
#define TIMER_OCR1A (*((volatile uint16*)0x4A))

#define TIMER_TCCR2 (*((volatile uint8*)0x45))
#define TIMER_TCNT2 (*((volatile uint8*)0x44))
#define TIMER_OCR2 (*((volatile uint8*)0x43))
#define TIMER_ASSR (*((volatile uint8*)0x42))
#define TIMER_SFIOR (*((volatile uint8*)0x50))


#endif /* TIMER_PRIVATE_H_ */
