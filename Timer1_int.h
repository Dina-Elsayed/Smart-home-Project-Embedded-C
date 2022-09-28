/*
 * Timer1_int.h
 *
 *  Created on: Aug 23, 2022
 *      Author: aya_enan
 */

#ifndef TIMER_1_TIMER1_INT_H_
#define TIMER_1_TIMER1_INT_H_

#define TIMER1_ICU_RISING_TRIGG   1
#define TIMER1_ICU_FALLING_TRIGG  0

void M_Timer1_void_Init(void);

void M_Timer1_void_ICU_init(void);
//input capture read
u16 M_Timer1_u16_ICU_inputRead(void);
//set call back
void M_Timer1_void_ICU_setCallBack(void (*ptr)(void));
//interrupt Enable
void M_Timer1_void_ICU_EnableInt(void);
//interrupt disable
void M_Timer1_void_ICU_DisableInt(void);
//set trigger
void M_Timer1_void_ICU_setTrigger(u8 copy_u8trigger);
#endif /* TIMER_1_TIMER1_INT_H_ */
