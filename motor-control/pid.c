/**
 * @file
 * @author Ethan LaMaster <ealamast@ncsu.edu>
 * @version 0.1
 *
 * @section Description
 *
 * Functions implementing a software PID controller
 *
 * @todo Set up timer interrupt to run compute_pid()
 */

#include <stdio.h>
#include "motor.h"

#define LIMIT(x, min, max)	((x) < (min)) ? (min) : (((x) > (max)) ? (max) : (x))

/**
 * Updates the motor response using a PID algorithm
 *
 * @param motor Motor to update
 *
 * @todo Implement this function.
 * @todo Verify that this code meets real-time processing constraints when
 * 		 using floating-point arithmetic
 */
void compute_pid(motor_t *motor)
{
	controller_t *pid = &(motor->controller);
	int current_speed = *(motor->reg.enc) ? (ENC_SAMPLE_HZ / (unsigned short int)*(motor->reg.enc)) : 0;
	int error = pid->setpoint - current_speed;
	int p, i, d;

	pid->i_sum += error;
	pid->i_sum = LIMIT(pid->i_sum, pid->i_sum_min, pid->i_sum_max);

	p = pid->p_const * error;
	i = pid->i_const * pid->i_sum;
	d = pid->d_const * (error - pid->prev_input);

	pid->prev_input = error;

	motor->response.pwm = LIMIT(p + i + d, 0, PWM_PERIOD);

	if(motor->sample_counter < NUM_SAMPLES)
	{
		motor->samples[motor->sample_counter].enc = current_speed;
		motor->samples[motor->sample_counter].pwm = motor->response.pwm;
		motor->sample_counter++;
	}
}


/**
 * Initializes a controller_t struct
 *
 * @param controller Controller to initialize
 *
 */
void init_controller(controller_t *controller)
{
	controller->p_const = 20;
	controller->i_const = 2;
	controller->d_const = 5;

	controller->i_sum_min = -10000000;
	controller->i_sum_max = 10000000;

	controller->i_sum = 0;
	controller->prev_input = 0;
	controller->setpoint = 0;
	controller->enabled = 0;
}


/**
 * Change the PID setpoint of a motor_t
 *
 * @param motor Pointer to the motor_t struct
 * @param sp The new setpoint
 *
 */
void change_setpoint(motor_t *motor, int sp)
{
	motor->controller.setpoint = sp;
	motor->sample_counter = 0;
}
