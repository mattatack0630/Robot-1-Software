class Launcher {
	private:
		int pinRWheel;
		int pinLWheel;
		int pinAngler;
		int pinDropper;

	public:
		Launcher(int pinLeft, int pinRight, int pinAngler, int pinDropper);

		void launch();
		void setAngle(int angleDeg);
		void setSpeed(int speed);
		void rampSpeed(int begin, int end, int timeMs);

		void setUsingFormula(double distX, double distY);
};