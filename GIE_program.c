/*
 * GIE_program.c
 *
 *  Created on: ???/???/????
 *      Author: dell
 */

#include "GIE_private.h"
#include "GIE_interface.h"

void M_GIE_void_Enable(void)
{
	SET_BIT(SREG_REG,I_BIT);
}
void M_GIE_void_Disable(void)
{
	CLR_BIT(SREG_REG,I_BIT);
}
