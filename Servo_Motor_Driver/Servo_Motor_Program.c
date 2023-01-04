/*
 * Servo_Motor_Program.c
 *
 *  Created on: 3 Jan 2023
 *      Author: Dell
 */

#include "std_types.h"
#include "common_macros.h"
#include "Servo_Motor_Private.h"
#include "Servo_Motor_Config.h"
#include "Servo_Motor_Interface.h"
#include "GPIO_Interface.h"
#include "PWM_Interface.h"
#include "util/delay.h"

/*******************************************************************************
 *                      Functions Definition                                   *
 *******************************************************************************/



/*
 * Description :
 * Function responsible for rotate the servo motor with angle 90.
 */



void Servo_Motor_Rotate_90(void)
{
	PWM1_Configuration PWM_1={
				7.5,
				PWM1_NON_INVERTING,
				50,
				PWM1_PRE_SCALE_8,
				PWM1_FAST};

		PWM_Timer1_init(&PWM_1);
}


/*
 * Description :
 * Function responsible for rotate the servo motor with angle 180.
 */

void Servo_Motor_Rotate_180(void)
{
	PWM1_Configuration PWM_1={
				10,
				PWM1_NON_INVERTING,
				50,
				PWM1_PRE_SCALE_8,
				PWM1_FAST};

		PWM_Timer1_init(&PWM_1);
}

/*
 * Description :
 * Function responsible for rotate the servo motor with angle 0.
 */
void Servo_Motor_Rotate_0(void)
{
	PWM1_Configuration PWM_1={
				5,
				PWM1_NON_INVERTING,
				50,
				PWM1_PRE_SCALE_8,
				PWM1_FAST};

		PWM_Timer1_init(&PWM_1);
}
