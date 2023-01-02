/*
 * External_Interrupt_Interface.h
 *
 *  Created on: Dec 3, 2022
 *      Author: DELL
 */

#ifndef EXTERNAL_INTERRUPT_INTERFACE_H_
#define EXTERNAL_INTERRUPT_INTERFACE_H_

#define EXT_INT0_ID   0
#define EXT_INT1_ID   1
#define EXT_INT2_ID   2


#define EXT_INT0_LOW   			0
#define EXT_INT0_LOC   			1
#define EXT_INT0_FALLING_EDGE   2
#define EXT_INT0_RISSING_EDGE	3


#define EXT_INT1_LOW   			0
#define EXT_INT1_LOC   			1
#define EXT_INT1_FALLING_EDGE   2
#define EXT_INT1_RISSING_EDGE	3

#define EXT_INT2_FALLING_EDGE   0
#define EXT_INT2_RISSING_EDGE	1



void EXT_INT_Init(uint8 EXT_INT_Index, uint8 EXT_INT_Level );
void EXT_INT_Deinit(uint8 EXT_INT_Index );
void EXT_INT_SetCallBack(uint8 EXT_INT_Index,void(*a_ptr)(void));

#endif /* EXTERNAL_INTERRUPT_INTERFACE_H_ */
