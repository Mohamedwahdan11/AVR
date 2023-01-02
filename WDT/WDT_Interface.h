/*
 * WDT_Interface.h
 *
 *  Created on: 24 Dec 2022
 *      Author: tiger
 */

#ifndef WDT_INTERFACE_H_
#define WDT_INTERFACE_H_


#include "std_types.h"
#include "WDT_Config.h"
/*******************************************************************************
 *                         Types   Definitions                                  *
 *******************************************************************************/



#if(WDT_VCC == 5)
typedef enum  {
						WDT_TIME_OUT_16_3_ms=0,
						WDT_TIME_OUT_32_5_ms,
						WDT_TIME_OUT_65_ms,
						WDT_TIME_OUT_0_13_s,
						WDT_TIME_OUT_0_26_s,
						WDT_TIME_OUT_0_52_s,
						WDT_TIME_OUT_1_s,
						WDT_TIME_OUT_2_1_s}TIME_OUT;


#endif

#if(WDT_VCC == 3)
typedef enum  {
						WDT_TIME_OUT_17_1_ms=0,
						WDT_TIME_OUT_34_3_ms,
						WDT_TIME_OUT_68_5_ms,
						WDT_TIME_OUT_0_14_s,
						WDT_TIME_OUT_0_27_s,
						WDT_TIME_OUT_0_55_s,
						WDT_TIME_OUT_1_1_s,
						WDT_TIME_OUT_2_2_s}TIME_OUT;

#endif

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
/*
 * function to turn on Watch dog timer
 */

void WDT_Start_Timer(const TIME_OUT time_out);

/*
 * function to turn off Watch dog timer
 */

void WDT_Stop_Timer(void);

/*
 * function to change Watch dog timer timeout
 */


void WDT_SET_New_Time_Out(const TIME_OUT time_out);

#endif /* WDT_INTERFACE_H_ */
