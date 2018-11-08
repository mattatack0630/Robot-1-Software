class TreadDrive
{
	private:
		int r_motor_pin;
		int l_motor_pin;
		void set_motors(double l_pwm, double r_pwm);

	public:	
		TreadDrive(double l_motor, double r_motor);

		void manual_drive(double l_in, double r_in);
		void easy_drive(double x_in, double y_in);
};
