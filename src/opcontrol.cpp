#include "main.h"
static lv_obj_t *background;

bool isIntake = true;
inline void intake()
{
  if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_DOWN))
  {
    isIntake = !isIntake;
  }
  if (isIntake)
  {
    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R1))
    {
      rightIn.move(-127);
      leftIn.move(127);
    }
    else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R2))
    {
      rightIn.move(127);
      leftIn.move(-127);
    }
    else if (tilt.get_position() > -50)
    {
      rightIn.move(-20);
      leftIn.move(20);
    }
    else
    {
      if (fabs(twoBar.get_position()) < 200)
      {
        rightIn.move(-20);
        leftIn.move(20);
      }
      else
      {
        rightIn.move(0);
        leftIn.move(0);
      }
    }
  }
  else if (!isIntake)
  {
    rightIn.move(0);
    leftIn.move(0);
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
  else if (fabs(twoBar.get_position()) < 200)
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
  background = lv_page_create(NULL, NULL);
  lv_scr_load(background);

  lv_obj_t *Position = lv_label_create(background, NULL);
  lv_obj_align(Position, NULL, LV_ALIGN_OUT_TOP_MID, 0, 0);
  while (true)
  {
    //std::cout << "Tilt Position: " << tilt.get_position() << "\n";
    std::cout << "Arm Position: " << twoBar.get_position() << "\n";

    //  lv_label_set_text(Position,"Target Motor Position - " + tilt.get_position());

    //Deploy
    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_UP))
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

    //AUTON
/*
    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_X))
    {
      robotChassis.driveVector(0.3, -0.4);
      pros::delay(670);
    }
*/
    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_Y))
    {
        /*
    tilt = -5;

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
*/

twoBar.move(10);
      rightIn = -200;
		  leftIn = 200;
       left.moveVelocity(125);
      right.moveVelocity(125);
      pros::delay(700);
       left.moveVelocity(65);
      right.moveVelocity(65);
      pros::delay(800);
      robotChassis.stop();
      while(fabs(twoBar.get_position()) < 510)
 {
     twoBar.move(-127);
   pros::delay(5);
 }
 twoBar.move(-10);
      left.moveVelocity(90);
      right.moveVelocity(90);
      pros::delay(500);
      robotChassis.stop();
      twoBar.move(100);
      pros::delay(300);
      robotChassis.turnAngleAsync(-23.5_deg);
      pros::delay(200);
      robotChassis.waitUntilSettled();
      robotChassis.stop();
      pros::delay(100);
      
      left.moveVelocity(-200);
      right.moveVelocity(-200);
      pros::delay(1400);
      right.moveVelocity(-200);
      pros::delay(700);
      robotChassis.stop();
      left.moveVelocity(125);
      right.moveVelocity(125);
      pros::delay(600);
       left.moveVelocity(65);
      right.moveVelocity(65);
      pros::delay(1700);
      robotChassis.stop();
      left.moveVelocity(-200);
      right.moveVelocity(-200);
      pros::delay(1100);
      robotChassis.stop();
      left.tarePosition();
      right.tarePosition();
      robotChassis.turnAngle(80_deg);
      left.moveVelocity(100);
      right.moveVelocity(100);
      pros::delay(400);
      robotChassis.stop();
      rightIn = 0;
  leftIn = 0;
  pros::delay(100);
	while(tilt.get_position() > -1300)
           {
             tilt = -100;
             pros::delay(10);
           }
    while(tilt.get_position() < -1200 && tilt.get_position() > -3900)
           {
               tilt = -60;
               pros::delay(10);
           }
           tilt = 0;
            left.moveVelocity(60);
      right.moveVelocity(60);
      pros::delay(150);
      robotChassis.stop();
    
           pros::delay(200);
           rightIn = 127;
  leftIn = -127;
  left.moveVelocity(-200);
      right.moveVelocity(-200);
      pros::delay(500);
      robotChassis.stop();
      rightIn = 0;
  leftIn = 0;


      /*
     robotChassis.driveVector(0.85 ,0.75);
     pros::delay(1100);
     //robotChassis.driveVector(1 ,0.8);
     */
    }

    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_X))
    {
      robotChassis.turnAngle(85_deg);
    }

    tiltSpeed = master.get_analog(ANALOG_RIGHT_Y);
    tilt = -tiltSpeed;
    /*
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
      */

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
   // arm();
    
//bottom or mid to top
//twoBar.move(0);
		if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L1) && (liftTop == false))
{
	robotChassis.arcade(controller.getAnalog(ControllerAnalog::leftY), controller.getAnalog(ControllerAnalog::leftX));
 tilt.move(-9);
 while(fabs(twoBar.get_position()) <= 2000)
 {
   robotChassis.arcade(controller.getAnalog(ControllerAnalog::leftY), controller.getAnalog(ControllerAnalog::leftX));
   if(fabs(twoBar.get_position()) <= 1800)
   {
     twoBar.move(-127);
   }
   else if(fabs(twoBar.get_position()) <= 1900)
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
else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L1) && (liftTop == true))
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
 if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L2) && (liftMid == false))
{
 robotChassis.arcade(controller.getAnalog(ControllerAnalog::leftY), controller.getAnalog(ControllerAnalog::leftX));
 tilt.move(-9);
 while(fabs(twoBar.get_position()) <= 1600)
 {
   robotChassis.arcade(controller.getAnalog(ControllerAnalog::leftY), controller.getAnalog(ControllerAnalog::leftX));
   if(fabs(twoBar.get_position()) <= 1400)
   {
     twoBar.move(-127);
   }
   else if(fabs(twoBar.get_position()) <= 1500)
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
 if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L2) && (liftMid == true))
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
if(fabs(twoBar.get_position()) > 400)
{
  twoBar.move(-1);
}
else
{
  twoBar.move(9);
}





    //CUBE LOCK MACRO
    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_LEFT))
    {
      //robotChassis.arcade(controller.getAnalog(ControllerAnalog::leftY), controller.getAnalog(ControllerAnalog::leftX));

      tilt.move(-7);
      rightIn.move(50);
      leftIn.move(-50);
      pros::delay(100);
      twoBar.move_voltage(-12000);
      pros::delay(110);
      rightIn.move(80);
      leftIn.move(-80);
      pros::delay(100);
      rightIn.move(30);
      leftIn.move(-30);
      pros::delay(100);
      /*
      rightIn.move(0);
      leftIn.move(0);
      pros::delay(140);
      
      rightIn.move(-90);
      leftIn.move(90);
      pros::delay(90);
      */
      rightIn.move(-15);
      leftIn.move(15);
      tilt.move(0);
      pros::delay(500);
      twoBar.move(0);
    }
  }
}
