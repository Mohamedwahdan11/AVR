/*
 * LCD_Config.h
 *
 *  Created on: Dec 3, 2022
 *      Author: DELL
 */

#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_
/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

/* LCD Data bits mode configuration, its value should be 4 or 8*/
#define LCD_DATA_BITS_MODE 8

#if((LCD_DATA_BITS_MODE != 4) && (LCD_DATA_BITS_MODE != 8))

#error "Number of Data bits should be equal to 4 or 8"

#endif

#if (LCD_DATA_BITS_MODE == 4)

#ifdef LCD_LAST_PORT_PINS
#define LCD_FIRST_DATA_PIN_ID         PIN4_ID
#else
#define LCD_FIRST_DATA_PIN_ID         PIN0_ID
#endif

#endif



/* LCD HW Ports and Pins Ids */
#define LCD_RS_PORT_ID                 PORTB_ID
#define LCD_RS_PIN_ID                  PIN1_ID

#define LCD_RW_PORT_ID                 PORTB_ID
#define LCD_RW_PIN_ID                  PIN2_ID

#define LCD_E_PORT_ID                  PORTB_ID
#define LCD_E_PIN_ID                   PIN3_ID

#define LCD_DATA_PORT_ID               PORTD_ID



#endif /* LCD_CONFIG_H_ */
