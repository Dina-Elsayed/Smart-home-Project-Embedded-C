/*
 * Timer1_prg.c
 *
 *  Created on: Aug 23, 2022
 *      Author: aya_enan
 */
#include "StandardTypes.h"
#include "BitMath.h"
#include "Timer1_priv.h"
#include "Timer1_config.h"
#include "Timer1_int.h"

#include <avr/interrupt.h>
static void (*Timer1_ICU_CallBack)(void) = NULL;
void M_Timer1_void_Init(void)
{
   //step 1 : config timer in Normal Mode
	CLR_BIT(TCCR1A_REG,WGM10_BIT);
	CLR_BIT(TCCR1A_REG,WGM11_BIT);
	CLR_BIT(TCCR1B_REG,WGM12_BIT);
	CLR_BIT(TCCR1B_REG,WGM13_BIT);

  //step 2 : config prescaler => 256
	CLR_BIT(TCCR1B_REG,CS10_BIT);
	CLR_BIT(TCCR1B_REG,CS11_BIT);
	SET_BIT(TCCR1B_REG,CS12_BIT);
}

void M_Timer1_void_ICU_init(void)
{
  // set trigger as rising edge
	SET_BIT(TCCR1B_REG,ICES1_BIT);
}

u16 M_Timer1_u16_ICU_inputRead(void)
{
   return ICR1_REG;
}

void M_Timer1_void_ICU_setCallBack(void (*ptr)(void))
{
	Timer1_ICU_CallBack = ptr;
}

void M_Timer1_void_ICU_EnableInt(void)
{
	SET_BIT(TIMSK_REG,TICIE1_BIT);
}

void M_Timer1_void_ICU_DisableInt(void)
{
	CLR_BIT(TIMSK_REG,TICIE1_BIT);
}

void M_Timer1_void_ICU_setTrigger(u8 copy_u8trigger)
{
	// Method 1
   switch(copy_u8trigger)
   {
   case TIMER1_ICU_RISING_TRIGG :
	   SET_BIT(TCCR1B_REG,ICES1_BIT);
	   break;
   case TIMER1_ICU_FALLING_TRIGG:
	   CLR_BIT(TCCR1B_REG,ICES1_BIT);
	   break;
   default :
	   break;
   }
   // Method 2
 //  TCCR1B_REG &= 0b10111111;
 //  TCCR1B_REG |= copy_u8trigger << 6;

}

ISR(TIMER1_CAPT_vect)
{
	Timer1_ICU_CallBack();
}
