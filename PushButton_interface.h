/*
 * PushButton_interface.h
 *
 *  Created on: ???/???/????
 *      Author: dell
 */

#ifndef HAL_PUSHBUTTON_PUSHBUTTON_INTERFACE_H_
#define HAL_PUSHBUTTON_PUSHBUTTON_INTERFACE_H_

/********************************************_INCLUDES_*******************************/
#include "PushButton_configuration.h"
#include "Dio_interface.h"
#include "PushButton_private.h"
#include <util/delay.h>

/*********************************************_MACROS_*******************************/
#define PUSH_BUTTON_1          1
#define PUSH_BUTTON_2          2
#define PUSH_BUTTON_3          3
#define PUSH_BUTTON_4          4
#if   PUSH_BUTTON_MODE   ==   ACTIVE_LOW
#define PRESSED         0
#define RELEASED        1
#elif PUSH_BUTTON_MODE   ==   ACTIVE_HIGH
#define PRESSED         1
#define RELEASED        0
#endif

/******************************************_PROTOTYPES_*******************************/
void H_PushButton_void_PushButtonInit(u8);
u8   H_PushButton_u8_PushButtonRead(u8);

#endif /* HAL_PUSHBUTTON_PUSHBUTTON_INTERFACE_H_ */
