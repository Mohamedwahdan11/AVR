/*
 * Keypad_Config.h
 *
 *  Created on: Dec 3, 2022
 *      Author: DELL
 */

#ifndef KEYPAD_CONFIG_H_
#define KEYPAD_CONFIG_H_


/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

/* Keypad configurations for number of rows and columns */
#define KEYPAD_NUM_COLS                  4
#define KEYPAD_NUM_ROWS                  4

/* Keypad Port Configurations */
#define KEYPAD_PORT_ID                   PORTA_ID

#define KEYPAD_FIRST_ROW_PIN_ID           PIN0_ID
#define KEYPAD_FIRST_COLUMN_PIN_ID        PIN4_ID

/* Keypad button logic configurations */
#define KEYPAD_BUTTON_PRESSED            LOGIC_LOW
#define KEYPAD_BUTTON_RELEASED           LOGIC_HIGH


/* Buttons configuration*/
#define KEY1_ID 7      /*r0*c0 */
#define KEY2_ID 8	   /*r0*c1 */
#define KEY3_ID 9      /*r0*c2 */
#define KEY4_ID '/'    /*r0*c3 */
#define KEY5_ID 4       /*r1*c0 */
#define KEY6_ID 5       /*r1*c1 */
#define KEY7_ID 6       /*r1*c2 */
#define KEY8_ID '*'      /*r1*c3 */
#define KEY9_ID 1         /*r2*c0 */
#define KEY10_ID 2       /*r2*c1 */
#define KEY11_ID 3       /*r2*c2 */
#define KEY12_ID '-'     /*r2*c3 */
#define KEY13_ID '\0'     /*r3*c0 */
#define KEY14_ID 0        /*r3*c1 */
#define KEY15_ID '='      /*r3*c2 */
#define KEY16_ID '+'       /*r3*c3 */




#endif /* KEYPAD_CONFIG_H_ */
