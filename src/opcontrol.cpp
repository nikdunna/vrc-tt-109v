#include "main.h"
static lv_obj_t *background;

inline void intake()
{
	if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R1))
	{
		rightIn = -100;
		leftIn = 100;
	}
	else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R2))
	{
		rightIn = 100;
		leftIn = -100;
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
		twoBar.move(-200);
	}
	else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L2))
	{
		twoBar.move(200);
	}
  /*
	else if(twoBar.get_position() < -100)
	{
		//twoBar.set_brake_mode(AbstractMotor::brakeMode::brake); //hold
	}
  */
	else if(fabs(twoBar.get_position()) < 200)
	{
		twoBar.move(10);
	}
  else
  {
    twoBar.move(-10);
  }
  
	
	
}
/*

void moveToLow()
{
  tilterMac.suspend();
  while(tilt.get_position() > -200)
           {
             tilter.move(-175);
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
*/


    
void opcontrol()
{
    bool liftTop = false;
	bool liftMid = false;
	bool liftBottom = true;
	robotChassis.stop();
    //int tiltSpeed;
	//pros::Task tilterMac(tiltMac, NULL, "Tilt");
//pros::Task twoBarMacHigh(move2bMac, NULL, "2b");
//pros::Task twoBarMacLow(move2bMacLow, NULL, "2bLow");

	int tiltSpeed;


	while(true)
	{
		//std::cout << "Tilt Position: " << tilt.get_position()  << "bruh\n";
		std::cout << "Arm Position: " << twoBar.get_position() << "\n";
		
    //Deploy
    if(master.get_digital(pros::E_CONTROLLER_DIGITAL_UP))
    {
      rightIn = 200;
		  leftIn = -200;
      pros::delay(400);
      twoBar.move(-127);
      pros::delay(100);
      pros::delay(500);
      twoBar.move(0);
      pros::delay(50);
      twoBar.move(100);
      pros::delay(500);
      rightIn = 0;
		  leftIn = 0;
      twoBar.move(0);
    }
	
		//DRIVE

		robotChassis.arcade(controller.getAnalog(ControllerAnalog::leftY), controller.getAnalog(ControllerAnalog::leftX));

		//TILT
	/*
	    if(master.get_digital(pros::E_CONTROLLER_DIGITAL_Y))
		{
			tilt.move_velocity(-200);
		}
		else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN))
		{
			tilt.move_velocity(200);
		}
		else
		{
			tilt.move_velocity(0);
		}
		*/

       tiltSpeed = master.get_analog(ANALOG_RIGHT_Y);
			
      if(tilt.get_position() < -1620)
      {
        tilt = 0;
      }
      else if(tilt.get_position() < -540)
      {
        tilt = -tiltSpeed / 1.5 ;
      }
      else
      {
        tilt = -tiltSpeed;
      }
      
      
	


		//PID TEST
		/*
		if(master.get_digital(pros::E_CONTROLLER_DIGITAL_Y))
	{
		/*
  robotChassis.moveDistance(5.5_ft);
  robotChassis.setMaxVelocity(200);
  */
 
		//INTAKE
		intake();

		//ARM
		arm();
/*
//bottom or mid to top
//twoBar.move(0);
		if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L2) && (liftTop == false))
{
	robotChassis.arcade(controller.getAnalog(ControllerAnalog::leftY), controller.getAnalog(ControllerAnalog::leftX));
 tilt.move(-9);
 while(fabs(twoBar.get_position()) <= 1500)
 {
   robotChassis.arcade(controller.getAnalog(ControllerAnalog::leftY), controller.getAnalog(ControllerAnalog::leftX));
   if(fabs(twoBar.get_position()) <= 1300)
   {
     twoBar.move(-127);
   }
   else if(fabs(twoBar.get_position()) <= 1400)
   {
     twoBar.move(-100);
   }
   else
   {
     twoBar.move(-70);
   }
 }
tilt.move(9);
twoBar.move(0);
 liftBottom = false;
liftMid = false;
 liftTop = true;
}

//top to bottom
else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L2) && (liftTop == true))
{
 robotChassis.arcade(controller.getAnalog(ControllerAnalog::leftY), controller.getAnalog(ControllerAnalog::leftX));
 tilt.move(-9);
 while(fabs(twoBar.get_position()) >= 150)
 {
   robotChassis.arcade(controller.getAnalog(ControllerAnalog::leftY), controller.getAnalog(ControllerAnalog::leftX));
   if(fabs(twoBar.get_position()) >= 500)
   {
     twoBar.move(127);
   }
   else if(fabs(twoBar.get_position()) >= 400)
   {
     twoBar.move(60);
   }
   else
   {
     twoBar.move(30);
   }
 }
tilt.move(9);
twoBar.move(0);
 liftBottom = true;
liftMid = false;
 liftTop = false;
}

//bottom to mid
 if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L1) && (liftMid == false))
{
 robotChassis.arcade(controller.getAnalog(ControllerAnalog::leftY), controller.getAnalog(ControllerAnalog::leftX));
 tilt.move(-9);
 while(fabs(twoBar.get_position()) <= 1200)
 {
   robotChassis.arcade(controller.getAnalog(ControllerAnalog::leftY), controller.getAnalog(ControllerAnalog::leftX));
   if(fabs(twoBar.get_position()) <= 1000)
   {
     twoBar.move(-127);
   }
   else if(fabs(twoBar.get_position()) <= 1100)
   {
     twoBar.move(-100);
   }
   else
   {
     twoBar.move(-70);
   }
 }
 
while(fabs(twoBar.get_position()) >= 1700)
 {
   robotChassis.arcade(controller.getAnalog(ControllerAnalog::leftY), controller.getAnalog(ControllerAnalog::leftX));
   if(fabs(twoBar.get_position()) >= 1800)
   {
     twoBar.move(127);
   }
   else if(fabs(twoBar.get_position()) >= 1780)
   {
     twoBar.move(60);
   }
   else
   {
     twoBar.move(30);
   }
 }
 
tilt.move(9);
twoBar.move(0);
 liftBottom = false;
 liftMid = true;
liftTop = false;
}
//mid to bottom
 if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L1) && (liftMid == true))
{
robotChassis.arcade(controller.getAnalog(ControllerAnalog::leftY), controller.getAnalog(ControllerAnalog::leftX));
 tilt.move(-9);
 while(fabs(twoBar.get_position()) >= 150)
 {
   robotChassis.arcade(controller.getAnalog(ControllerAnalog::leftY), controller.getAnalog(ControllerAnalog::leftX));
   if(fabs(twoBar.get_position()) >= 500)
   {
     twoBar.move(127);
   }
   else if(fabs(twoBar.get_position()) >= 400)
   {
     twoBar.move(60);
   }
   else
   {
     twoBar.move(30);
   }
 }
 tilt.move(9);
 twoBar.move(0);
 liftBottom = true;
 liftMid = false;
liftTop = false;
}
*/
	}
}
