#include "drives.h"
#include "main.h"

#define clamp(x, a, b) (x < a) ? a : ((x > b) ? b : x)
#define min(a, b) (a<b) ? a : b
#define max(a, b) (a>b) ? a : b

TreadDrive::TreadDrive(double l_motor, double r_motor)
	: l_motor_pin(l_motor), r_motor_pin(r_motor)
{

}

void TreadDrive::manual_drive(double l_in, double r_in)
{
	set_motors(l_in * 127, -r_in * 127);
}

void TreadDrive::easy_drive(double x_in, double y_in)
{
	double l_out = clamp((x_in+1), 0.1, 1);
	double r_out = clamp((-x_in+1), 0.1, 1);
	set_motors(l_out * y_in * 127, -1 * r_out * y_in * 127);
}

void TreadDrive::set_motors(double l_pwm, double r_pwm)
{
	motorSet(l_motor_pin, l_pwm);
	motorSet(r_motor_pin, r_pwm);
}
