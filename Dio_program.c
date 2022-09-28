/*
 * Dio_program.c
 *
 *  Created on: ???/???/????
 *      Author: dell
 */
#include "Dio_private.h"
#include "Dio_interface.h"

void M_Dio_void_PinMode(u8 Copy_u8_Value,u8 Copy_u8_PinMode)
{
	u8 Local_u8_PinNum  = Copy_u8_Value % 10;
	u8 Local_u8_PortNum = Copy_u8_Value / 10;
	switch(Copy_u8_PinMode)
	{
	case INPUT:
		switch(Local_u8_PortNum)
		{
		case 1  : CLR_BIT(DDRA_REG,Local_u8_PinNum); break;
		case 2  : CLR_BIT(DDRB_REG,Local_u8_PinNum); break;
		case 3  : CLR_BIT(DDRC_REG,Local_u8_PinNum); break;
		case 4  : CLR_BIT(DDRD_REG,Local_u8_PinNum); break;
		default :                                    break;
		}
		break;
	case OUTPUT:
		switch(Local_u8_PortNum)
		{
		case 1  : SET_BIT(DDRA_REG,Local_u8_PinNum); break;
		case 2  : SET_BIT(DDRB_REG,Local_u8_PinNum); break;
		case 3  : SET_BIT(DDRC_REG,Local_u8_PinNum); break;
		case 4  : SET_BIT(DDRD_REG,Local_u8_PinNum); break;
		default :                                    break;
		}		break;
		default :    break;
	}
}


void M_Dio_void_PinWrite(u8 Copy_u8_Value,u8 Copy_u8_PinMode)
{
	u8 Local_u8_PinNum  = Copy_u8_Value % 10;
	u8 Local_u8_PortNum = Copy_u8_Value / 10;
	switch(Copy_u8_PinMode)
	{
	case LOW:
		switch(Local_u8_PortNum)
		{
		case 1  : CLR_BIT(PORTA_REG,Local_u8_PinNum); break;
		case 2  : CLR_BIT(PORTB_REG,Local_u8_PinNum); break;
		case 3  : CLR_BIT(PORTC_REG,Local_u8_PinNum); break;
		case 4  : CLR_BIT(PORTD_REG,Local_u8_PinNum); break;
		default :                                     break;
		}
		break;
	case HIGH:
		switch(Local_u8_PortNum)
		{
		case 1  : SET_BIT(PORTA_REG,Local_u8_PinNum); break;
		case 2  : SET_BIT(PORTB_REG,Local_u8_PinNum); break;
		case 3  : SET_BIT(PORTC_REG,Local_u8_PinNum); break;
		case 4  : SET_BIT(PORTD_REG,Local_u8_PinNum); break;
		default :                                     break;
		}		break;
		default :    break;

	}
}


void M_Dio_void_PinTog(u8 Copy_u8_Value)
{
	u8 Local_u8_PinNum  = Copy_u8_Value % 10;
	u8 Local_u8_PortNum = Copy_u8_Value / 10;
	switch(Local_u8_PortNum)
	{
	case 1  : TOG_BIT(PORTA_REG,Local_u8_PinNum); break;
	case 2  : TOG_BIT(PORTB_REG,Local_u8_PinNum); break;
	case 3  : TOG_BIT(PORTC_REG,Local_u8_PinNum); break;
	case 4  : TOG_BIT(PORTD_REG,Local_u8_PinNum); break;
	default :                                     break;
	}
}
u8   M_Dio_u8_PinRead(u8 Copy_u8_Value)
{
	u8 Local_u8_PinNum  = Copy_u8_Value % 10;
	u8 Local_u8_PortNum = Copy_u8_Value / 10;
	u8 Local_u8_Reading = 0;
	switch(Local_u8_PortNum)
	{
	case 1  : Local_u8_Reading = GET_BIT(PINA_REG,Local_u8_PinNum); break;
	case 2  : Local_u8_Reading = GET_BIT(PINB_REG,Local_u8_PinNum); break;
	case 3  : Local_u8_Reading = GET_BIT(PINC_REG,Local_u8_PinNum); break;
	case 4  : Local_u8_Reading = GET_BIT(PIND_REG,Local_u8_PinNum); break;
	default :                                                       break;
	}
	return Local_u8_Reading;
}
