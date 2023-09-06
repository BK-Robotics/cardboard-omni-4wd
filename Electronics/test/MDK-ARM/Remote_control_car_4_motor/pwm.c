#include "pwm.h"

void set_pwm_duty(TIM_HandleTypeDef *htim, uint16_t channel, uint8_t duty)
{
	uint16_t ccr = (uint16_t)duty*(htim->Instance->ARR)/100;
		switch(channel)
	{		
		case TIM_CHANNEL_1:
			htim->Instance->CCR1 = ccr;
			break;
		case TIM_CHANNEL_2:
			htim->Instance->CCR2 = ccr;
			break;
		case TIM_CHANNEL_3:
			htim->Instance->CCR3 = ccr;
			break;
		case TIM_CHANNEL_4:
			htim->Instance->CCR4 = ccr;
			break;
		HAL_TIM_PWM_Start(htim, channel);
	}
}
