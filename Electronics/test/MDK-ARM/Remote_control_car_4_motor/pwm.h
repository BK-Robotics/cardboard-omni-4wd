#ifndef PWM_H
#define PWM_H
#include "stm32f4xx_hal.h"

void set_pwm_duty(TIM_HandleTypeDef *htim, uint16_t channel, uint8_t duty);

#endif