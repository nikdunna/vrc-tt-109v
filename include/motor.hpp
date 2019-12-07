#ifndef MOTOR_H
#define MOTOR_H
#include "main.h"



//DEFS//

//Motors

extern MotorGroup left;
extern MotorGroup right;

//extern pros::Motor twoBar;
extern Motor twoBar;
extern Motor tilter;
extern pros::Motor rightIn;
extern pros::Motor leftIn;
extern pros::Motor tilt;
//Controllers
extern pros::Controller master;
extern Controller controller;



//GLOBAL VARIABLES
extern int driveGet();
extern int autonNumber;

//DEFINE CHASSIS/MOTIONPROFILE//
extern ChassisControllerPID robotChassis;
//extern ChassisControllerIntegrated robotChassis;
extern AsyncMotionProfileController profileController;
//SENSORS//



//FUNCTIONS//
void move2bMac(void *x);
void move2bMacLow(void *x);
void tiltMac(void *flob);
void driveSpeed(int iSpeed);
void turnLeft(int iSpeed);
void turnRight(int iSpeed);
void encoderReset();
void lcdAuton();
void moveToLow();
void moveToHigh();
void resumeTilt();

#endif