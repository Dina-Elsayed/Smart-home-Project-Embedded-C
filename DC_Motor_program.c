/*
 * DC_Motor_program.c
 *
 *  Created on: Aug 29, 2022
 *      Author: pc
 */
#include "DC_Motor_interface.h"


void H_DC_Motor_void_Init(void)
{
	//step1: IN1,IN2 as OUTPUT
	M_Dio_void_PinMode(IN1_PIN,OUTPUT);
	M_Dio_void_PinMode(IN2_PIN,OUTPUT);



	/**STOP THE MOTOR INITIALLY_*****/
	M_Dio_void_PinWrite(IN1_PIN,LOW);
	M_Dio_void_PinWrite(IN2_PIN,LOW);
}
void H_DC_Motor_void_DCMode(u8 copy_u8_DC_Mode)
{
	switch(copy_u8_DC_Mode)
	{
	case ROTATE_CLK_WISE:
		//Rotate CLK_Wise
			M_Dio_void_PinWrite(IN1_PIN,LOW);
			M_Dio_void_PinWrite(IN2_PIN,HIGH);
		break;

	case ROTATE_ANTI_CLK_WISE:

			M_Dio_void_PinWrite(IN1_PIN,HIGH);
			M_Dio_void_PinWrite(IN2_PIN,LOW);

		break;
	case DC_MOTOR_STOP:

			M_Dio_void_PinWrite(IN1_PIN,LOW);
			M_Dio_void_PinWrite(IN2_PIN,LOW);
		    break;

	default:
		break;
	}



}
void H_DC_Motor_void_Speed(u8 copy_u8_Speed)
{
	 M_Timer_0_void_Init();
	 M_Dio_void_PinMode(PB3_PIN, OUTPUT);
	 M_Timer_0_void_Start();
	switch(copy_u8_Speed)
	{
	case DC_LOW :
		M_Timer_0_void_SetPhaseCorrectPWM(50);
		break;
	case DC_HIGH:
		M_Timer_0_void_SetPhaseCorrectPWM(100);
		break;
	case Stop:
		M_Timer_0_void_SetPhaseCorrectPWM(0);
		break;

	default: break;
	}


}

