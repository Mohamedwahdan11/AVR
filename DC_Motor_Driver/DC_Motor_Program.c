/*
 * DC_Motor_Program.c
 *
 *  Created on: 20 Dec 2022
 *      Author: Dell
 */


#include "GPIO_Interface.h"
#include "DC_Motor_Config.h"
#include "DC_Motor_Interface.h"
#include "DC_Motor_Private.h"

/*Add the PWM driver if you need to control the speed*/
#if(DC_MOTOR_USING_PWM == 1)

#include "PWM_Inteface.h"

#endif

/*
 * Description :
 * Function responsible for initialize the DC Motor driver.
 */



void DC_Motor_Init(void)
{
	/*make the DC Motor pins as output pins*/
	GPIO_setupPinDirection(DC_MOTOR_PORTID_0,DC_MOTOR_PINID_0, PIN_OUTPUT);
	GPIO_setupPinDirection(DC_MOTOR_PORTID_1,DC_MOTOR_PINID_1, PIN_OUTPUT);
	/*initialize the DC Motor with logic 0 to make it off at the beginning*/
	GPIO_writePin(DC_MOTOR_PORTID_0,DC_MOTOR_PINID_0, LOGIC_LOW);
	GPIO_writePin(DC_MOTOR_PORTID_1,DC_MOTOR_PINID_1, LOGIC_LOW);


	/*function will be set to initialize the PWM if we need to control
	 * speed.
	 */
}

/*
 * Description :
 * Function responsible for set the DC Motor rotation direction
 * or to stop the motor.
 */

void DC_Motor_Rotate(DcMotor_State state)
{
	/*if condition to set the mode of the DC Motor where it is off or with
	 * 	clock wise direction or anti-clock wise direction
	 * 	*/

	if(state==DC_MOTOR_ANTI_CLK_WISE)
	{
		GPIO_writePin(DC_MOTOR_PORTID_0,DC_MOTOR_PINID_0, LOGIC_LOW);
		GPIO_writePin(DC_MOTOR_PORTID_1,DC_MOTOR_PINID_1, LOGIC_HIGH);
	}
	else if(state==DC_MOTOR_CLK_WISE)
	{
		GPIO_writePin(DC_MOTOR_PORTID_0,DC_MOTOR_PINID_0, LOGIC_HIGH);
		GPIO_writePin(DC_MOTOR_PORTID_1,DC_MOTOR_PINID_1, LOGIC_LOW);
	}
	else
	{
		GPIO_writePin(DC_MOTOR_PORTID_0,DC_MOTOR_PINID_0, LOGIC_LOW);
		GPIO_writePin(DC_MOTOR_PORTID_1,DC_MOTOR_PINID_1, LOGIC_LOW);
	}
}

#if(DC_MOTOR_USING_PWM == 1)
/*
 * Description :
 * Function responsible for set the DC Motor rotation direction with speed
 * or to stop the motor.
 */

void DC_Motor_Rotate_With_Speed(DcMotor_State state,uint8 speed)
{
	/*if condition to set the mode of the DC Motor where it is off or with
	 * 	clock wise direction or anti-clock wise direction
	 * 	*/



	if(state==DC_MOTOR_ANTI_CLK_WISE)
	{
		GPIO_writePin(DC_MOTOR_PORTID_0,DC_MOTOR_PINID_0, LOGIC_LOW);
		GPIO_writePin(DC_MOTOR_PORTID_1,DC_MOTOR_PINID_1, LOGIC_HIGH);
	}
	else if(state==DC_MOTOR_CLK_WISE)
	{
		GPIO_writePin(DC_MOTOR_PORTID_0,DC_MOTOR_PINID_0, LOGIC_HIGH);
		GPIO_writePin(DC_MOTOR_PORTID_1,DC_MOTOR_PINID_1, LOGIC_LOW);
	}
	else
	{
		GPIO_writePin(DC_MOTOR_PORTID_0,DC_MOTOR_PINID_0, LOGIC_LOW);
		GPIO_writePin(DC_MOTOR_PORTID_1,DC_MOTOR_PINID_1, LOGIC_LOW);
		/*function will be set to stop the PWM */
	}

	/*set the PWM with the wanted duty cycle*/
	DC_Motor_Set_Speed(uint8 speed);
}
/*
 * Description :
 * Function responsible to change the DC Motor speed.
 */
void DC_Motor_Set_Speed(uint8 speed)
{
	/*function will be set to change the PWM */
}

#endif

