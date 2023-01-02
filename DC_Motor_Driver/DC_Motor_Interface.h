/*
 * DC_Motor_Interface.h
 *
 *  Created on: 20 Dec 2022
 *      Author: Dell
 */

#ifndef DC_MOTOR_INTERFACE_H_
#define DC_MOTOR_INTERFACE_H_

#include "std_types.h"
/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/
/*enum  used to set the DC Motor direction*/
typedef enum
{
	DC_MOTOR_OFF,DC_MOTOR_CLK_WISE,DC_MOTOR_ANTI_CLK_WISE
}DcMotor_State;


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for initialize the DC Motor driver..
 */

void DC_Motor_Init(void);

/*
 * Description :
 * Function responsible for set the DC Motor rotation direction
 * or to stop the motor.
 */
void DC_Motor_Rotate(DcMotor_State state);



/*If using the PWM to control the DC motor speed*/
#if(DC_MOTOR_USING_PWM == 1)

/*
 * Description :
 * Function responsible for set the DC Motor rotation direction with speed
 * or to stop the motor.
 */


void DC_Motor_Rotate_With_Speed(DcMotor_State state,uint8 speed);

/*
 * Description :
 * Function responsible to change the DC Motor speed.
 */
void DC_Motor_Set_Speed(uint8 speed);
#endif

#endif /* DC_MOTOR_INTERFACE_H_ */
