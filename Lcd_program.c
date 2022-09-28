/*
 * Lcd_program.c
 *
 *  Created on: ???/???/????
 *      Author: dell
 */
#include "Lcd_interface.h"
#include "Lcd_private.h"


void H_Lcd_void_LcdInit(void)
{
#if    LCD_MODE   ==   _8_BIT_MODE
	M_Dio_void_PinMode(LCD_D0_PIN,OUTPUT);
	M_Dio_void_PinMode(LCD_D1_PIN,OUTPUT);
	M_Dio_void_PinMode(LCD_D2_PIN,OUTPUT);
	M_Dio_void_PinMode(LCD_D3_PIN,OUTPUT);
	M_Dio_void_PinMode(LCD_D4_PIN,OUTPUT);
	M_Dio_void_PinMode(LCD_D5_PIN,OUTPUT);
	M_Dio_void_PinMode(LCD_D6_PIN,OUTPUT);
	M_Dio_void_PinMode(LCD_D7_PIN,OUTPUT);

	M_Dio_void_PinMode(LCD_RS_PIN,OUTPUT);
	M_Dio_void_PinMode(LCD_EN_PIN,OUTPUT);

	H_Lcd_void_LcdSendCommand(LCD_8_BIT_MODE_COMMAND);
	H_Lcd_void_LcdSendCommand(LCD_DISPLAY_ON_COMMAND);
#elif LCD_MODE   ==   _4_BIT_MODE
	M_Dio_void_PinMode(LCD_D4_PIN,OUTPUT);
	M_Dio_void_PinMode(LCD_D5_PIN,OUTPUT);
	M_Dio_void_PinMode(LCD_D6_PIN,OUTPUT);
	M_Dio_void_PinMode(LCD_D7_PIN,OUTPUT);

	M_Dio_void_PinMode(LCD_RS_PIN,OUTPUT);
	M_Dio_void_PinMode(LCD_EN_PIN,OUTPUT);
	M_Dio_void_PinMode(LCD_RW_PIN,OUTPUT);
	M_Dio_void_PinWrite(LCD_RW_PIN,LOW);
	_delay_ms(1000);
	H_Lcd_void_LcdSendCommand(LCD_4_BIT_MODE_COMMAND_1);
	H_Lcd_void_LcdSendCommand(LCD_4_BIT_MODE_COMMAND_2);
	H_Lcd_void_LcdSendCommand(LCD_4_BIT_MODE_COMMAND_3);

#endif
	H_Lcd_void_LcdSendCommand(LCD_DISPLAY_ON_COMMAND);
	H_Lcd_void_LcdSendCommand(LCD_CLEAR_COMMAND);


}
void H_Lcd_void_LcdSendCommand(u8 Copy_u8_Command)
{
	M_Dio_void_PinWrite(LCD_RS_PIN,LOW);
#if   LCD_MODE   ==   _8_BIT_MODE

	M_Dio_void_PinWrite(LCD_D0_PIN,Copy_u8_Command >> 0 & 0x01);
	M_Dio_void_PinWrite(LCD_D1_PIN,Copy_u8_Command >> 1 & 0x01);
	M_Dio_void_PinWrite(LCD_D2_PIN,Copy_u8_Command >> 2 & 0x01);
	M_Dio_void_PinWrite(LCD_D3_PIN,Copy_u8_Command >> 3 & 0x01);
	M_Dio_void_PinWrite(LCD_D4_PIN,Copy_u8_Command >> 4 & 0x01);
	M_Dio_void_PinWrite(LCD_D5_PIN,Copy_u8_Command >> 5 & 0x01);
	M_Dio_void_PinWrite(LCD_D6_PIN,Copy_u8_Command >> 6 & 0x01);
	M_Dio_void_PinWrite(LCD_D7_PIN,Copy_u8_Command >> 7 & 0x01);

	M_Dio_void_PinWrite(LCD_EN_PIN,HIGH);
	_delay_ms(5);
	M_Dio_void_PinWrite(LCD_EN_PIN,LOW);
#elif LCD_MODE   ==   _4_BIT_MODE
	M_Dio_void_PinWrite(LCD_D4_PIN,Copy_u8_Command >> 4 & 0x01);
	M_Dio_void_PinWrite(LCD_D5_PIN,Copy_u8_Command >> 5 & 0x01);
	M_Dio_void_PinWrite(LCD_D6_PIN,Copy_u8_Command >> 6 & 0x01);
	M_Dio_void_PinWrite(LCD_D7_PIN,Copy_u8_Command >> 7 & 0x01);
	M_Dio_void_PinWrite(LCD_EN_PIN,HIGH);
	_delay_ms(5);
	M_Dio_void_PinWrite(LCD_EN_PIN,LOW);
	_delay_ms(5);
	Copy_u8_Command = Copy_u8_Command << 4;
	M_Dio_void_PinWrite(LCD_D4_PIN,Copy_u8_Command >> 4 & 0x01);
	M_Dio_void_PinWrite(LCD_D5_PIN,Copy_u8_Command >> 5 & 0x01);
	M_Dio_void_PinWrite(LCD_D6_PIN,Copy_u8_Command >> 6 & 0x01);
	M_Dio_void_PinWrite(LCD_D7_PIN,Copy_u8_Command >> 7 & 0x01);
	M_Dio_void_PinWrite(LCD_EN_PIN,HIGH);
	_delay_ms(5);
	M_Dio_void_PinWrite(LCD_EN_PIN,LOW);
#endif
}
void H_Lcd_void_LcdSendCharacter(u8 Copy_u8_Character)
{
	M_Dio_void_PinWrite(LCD_RS_PIN,HIGH);
#if   LCD_MODE   ==   _8_BIT_MODE

	M_Dio_void_PinWrite(LCD_D0_PIN,Copy_u8_Character >> 0 & 0x01);
	M_Dio_void_PinWrite(LCD_D1_PIN,Copy_u8_Character >> 1 & 0x01);
	M_Dio_void_PinWrite(LCD_D2_PIN,Copy_u8_Character >> 2 & 0x01);
	M_Dio_void_PinWrite(LCD_D3_PIN,Copy_u8_Character >> 3 & 0x01);
	M_Dio_void_PinWrite(LCD_D4_PIN,Copy_u8_Character >> 4 & 0x01);
	M_Dio_void_PinWrite(LCD_D5_PIN,Copy_u8_Character >> 5 & 0x01);
	M_Dio_void_PinWrite(LCD_D6_PIN,Copy_u8_Character >> 6 & 0x01);
	M_Dio_void_PinWrite(LCD_D7_PIN,Copy_u8_Character >> 7 & 0x01);

	M_Dio_void_PinWrite(LCD_EN_PIN,HIGH);
	_delay_ms(5);
	M_Dio_void_PinWrite(LCD_EN_PIN,LOW);
#elif LCD_MODE   ==   _4_BIT_MODE
	M_Dio_void_PinWrite(LCD_D4_PIN,Copy_u8_Character >> 4 & 0x01);
	M_Dio_void_PinWrite(LCD_D5_PIN,Copy_u8_Character >> 5 & 0x01);
	M_Dio_void_PinWrite(LCD_D6_PIN,Copy_u8_Character >> 6 & 0x01);
	M_Dio_void_PinWrite(LCD_D7_PIN,Copy_u8_Character >> 7 & 0x01);
	M_Dio_void_PinWrite(LCD_EN_PIN,HIGH);
	_delay_ms(5);
	M_Dio_void_PinWrite(LCD_EN_PIN,LOW);
	_delay_ms(5);
	Copy_u8_Character = Copy_u8_Character << 4;
	M_Dio_void_PinWrite(LCD_D4_PIN,Copy_u8_Character >> 4 & 0x01);
	M_Dio_void_PinWrite(LCD_D5_PIN,Copy_u8_Character >> 5 & 0x01);
	M_Dio_void_PinWrite(LCD_D6_PIN,Copy_u8_Character >> 6 & 0x01);
	M_Dio_void_PinWrite(LCD_D7_PIN,Copy_u8_Character >> 7 & 0x01);
	M_Dio_void_PinWrite(LCD_EN_PIN,HIGH);
	_delay_ms(5);
	M_Dio_void_PinWrite(LCD_EN_PIN,LOW);
#endif
}
void H_Lcd_void_LcdSendString(u8 *Copy_u8_Ptr)
{
	u8 Local_u8_Counter = 0;
	while(Copy_u8_Ptr[Local_u8_Counter] != '\0')
	{
		H_Lcd_void_LcdSendCharacter(Copy_u8_Ptr[Local_u8_Counter]);
		Local_u8_Counter++;
	}
}
void H_Lcd_void_LcdSendNumber(s32 Copy_s32_Number)
{
	u8 Local_u8_Arr [11];
	s8 Local_s8_Counter = 0;
	if(Copy_s32_Number < 0)
	{
		Copy_s32_Number = Copy_s32_Number * -1;
		H_Lcd_void_LcdSendCharacter('-');
	}
	do
	{
		Local_u8_Arr[Local_s8_Counter] = Copy_s32_Number % 10;
		Copy_s32_Number = Copy_s32_Number / 10;
		Local_s8_Counter++;
	}while(Copy_s32_Number != 0);
	Local_s8_Counter--;
	while(Local_s8_Counter >= 0)
	{
		H_Lcd_void_LcdSendCharacter(Local_u8_Arr[Local_s8_Counter] + 48);
		Local_s8_Counter--;
	}

}
void H_Lcd_void_LcdClear(void)
{
	H_Lcd_void_LcdSendCommand(LCD_CLEAR_COMMAND);
}
/*void H_Lcd_void_LcdGoTo(u8 Copy_u8_Row,u8 Copy_u8_Col)
{
	u8 Local_u8_Arr[2] = {0x80 , 0xC0};
	H_Lcd_void_LcdSendCommand(Local_u8_Arr[Copy_u8_Row] + Copy_u8_Col);
}*/

void H_Lcd_void_LcdGoTo(u8 Copy_u8_Row,u8 Copy_u8_Col)
{
	u8 data ; // the command which will set the position of the cursor
	/* in case of wrong input set the cursor to the first position of the LCD*/
	if(Copy_u8_Row>2||Copy_u8_Row<1||Copy_u8_Col>16||Copy_u8_Col<1)
	{
		data=0x80;
	}
	/********************************************/
	/*set the postion of cursor depend on the selected row and coloumn*/
	if(Copy_u8_Row==1)
	{
		data=0x80+Copy_u8_Col-1 ;
	}
	else if (Copy_u8_Row==2)
	{
		data=0xc0+Copy_u8_Col-1;
	}
	/**************************************/

	H_Lcd_void_LcdSendCommand(data); //set the position  of the cursor
}
