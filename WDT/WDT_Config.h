/*
 * WDT_Config.h
 *
 *  Created on: 24 Dec 2022
 *      Author: tiger
 */

#ifndef WDT_CONFIG_H_
#define WDT_CONFIG_H_


/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/


/*choose the operation VCC*/

#define WDT_VCC 5

#if((WDT_VCC != 5) && (WDT_VCC != 3))

#error "Number of VCC should be equal to 5 or 3"

#endif


#endif /* WDT_CONFIG_H_ */
