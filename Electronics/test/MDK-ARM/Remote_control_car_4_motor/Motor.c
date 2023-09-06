#include "Motor.h"
#include "pwm.h"

void Control_Motor(Motor_TypeDef *motor, MotorState motor_state, uint8_t speed)
{
	switch(motor_state)
	{
		case MOTOR_STOP_STATE:
			HAL_GPIO_WritePin(motor->IO_Port, motor->IO_Pin, GPIO_PIN_RESET);
			set_pwm_duty(motor->htim,motor->channel,0);
			break;
		case MOTOR_CW_STATE:
			HAL_GPIO_WritePin(motor->IO_Port, motor->IO_Pin, GPIO_PIN_RESET);
			set_pwm_duty(motor->htim,motor->channel,speed);
			break;
		case MOTOR_CCW_STATE:
			HAL_GPIO_WritePin(motor->IO_Port, motor->IO_Pin, GPIO_PIN_SET);
			set_pwm_duty(motor->htim,motor->channel, 100-speed);
			break;
	}
	motor->motor_state = motor_state;
}

void motor_init(Motor_TypeDef *motor, TIM_HandleTypeDef *htim, uint32_t channel, 
								GPIO_TypeDef *IO_Port, uint16_t IO_Pin)
{
	motor->IO_Port = IO_Port;
	motor->IO_Pin = IO_Pin;
	motor->htim = htim;
	motor->channel = channel;
	HAL_TIM_PWM_Start(htim, channel);
}