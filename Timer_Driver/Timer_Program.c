/*
 * Timer_Program.c
 *
 *  Created on: 20 Dec 2022
 *      Author: Dell
 */

#include "Timer_Config.h"
#include "Timer_Interface.h"
#include "Timer_Private.h"
#include "common_macros.h"



/* Global variables to hold the address of the call back function in the application */
static volatile void (*g_callBackPtr_Timer0)(void) = NULL_PTR;
static volatile void (*g_callBackPtr_Timer1)(void) = NULL_PTR;
static volatile void (*g_callBackPtr_Timer2)(void) = NULL_PTR;

/*******************************************************************************
 *                       Interrupt Service Routines                            *
 *******************************************************************************/
/*
 * The Interrupt service routine for Timer0 Compare mode
 * */
void __vector_10(void)
{
	if(g_callBackPtr_Timer0 != NULL_PTR)
	{
		/* Call the Call Back function in the application after the receiving data */
		(*g_callBackPtr_Timer0)(); /* another method to call the function using pointer to function g_callBackPtr(); */
	}
}
/*
 * The Interrupt service routine for Timer0 over flow mode
 * */
void __vector_11(void)
{
	if(g_callBackPtr_Timer0 != NULL_PTR)
	{
		/* Call the Call Back function in the application after the receiving data */
		(*g_callBackPtr_Timer0)(); /* another method to call the function using pointer to function g_callBackPtr(); */
	}
}
/*
 * The Interrupt service routine for Timer1 Compare A mode
 * */
void __vector_7(void)
{
	if(g_callBackPtr_Timer1 != NULL_PTR)
	{
		/* Call the Call Back function in the application after the receiving data */
		(*g_callBackPtr_Timer1)(); /* another method to call the function using pointer to function g_callBackPtr(); */
	}
}
/*
 * The Interrupt service routine for Timer1 over flow mode
 * */
void __vector_9(void)
{
	if(g_callBackPtr_Timer1 != NULL_PTR)
	{
		/* Call the Call Back function in the application after the receiving data */
		(*g_callBackPtr_Timer1)(); /* another method to call the function using pointer to function g_callBackPtr(); */
	}
}
/*
 * The Interrupt service routine for Timer2 over flow mode
 * */
void __vector_5(void)
{
	if(g_callBackPtr_Timer2 != NULL_PTR)
	{
		/* Call the Call Back function in the application after the receiving data */
		(*g_callBackPtr_Timer2)(); /* another method to call the function using pointer to function g_callBackPtr(); */
	}
}
/*
 * The Interrupt service routine for Timer2 Compare mode
 * */
void __vector_4(void)
{
	if(g_callBackPtr_Timer2 != NULL_PTR)
	{
		/* Call the Call Back function in the application after the receiving data */
		(*g_callBackPtr_Timer2)(); /* another method to call the function using pointer to function g_callBackPtr(); */
	}
}


/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/


/*
 * Description :
 * This function is responsible for initialize or start the Timer 0 and it takes structure to the configuration
 * which the counter start time, the comparator value the pre scale and the needed mode
 */

void Timer_Timer0_Init(const Timer0_Configuration* Conf)
{
	/*Set the initial counter value */
	TIMER_TCNT0=Conf->int_Value;

	/*configure the timer in over flow or compare mode */
	if( Conf->Mode == TIMER0_OVF)
	{
		TIMER_TCCR0=(1<<7)|Conf->Pre_Scale;
		SET_BIT(TIMER_TIMSK,0);
	}
	else if(Conf->Mode ==TIMER0_COMPARE)
	{
		/*Set the compare register value */
			TIMER_OCR0=Conf->comp_Value;
		TIMER_TCCR0=(1<<7)|(1<<3)|Conf->Pre_Scale;
		SET_BIT(TIMER_TIMSK,1);
	}
}
/*
 * Description :
 * This function is responsible for initialize or start the Timer 1 and it takes structure to the configuration
 * which the counter start time, the comparator value the pre scale and the needed mode
 */

void Timer_Timer1_Init(const Timer1_Configuration* Conf)
{

	TIMER_TCNT1=Conf->int_Value;

	TIMER_TCCR1A=(1<<7)|(1<<6);

	if(Conf->Mode==TIMER1_OVF)
	{
		TIMER_TCCR1B=Conf->Pre_Scale;
		SET_BIT(TIMER_TIMSK,2);
	}
	else if(Conf->Mode==TIMER1_COMPARE)
	{
		TIMER_TCCR1B=(1<<3)|Conf->Pre_Scale;
		TIMER_OCR1A=Conf->comp_Value;
		SET_BIT(TIMER_TIMSK,4);
	}
}

/*
 * Description :
 * This function is responsible for initialize or start the Timer 2 and it takes structure to the configuration
 * which the counter start time, the comparator value the pre scale and the needed mode
 */
void Timer_Timer2_Init(const Timer2_Configuration* Conf )
{
	TIMER_TCNT2=Conf->int_Value;
	if(Conf->Mode==TIMER2_OVF)
	{
		TIMER_TCCR2=(1<<7)|Conf->Pre_Scale;
		SET_BIT(TIMER_TIMSK,6);
	}
	else if(Conf->Mode==TIMER2_COMPARE)
	{
		TIMER_TCCR2=(1<<3)|Conf->Pre_Scale;
		TIMER_OCR2=Conf->comp_Value;
		SET_BIT(TIMER_TIMSK,7);
	}
}



/*
 * function to turn off timer0
 */

void Timer_Timer0_Deinit(void)
{
	TIMER_TCCR0=0;
}
/*
 * function to turn off timer1
 */

void Timer_Timer1_Deinit(void)
{
	TIMER_TCCR1B=0;
}


/*
 * function to turn off timer2
 */

void Timer_Timer2_Deinit(void)
{
	TIMER_TCCR2=0;
}

/*
 * Description: Function to set the Call Back function address for timer 0.
 */

void Timer_Timer0_setCallBack(void(*a_ptr)(void))
{

	/* Save the address of the Call back function in a global variable */
	g_callBackPtr_Timer0 = a_ptr;

}

/*
 * Description: Function to set the Call Back function address for timer 1.
 */

void Timer_Timer1_setCallBack(void(*a_ptr)(void))
{

	/* Save the address of the Call back function in a global variable */
	g_callBackPtr_Timer1 = a_ptr;

}

/*
 * Description: Function to set the Call Back function address for timer 2.
 */

void Timer_Timer2_setCallBack(void(*a_ptr)(void))
{
	/* Save the address of the Call back function in a global variable */
	g_callBackPtr_Timer2 = a_ptr;
}



