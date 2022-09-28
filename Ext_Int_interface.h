/*
 * Ext_Int_interface.h
 *
 *  Created on: ???/???/????
 *      Author: dell
 */

#ifndef MCAL_EXT_INT_EXT_INT_INTERFACE_H_
#define MCAL_EXT_INT_EXT_INT_INTERFACE_H_

/********************************************_INCLUDES_******************************/
#include "Ext_Int_configuration.h"
#include "BitMath.h"
#include "StandardTypes.h"
#include "GIE_interface.h"
#include <avr/interrupt.h>
/*********************************************_MACROS_*******************************/
#define EXT_INT_0          0
#define EXT_INT_1          1
#define EXT_INT_2          2
/*******************************************_PROTOTYPES_*******************************/
void M_Ext_Int_void_Init(u8);
void M_Ext_Int_void_SetCallBack(void (*) (void));

#endif /* MCAL_EXT_INT_EXT_INT_INTERFACE_H_ */
