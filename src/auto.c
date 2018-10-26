/** @file auto.c
 * @brief File for autonomous code
 *
 * This file should contain the user autonomous() function and any functions related to it.
 *
 * PROS contains FreeRTOS (http://www.freertos.org) whose source code may be
 * obtained from http://sourceforge.net/projects/freertos/files/ or on request.
 */

#include "main.h"
#include "launcher.h"
#include "field_layout.h"
#include "robot_layout.h"

/*
 * Runs the user autonomous code. This function will be started in its own task with the default
 * priority and stack size whenever the robot is enabled via the Field Management System or the
 * VEX Competition Switch in the autonomous mode. If the robot is disabled or communications is
 * lost, the autonomous task will be stopped by the kernel. Re-enabling the robot will restart
 * the task, not re-start it from where it left off.
 *
 * Code running in the autonomous task cannot access information from the VEX Joystick. However,
 * the autonomous function can be invoked from another task if a VEX Competition Switch is not
 * available, and it can access joystick information if called in this way.
 *
 * The autonomous task may exit, unlike operatorControl() which should never exit. If it does
 * so, the robot will await a switch to another mode or disable/enable cycle.
 */

void autonomous() {
	//Launcher launcher(3,2,1,4);
	//TracksMotion motion(5,6);
	//TwoWheelMoton motion(5,7);
	//FourWheelMoton motion(5,6,7,8);
	//SonarSensor sonar(8);
	//ScissorLift lift(9);

	//OperatorController controller(launcher, motion, lift, sensors); 
 	//AutonomousContoller controller(launcher, motion, lift, sensors);

	//launcher.setAngle(50);
	//launcher.rampSpeed(0, 100, 1000);
	//launcher.launch();
	//launcher.rampSpeed(100, 0, 1000);

	//int sonarDist = 5.2;
	//launcher.setUsingFormula(sonarDist, FIELD_FLAGS[0].z - LAUNCHER_Z);
	//launcher.launch();
	//launcher.rampSpeed(100, 0, 1000);
}
