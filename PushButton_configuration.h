/*
 * PushButton_configuration.h
 *
 *  Created on: ???/???/????
 *      Author: dell
 */

#ifndef HAL_PUSHBUTTON_PUSHBUTTON_CONFIGURATION_H_
#define HAL_PUSHBUTTON_PUSHBUTTON_CONFIGURATION_H_

/***_SELECT_MC_PIN_******************************************************/
#define PUSH_BUTTON_1_PIN          PD2_PIN
#define PUSH_BUTTON_2_PIN          PD3_PIN
#define PUSH_BUTTON_3_PIN          PD4_PIN
#define PUSH_BUTTON_4_PIN          PD5_PIN
/***_SELECT_PUSH_BUTTON_MODE: ACTIVE_LOW , ACTIVE_HIGH ******************/
#define PUSH_BUTTON_MODE              ACTIVE_LOW
/***_SELECT_PUSH_BUTTON_DEBOUNCING_TIME: ********************************/
#define PUSH_BUTTON_DEBOUNCING_TIME        100

#endif /* HAL_PUSHBUTTON_PUSHBUTTON_CONFIGURATION_H_ */
