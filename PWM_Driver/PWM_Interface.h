/*
 * PWM_Interface.h
 *
 *  Created on: 28 Dec 2022
 *      Author: tiger
 */

#ifndef PWM_INTERFACE_H_
#define PWM_INTERFACE_H_


/*enum type to take the PWM0 mode*/
enum PWM0_MODE {PWM0_FAST=3,PWM0_PHASE_SHIFT=1};

/*enum type to take the PWM0 signal*/
enum PWM0_SIGNAL {PWM0_NON_INVERTING=2,PWM0_INVERTING=3};

/*enum type to take the PWM2 mode*/
enum PWM1_MODE {PWM1_FAST,PWM1_PHASE_SHIFT};

/*enum type to take the PWM0 signal*/
enum PWM1_SIGNAL {PWM1_NON_INVERTING=2,PWM1_INVERTING=3};


/*enum type to take the PWM1 mode*/
enum PWM2_MODE {PWM2_FAST,PWM2_PHASE_SHIFT};

/*enum type to take the PWM0 signal*/
enum PWM2_SIGNAL {PWM2_INVERTING=3,PWM2_NON_INVERTING=2};


/*enum type to take the Timer prescaler value for PWM2*/
enum PWM2_PRE_SCALE {
	PWM2_PRE_SCALE_1=1,
	PWM2_PRE_SCALE_8,
	PWM2_PRE_SCALE_32,
	PWM2_PRE_SCALE_64,
	PWM2_PRE_SCALE_128,
	PWM2_PRE_SCALE_256,
	PWM2_PRE_SCALE_1024};


/*enum type to take the timer prescale value for PWM0 */
enum PWM0_PRE_SCALE{
	PWM0_PRE_SCALE_1=1,
	PWM0_PRE_SCALE_8,
	PWM0_PRE_SCALE_64,
	PWM0_PRE_SCALE_256,
	PWM0_PRE_SCALE_1024};

/*enum type to take the timer prescale value for PWM1 */
enum PWM1_PRE_SCALE{
	PWM1_PRE_SCALE_1=1,
	PWM1_PRE_SCALE_8,
	PWM1_PRE_SCALE_64,
	PWM1_PRE_SCALE_256,
	PWM1_PRE_SCALE_1024};



/* type structure to take the configuration of PWM0*/
typedef struct {
	uint8 Duty_Cycle;
	enum PWM0_SIGNAL Draw;
	enum PWM0_PRE_SCALE Pre_Scale;
	enum PWM0_MODE Mode;

}PWM0_Configuration;

/* type structure to take the configuration of PWM1*/
typedef struct {
	uint8 Duty_Cycle;
	enum PWM1_SIGNAL Draw;
	uint32 Frequency;
	enum PWM1_PRE_SCALE Pre_Scale;
	enum PWM1_MODE Mode;

}PWM1_Configuration;

/* type structure to take the configuration of PWM0*/
typedef struct {
	uint8 Duty_Cycle;
	enum PWM2_SIGNAL Draw;
	enum PWM2_PRE_SCALE Pre_Scale;
	enum PWM0_MODE Mode;

}PWM2_Configuration;




/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for initialize the PWM driver Timer 0.
 */

void PWM_Timer0_init(const PWM0_Configuration* config);

/*
 * Description :
 * Function responsible for set PWM Signal With Specific Duty Cycle Timer 0.
 */

void PWM_Timer0_Set_Duty_Cycle(uint8 duty_cycle);

/*
 * Description :
 * Function responsible for deinitialize the PWM driver Timer 0.
 */

void PWM_Timer0_Deinit(void);

/*
 * Description :
 * Function responsible for initialize the PWM driver Timer 1.
 */

void PWM_Timer1_init(const PWM1_Configuration* config);

/*
 * Description :
 * Function responsible for set PWM Signal With Specific Duty Cycle Timer 1.
 */

void PWM_Timer1_Set_Duty_Cycle(uint8 duty_cycle);


/*
 * Description :
 * Function responsible for deinitialize the PWM driver Timer 1.
 */

void PWM_Timer1_Deinit(void);



/*
 * Description :
 * Function responsible for initialize the PWM driver Timer 0.
 */

void PWM_Timer2_init(const PWM2_Configuration* config);

/*
 * Description :
 * Function responsible for set PWM Signal With Specific Duty Cycle Timer 2.
 */

void PWM_Timer2_Set_Duty_Cycle(uint8 duty_cycle);

/*
 * Description :
 * Function responsible for deinitialize the PWM driver Timer 2.
 */

void PWM_Timer2_Deinit(void);



#endif /* PWM_INTERFACE_H_ */
