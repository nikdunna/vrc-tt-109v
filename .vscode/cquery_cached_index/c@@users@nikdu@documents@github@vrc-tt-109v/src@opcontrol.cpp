#include "main.h"
static lv_obj_t *background;

inline void intake()
{
	if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R1))
	{
		rightIn = 127;
		leftIn = -127;
	}
	else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R2))
	{
		rightIn = -127;
		leftIn = 127;
	}
	else
	{
		rightIn = 0;
		leftIn =  0;
		
	}
	
}

inline void arm()
{
	if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L1))
	{
		twoBar = -127;
	}
	else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L2))
	{
		twoBar = 127;
	}
	else
	{
		twoBar = -10;
	}
	
}




void opcontrol()
{
	robotChassis.stop();

	int tiltSpeed;
	while (true)
	{
		std::cout << "Tilt Position: \n" << tilt.get_position();
		std::cout << "Arm Position: \n" << twoBar.get_position();
		//LVGL//

		//DRIVE

		robotChassis.arcade(controller.getAnalog(ControllerAnalog::leftY), controller.getAnalog(ControllerAnalog::leftX));

		//TILT
		tiltSpeed = master.get_analog(ANALOG_RIGHT_Y);
		tilt = -tiltSpeed;

		//INTAKE
		intake();

		//ARM
		arm();
	}
}
