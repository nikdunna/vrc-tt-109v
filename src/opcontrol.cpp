#include "main.h"
static lv_obj_t *background;

inline void intake()
{
	if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R1))
	{
		rightIn = -127;
		leftIn = 127;
	}
	else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R2))
	{
		rightIn = 127;
		leftIn = -127;
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
		twoBar.moveVelocity(-200);
	}
	else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L2))
	{
		twoBar.moveVelocity(200);
	}
	else
	{
		twoBar.moveVelocity(-1);
	}
	
}




void opcontrol()
{
	robotChassis.stop();
    //int tiltSpeed;

	pros::Task tilterMac(tiltMac, NULL, "Tilt");
	//pros::Task twoBarMac(move2bMac, NULL, "2b");

	while (true)
	{
		//std::cout << "Tilt Position: " << tilt.get_position();
		std::cout << "Arm Position: " << twoBar.getPosition() << "\n";
		
	
		//DRIVE

		robotChassis.arcade(controller.getAnalog(ControllerAnalog::leftY), controller.getAnalog(ControllerAnalog::leftX));
/*
		//TILT
		tiltSpeed = master.get_analog(ANALOG_RIGHT_Y);
	    if(tilt.get_position() < -720)
		{
			tilt = -tiltSpeed;
		}
		else
		{
			tilt = -tiltSpeed  + 7;
		}*/
		
		//PID TEST
		if(master.get_digital(pros::E_CONTROLLER_DIGITAL_A))
		{
			robotChassis.moveDistance(2_ft);
		}
		else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_B))
		{
			robotChassis.setMaxVelocity(150);
			robotChassis.turnAngle(276);
			robotChassis.setMaxVelocity(200);
		}
		

		//INTAKE
		intake();

		//ARM
		//arm();
	}
}
