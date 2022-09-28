/*
 * Timer_0_program.c
 *
 *  Created on: ???/???/????
 *      Author: dell
 */
//
//#include "StandardTypes.h"
//#include "BitMath.h"
//#include <avr/interrupt.h>
#include "StandardTypes.h"
#include "BitMath.h"
#include "Timer_0_private.h"
#include "Timer_0_configuration.h"
#include "Timer_0_interface.h"
#include <stdlib.h>
#include <avr/interrupt.h>
void (*Timer_0_CallBack[2]) (void) = {NULL};

u32 Timer_0_u32_NumOfOv = 0;
u8  Timer_0_u8_RemTicks = 0;
u32 Timer0_u32NumOfCm = 0;
void M_Timer_0_void_Init(void)
{
	// step 1 : config Timer Mode
#if(TIMER_0_MODE ==  TIMER0_NORMAL_MODE )
	CLR_BIT(TCCR0_REG,WGM00_BIT);
	CLR_BIT(TCCR0_REG,WGM01_BIT);
#if (TIMER_0_OC0_MODE >= 0 && TIMER_0_OC0_MODE <= 3)
	//step 1 : apply mask
	TCCR0_REG &= TIMER0_OC0_MODE_MASK;
	//step 2 : insert value
	TCCR0_REG |= TIMER_0_OC0_MODE << TIMER0_OC0_SHIFT ;
#else
 #error ("wrong OC0 mode ")
#endif

#elif(TIMER_0_MODE ==  TIMER0_CTC_MODE )
	CLR_BIT(TCCR0_REG,WGM00_BIT);
	SET_BIT(TCCR0_REG,WGM01_BIT);
#if (TIMER_0_OC0_MODE >= 0 && TIMER_0_OC0_MODE <= 3)
	//step 1 : apply mask
	TCCR0_REG &= TIMER0_OC0_MODE_MASK;
	//step 2 : insert value
	TCCR0_REG |= TIMER_0_OC0_MODE << TIMER0_OC0_SHIFT ;
#else
 #error ("wrong OC0 mode ")
#endif
#elif(TIMER_0_MODE ==  TIMER0_PHASECORRECT_MODE )
	SET_BIT(TCCR0_REG,WGM00_BIT);
	CLR_BIT(TCCR0_REG,WGM01_BIT);
    #if(TIMER_0_OC0_MODE ==  TIMER0_OC0_PWM_NON_INVERTING || TIMER_0_OC0_MODE  == TIMER0_OC0_PWM_INVERTING)
	//step 1 : apply mask
	TCCR0_REG &= TIMER0_OC0_MODE_MASK;
	//step 2 : insert value
	TCCR0_REG |= TIMER_0_OC0_MODE  ;
    #else
       #error("wrong OC0 mode")
    #endif
#elif(TIMER_0_MODE ==  TIMER0_FASTPWM_MODE  )
	SET_BIT(TCCR0_REG,WGM00_BIT);
	SET_BIT(TCCR0_REG,WGM01_BIT);
    #if(TIMER_0_OC0_MODE ==  TIMER0_OC0_PWM_NON_INVERTING || TIMER_0_OC0_MODE  == TIMER0_OC0_PWM_INVERTING)
	//step 1 : apply mask
	TCCR0_REG &= TIMER0_OC0_MODE_MASK;
	//step 2 : insert value
	TCCR0_REG |= TIMER_0_OC0_MODE  ;
    #else
      #error("wrong OC0 mode")
    #endif
#else
   #error ("wrong Timer Mode")
#endif



}
void M_Timer_0_void_SetTime(u32 Copy_u32_DesiredTime)
{
	u32 Local_arr_prescaler[5] = {1,8,64,256,1024};
	u32 Local_u32_TickTime   = Local_arr_prescaler[TIMER_0_PRESCALER-1] / F_OSC;   // result will be in micro
	u32 Local_u32_TotalTicks = (Copy_u32_DesiredTime * 1000) / Local_u32_TickTime;
#if(TIMER_0_MODE ==  TIMER0_NORMAL_MODE )
	Timer_0_u32_NumOfOv      = Local_u32_TotalTicks / 256;
	Timer_0_u8_RemTicks      = Local_u32_TotalTicks % 256;
	if(Timer_0_u8_RemTicks != 0)
	{
		TCNT0_REG = 256 - Timer_0_u8_RemTicks;
		Timer_0_u32_NumOfOv++;
	}
#elif(TIMER_0_MODE ==  TIMER0_CTC_MODE)
	u8 Local_u8Counter = 255;
	while((Local_u32_TotalTicks % Local_u8Counter) )
	{
		Local_u8Counter--;
	}
	Timer0_u32NumOfCm  = Local_u32_TotalTicks /Local_u8Counter;
	OCR0_REG  = Local_u8Counter;
#endif
}
void M_Timer_0_void_Start(void)
{
#if(TIMER_0_PRESCALER>= 0 && TIMER_0_PRESCALER <=7)
	//step 1 : apply mask
	TCCR0_REG &= TIMER0_PRESCALER_MASK;
	//step 2 : insert value
	TCCR0_REG |= TIMER_0_PRESCALER;
#else
  #error("wrong prescaler")
#endif
}
void M_Timer_0_void_Stop(void)
{
	CLR_BIT(TCCR0_REG,CS00_BIT);
	CLR_BIT(TCCR0_REG,CS01_BIT);
	CLR_BIT(TCCR0_REG,CS02_BIT);
}
void M_Timer_0_SetCallBack(void (*Copy_Ptr)(void),u8 IntID )
{
	Timer_0_CallBack[IntID] = Copy_Ptr;
}
void M_Timer_0_void_EnableInt(u8 copy_u8IntId)
{
    switch(copy_u8IntId)
    {
    case TIMER0_OVF_INT_ID:
    	SET_BIT(TIMSK_REG,TOIE0_BIT);
    	break;
    case TIMER0_COMP_MATCH_INT_ID:
    	SET_BIT(TIMSK_REG,OCIE0_BIT);
    	break;
    default: break;
    }
}
void M_Timer_0_void_DisableInt(u8 copy_u8IntId)
{
	 switch(copy_u8IntId)
	{
	case TIMER0_OVF_INT_ID:
		CLR_BIT(TIMSK_REG,TOIE0_BIT);
		break;
	case TIMER0_COMP_MATCH_INT_ID:
		CLR_BIT(TIMSK_REG,OCIE0_BIT);
		break;
	default: break;
	}
}
void M_Timer_0_void_SetFastPWM(u8 copy_u8DutyCycle)
{
#if(TIMER_0_MODE ==  TIMER0_FASTPWM_MODE )
  #if(TIMER_0_OC0_MODE ==  TIMER0_OC0_PWM_NON_INVERTING)
	OCR0_REG   = abs(((copy_u8DutyCycle * 256)/100)-1);
  #elif(TIMER_0_OC0_MODE == TIMER0_OC0_PWM_INVERTING)
	OCR0_REG   = abs(255 - ((copy_u8DutyCycle * 256)/100));
  #else
    #error ("wrong OC0 mode")
  #endif
#endif
}
void M_Timer_0_void_SetPhaseCorrectPWM(u8 copy_u8DutyCycle)
{
#if(TIMER_0_MODE ==  TIMER0_PHASECORRECT_MODE )
  #if(TIMER_0_OC0_MODE ==  TIMER0_OC0_PWM_NON_INVERTING)
	OCR0_REG  = ((copy_u8DutyCycle* 255)/100);
  #elif(TIMER_0_OC0_MODE == TIMER0_OC0_PWM_INVERTING)
	OCR0_REG  =( 255 -  ((copy_u8DutyCycle* 255)/100));
  #else
    #error ("wrong OC0 mode")
  #endif
#endif
}
ISR(TIMER0_OVF_vect)
{
	if(Timer_0_CallBack[TIMER0_OVF_INT_ID] != NULL)
	{
		static u32 Local_u32_Counter = 0;
		Local_u32_Counter++;
		if(Local_u32_Counter == Timer_0_u32_NumOfOv)
		{
			Timer_0_CallBack[TIMER0_OVF_INT_ID]();
			Local_u32_Counter=0;
			TCNT0_REG = 256 - Timer_0_u8_RemTicks;
		}
	}
}

ISR(TIMER0_COMP_vect)
{
	if(Timer_0_CallBack[TIMER0_COMP_MATCH_INT_ID] != NULL)
	{
		static u32 Local_u32_Counter = 0;
		Local_u32_Counter++;
		if(Local_u32_Counter ==  Timer0_u32NumOfCm)
		{
			Timer_0_CallBack[TIMER0_COMP_MATCH_INT_ID]();
			Local_u32_Counter=0;

		}
	}
}
