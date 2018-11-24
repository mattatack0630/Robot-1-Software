#include "arm.h"

Arm::Arm(int turn_pin, int grab_pin):
	turn_motor(turn_pin),
	grab_motor(grab_pin)
{
	
}

void Arm::turn_arm(double angle_deg, int speed){
	turn_motor.turnAngle(angle_deg, speed);
}

void Arm::turn_hand(double angle_deg, int speed){
	grab_motor.turnAngle(angle_deg, speed);
}
