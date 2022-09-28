/*
 * DC_Motor_interface.h
 *
 *  Created on: Aug 29, 2022
 *      Author: pc
 */

#ifndef DC_MOTOR_DC_MOTOR_INTERFACE_H_
#define DC_MOTOR_DC_MOTOR_INTERFACE_H_
/*********_INCLUDES_**************/
#include "StandardTypes.h"
#include "BitMath.h"
#include "DC_Motor_config.h"
#include "Timer_0_interface.h"
/**********_PROTOTYPES_************/
void H_DC_Motor_void_Init(void);
void H_DC_Motor_void_DCMode(u8);
void H_DC_Motor_void_Speed(u8);

/************_MACROS_*************/
#define ROTATE_CLK_WISE           0
#define ROTATE_ANTI_CLK_WISE	  1
#define DC_MOTOR_STOP	  		  2

#define DC_LOW					  1
#define DC_HIGH					  0
#define Stop                      2
#endif /* DC_MOTOR_DC_MOTOR_INTERFACE_H_ */
