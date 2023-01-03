/*
 * PWM_Program.c
 *
 *  Created on: 28 Dec 2022
 *      Author: tiger
 */
#include "std_types.h"
#include "common_macros.h"
#include "PWM_Private.h"
#include "PWM_Config.h"
#include "PWM_Interface.h"
#include "GPIO_Interface.h"


static uint16 g_Max_Value_Timer1=0;


/*******************************************************************************
 *                    Static  Functions Prototypes                                   *
 *******************************************************************************/
/*
 * Description :
 * Function responsible for set PWM Signal With Specific Frequency Timer 1.
 */

static void PWM_Timer1_Set_Frequency(uint32 freq,enum PWM1_PRE_SCALE scale);

/*******************************************************************************
 *                      Functions Definition                                   *
 *******************************************************************************/



/*
 * Description :
 * Function responsible for initialize the PWM driver Timer 0.
 */

void PWM_Timer0_init(const PWM0_Configuration* config)
{

	/*set the Timer Register with 0*/
	PWM_TCNT0=0;
	/*set the OC0 as output direction*/
	GPIO_setupPinDirection(PORTB_ID, PIN3_ID, PIN_OUTPUT);
	/*set the duty cycle*/
	PWM_Timer0_Set_Duty_Cycle(config->Duty_Cycle);
	/*if the user want fast PWM mode*/
	if(config->Mode==PWM0_FAST)
	{
		/*set the timer prescaler and the fast PWM mode and select the required if
		 * inverting or not*/
		PWM_TCCR0=(1<<6)|((config->Draw)<<4)|(1<<3)|(config->Pre_Scale);
	}
	else if(config->Mode==PWM0_PHASE_SHIFT)
	{
		/*set the timer prescaler and the phase correct PWM mode and select the required if
		 * inverting or not*/
		PWM_TCCR0=(1<<6)|((config->Draw)<<4)|(config->Pre_Scale);
	}

}

/*
 * Description :
 * Function responsible for set PWM Signal With Specific Duty Cycle Timer 0.
 */

void PWM_Timer0_Set_Duty_Cycle(uint8 duty_cycle)
{
	PWM_OCR0=(uint8)((255*((float32)duty_cycle/100)));

}

/*
 * Description :
 * Function responsible for deinitialize the PWM driver Timer 0.
 */

void PWM_Timer0_Deinit(void)
{
	PWM_TCCR0=0;
}

/*
 * Description :
 * Function responsible for initialize the PWM driver Timer 1 Channel A.
 */

void PWM_Timer1_init(const PWM1_Configuration* config)
{
	/*set the Timer Register with 0*/
	PWM_TCNT1=0;

	/*set the OC0 as output direction*/
	GPIO_setupPinDirection(PORTD_ID, PIN5_ID, PIN_OUTPUT);

	/*set the frequency*/
	PWM_Timer1_Set_Frequency(config->Frequency,config->Pre_Scale);

	/*set the duty cycle*/
	PWM_Timer1_Set_Duty_Cycle((config->Duty_Cycle));

	/*if the user want fast PWM mode*/
	if(config->Mode==PWM1_FAST)
	{
		/*set the timer prescaler and the fast PWM mode and select the required if
		 * inverting or not*/
		PWM_TCCR1A=((config->Draw)<<6)|(1<<1);
		PWM_TCCR1B=(config->Pre_Scale)|(1<<4)|(1<<3);
	}
	else if(config->Mode==PWM1_PHASE_SHIFT)
	{
		/*set the timer prescaler and the phase correct PWM mode and select the required if
		 * inverting or not*/
		PWM_TCCR1A=((config->Draw)<<6)|(1<<1);
		PWM_TCCR1B=(config->Pre_Scale)|(1<<4);
	}

}

/*
 * Description :
 * Function responsible for set PWM Signal With Specific Duty Cycle Timer 1.
 */

void PWM_Timer1_Set_Duty_Cycle(uint8 duty_cycle)
{
	PWM_OCR1A=(uint16)((g_Max_Value_Timer1*((float32)duty_cycle/100)));


}

/*
 * Description :
 * Function responsible for set PWM Signal With Specific Frequency Timer 1.
 */


static void PWM_Timer1_Set_Frequency(uint32 freq,enum PWM1_PRE_SCALE scale)
{
	uint16 new_scale;
	switch(scale)
	{
	case PWM1_PRE_SCALE_1:new_scale=1;break;
	case PWM1_PRE_SCALE_8:new_scale=8;break;
	case PWM1_PRE_SCALE_64:new_scale=64;break;
	case PWM1_PRE_SCALE_256:new_scale=256;break;
	case PWM1_PRE_SCALE_1024:new_scale=1024;break;
	}
	g_Max_Value_Timer1=(int)(F_CPU/(new_scale*freq))-1;
	PWM_ICR1=g_Max_Value_Timer1;


}

/*
 * Description :
 * Function responsible for deinitialize the PWM driver Timer 0.
 */

void PWM_Timer1_Deinit(void)
{
	PWM_TCCR1A=0;
	PWM_TCCR1B=0;
}



/*
 * Description :
 * Function responsible for initialize the PWM driver Timer 2.
 */

void PWM_Timer2_init(const PWM2_Configuration* config)
{

	/*set the Timer Register with 0*/
	PWM_TCNT2=0;
	/*set the OC0 as output direction*/
	GPIO_setupPinDirection(PORTD_ID, PIN7_ID, PIN_OUTPUT);
	/*set the duty cycle*/
	PWM_Timer2_Set_Duty_Cycle(config->Duty_Cycle);
	/*if the user want fast PWM mode*/
	if(config->Mode==PWM2_FAST)
	{
		/*set the timer prescaler and the fast PWM mode and select the required if
		 * inverting or not*/
		PWM_TCCR2=(1<<6)|((config->Draw)<<4)|(1<<3)|(config->Pre_Scale);
	}
	else if(config->Mode==PWM2_PHASE_SHIFT)
	{
		/*set the timer prescaler and the phase correct PWM mode and select the required if
		 * inverting or not*/
		PWM_TCCR2=(1<<6)|((config->Draw)<<4)|(config->Pre_Scale);
	}

}

/*
 * Description :
 * Function responsible for set PWM Signal With Specific Duty Cycle Timer 2.
 */

void PWM_Timer2_Set_Duty_Cycle(uint8 duty_cycle)
{
	PWM_OCR2=(uint8)((255*((float32)duty_cycle/100)));


}

/*
 * Description :
 * Function responsible for deinitialize the PWM driver Timer 2.
 */

void PWM_Timer2_Deinit(void)
{
	PWM_TCCR2=0;
}

