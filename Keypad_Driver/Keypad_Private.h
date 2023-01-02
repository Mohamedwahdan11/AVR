/*
 * Keypad_Private.h
 *
 *  Created on: Dec 3, 2022
 *      Author: DELL
 */

#ifndef KEYPAD_PRIVATE_H_
#define KEYPAD_PRIVATE_H_


/*******************************************************************************
 *                      Functions Prototypes(Private)                          *
 *******************************************************************************/

#if (KEYPAD_NUM_COLS == 3)
/*
 * Function responsible for mapping the switch number in the keypad to
 * its corresponding functional number in the proteus for 4x3 keypad
 */
static uint8 KEYPAD_4x3_adjustKeyNumber(uint8 button_number);
#elif (KEYPAD_NUM_COLS == 4)
/*
 * Function responsible for mapping the switch number in the keypad to
 * its corresponding functional number in the proteus for 4x4 keypad
 */
static uint8 KEYPAD_4x4_adjustKeyNumber(uint8 button_number);
#endif



#endif /* KEYPAD_PRIVATE_H_ */
