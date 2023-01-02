/*
 * External_Interrupt_Private.h
 *
 *  Created on: Dec 3, 2022
 *      Author: DELL
 */

#ifndef EXTERNAL_INTERRUPT_PRIVATE_H_
#define EXTERNAL_INTERRUPT_PRIVATE_H_

/*The ISR prototypes*/
void __vector_1(void)__attribute__((signal));
void __vector_2(void)__attribute__((signal));
void __vector_3(void)__attribute__((signal));

//from data sheet
#define EXT_INT_MCUCR	 *((volatile uint8*)0x55)
#define EXT_INT_MCUCSR 	 *((volatile uint8*)0x54)
#define EXT_INT_GICR 	 *((volatile uint8*)0x5B)


#endif /* EXTERNAL_INTERRUPT_PRIVATE_H_ */
