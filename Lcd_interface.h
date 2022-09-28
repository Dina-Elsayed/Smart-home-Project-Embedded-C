/*
 * Lcd_interface.h
 *
 *  Created on: ???/???/????
 *      Author: dell
 */

#ifndef HAL_LCD_LCD_INTERFACE_H_
#define HAL_LCD_LCD_INTERFACE_H_

/********************************************_INCLUDES_*******************************/
#include "Lcd_configuration.h"
#include "StandardTypes.h"
#include "Dio_interface.h"
#include <util/delay.h>
/********************************************_PROTOTYPES_*******************************/
void H_Lcd_void_LcdInit(void);
void H_Lcd_void_LcdSendCommand(u8);
void H_Lcd_void_LcdSendCharacter(u8);
void H_Lcd_void_LcdSendString(u8*);
void H_Lcd_void_LcdSendNumber(s32);
void H_Lcd_void_LcdClear(void);
void H_Lcd_void_LcdGoTo(u8,u8);

#endif /* HAL_LCD_LCD_INTERFACE_H_ */
