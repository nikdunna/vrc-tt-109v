#include "main.h"

//DEFS//
//Vis Sensor
//pros::Vision visSensor(19, pros::vision_zero(1));

//Motors
pros::Motor tilt(4, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor twoBar(21, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor rightIn(11, pros::E_MOTOR_GEARSET_36, false, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor leftIn(7, pros::E_MOTOR_GEARSET_36, false, pros::E_MOTOR_ENCODER_DEGREES);
//Motor tilter();
//Motor twoBar(10);


//Controller (Defined two times for okapi uses)
pros::Controller master(pros::E_CONTROLLER_MASTER);
Controller controller;


//Sensors

  

//Drive Motors
MotorGroup left = MotorGroup({19, 2});
MotorGroup right = MotorGroup({-12, -3});

//DEFINE CHASSIS//
ChassisControllerPID robotChassis = ChassisControllerFactory::create(
  left, right,
  IterativePosPIDController::Gains{0.003, 0.004, 0.00015}, //0.001, 0.0005, 0.00005      0.7...0.0003
  IterativePosPIDController::Gains{0, 0, 0},
  IterativePosPIDController::Gains{0.0029, 0.000011, -0.000001}, //0.0056 , 0.0057, 0
  AbstractMotor::gearset::green,
  {4_in, 12.546_in}
);


AsyncMotionProfileController profileController = AsyncControllerFactory::motionProfile(
  4.0,  // Maximum linear velocity of the Chassis in m/s 1.06
  4.0,  // Maximum linear acceleration of the Chassis in m/s/s 0.83
  4.0, // Maximum linear jerk of the Chassis in m/s/s/s 0.5
  robotChassis // Chassis Controller
);







/*
//ENCODER DRIVEGET//
int driveGet()
{
    return (abs((frontRight.get_position() + frontLeft.get_position() + backRight.get_position() + backLeft.get_position()) / 4));
}


//FUNCTIONS//
/*
void driveSpeed(int iSpeed)
{
    frontRight.move(-iSpeed);
    frontLeft.move(iSpeed);
    backRight.move(-iSpeed);
    backLeft.move(iSpeed);
}

void turnLeft(int iSpeed)
{
    frontRight.move(-iSpeed);
    frontLeft.move(-iSpeed);
    backRight.move(-iSpeed);
    backLeft.move(-iSpeed);
}

void turnRight(int iSpeed)
{
    frontRight.move(iSpeed);
    frontLeft.move(iSpeed);
    backRight.move(iSpeed);
    backLeft.move(iSpeed);
}
/*
void encoderReset()
{
    frontRight.set_zero_position(0);
    frontLeft.set_zero_position(0);
    backRight.set_zero_position(0);
    backLeft.set_zero_position(0);
}
*/


/*int toggle() {
  static bool lowTower = false;

  while (true) {

    if (Controller1.ButtonL2.pressing() && hit == false) {

      hit = 1;
      vex::task::stop(moveArmHigh);
      vex::task::stop(moveArmDownHigh);

      lowTower = !lowTower;
      switchMode = !switchMode;

      if (lowTower == true) {
        vex::task::stop(moveArmDown);
        vex::task h = vex::task(moveArm);
      }

      else {
        vex::task::stop(moveArm);
        vex::task n = vex::task(moveArmDown);
      }
    }

    if (!Controller1.ButtonL2.pressing() && hit == 1) {
      hit = 0;
    }
    task::sleep(10);
  }
}*/
/*
void move2bMac(void *x)
{
    
    bool hit;
    bool lowTower;
    while(true)
    {
       if(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L2) && !hit)
       {
             hit = 1;

      lowTower = !lowTower;
      
      if(lowTower)
      {
        // moveToHigh();
        twoBar.moveAbsolute(-830, 200);
         
      }
      else
      {
          twoBar.moveAbsolute(-1, 170);
      }
      
       }

    if(!(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L2)) && hit)
    {
        hit = 0;
    }


    }
    
       
}
/*
void moveToLow()
{
  tilterMac.suspend();
  while(tilt.get_position() > -200)
           {
             tilter.moveVelocity(-200);
             pros::delay(10);
           }
         twoBar.moveAbsolute(-570, 200);
  tilterMac.resume();
}
*/
/*
void move2bMacLow(void *x)
{
    
    bool hit;
    bool lowTower;
    while(true)
    {
      
       if(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L1) && !hit )
       {
             hit = 1;

      lowTower = !lowTower;
      
      if(lowTower)
      {
        twoBar.moveAbsolute(-570, 200);
      //  moveToLow();

      }
      else
      {  
        twoBar.moveAbsolute(-1, 170);
      }
      
       }

    if(!(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L1)) && hit)
    {
        hit = 0;
    }


    }
    
       
}
*/
/*
void tiltMac(void *flob)
{
    
    int tiltSpeed;
    bool hit;
    while(true)
    {
     
        tiltSpeed = master.get_analog(ANALOG_RIGHT_Y);
     if (master.get_digital(pros::E_CONTROLLER_DIGITAL_UP))
        {
           hit = true;
           while(tilt.get_position() > -1500 && hit)
           {
             tilt = -127;
             pros::delay(10);
           }
           while(tilt.get_position() < -1400 && tilt.get_position() > -1500 && hit)
           {
               tilt = -60;
               pros::delay(10);
           }
           hit = false;
        } 
      else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT))
        {
           hit = true;
           while(tilt.get_position() > -300 && hit)
           {
             tilt = -127;
             pros::delay(10);
           }
           hit = false;
        }
      /*
	    else if(tilt.get_position() < -500)
		{
			tilt = -tiltSpeed / 1.5;
		}
    */
   /*
      else
		{
			tilt = -tiltSpeed;
		}
  
         if(tilt.get_position() < -1300 && tiltSpeed > 3)
        {

           tilt = 0;
        }
        else if(tilt.get_position() > -10)
        {
         tilt = 3;
        }
        
    }
   
    
}
*/