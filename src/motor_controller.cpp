#include "motor_controller.h"
#include "API.h"
#include "mathfuncs.h"

MotorController::MotorController(int motor_pin)
{
	this->motor_pin = motor_pin;
}

void MotorController::turnTime(int time_ms, int speed)
{
	motorSet(motor_pin, speed); // Right now speed doesn't affect anything
	delay(time_ms);
	motorSet(motor_pin, 0);
}


EncodedMotorController::EncodedMotorController(int motor_pin, int encoder_pin_a, int encoder_pin_b) :
						MotorController(motor_pin)
{
	this->encoder_pin = encoder_pin;
	this->encoder = encoderInit(encoder_pin_a, encoder_pin_b, false);
}

void EncodedMotorController::turnAngle(int degrees, int speed, int tol = 1)
{
	while(abs(encoderGet(encoder) - degrees) < tol)
	{
		int diff_cw  =  0   + (encoderGet(encoder) - degrees); // Clockwise
		int diff_ccw =  360 - (encoderGet(encoder) - degrees); // Counter-Clockwise
		
		double norm = min(diff_cw, diff_ccw);
		norm = norm / 180.0;
		norm = clamp(norm, (1.0/((double)speed)), 1.0);
		
		motorSet(motor_pin, (int) (speed * norm)); // Should slow linearly as it reaches the mark
		delay(10); // Random delay right now
	}

	motorSet(motor_pin, 0);
}


TimedMotorController::TimedMotorController(int motor_pin) :
						MotorController(motor_pin)
{
}

void TimedMotorController::turnAngle(int degrees, int speed, int tol = 1)
{
	int time_needed_ms = (int)(((double)degrees / 360.0) * TIME_360_DEGREE);
	motorSet(motor_pin, 127); // Right now speed doesn't affect anything
	delay(time_needed_ms);
	motorSet(motor_pin, 0);
}