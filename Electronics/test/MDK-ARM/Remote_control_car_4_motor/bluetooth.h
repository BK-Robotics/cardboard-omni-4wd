#ifndef BLUETOOTH_H
#define BLUETOOTH_H
#include <stdint.h>
//Information to control by bluetooth:
/*
== character to control car:
- Stop													: 'S'
- ForWard												: 'F'
- BackWard											:	'B'
- Going to Left									:	'L'
- Going to Right								:	'R'
- Counter ClockWise - Turn Left	:	'W'
- ClockWise - Turn Right				:	'C'
- Forward and Left							:	'Z'
- Forward and Right							:	'Y'
- Backward and Left							:	'G'
- Backward and Right						:	'T'
--------------------------------
== character to control car speed:
- 10 -> 90 	: 1 -> 9 
- 100 			:	'q'
*/
void bluetooth_handle(uint8_t *uart_flag, uint8_t *data_rx, uint8_t *car_speed);
void bluetooth_init();
#endif
