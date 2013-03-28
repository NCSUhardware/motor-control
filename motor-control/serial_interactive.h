/*
 * serial_interactive.h
 *
 *  Created on: Dec 22, 2012
 *      Author: eal
 */

#ifndef SERIAL_INTERACTIVE_H_
#define SERIAL_INTERACTIVE_H_

/**
 * Valid tokens that can be sent over serial. The values correspond to indices in
 * the tokens array in serial.c.
 */
typedef enum token {
	TOKEN_UNDEF = -1,
	TOKEN_A,
	TOKEN_B,
	TOKEN_C,
	TOKEN_COMPASS_START_CALIBRATION,
	TOKEN_COMPASS_STOP_CALIBRATION,
	TOKEN_D,
	TOKEN_HEADING,
	TOKEN_HEADING_PID,
	TOKEN_HELP,
	TOKEN_INTERACTIVE,
	TOKEN_MOTOR_PID,
	TOKEN_MOTOR_STEP_RESPONSE,
	TOKEN_MOVE,
	TOKEN_PWM,
	TOKEN_PWM_DRIVE,
	TOKEN_RESET,
	TOKEN_S,
	TOKEN_SENSOR,
	TOKEN_SENSORS,
	TOKEN_SENSORS_CONTINUOUS,
	TOKEN_SERVO,
	TOKEN_SET,
	TOKEN_SIZEOFS,
	TOKEN_STATUS,
	TOKEN_STOP,
	TOKEN_STRAIGHT,
	TOKEN_TURN_ABS,
	TOKEN_TURN_IN_PLACE,
	TOKEN_TURN_REL,
} token_t;


typedef enum sensor_id {
	SENSOR_COMPASS = 0,
	SENSOR_ACCEL_X = 1,
	SENSOR_ACCEL_Y = 2,
	SENSOR_ACCEL_Z = 3,
	SENSOR_US_LEFT = 4,
	SENSOR_US_FRONT = 5,
	SENSOR_US_RIGHT = 6,
	SENSOR_US_BACK = 7
} sensor_id_t;

void test_serial_out(void);
void print_banner(void);
void get_command_interactive(void);

#endif /* SERIAL_INTERACTIVE_H_ */
