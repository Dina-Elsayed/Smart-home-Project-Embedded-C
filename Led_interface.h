/*
 * Led_interfacing.h
 *
 *  Created on: ???/???/????
 *      Author: dell
 */

#ifndef LED_LED_INTERFACING_H_
#define LED_LED_INTERFACING_H_

/********************************************_MACROS_*******************************/
#define BLU_LED            1
#define GRN_LED            2
#define RED_LED            3
/********************************************_INCLUDES_*******************************/
#include "Led_configuration.h"
#include "StandardTypes.h"
#include "Dio_interface.h"
#include <util/delay.h>
/*******************************************_PROTOTYPES_*******************************/
void H_Led_void_LedInit(u8);
void H_Led_void_LedOn(u8);
void H_Led_void_LedOff(u8);
void H_Led_void_LedTog(u8);
void H_Led_void_LedBlinkOnce(u8);
void H_Led_void_LedBlinkTwice(u8);

#endif /* LED_LED_INTERFACING_H_ */
