#include <API.h>

class MotorController {
	protected:
		int motor_pin;
	
	public:	
		MotorController(int motor_pin);
		virtual void turnAngle(int degrees, int speed, int tol = 1);
		virtual void turnTime(int time_ms, int speed);
};

class EncodedMotorController : public MotorController {
	private:
		int encoder_pin;
		Encoder encoder;
		
	public:	
		EncodedMotorController(int motor_pin, int encoder_pin_a, int encoder_pin_b);
		void turnAngle(int degrees, int speed, int tol = 1) override;
};


class TimedMotorController : public MotorController {
	private:
		int TIME_360_DEGREE = 3600;

	public:	
		TimedMotorController(int motor_pin);
		void turnAngle(int degrees, int speed, int tol = 1) override;
};