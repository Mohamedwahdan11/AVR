/*
 * Keypad_Program.c
 *
 *  Created on: Dec 3, 2022
 *      Author: DELL
 */

#include "GPIO_Interface.h"
#include "std_types.h"
#include "Keypad_Config.h"
#include "Keypad_Interface.h"
#include "Keypad_Private.h"


/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/
uint8 KEYPAD_getPressedKey(void)
{
	uint8 col,row;
	uint8 keypad_port_value = 0;
	while(1)
	{
		for(col=0;col<KEYPAD_NUM_COLS;col++) /* loop for columns */
		{
			/*
			 * Each time setup the direction for all keypad port as input pins,
			 * except this column will be output pin
			 */
			GPIO_setupPortDirection(KEYPAD_PORT_ID,PORT_INPUT);
			GPIO_setupPinDirection(KEYPAD_PORT_ID,KEYPAD_FIRST_COLUMN_PIN_ID+col,PIN_OUTPUT);

#if(KEYPAD_BUTTON_PRESSED == LOGIC_LOW)
			/* Clear the column output pin and set the rest pins value */
			keypad_port_value = ~(1<<(KEYPAD_FIRST_COLUMN_PIN_ID+col));
#else
			/* Set the column output pin and clear the rest pins value */
			keypad_port_value = (1<<(KEYPAD_FIRST_COLUMN_PIN_ID+col));
#endif
			GPIO_writePort(KEYPAD_PORT_ID,keypad_port_value);

			for(row=0;row<KEYPAD_NUM_ROWS;row++) /* loop for rows */
			{
				/* Check if the switch is pressed in this row */
				if(GPIO_readPin(KEYPAD_PORT_ID,row+KEYPAD_FIRST_ROW_PIN_ID) == KEYPAD_BUTTON_PRESSED)
				{
					#if (KEYPAD_NUM_COLS == 3)
						return KEYPAD_4x3_adjustKeyNumber((row*KEYPAD_NUM_COLS)+col+1);
					#elif (KEYPAD_NUM_COLS == 4)
						return KEYPAD_4x4_adjustKeyNumber((row*KEYPAD_NUM_COLS)+col+1);
					#endif
				}
			}
		}
	}
}

#if (KEYPAD_NUM_COLS == 3)

/*
 * Description :
 * Update the keypad pressed button value with the correct one in keypad 4x3 shape
 */
static uint8 KEYPAD_4x3_adjustKeyNumber(uint8 button_number)
{
	uint8 keypad_button = 0;
	switch(button_number)
	{
		case 10: keypad_button = '*'; // ASCII Code of *
				 break;
		case 11: keypad_button = 0;
				 break;
		case 12: keypad_button = '#'; // ASCII Code of #
				 break;
		default: keypad_button = button_number;
				break;
	}
	return keypad_button;
}

#elif (KEYPAD_NUM_COLS == 4)

/*
 * Description :
 * Update the keypad pressed button value with the correct one in keypad 4x4 shape
 */
static uint8 KEYPAD_4x4_adjustKeyNumber(uint8 button_number)
{
	uint8 keypad_button = 0;
	switch(button_number)
	{
		case 1: keypad_button = KEY1_ID;
				break;
		case 2: keypad_button = KEY2_ID;
				break;
		case 3: keypad_button = KEY3_ID;
				break;
		case 4: keypad_button = KEY4_ID;
				break;
		case 5: keypad_button = KEY5_ID;
				break;
		case 6: keypad_button = KEY6_ID;
				break;
		case 7: keypad_button = KEY7_ID;
				break;
		case 8: keypad_button = KEY8_ID;
				break;
		case 9: keypad_button = KEY9_ID;
				break;
		case 10: keypad_button = KEY10_ID;
				break;
		case 11: keypad_button = KEY11_ID;
				break;
		case 12: keypad_button = KEY12_ID;
				break;
		case 13: keypad_button = KEY13_ID;
				break;
		case 14: keypad_button = KEY14_ID;
				break;
		case 15: keypad_button = KEY15_ID;
				break;
		case 16: keypad_button = KEY16_ID;
				break;
		default: keypad_button = button_number;
				break;
	}
	return keypad_button;
}

#endif
