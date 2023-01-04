/*
 * PWM_Private.h
 *
 *  Created on: 28 Dec 2022
 *      Author: tiger
 */

#ifndef PWM_PRIVATE_H_
#define PWM_PRIVATE_H_
/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

//from data sheet
#define PWM_TCCR0 (*((volatile uint8*)0x53))
#define PWM_TCNT0 (*((volatile uint8*)0x52))
#define PWM_OCR0 (*((volatile uint8*)0x5C))

#define PWM_TIMSK (*((volatile uint8*)0x59))
#define PWM_TIFR (*((volatile uint8*)0x58))

#define PWM_TCCR1A (*((volatile uint8*)0x4F))
#define PWM_TCCR1B (*((volatile uint8*)0x4E))
#define PWM_TCNT1 (*((volatile uint16*)0x4C))
#define PWM_OCR1B (*((volatile uint16*)0x48))
#define PWM_OCR1A (*((volatile uint16*)0x4A))
#define PWM_ICR1 (*((volatile uint16*)0x46))


#define PWM_TCCR2 (*((volatile uint8*)0x45))
#define PWM_TCNT2 (*((volatile uint8*)0x44))
#define PWM_OCR2 (*((volatile uint8*)0x43))
#define PWM_ASSR (*((volatile uint8*)0x42))
#define PWM_SFIOR (*((volatile uint8*)0x50))



#endif /* PWM_PRIVATE_H_ */
