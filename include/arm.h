#include "motor_controller.h"

class Arm {
	private:
		TimedMotorController turn_motor;
		TimedMotorController grab_motor;
		
	public:
		Arm(int turn_pin, int grab_pin);	
		
		void turn_arm(double angle_deg, int speed);
		void turn_hand(double angle_deg, int speed);
};
