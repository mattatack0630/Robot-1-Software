/** @file opcontrol.c
 * @brief File for operator control code
 *
 * This file should contain the user operatorControl() function and any functions related to it.
 *
 * ` contains FreeRTOS (http://www.freertos.org) whose source code may be
 * obtained from http://sourceforge.net/projects/freertos/files/ or on request.
 */

#include "main.h"
#include "launcher.h"

/*
 * Runs the user operator control code. This function will be started in its own task with the
 * default priority and stack size whenever the robot is enabled via the Field Management System
 * or the VEX Competition Switch in the operator control mode. If the robot is disabled or
 * communications is lost, the operator control task will be stopped by the kernel. Re-enabling
 * the robot will restart the task, not resume it from where it left off.
 *
 * If no VEX Competition Switch or Field Management system is plugged in, the VEX Cortex will
 * run the operator control task. Be warned that this will also occur if the VEX Cortex is
 * tethered directly to a computer via the USB A to A cable without any VEX Joystick attached.
 *
 * Code running in this task can take almost any action, as the VEX Joystick is available and
 * the scheduler is operational. However, proper use of delay() or taskDelayUntil() is highly
 * recommended to give other tasks (including system tasks such as updating LCDs) time to run.
 *
 * This task should never exit; it should end with some kind of infinite loop, even if empty.
 */
#define clamp(x, a, b) (x < a) ? a : ((x > b) ? b : x)


double map(double x, double in_a, double in_b, double out_a, double out_b){
	return (x - in_a) * (out_b - out_a) / (in_b - in_a) + out_b;
}

void operatorControl() {
	delay(1000);
	printf("Starting\n");

	while (1) {

		double yin = (double) -joystickGetAnalog(3, 2) / 127.0;
		double xin = (double) -joystickGetAnalog(3, 1) / 127.0;
		double right_out = clamp((xin*2+1), -1, 1);
		double left_out = clamp((-xin*2+1), -1, 1);

		left_out = map(left_out, -1, 1, 0, 1);
		right_out = map(right_out, -1, 1, 0, 1);

		motorSet(4, (int)(-left_out * (yin*127)));
		motorSet(5, (int)(right_out * (yin*127)));

		/*double j1 = (double) joystickGetAnalog(3, 2);
		double j2 = (double) joystickGetAnalog(3, 3);
		
		motorSet(4, j1);
		motorSet(5, -j2);
		*/
		printf("Analog 1 - %d\n", 100);	
		delay(20);
	}
}
