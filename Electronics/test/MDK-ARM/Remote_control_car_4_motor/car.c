#include "car.h"


Motor_TypeDef front_left_motor;
Motor_TypeDef front_right_motor;
Motor_TypeDef back_left_motor;
Motor_TypeDef back_right_motor;

// car_control function check car's state and control 4 motor to run following this state
void car_control(CarState car_state, uint8_t speed)
{
	switch(car_state)
	{
		case CAR_STOP_STATE:			//CASE 1: STOP
			Control_Motor(&front_left_motor, MOTOR_STOP_STATE, 0); 
			Control_Motor(&front_right_motor, MOTOR_STOP_STATE, 0);
			Control_Motor(&back_left_motor, MOTOR_STOP_STATE, 0);
			Control_Motor(&back_right_motor, MOTOR_STOP_STATE, 0);
			break;
		case CAR_FORWARD_STATE:		//CASE 2: FORWARD
			Control_Motor(&front_left_motor, MOTOR_CCW_STATE, speed);
			Control_Motor(&front_right_motor, MOTOR_CW_STATE, speed);
			Control_Motor(&back_left_motor, MOTOR_CCW_STATE, speed);
			Control_Motor(&back_right_motor, MOTOR_CW_STATE, speed);
			break;
		case CAR_BACKWARD_STATE:	//CASE 3: BACKWARD
			Control_Motor(&front_left_motor, MOTOR_CW_STATE, speed);
			Control_Motor(&front_right_motor, MOTOR_CCW_STATE, speed);
			Control_Motor(&back_left_motor, MOTOR_CW_STATE, speed);
			Control_Motor(&back_right_motor, MOTOR_CCW_STATE, speed);
			break;
		case CAR_COUNTER_CLOCKWISE_STATE:	//CASE 4: TURN LEFT - COUNTER_CLOCK_WISE
			Control_Motor(&front_left_motor, MOTOR_CW_STATE, speed);
			Control_Motor(&front_right_motor, MOTOR_CW_STATE, speed);
			Control_Motor(&back_left_motor, MOTOR_CW_STATE, speed);
			Control_Motor(&back_right_motor, MOTOR_CW_STATE, speed);
			break;
		case CAR_CLOCKWISE_STATE://CASE 5: TURN RIGHT - CLOCK_WISE
			Control_Motor(&front_left_motor, MOTOR_CCW_STATE, speed);
			Control_Motor(&front_right_motor, MOTOR_CCW_STATE, speed);
			Control_Motor(&back_left_motor, MOTOR_CCW_STATE, speed);
			Control_Motor(&back_right_motor, MOTOR_CCW_STATE, speed);
			break;
		case CAR_LEFT_STATE:			//CASE 6: GO TO LEFT
			Control_Motor(&front_left_motor, MOTOR_CCW_STATE, speed);
			Control_Motor(&front_right_motor, MOTOR_CCW_STATE, speed);
			Control_Motor(&back_left_motor, MOTOR_CW_STATE, speed);
			Control_Motor(&back_right_motor, MOTOR_CW_STATE, speed);
			break;
		case CAR_RIGHT_STATE:			//CASE 6: GO TO RIGHT
			Control_Motor(&front_left_motor, MOTOR_CW_STATE, speed);
			Control_Motor(&front_right_motor, MOTOR_CW_STATE, speed);
			Control_Motor(&back_left_motor, MOTOR_CCW_STATE, speed);
			Control_Motor(&back_right_motor, MOTOR_CCW_STATE, speed);
			break;
		case CAR_FRONT_LEFT_STATE://CASE 7: FORWARD LEFT
			Control_Motor(&front_left_motor, MOTOR_CCW_STATE, speed);
			Control_Motor(&front_right_motor, MOTOR_STOP_STATE, 0);
			Control_Motor(&back_left_motor, MOTOR_STOP_STATE, 0);
			Control_Motor(&back_right_motor, MOTOR_CW_STATE, speed);
			break;
		case CAR_FRONT_RIGHT_STATE://CASE 8: FORWARD RIGHT
			Control_Motor(&front_left_motor, MOTOR_STOP_STATE, 0);
			Control_Motor(&front_right_motor, MOTOR_CW_STATE, speed);
			Control_Motor(&back_left_motor, MOTOR_CCW_STATE, speed);
			Control_Motor(&back_right_motor, MOTOR_STOP_STATE, 0);
			break;
		case CAR_BACK_LEFT_STATE: //CASE 9: BACKWARD LEFT
			Control_Motor(&front_left_motor, MOTOR_STOP_STATE, 0);
			Control_Motor(&front_right_motor, MOTOR_CCW_STATE, speed);
			Control_Motor(&back_left_motor, MOTOR_CW_STATE, speed);
			Control_Motor(&back_right_motor, MOTOR_STOP_STATE, 0);
			break;
		case CAR_BACK_RIGHT_STATE://CASE 10: BACKWARD RIGHT
			Control_Motor(&front_left_motor, MOTOR_CW_STATE, speed);
			Control_Motor(&front_right_motor, MOTOR_STOP_STATE, 0);
			Control_Motor(&back_left_motor, MOTOR_STOP_STATE, 0);
			Control_Motor(&back_right_motor, MOTOR_CCW_STATE, speed);
			break;
	}
}

void car_init(TIM_HandleTypeDef *htim)
{
	
	motor_init(&front_left_motor, htim, FL_PWM_CHANNEL ,		// FRONT_LEFT_MOTOR
							FL_IO_GPIO_Port, FL_IO_Pin);	
	motor_init(&front_right_motor, htim, FR_PWM_CHANNEL,		// FRONT_RIGHT_MOTOR
							FR_IO_GPIO_Port, FR_IO_Pin);	
	motor_init(&back_left_motor, htim, BL_PWM_CHANNEL,			// BACK_LEFT_MOTOR
							BL_IO_GPIO_Port, BL_IO_Pin);	
	motor_init(&back_right_motor, htim, BR_PWM_CHANNEL,		// BACK_RIGHT_MOTOR
							BR_IO_GPIO_Port, BR_IO_Pin);	
	car_control(CAR_STOP_STATE, 0);												// Set up Car in Stop state
}
