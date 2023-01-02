/*
 * WDT_Program.c
 *
 *  Created on: 24 Dec 2022
 *      Author: DELL
 */


#include "WDT_Config.h"
#include "WDT_Private.h"
#include "WDT_Interface.h"



#include "common_macros.h"
#include "util/delay.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/


/*
 * Description :
 * This function is responsible for initialize or start the watch dog timer with time out send by the caller
 */

void WDT_Start_Timer(const TIME_OUT time_out)
{
	WDT_WDTCR|=(1<<3)|time_out;
}

/*
 * Description :
 * This function is responsible for turn off the watch dog timer
 */

void WDT_Stop_Timer(void)
{
	WDT_WDTCR = (1<<3)|(1<<4);
	// Wait 4 cycles before clear the WDE bit
	_delay_us(4);
	WDT_WDTCR = 0x00;
}

/*
 * Description :
 * This function is responsible for change the watch dog timer timeout time  with time send by the caller
 */

void WDT_SET_New_Time_Out(const TIME_OUT time_out)
{
	WDT_WDTCR = (1<<3)|(1<<4);
		// Wait 4 cycles before clear the WDE bit
		_delay_us(4);
		WDT_WDTCR = 0x00;
		WDT_WDTCR|=(1<<3)|time_out;
}
