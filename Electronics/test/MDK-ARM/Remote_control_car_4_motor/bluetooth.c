#include "bluetooth.h"
#include "car.h"
void bluetooth_handle(uint8_t *uart_flag, uint8_t *data_rx, uint8_t *car_speed)
{
	if(uart_flag)
		{
			
			switch(*data_rx)
			{
				case 'S': //Stop
					car_control(CAR_STOP_STATE, 0);
					break;
				case 'F': // Forward
					car_control(CAR_FORWARD_STATE, *car_speed);
					break;
				case 'B': // Backward
					car_control(CAR_BACKWARD_STATE, *car_speed);
					break;
				case 'L': //Going Left
					car_control(CAR_LEFT_STATE, *car_speed);
					break;
				case 'R': // Going Right
					car_control(CAR_RIGHT_STATE, *car_speed);
					break;
				case 'W': // ClockWise - Turn Right
					car_control(CAR_CLOCKWISE_STATE, *car_speed);
					break;
				case 'C':	// Counter ClockWise - Turn Left
					car_control(CAR_COUNTER_CLOCKWISE_STATE, *car_speed);
					break;
				case 'G': //FORWAR AND LEFT
					car_control(CAR_FRONT_LEFT_STATE, *car_speed);
					break;
				case 'I': // FORWAR AND RIGHT
					car_control(CAR_FRONT_RIGHT_STATE, *car_speed);
					break;
				case 'H': // BACKWARD AND LEFT
					car_control(CAR_BACK_LEFT_STATE, *car_speed);
					break;
				case 'J':	// BACKWARD AND RIGHT
					car_control(CAR_BACK_RIGHT_STATE, *car_speed);
					break;
				default:
					if(*data_rx >= '0' && *data_rx <= '9')
					{
						*car_speed = (uint8_t)(*data_rx -'0')*10;
						
					}
					else if(*data_rx == 'q')
					{
						*car_speed = 100;
					}
					break;
			}
			*uart_flag = 0;
		}
}
void bluetooth_init()
{
	
}
