/** @file opcontrol.c
 * @brief File for operator control code
 *
 * This file should contain the user operatorControl() function and any functions related to it.
 *
 * contains FreeRTOS (http://www.freertos.org) whose source code may be
 * obtained from http://sourceforge.net/projects/freertos/files/ or on request.
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

#include "main.h"
#include "launcher.h"
#include "drives.h"

void operatorControl() 
{
	delay(10);

	TreadDrive drive(4,5);

	while (1) 
	{
		double yin1 = (double) joystickGetAnalog(1, 2) / 127.0;
		double xin1 = (double) joystickGetAnalog(1, 1) / 127.0;

		double yin2 = (double) joystickGetAnalog(1, 3) / 127.0;
		double xin2 = (double) joystickGetAnalog(1, 4) / 127.0;

		bool LB = joystickGetDigital(1, 5, JOY_UP);
		bool RB = joystickGetDigital(1, 6, JOY_UP);
		
		int s = 0;
		if(LB)
			s+=127;
		if(RB)
			s-=127;

		motorSet(9, s);

		drive.manual_drive(yin2, yin1);

		delay(20);
	}
}
