/*
 * Lcd_configuration.h
 *
 *  Created on: ???/???/????
 *      Author: dell
 */

#ifndef HAL_LCD_LCD_CONFIGURATION_H_
#define HAL_LCD_LCD_CONFIGURATION_H_

/***_LCD_MODE_OPTIONS: _4_BIT_MODE , _8_BIT_MODE ***********************/
#define LCD_MODE         _4_BIT_MODE
/***_SELECT_MC_PIN_******************************************************/
#define LCD_D0_PIN       PA0_PIN
#define LCD_D1_PIN       PA1_PIN
#define LCD_D2_PIN       PA2_PIN
#define LCD_D3_PIN       PA3_PIN
#define LCD_D4_PIN       PA3_PIN
#define LCD_D5_PIN       PA4_PIN
#define LCD_D6_PIN       PA5_PIN
#define LCD_D7_PIN       PA6_PIN

#define LCD_RS_PIN       PA1_PIN
#define LCD_EN_PIN       PA2_PIN
#define LCD_RW_PIN       PB2_PIN

#endif /* HAL_LCD_LCD_CONFIGURATION_H_ */
