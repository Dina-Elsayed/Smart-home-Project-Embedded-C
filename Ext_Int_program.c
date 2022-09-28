/*
 * Ext_Int_program.c
 *
 *  Created on: ???/???/????
 *      Author: dell
 */

#include "Led_interface.h"    // remove later

#include "Ext_Int_private.h"
#include "Ext_Int_interface.h"

void (*Ext_Int_CallBack) (void);

void M_Ext_Int_void_Init(u8 Copy_u8_Int)
{
	switch(Copy_u8_Int)
	{
	case EXT_INT_0:
#if   EXT_INT0_SENSE_CONTROL   ==   FALLING_EDGE
		SET_BIT(MCUCR_REG,ISC01_BIT);
		CLR_BIT(MCUCR_REG,ISC00_BIT);
#elif EXT_INT0_SENSE_CONTROL   ==   RISING_EDGE
		SET_BIT(MCUCR_REG,ISC01_BIT);
		SET_BIT(MCUCR_REG,ISC00_BIT);
#elif EXT_INT0_SENSE_CONTROL   ==   LOW_LEVEL
		CLR_BIT(MCUCR_REG,ISC01_BIT);
		CLR_BIT(MCUCR_REG,ISC00_BIT);
#elif EXT_INT0_SENSE_CONTROL   ==   LOGICAL_CHANGE
		CLR_BIT(MCUCR_REG,ISC01_BIT);
		SET_BIT(MCUCR_REG,ISC00_BIT);
#endif
		// to enable int0 interrupt
		SET_BIT(GICR_REG,INT0_BIT);

		break;
	case EXT_INT_1:
#if   EXT_INT1_SENSE_CONTROL   ==   FALLING_EDGE
		SET_BIT(MCUCR_REG,ISC11_BIT);
		CLR_BIT(MCUCR_REG,ISC10_BIT);
#elif EXT_INT1_SENSE_CONTROL   ==   RISING_EDGE
		SET_BIT(MCUCR_REG,ISC10_BIT);
		SET_BIT(MCUCR_REG,ISC11_BIT);
#elif EXT_INT1_SENSE_CONTROL   ==   LOW_LEVEL
		CLR_BIT(MCUCR_REG,ISC10_BIT);
		CLR_BIT(MCUCR_REG,ISC11_BIT);
#elif EXT_INT1_SENSE_CONTROL   ==   LOGICAL_CHANGE
		CLR_BIT(MCUCR_REG,ISC11_BIT);
		SET_BIT(MCUCR_REG,ISC10_BIT);
#endif
		// to enable int0 interrupt
		SET_BIT(GICR_REG,INT1_BIT);

		break;
	case EXT_INT_2:
#if   EXT_INT2_SENSE_CONTROL   ==   FALLING_EDGE
		CLR_BIT(MCUCSR_REG,ISC2_BIT);
#elif EXT_INT2_SENSE_CONTROL   ==   RISING_EDGE
		SET_BIT(MCUCSR_REG,ISC2_BIT);
#endif
		// to enable int0 interrupt
		SET_BIT(GICR_REG,INT2_BIT);
		break;
	default:   break;
	}
	M_GIE_void_Enable();
}

void M_Ext_Int_void_SetCallBack(void (*Copy_Ptr) (void))
{
	Ext_Int_CallBack = Copy_Ptr;
}

ISR(INT0_vect)
{
	Ext_Int_CallBack();
}
