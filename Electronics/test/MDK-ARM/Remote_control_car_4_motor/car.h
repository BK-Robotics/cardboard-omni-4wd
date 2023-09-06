#ifndef CAR_H
#define CAR_H

#include "Motor.h"
#include "pwm.h"
// You also config pins on STM32CubeMX on yourself
// pin of Front left motor
#define FL_IO_Pin 				GPIO_PIN_7
#define FL_IO_GPIO_Port 	GPIOE
// pin of front right motor
#define FR_IO_Pin 				GPIO_PIN_8
#define FR_IO_GPIO_Port 	GPIOE
// pin of back left motor
#define BL_IO_Pin 				GPIO_PIN_10
#define BL_IO_GPIO_Port 	GPIOE
// pin of back right motor
#define BR_IO_Pin 				GPIO_PIN_12
#define BR_IO_GPIO_Port 	GPIOE

// the channels of TIMER control PWM pulse
// check the pin of the channels on STM32CubeMX
#define FL_PWM_CHANNEL 		TIM_CHANNEL_1
#define FR_PWM_CHANNEL 		TIM_CHANNEL_2
#define BL_PWM_CHANNEL 		TIM_CHANNEL_3
#define BR_PWM_CHANNEL 		TIM_CHANNEL_4

// the state of car when active
typedef enum
{
	CAR_STOP_STATE, 						// STOP
	CAR_FORWARD_STATE, 					// FORWARD
	CAR_BACKWARD_STATE, 				// BACKWARD
	CAR_COUNTER_CLOCKWISE_STATE,// TURN LEFT
	CAR_CLOCKWISE_STATE, 				// TURN RIGHT
	CAR_LEFT_STATE, 						// GOING LEFT
	CAR_RIGHT_STATE, 						// GOING RIGHT
	CAR_FRONT_LEFT_STATE, 			// GOING FRONT LEFT
	CAR_FRONT_RIGHT_STATE, 			// GOING FRONT RIGHT
	CAR_BACK_LEFT_STATE,				// GOING BACK LEFT
	CAR_BACK_RIGHT_STATE				// GOING BACK RIGHT
}CarState;



void car_control(CarState car_state, uint8_t speed);
void car_init(TIM_HandleTypeDef *htim);


#endif