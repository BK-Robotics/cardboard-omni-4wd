#ifndef MOTOR_H
#define MOTOR_H

#include "stm32f4xx_hal.h"

typedef enum
{
	MOTOR_STOP_STATE,
	MOTOR_CW_STATE,		//CLOCKWISE
	MOTOR_CCW_STATE		// COUNTER_CLOCKWISE
}MotorState;

typedef struct
{
	TIM_HandleTypeDef *htim;
	uint32_t channel;
	GPIO_TypeDef *IO_Port;
	uint16_t IO_Pin;
	MotorState motor_state;
	uint8_t speed;
}Motor_TypeDef;

// initialize motor
void motor_init(Motor_TypeDef *motor, TIM_HandleTypeDef *htim, uint32_t channel, 
								GPIO_TypeDef *IO_Port, uint16_t IO_Pin);

// control motor
void Control_Motor(Motor_TypeDef *motor, MotorState motor_state, uint8_t speed);
#endif
