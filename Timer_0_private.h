/*
 * Timer_0_private.h
 *
 *  Created on: ???/???/????
 *      Author: dell
 */

#ifndef MCAL_TIMER_0_TIMER_0_PRIVATE_H_
#define MCAL_TIMER_0_TIMER_0_PRIVATE_H_

#define TCCR0_REG     (*((volatile u8*)0x53))
#define TIMSK_REG     (*((volatile u8*)0x59))
#define TCNT0_REG     (*((volatile u8*)0x52))
#define OCR0_REG      (*((volatile u8*)0x5C))

// TCCR0 BITS
#define WGM00_BIT          6
#define WGM01_BIT          3
#define CS02_BIT           2
#define CS01_BIT           1
#define CS00_BIT           0

// TIMSK BITS
#define TOIE0_BIT          0
#define OCIE0_BIT          1
/*Timer Mode*/
#define   TIMER0_NORMAL_MODE        0
#define   TIMER0_CTC_MODE           1
#define   TIMER0_PHASECORRECT_MODE  2
#define   TIMER0_FASTPWM_MODE       3

/*Timer prescaler*/
#define    TIMER0_PRESCALER_1                   1
#define    TIMER0_PRESCALER_8                   2
#define    TIMER0_PRESCALER_64                  3
#define    TIMER0_PRESCALER_256                 4 //100
#define    TIMER0_PRESCALER_1024                5 //101
#define    TIMER0_PRESCALER_EXTCLK_FALLEDGE     6
#define    TIMER0_PRESCALER_EXTCLK_RAISEDGE     7

/*Timer OC0 Mode */
#define   TIMER0_OC0_DISCONNECTED        0
#define   TIMER0_OC0_TOG                 1
#define   TIMER0_OC0_CLEAR               2
#define   TIMER0_OC0_SET                 3
#define   TIMER0_OC0_PWM_NON_INVERTING   0b00100000 //vlaue is inside mask
#define   TIMER0_OC0_PWM_INVERTING       0b00110000 //value is inside mask


#define TIMER0_PRESCALER_MASK 0b11111000

#define TIMER0_OC0_MODE_MASK  0b11001111

#define TIMER0_OC0_SHIFT  4

#endif /* MCAL_TIMER_0_TIMER_0_PRIVATE_H_ */
