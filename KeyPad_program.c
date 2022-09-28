/*
 * KeyPad_program.c
 *
 *  Created on: ???/???/????
 *      Author: dell
 */

#include "KeyPad_interface.h"

void H_KeyPad_void_KeyPadInit(void)
{
	M_Dio_void_PinMode(KEYPAD_R0_PIN,OUTPUT);
	M_Dio_void_PinMode(KEYPAD_R1_PIN,OUTPUT);
	M_Dio_void_PinMode(KEYPAD_R2_PIN,OUTPUT);
	M_Dio_void_PinMode(KEYPAD_R3_PIN,OUTPUT);

	M_Dio_void_PinWrite(KEYPAD_R0_PIN,HIGH);
	M_Dio_void_PinWrite(KEYPAD_R1_PIN,HIGH);
	M_Dio_void_PinWrite(KEYPAD_R2_PIN,HIGH);
	M_Dio_void_PinWrite(KEYPAD_R3_PIN,HIGH);

	M_Dio_void_PinMode(KEYPAD_C0_PIN,INPUT);
	M_Dio_void_PinMode(KEYPAD_C1_PIN,INPUT);
	M_Dio_void_PinMode(KEYPAD_C2_PIN,INPUT);
	M_Dio_void_PinMode(KEYPAD_C3_PIN,INPUT);
}
u8   H_KeyPad_void_KeyPadRead(void)
{
	u8 Local_u8_Col = 0;
	u8 Local_u8_Row = 0;

	u8 Local_u8_Arr[4][4] = {{ '1' , '2' , '3' , 'A' },
							 { '4' , '5' , '6' , 'B' },
							 { '7' , '8' , '9' , 'C' },
							 { '*' , '0' , '#' , 'D' }};

	u8 Local_u8_Reading = 0;
	for(Local_u8_Row=KEYPAD_R0_PIN;Local_u8_Row<=KEYPAD_R3_PIN;Local_u8_Row++)
	{
		M_Dio_void_PinWrite(Local_u8_Row,LOW);
		for(Local_u8_Col=KEYPAD_C0_PIN;Local_u8_Col<=KEYPAD_C3_PIN;Local_u8_Col++)
		{
			if(M_Dio_u8_PinRead(Local_u8_Col) == 0)
			{
				_delay_ms(100);
				if(M_Dio_u8_PinRead(Local_u8_Col) == 0)
				{
					Local_u8_Reading = Local_u8_Arr [Local_u8_Row - KEYPAD_R0_PIN][Local_u8_Col - KEYPAD_C0_PIN];
					while(M_Dio_u8_PinRead(Local_u8_Col) == 0);
				}
			}
		}
		M_Dio_void_PinWrite(Local_u8_Row,HIGH);
	}
	return Local_u8_Reading;
}
