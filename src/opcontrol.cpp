#include "main.h"
static lv_obj_t *background;

inline void intake()
{
	if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R1))
	{
		rightIn = -200;
		leftIn = 200;
	}
	else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R2))
	{
		rightIn = 200;
		leftIn = -200;
	}
	else if(tilt.get_position() > -50)
	{
		rightIn = -10;
		leftIn =  10;
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
pros::Task tilterMac(tiltMac, NULL, "Tilt");
void moveToLow()
{
  tilterMac.suspend();
  while(tilt.get_position() > -200)
           {
             tilter.moveVelocity(-175);
             pros::delay(10);
           }
         twoBar.moveAbsolute(-570, 200);
		 pros::delay(150);
		tilterMac.resume();
}
void moveToHigh()
{
  tilterMac.suspend();
  while(tilt.get_position() > -180)
           {
             tilter.moveVelocity(-175);
             pros::delay(10);
           }
         twoBar.moveAbsolute(-830, 200);
		 pros::delay(150);
  tilterMac.resume();
}


    
void opcontrol()
{
	robotChassis.stop();
    //int tiltSpeed;
	
pros::Task twoBarMacHigh(move2bMac, NULL, "2b");
pros::Task twoBarMacLow(move2bMacLow, NULL, "2bLow");

	

bool hitted;
	while(true)
	{
		std::cout << "Tilt Position: " << tilt.get_position()  << "bruh\n";
		//std::cout << "Arm Position: " << twoBar.getPosition() << "\n";
		
	
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
  robotChassis.moveDistance(5.5_ft);
  robotChassis.setMaxVelocity(200);
  */
 
  hitted = true;
 while(tilt.get_position() > -500 && hitted)
           {
             tilt = -127;
             pros::delay(10);
           }
		   hitted = false;
		   /*
           while(tilt.get_position() < -700 && tilt.get_position() > -800)
           {
               tilt = -60;
               pros::delay(10);
           }
		   */
		}
		else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_B))
		{
			/*
			robotChassis.setMaxVelocity(100);
			robotChassis.turnAngle(90_deg);
			robotChassis.setMaxVelocity(200);
			*/
		 robotChassis.setMaxVelocity(100);
	tilt = 7;
	rightIn = -127;
	leftIn = 127;
  robotChassis.moveDistance(3.5_ft);
  //robotChassis.setMaxVelocity(200);
  rightIn = -127;
  leftIn = 127;
  pros::delay(200);
  rightIn = 0;
  leftIn = 0;
  robotChassis.moveDistance(-2.5_ft);
  right.moveVelocity(-100);
		left.moveVelocity(100);
		pros::delay(490);
		right.moveVelocity(50);
		left.moveVelocity(-50);
		pros::delay(120);
		right.moveVelocity(0);
		left.moveVelocity(0);
    pros::delay(100);
    robotChassis.moveDistance(1.25_ft);
	pros::delay(50);
	
	while(tilt.get_position() > -700)
           {
             tilt = -127;
             pros::delay(10);
           }
    while(tilt.get_position() < -700 && tilt.get_position() > -800)
           {
               tilt = -60;
               pros::delay(10);
           }
		}
		

		//INTAKE
		intake();

		//ARM
		//arm();
	}
}
