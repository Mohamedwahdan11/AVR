/*
 * Timer_Interface.h
 *
 *  Created on: 20 Dec 2022
 *      Author: Dell
 */

#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_

#include "std_types.h"
/*******************************************************************************
 *                         Types   Definitions                                  *
 *******************************************************************************/


/*enum type to take the Timer0 mode*/
enum TIMER0_MODE {TIMER0_OVF,TIMER0_COMPARE};

/*enum type to take the Timer2 mode*/
enum TIMER2_MODE {TIMER2_OVF,TIMER2_COMPARE};

/*enum type to take the Timer1 mode*/
enum TIMER1_MODE {TIMER1_OVF,TIMER1_COMPARE};


/*enum type to take the Timer prescaler value for Timer2*/
enum TIMER2_PRE_SCALE {
						TIMER2_PRE_SCALE_1=1,
					    TIMER2_PRE_SCALE_8,
						TIMER2_PRE_SCALE_32,
						TIMER2_PRE_SCALE_64,
						TIMER2_PRE_SCALE_128,
						TIMER2_PRE_SCALE_256,
						TIMER2_PRE_SCALE_1024};


/*enum type to take the timer prescale value for Timer0 */
enum TIMER0_PRE_SCALE{
					  TIMER0_PRE_SCALE_1=1,
					  TIMER0_PRE_SCALE_8,
					  TIMER0_PRE_SCALE_64,
					  TIMER0_PRE_SCALE_256,
					  TIMER0_PRE_SCALE_1024};

/*enum type to take the timer prescale value for Timer1 */
enum TIMER1_PRE_SCALE{
					  TIMER1_PRE_SCALE_1=1,
					  TIMER1_PRE_SCALE_8,
					  TIMER1_PRE_SCALE_64,
					  TIMER1_PRE_SCALE_256,
					  TIMER1_PRE_SCALE_1024};


/* type structure to take the configuration of Timer0*/
typedef struct Timer0_conf{
	uint8 int_Value;
	uint8 comp_Value;
	enum TIMER0_PRE_SCALE Pre_Scale;
	enum TIMER0_MODE Mode;

}Timer0_Configuration;

/* type structure to take the configuration of Timer1*/
typedef struct Timer1_conf{
	uint16 int_Value;
	uint16 comp_Value;
	enum TIMER1_PRE_SCALE Pre_Scale;
	enum TIMER1_MODE Mode;

}Timer1_Configuration;/* type structure to take the configuration of timer 2*/

/* type structure to take the configuration of Timer0*/
typedef struct Timer2_conf{
	uint8 int_Value;
	uint8 comp_Value;
	enum TIMER2_PRE_SCALE Pre_Scale;
	enum TIMER2_MODE Mode;

}Timer2_Configuration;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/


/*
 * function to turn on Timer0
 */

void Timer_Timer0_Init(const Timer0_Configuration* Conf);


/*
 * function to turn on Timer1
 */
void Timer_Timer1_Init(const Timer1_Configuration* Conf);
/*
 * function to turn on Timer2
 */

void Timer_Timer2_Init(const Timer2_Configuration* Conf );

/*
 * function to turn off timer0
 */

void Timer_Timer0_Deinit(void);
/*
 * function to turn off timer1
 */

void Timer_Timer1_Deinit(void);


/*
 * function to turn off timer2
 */

void Timer_Timer2_Deinit(void);

/*
 * Description: Function to set the Call Back function address for timer 2.
 */

void Timer_Timer0_setCallBack(void(*a_ptr)(void));

/*
 * Description: Function to set the Call Back function address for timer 1.
 */

void Timer_Timer1_setCallBack(void(*a_ptr)(void));

/*
 * Description: Function to set the Call Back function address for timer 0.
 */

void Timer_Timer2_setCallBack(void(*a_ptr)(void));


#endif /* TIMER_INTERFACE_H_ */
