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
	else if(twoBar.getPosition() < -100)
	{
		twoBar.setBrakeMode(AbstractMotor::brakeMode::brake); //hold
	}
	else
	{
		twoBar.moveVelocity(0);
	}
	
	
}




void opcontrol()
{
	robotChassis.stop();
    //int tiltSpeed;

	pros::Task tilterMac(tiltMac, NULL, "Tilt");
	pros::Task twoBarMacHigh(move2bMac, NULL, "2b");
	pros::Task twoBarMacLow(move2bMacLow, NULL, "2bLow");


	while(true)
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
		if(master.get_digital(pros::E_CONTROLLER_DIGITAL_Y))
	{
		/*
			while(tilt.get_position() > -640 || twoBar.getPosition() > -300)
  		{
			if(tilt.get_position() > -640)
			{
				tilt = -127;
			}
			pros::delay(400);
			if(twoBar.getPosition() > -300)
			{
				twoBar.moveVelocity(-200);
			}
  			
  			pros::delay(10);
			  
			
  		}
  		tilt = 0;
		twoBar.moveVelocity(0);
		while(tilt.get_position() > -1400)
  		{
  			tilt = -127;
  			pros::delay(10);
  		}
		/*
		robotChassis.moveDistanceAsync(3.6_ft);
		rightIn = -127;
		leftIn = 127;
		*/ 
	robotChassis.setMaxVelocity(100);
	tilt = 7;
	rightIn = -127;
	leftIn = 127;
  robotChassis.moveDistance(5.5_ft);
  robotChassis.setMaxVelocity(200);
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
