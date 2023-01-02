/*
 * External_Interrupt_Program.c
 *
 *  Created on: Dec 3, 2022
 *      Author: DELL
 */

#include "std_types.h"
#include "External_Interrupt_Config.h"
#include "External_Interrupt_Interface.h"
#include "External_Interrupt_Private.h"
#include "common_macros.h"


/*******************************************************************************
 *                           Global Variables                                  *
 *******************************************************************************/

/* Global variables to hold the address of the call back function in the application */


static volatile void (*EXT_INT_0_ISR_Ptr_Call_Back)(void)=NULL_PTR;
static volatile void (*EXT_INT_1_ISR_Ptr_Call_Back)(void)=NULL_PTR;
static volatile void (*EXT_INT_2_ISR_Ptr_Call_Back)(void)=NULL_PTR;



/*
 * Description :
 * Enable the external interrupt and set its level of trigger.
 * If the input interrupt number are not correct, The function will not handle the request.
 */

void EXT_INT_Init(uint8 EXT_INT_Index, uint8 EXT_INT_Level )
{
	/*Switch on the interrupt number
	 *in the switch case enable the interrupt a set its level of trigger*/
	switch(EXT_INT_Index)
	{
	case EXT_INT0_ID:
		EXT_INT_MCUCR=(EXT_INT_MCUCR&0xFC)|(EXT_INT_Level & 0x03);
		SET_BIT(EXT_INT_GICR,6);
		break;
	case EXT_INT1_ID:
		EXT_INT_MCUCR=(EXT_INT_MCUCR&0xF3)|((EXT_INT_Level & 0x03)<<2);
		SET_BIT(EXT_INT_GICR,7);
		break;
	case EXT_INT2_ID:
		EXT_INT_MCUCSR=(EXT_INT_MCUCR&0xBF)|((EXT_INT_Level & 0x01)<<6);
		SET_BIT(EXT_INT_GICR,5);
		break;
	}
}

/*
 * Description :
 * disable the external interrupt .
 * If the input interrupt number are not correct, The function will not handle the request.
 */

void EXT_INT_Deinit(uint8 EXT_INT_Index )
{
	/*Switch on the interrupt number
	 *in the switch case disable the interrupt */
	switch(EXT_INT_Index)
	{
	case EXT_INT0_ID:
		CLEAR_BIT(EXT_INT_GICR,6);
		break;
	case EXT_INT1_ID:
		CLEAR_BIT(EXT_INT_GICR,7);
		break;
	case EXT_INT2_ID:
		CLEAR_BIT(EXT_INT_GICR,5);
		break;
	}
}


/*
 * Description: Function to set the Call Back function address.
 */
void EXT_INT_SetCallBack(uint8 EXT_INT_Index,void(*a_ptr)(void))
{
	/*Switch on the interrupt number
	 *in the switch case disable the interrupt */
	switch(EXT_INT_Index)
	{
	case EXT_INT0_ID:
		/* Save the address of the Call back function in a global variable */
		EXT_INT_0_ISR_Ptr_Call_Back = a_ptr;
		break;
	case EXT_INT1_ID:
		/* Save the address of the Call back function in a global variable */
		EXT_INT_1_ISR_Ptr_Call_Back = a_ptr;
		break;
	case EXT_INT2_ID:
		/* Save the address of the Call back function in a global variable */
		EXT_INT_2_ISR_Ptr_Call_Back = a_ptr;
		break;
	}

}




/*******************************************************************************
 *                                Interrupt Service Routine                    *
 *******************************************************************************/


/*External Interrupt 0 ISR*/
void __vector_1(void)
{
	if(EXT_INT_0_ISR_Ptr_Call_Back != NULL_PTR)
	{
		/* Call the Call Back function in the application  */
		(*EXT_INT_0_ISR_Ptr_Call_Back)();
	}
}
/*External Interrupt 1 ISR*/
void __vector_2(void)
{
	if(EXT_INT_1_ISR_Ptr_Call_Back != NULL_PTR)
	{
		/* Call the Call Back function in the application  */
		(*EXT_INT_1_ISR_Ptr_Call_Back)();
	}
}




/*External Interrupt 2 ISR*/
void __vector_3(void)
{
	if(EXT_INT_2_ISR_Ptr_Call_Back != NULL_PTR)
	{
		/* Call the Call Back function in the application  */
		(*EXT_INT_2_ISR_Ptr_Call_Back)();
	}
}
