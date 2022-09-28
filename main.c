/*
 * main.c
 *
 *  Created on: Aug 29, 2022
 *      Author: pc
 */

#include "Dio_interface.h"
#include "Led_interface.h"
#include "Lcd_interface.h"
#include "KeyPad_interface.h"
#include "ADC_interface.h"
#include "Timer_0_interface.h"
#include "DC_Motor_interface.h"
#include "TempSensor_interface.h"

#include "StandardTypes.h"

/*********Macros************/
#define PASS_SIZE           6
#define NUM_OF_TRIES 		3
/**************************/


int main()
{


	u8 Local_u8_SavedPassword[PASS_SIZE];
	u8 Local_u8_Password[PASS_SIZE];
	u8 Local_u8_passwordTries = 0;
	u8 Local_u8_choice,readl,LedOn,led;
	u8 Local_NumOfTries = NUM_OF_TRIES;
	u16 TempRead =0;
	u8 correct_digit;


	H_Lcd_void_LcdInit();
	H_KeyPad_void_KeyPadInit();
	H_Led_void_LedInit(BLU_LED);
	H_Led_void_LedInit(GRN_LED);
	H_Led_void_LedInit(RED_LED);
	H_TempSensor_void_Init();
	H_DC_Motor_void_Init();


	/************_First_LOGIN_************************/
	H_Lcd_void_LcdSendString("Welcome!");
	H_Lcd_void_LcdGoTo(2,1);
	H_Lcd_void_LcdSendString("First Login");
	_delay_ms(500);
	H_Lcd_void_LcdClear();
	H_Lcd_void_LcdSendString("Set Password");
	H_Lcd_void_LcdGoTo(2,1);
	u8 Local_counter = 0;
	while(Local_counter<PASS_SIZE)
	{
		Local_u8_SavedPassword[Local_counter] = H_KeyPad_void_KeyPadRead();
		if (Local_u8_SavedPassword[Local_counter]!=0)
		{
			H_Lcd_void_LcdSendCharacter(Local_u8_SavedPassword[Local_counter]);
			_delay_ms(100);
			H_Lcd_void_LcdGoTo(2,Local_counter+1);
			H_Lcd_void_LcdSendCharacter('*');
			Local_counter++;
		}

	}
	H_Lcd_void_LcdClear();
	H_Lcd_void_LcdSendString("Password saved");


	/*****************_Check_password_*******************/

	do{
		_delay_ms(500);
		H_Lcd_void_LcdClear();
		H_Lcd_void_LcdSendString("Enter Password");
		H_Lcd_void_LcdGoTo(2,1);
		u8 Local_counter2 = 0;
		while(Local_counter2<PASS_SIZE)
		{
			Local_u8_Password[Local_counter2] = H_KeyPad_void_KeyPadRead();
			if (Local_u8_Password[Local_counter2]!=0)
			{
				H_Lcd_void_LcdSendCharacter(Local_u8_Password[Local_counter2]);
				_delay_ms(100);
				H_Lcd_void_LcdGoTo(2,Local_counter2 + 1);
				H_Lcd_void_LcdSendCharacter('*');
				Local_counter2++;
			}

		}


		for(int i = 0;i<PASS_SIZE;i++)
		{
			if(Local_u8_Password[i] == Local_u8_SavedPassword[i])
			{
				correct_digit++;
			}
			else
			{

			}

		}
		if(correct_digit<PASS_SIZE)
		{
			//display wrong password please try again
			H_Lcd_void_LcdClear();
			H_Lcd_void_LcdSendString("Wrong password");
			correct_digit = 0;
			_delay_ms(500);
			H_Lcd_void_LcdClear();
			H_Lcd_void_LcdSendString("Tries Left:");
			H_Lcd_void_LcdGoTo(2,1);
			H_Lcd_void_LcdSendCharacter((--Local_NumOfTries+'0'));
			_delay_ms(500);
			Local_u8_passwordTries++;
			if(Local_u8_passwordTries == NUM_OF_TRIES)
			{
				H_Lcd_void_LcdClear();
				H_Lcd_void_LcdSendString("Waiting");
				_delay_ms(5000);
				Local_u8_passwordTries = 0;
				Local_NumOfTries = NUM_OF_TRIES;
			}
		}


	}while(correct_digit!=PASS_SIZE);
	_delay_ms(500);
	H_Lcd_void_LcdClear();
	H_Lcd_void_LcdSendString("Correct Password");
	_delay_ms(300);
	H_Lcd_void_LcdSendString("Welcome");


	/******************_LED_ON/OFF_******************/

	H_Lcd_void_LcdClear();
	H_Lcd_void_LcdSendString("1-Leds On");
	H_Lcd_void_LcdGoTo(2,1);
	H_Lcd_void_LcdSendString("2-Leds Off");
	while(1)
	{
		/*********_TempSensor_*******************/
		TempRead = H_TempSensor_u16_Read();
		if(TempRead<=25)
		{
			H_DC_Motor_void_DCMode(DC_MOTOR_STOP);
			H_DC_Motor_void_Speed(Stop);
		}
		else if(TempRead >25&&TempRead<30)
		{
			H_DC_Motor_void_DCMode(ROTATE_CLK_WISE);
			H_DC_Motor_void_Speed(DC_LOW);
		}
		else if(TempRead>30)
		{
			H_DC_Motor_void_DCMode(ROTATE_CLK_WISE);
			H_DC_Motor_void_Speed(DC_HIGH);
		}

		/****************LEDS****************/

		Local_u8_choice = H_KeyPad_void_KeyPadRead();
		if (Local_u8_choice!=0)
		{
			readl = Local_u8_choice;
			/************_LED_ON_*****************/
			if(readl ==(1+'0'))
			{
				H_Lcd_void_LcdClear();
				H_Lcd_void_LcdSendString("4-BLUE ON 5-GREEN On");
				H_Lcd_void_LcdGoTo(2,1);
				H_Lcd_void_LcdSendString("6-RED 7-Exit Led On menu");
				while(1)
				{
					LedOn = H_KeyPad_void_KeyPadRead();
					if(LedOn!=0)
					{
						led = LedOn;
						if(led == (4+'0'))
							H_Led_void_LedOn(BLU_LED);
						else if(led == (5+'0'))
							H_Led_void_LedOn(GRN_LED);
						else if(led == (6+'0'))
							H_Led_void_LedOn(RED_LED);
						else if(led == (7+'0'))
						{
							H_Lcd_void_LcdClear();
							H_Lcd_void_LcdSendString("1-Leds On");
							H_Lcd_void_LcdGoTo(2,1);
							H_Lcd_void_LcdSendString("2-Leds Off");
							break;
						}

						else
						{
							H_Lcd_void_LcdClear();
							H_Lcd_void_LcdSendString("Wrong input");
							_delay_ms(500);
							H_Lcd_void_LcdClear();
							H_Lcd_void_LcdSendString("1-Leds On");
							H_Lcd_void_LcdGoTo(2,1);
							H_Lcd_void_LcdSendString("2-Leds Off");
							break;

						}

					}
				}

			}
			/************_LED_Off_*****************/
			else if(readl ==(2+'0'))
			{
				H_Lcd_void_LcdClear();
				H_Lcd_void_LcdSendString("4-BLUE Off 5-GREEN Off");
				H_Lcd_void_LcdGoTo(2,1);
				H_Lcd_void_LcdSendString("6-RED 7-Exit Led Off menu");

				while(1)
				{
					LedOn = H_KeyPad_void_KeyPadRead();
					if(LedOn!=0)
					{
						led = LedOn;
						if(led == (4+'0'))
							H_Led_void_LedOff(BLU_LED);
						else if(led == (5+'0'))
							H_Led_void_LedOff(GRN_LED);
						else if(led == (6+'0'))
							H_Led_void_LedOff(RED_LED);
						else if(led == (7+'0'))
						{
							H_Lcd_void_LcdClear();
							H_Lcd_void_LcdSendString("1-Leds On");
							H_Lcd_void_LcdGoTo(2,1);
							H_Lcd_void_LcdSendString("2-Leds Off");
							break;
						}
						else
						{
							H_Lcd_void_LcdClear();
							H_Lcd_void_LcdSendString("Wrong input");
							_delay_ms(500);
							H_Lcd_void_LcdClear();
							H_Lcd_void_LcdSendString("1-Leds On");
							H_Lcd_void_LcdGoTo(2,1);
							H_Lcd_void_LcdSendString("2-Leds Off");
							break;
						}

					}
				}

			}

		}

	}






	return 0;
}

