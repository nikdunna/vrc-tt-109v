#include "main.h"

//DEFS//
//Vis Sensor
//pros::Vision visSensor(19, pros::vision_zero(1));

//Motors
pros::Motor tilt(2, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_COUNTS);
//pros::Motor twoBar(3, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor rightIn(4, pros::E_MOTOR_GEARSET_36, false, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor leftIn(19, pros::E_MOTOR_GEARSET_36, false, pros::E_MOTOR_ENCODER_DEGREES);
Motor twoBar(15);


//Controller (Defined two times for okapi uses)
pros::Controller master(pros::E_CONTROLLER_MASTER);
Controller controller;


//Sensors



//Drive Motors
MotorGroup left = MotorGroup({9, 10});
MotorGroup right = MotorGroup({-11, -1});

//DEFINE CHASSIS//
ChassisControllerPID robotChassis = ChassisControllerFactory::create(
  left, right,
  IterativePosPIDController::Gains{0.003, 0, 0.00015}, //0.001, 0.0005, 0.00005      0.7...0.0003
  IterativePosPIDController::Gains{0, 0, 0},
  IterativePosPIDController::Gains{0.009, 0.0008, 0.00025}, //0.005 , 0.000031, 0.00026
  AbstractMotor::gearset::green,
  {4_in, 9_in}
);


AsyncMotionProfileController profileController = AsyncControllerFactory::motionProfile(
  2.0,  // Maximum linear velocity of the Chassis in m/s
  4.0,  // Maximum linear acceleration of the Chassis in m/s/s
  4.0, // Maximum linear jerk of the Chassis in m/s/s/s
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



void move2bMac(void *x)
{
    int hitNum = 0;
    while(true)
    {
       if(master.get_digital(pros::E_CONTROLLER_DIGITAL_L1) && hitNum == 0)
       {
           hitNum = 1;
           twoBar.moveVelocity(0);
           pros::delay(40);
           twoBar.moveRelative(-850, 200);
       }
       else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_L1) && hitNum == 1)
       {
           hitNum = 0;
           twoBar.moveVelocity(0);
           pros::delay(40);
           twoBar.moveRelative(-849, -20);
           
       }
       /*
       if(hitNum == 0)
       {
           twoBar.moveAbsolute(700, 20);
       }
       /*
       else if(hitNum == 1)
       {
           twoBar.moveAbsolute(-850, 200);
       }
*/
    }
       
}


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
           while(tilt.get_position() < -1500 && tilt.get_position() > -1600 && hit)
           {
               tilt = -100;
               pros::delay(10);
           }
           hit = false;
        } 
	    else if(tilt.get_position() < -720)
		{
			tilt = -tiltSpeed;
		}
		else
		{
			tilt = -tiltSpeed  + 7;
		}
    }
}
