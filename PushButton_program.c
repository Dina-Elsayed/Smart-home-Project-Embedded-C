/*
 * PushButton_program.c
 *
 *  Created on: ???/???/????
 *      Author: dell
 */

#include "PushButton_interface.h"

void H_PushButton_void_PushButtonInit(u8 Copy_u8_PushButton)
{
	switch(Copy_u8_PushButton)
	{
	case PUSH_BUTTON_1: M_Dio_void_PinMode(PUSH_BUTTON_1_PIN,INPUT); break;
	case PUSH_BUTTON_2: M_Dio_void_PinMode(PUSH_BUTTON_2_PIN,INPUT); break;
	case PUSH_BUTTON_3: M_Dio_void_PinMode(PUSH_BUTTON_3_PIN,INPUT); break;
	case PUSH_BUTTON_4: M_Dio_void_PinMode(PUSH_BUTTON_4_PIN,INPUT); break;
	default :                                                        break;
	}
}
u8   H_PushButton_u8_PushButtonRead(u8 Copy_u8_PushButton)
{
	u8 Local_u8_Reading = RELEASED;
	switch(Copy_u8_PushButton)
	{
	case PUSH_BUTTON_1:
		if(M_Dio_u8_PinRead(PUSH_BUTTON_1_PIN) == PRESSED)
		{
			_delay_ms(PUSH_BUTTON_DEBOUNCING_TIME);
			if(M_Dio_u8_PinRead(PUSH_BUTTON_1_PIN) == PRESSED)
			{
				Local_u8_Reading = PRESSED;
				while(M_Dio_u8_PinRead(PUSH_BUTTON_1_PIN) == PRESSED);
			}
		}
		break;
	case PUSH_BUTTON_2:
		if(M_Dio_u8_PinRead(PUSH_BUTTON_2_PIN) == PRESSED)
		{
			_delay_ms(PUSH_BUTTON_DEBOUNCING_TIME);
			if(M_Dio_u8_PinRead(PUSH_BUTTON_2_PIN) == PRESSED)
			{
				Local_u8_Reading = PRESSED;
				while(M_Dio_u8_PinRead(PUSH_BUTTON_2_PIN) == PRESSED);
			}
		}
		break;
	case PUSH_BUTTON_3:
		if(M_Dio_u8_PinRead(PUSH_BUTTON_3_PIN) == PRESSED)
		{
			_delay_ms(PUSH_BUTTON_DEBOUNCING_TIME);
			if(M_Dio_u8_PinRead(PUSH_BUTTON_3_PIN) == PRESSED)
			{
				Local_u8_Reading = PRESSED;
				while(M_Dio_u8_PinRead(PUSH_BUTTON_3_PIN) == PRESSED);
			}
		}
		break;
	case PUSH_BUTTON_4:
		if(M_Dio_u8_PinRead(PUSH_BUTTON_4_PIN) == PRESSED)
		{
			_delay_ms(PUSH_BUTTON_DEBOUNCING_TIME);
			if(M_Dio_u8_PinRead(PUSH_BUTTON_4_PIN) == PRESSED)
			{
				Local_u8_Reading = PRESSED;
				while(M_Dio_u8_PinRead(PUSH_BUTTON_4_PIN) == PRESSED);
			}
		}
		break;
	default: break;
	}

	return Local_u8_Reading;
}
