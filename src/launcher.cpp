#include "launcher.h"
#include "main.h"
#include <math.h>

#define clamp(x, a, b) (x < a) ? a : ((x > b) ? b : x)
#define PWM_TO_MPS 0.5

Launcher::Launcher(int pinLeft, int pinRight, int pinAngler, int pinDropper){
	this->pinRWheel = pinRight;
	this->pinLWheel = pinLeft;
	this->pinAngler = pinAngler;	
	this->pinDropper = pinDropper; 
}

void Launcher::launch(){
	//
}

void Launcher::setAngle(int angleDeg){
	//
}

void Launcher::setSpeed(int speed){
	motorSet(pinRWheel, clamp(speed, -127, 127));
	motorSet(pinLWheel, clamp(-speed, -127, 127));
}

void Launcher::rampSpeed(int begin, int end, int timeMs){
	// Make sure begin and end -127 to 127
	// Make sure time >= 0 

	long then = millis();
	
	while(millis() - then < timeMs){
		double elapsed = (double)(millis() - then) / (double)timeMs;
		double interpSpeed = (begin+elapsed*(end-begin));

		setSpeed((int)interpSpeed);
		
		delay(100);
	}

	setSpeed(end);
}

void Launcher::setUsingFormula(double x, double y){
	// Projectile Motion Formula
	// X cant be <= 0, y cant be <= 0, s1 cant be <= 0 

	int speedPWM = 127;
	double v = speedPWM * PWM_TO_MPS;
	double g = 9.81;

	double s1 = v*v*v*v - g * (g*x*x + 2*y*v*v);
	
	if(s1 > 0){
		double s2 = atan(v*v + sqrt(s1) / g*x);
		double s3 = atan(v*v - sqrt(s1) / g*x);

		double angleOutput = fmin(s2, s3);

		setAngle(angleOutput);
		setSpeed(speedPWM);
	}
}