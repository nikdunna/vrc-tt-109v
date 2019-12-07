#include "main.h"


void autonomous() {
  /*
  //RED LONG AUTON
    robotChassis.setMaxVelocity(80);
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
  robotChassis.setMaxVelocity(90);
  robotChassis.moveDistance(-2.5_ft);
  pros::delay(300);
  right.moveVelocity(-100);
		left.moveVelocity(100);
		pros::delay(505);
		right.moveVelocity(50);
		left.moveVelocity(-50);
		pros::delay(95);
		right.moveVelocity(0);
		left.moveVelocity(0);
    pros::delay(100);
    robotChassis.moveDistance(1_ft);
    right.moveVelocity(100);
		left.moveVelocity(100);
		pros::delay(100);
		right.moveVelocity(0);
		left.moveVelocity(0);
	pros::delay(100);
	 rightIn = 127;
  leftIn = -127;
  pros::delay(120);
  rightIn = 0;
  leftIn = 0;
	while(tilt.get_position() > -500)
           {
             tilt = -100;
             pros::delay(10);
           }
    while(tilt.get_position() < -500 && tilt.get_position() > -730)
           {
               tilt = -80;
               pros::delay(10);
           }
           tilt = 0;
           pros::delay(900);
           robotChassis.setMaxVelocity(50);
      robotChassis.moveDistance(-1.5_ft);
      while(tilt.get_position() < 10)
           {
               tilt = 100;
               pros::delay(10);
           }
           tilt = 0;
    robotChassis.setMaxVelocity(200);
*/



           //BLUE LONG AUTON
           robotChassis.setMaxVelocity(80);
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
  robotChassis.setMaxVelocity(90);
  robotChassis.moveDistance(-2.5_ft);
  pros::delay(300);
  right.moveVelocity(100);
		left.moveVelocity(-100);
		pros::delay(505);
		right.moveVelocity(-50);
		left.moveVelocity(50);
		pros::delay(95);
		right.moveVelocity(0);
		left.moveVelocity(0);
    pros::delay(100);
    robotChassis.moveDistance(1_ft);
    right.moveVelocity(100);
		left.moveVelocity(100);
		pros::delay(100);
		right.moveVelocity(0);
		left.moveVelocity(0);
	pros::delay(100);
	 rightIn = 127;
  leftIn = -127;
  pros::delay(120);
  rightIn = 0;
  leftIn = 0;
	while(tilt.get_position() > -500)
           {
             tilt = -100;
             pros::delay(10);
           }
    while(tilt.get_position() < -500 && tilt.get_position() > -730)
           {
               tilt = -80;
               pros::delay(10);
           }
           tilt = 0;
           pros::delay(900);
           robotChassis.setMaxVelocity(50);
      robotChassis.moveDistance(-1.5_ft);
      while(tilt.get_position() < 10)
           {
               tilt = 100;
               pros::delay(10);
           }
           tilt = 0;
           robotChassis.setMaxVelocity(200);
		}
    

  
 /*
  right.moveVelocity(-100);
  left.moveVelocity(-100);
  pros::delay(2000);
  right.moveVelocity(0);
  left.moveVelocity(0);
  pros::delay(700);
  right.moveVelocity(100);
  left.moveVelocity(100);
  pros::delay(2000);
  right.moveVelocity(0);
  left.moveVelocity(0);
  */

