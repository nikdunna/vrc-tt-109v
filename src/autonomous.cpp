#include "main.h"


void autonomous() {

//Red side 8 cube
/*
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
*/







/*
  //BLUE AUTON 7 CUBE // dont fold antis
     
      twoBar.move(5);
      pros::delay(50);

      
       rightIn = -200;
		  leftIn = 200;
      
      left.moveVelocity(70);
      right.moveVelocity(70);
      pros::delay(2600);
       left.moveVelocity(100);
      right.moveVelocity(100);
      pros::delay(600);
      
      robotChassis.stop();
      pros::delay(400);
      left.moveVelocity(-130);
      right.moveVelocity(-130);
      pros::delay(800);
      robotChassis.stop();
      left.tarePosition();
			right.tarePosition();
      robotChassis.setMaxVelocity(175);
   robotChassis.turnAngle(43_deg);

      pros::delay(300);
       left.moveVelocity(80);
      right.moveVelocity(80);
      pros::delay(700);
      robotChassis.stop();
      pros::delay(300);
       left.moveVelocity(-80);
      right.moveVelocity(-80);
      pros::delay(700);
      left.tarePosition();
			right.tarePosition();
      robotChassis.turnAngle(-26_deg);
      robotChassis.setMaxVelocity(200);

      pros::delay(300);
      left.moveVelocity(-200);
      right.moveVelocity(-200);
      pros::delay(450);
      rightIn = -15;
		  leftIn = 15;
      pros::delay(100);
      left.moveVelocity(-160);
      right.moveVelocity(-160);
      pros::delay(1050);
      robotChassis.stop();
      pros::delay(500);
      left.tarePosition();
			right.tarePosition();
    robotChassis.driveVector(0.3, -0.4);
    pros::delay(670);
      left.moveVelocity(100);
      right.moveVelocity(100);
      pros::delay(500);
      robotChassis.stop();
       rightIn = 70;
  leftIn = -70;
  pros::delay(100);
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
  
*/
 ///BLUE AUTON 6 CUBE **********

rightIn = 200;
		  leftIn = -200;
      pros::delay(400);
      twoBar.move(-127);
      pros::delay(200);
rightIn = 0;
		  leftIn = 0;
      pros::delay(900);
      twoBar.move(0);
      pros::delay(50);
      twoBar.move(100);
      pros::delay(1000);


      twoBar.move(5);
      pros::delay(50);

       rightIn = -200;
		  leftIn = 200;
      
      left.moveVelocity(70);
      right.moveVelocity(70);
      pros::delay(2600);
       left.moveVelocity(100);
      right.moveVelocity(100);
      pros::delay(600);
      robotChassis.stop();
      pros::delay(400);
      left.moveVelocity(-130);
      right.moveVelocity(-130);
      pros::delay(800);
      robotChassis.stop();
    pros::delay(400);

      rightIn = 0;
		  leftIn = 0;
      pros::delay(100);
      left.moveVelocity(-120);
      right.moveVelocity(-120);
      pros::delay(1900);
      robotChassis.stop();
      pros::delay(500);
      left.tarePosition();
			right.tarePosition();
    robotChassis.driveVector(0.3, -0.4);
    pros::delay(670);
      left.moveVelocity(100);
      right.moveVelocity(100);
      pros::delay(500);
      robotChassis.stop();
       rightIn = 70;
  leftIn = -70;
  pros::delay(100);
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
      pros::delay(250);
      robotChassis.stop();
    
           pros::delay(400);
           rightIn = 127;
  leftIn = -127;
  left.moveVelocity(-200);
      right.moveVelocity(-200);
      pros::delay(500);
      robotChassis.stop();
      rightIn = 0;
  leftIn = 0;




/*
//RED AUTON 7 CUBE dont fold antis
 twoBar.move(5);
      pros::delay(50);

      
       rightIn = -200;
		  leftIn = 200;
      
      left.moveVelocity(70);
      right.moveVelocity(70);
      pros::delay(2600);
       left.moveVelocity(100);
      right.moveVelocity(100);
      pros::delay(600);
      
      robotChassis.stop();
      pros::delay(400);
      left.moveVelocity(-130);
      right.moveVelocity(-130);
      pros::delay(800);
      robotChassis.stop();
      left.tarePosition();
			right.tarePosition();
      robotChassis.setMaxVelocity(175);
   robotChassis.turnAngle(-43_deg);

      pros::delay(300);
       left.moveVelocity(80);
      right.moveVelocity(80);
      pros::delay(700);
      robotChassis.stop();
      pros::delay(300);
       left.moveVelocity(-80);
      right.moveVelocity(-80);
      pros::delay(700);
      left.tarePosition();
			right.tarePosition();
      robotChassis.turnAngle(36_deg);
      robotChassis.setMaxVelocity(200);

      pros::delay(300);
      left.moveVelocity(-200);
      right.moveVelocity(-200);
      pros::delay(450);
      rightIn = -15;
		  leftIn = 15;
      pros::delay(100);
      left.moveVelocity(-160);
      right.moveVelocity(-160);
      pros::delay(1050);
      robotChassis.stop();
      pros::delay(500);
      left.tarePosition();
			right.tarePosition();
    robotChassis.driveVector(0.3, 0.4);
    pros::delay(670);
      left.moveVelocity(100);
      right.moveVelocity(100);
      pros::delay(500);
      robotChassis.stop();
       rightIn = 70;
  leftIn = -70;
  pros::delay(100);
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
*/








/// RED AUTON 6 CUBE **********

rightIn = 200;
		  leftIn = -200;
      pros::delay(400);
      twoBar.move(-127);
      pros::delay(200);
rightIn = 0;
		  leftIn = 0;
      pros::delay(900);
      twoBar.move(0);
      pros::delay(50);
      twoBar.move(100);
      pros::delay(1000);


      twoBar.move(5);
      pros::delay(50);

       rightIn = -200;
		  leftIn = 200;
      
      left.moveVelocity(70);
      right.moveVelocity(70);
      pros::delay(2600);
       left.moveVelocity(100);
      right.moveVelocity(100);
      pros::delay(600);
      robotChassis.stop();
      pros::delay(400);
      left.moveVelocity(-130);
      right.moveVelocity(-130);
      pros::delay(800);
      robotChassis.stop();
    pros::delay(400);

      rightIn = 0;
		  leftIn = 0;
      pros::delay(100);
      left.moveVelocity(-120);
      right.moveVelocity(-120);
      pros::delay(1900);
      robotChassis.stop();
      pros::delay(500);
      left.tarePosition();
			right.tarePosition();
    robotChassis.driveVector(0.3, -0.4);
    pros::delay(670);
      left.moveVelocity(100);
      right.moveVelocity(100);
      pros::delay(500);
      robotChassis.stop();
       rightIn = 70;
  leftIn = -70;
  pros::delay(100);
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
      pros::delay(250);
      robotChassis.stop();
    
           pros::delay(400);
           rightIn = 127;
  leftIn = -127;
  left.moveVelocity(-200);
      right.moveVelocity(-200);
      pros::delay(500);
      robotChassis.stop();
      rightIn = 0;
  leftIn = 0;







































/*



  //PUSH IN CUBE
 rightIn = 200;
		  leftIn = -200;
      pros::delay(400);
      twoBar.move(-127);
      pros::delay(200);
rightIn = 0;
		  leftIn = 0;
      pros::delay(400);
      twoBar.move(0);
      pros::delay(50);
      twoBar.move(100);
      pros::delay(700);


    
      twoBar.move(5);
      pros::delay(50);
      right.moveVelocity(100);
  left.moveVelocity(100);
  pros::delay(600);
     robotChassis.stop();
     pros::delay(400);
       right.moveVelocity(-100);
  left.moveVelocity(-100);
  pros::delay(600);
   robotChassis.turnAngle(90_deg);
  right.moveVelocity(-100);
  left.moveVelocity(-100);
  pros::delay(1000);
  right.moveVelocity(0);
  left.moveVelocity(0);
  pros::delay(700);
  right.moveVelocity(100);
  left.moveVelocity(100);
  pros::delay(800);
  right.moveVelocity(0);
  left.moveVelocity(0);
  */
  }





