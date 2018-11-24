#include "drives.h"
#include "main.h"
#include "mathfuncs.h"

TreadDrive::TreadDrive(double l_motor, double r_motor)
	: l_motor_pin(l_motor), r_motor_pin(r_motor)
{

}

void TreadDrive::manual_drive(double l_in, double r_in)
{
	set_motors(l_in * 127, r_in * 127);
}

void TreadDrive::easy_drive(double x_in, double y_in)
{
	double l_out = min((x_in+1), 1);
	double r_out = min((-x_in+1), 1);
	set_motors(l_out * 127, r_out * 127);
}

void TreadDrive::set_motors(double l_pwm, double r_pwm)
{
	motorSet(l_motor_pin, l_pwm);
	motorSet(r_motor_pin, r_pwm);
}
