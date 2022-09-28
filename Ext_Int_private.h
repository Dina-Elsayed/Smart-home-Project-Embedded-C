/*
 * Ext_Int_private.h
 *
 *  Created on: ???/???/????
 *      Author: dell
 */

#ifndef MCAL_EXT_INT_EXT_INT_PRIVATE_H_
#define MCAL_EXT_INT_EXT_INT_PRIVATE_H_

/********************************************_MACROS_*******************************/
#define FALLING_EDGE              1
#define RISING_EDGE               2
#define LOW_LEVEL                 3
#define LOGICAL_CHANGE            4
/********************************************_REGISTERS_****************************/
#define MCUCR_REG     (*((volatile u8*)0x55))
#define GICR_REG      (*((volatile u8*)0x5B))
#define MCUCSR_REG    (*((volatile u8*)0x54))
/********************************************_BITS_*********************************/
// MCUCR BITS
#define ISC11_BIT                 3
#define ISC10_BIT                 2
#define ISC01_BIT                 1
#define ISC00_BIT                 0
// GICR BITS
#define INT1_BIT                  7
#define INT0_BIT                  6
#define INT2_BIT                  5
// MCUCSR BITS
#define ISC2_BIT                  6

#endif /* MCAL_EXT_INT_EXT_INT_PRIVATE_H_ */
