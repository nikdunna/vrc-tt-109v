#include "main.h"


void autonomous() {


  
 ///BLUE AUTON
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

       rightIn = -200;
		  leftIn = 200;
      
      pros::delay(1500);
      left.moveVelocity(65);
      right.moveVelocity(65);
      pros::delay(2700);
      robotChassis.stop();
      pros::delay(400);
      left.tarePosition();
			right.tarePosition();
      robotChassis.setMaxVelocity(150);
   robotChassis.turnAngle(25_deg);

      pros::delay(300);
       left.moveVelocity(80);
      right.moveVelocity(80);
      pros::delay(700);
      robotChassis.stop();
      pros::delay(300);
      left.tarePosition();
			right.tarePosition();
      robotChassis.turnAngle(-20_deg);
      robotChassis.setMaxVelocity(200);

      pros::delay(300);
      left.moveVelocity(-200);
      right.moveVelocity(-200);
      pros::delay(450);
      rightIn = 0;
		  leftIn = 0;
      pros::delay(100);
      left.moveVelocity(-120);
      right.moveVelocity(-120);
      pros::delay(1050);
      robotChassis.stop();
      pros::delay(500);
      left.tarePosition();
			right.tarePosition();
      robotChassis.setMaxVelocity(90);
      robotChassis.turnAngle(-120_deg);
      robotChassis.setMaxVelocity(200);
      pros::delay(500);
      left.moveVelocity(80);
      right.moveVelocity(80);
      pros::delay(400);
      robotChassis.stop();
       rightIn = 127;
  leftIn = -127;
  pros::delay(290);
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



/// RED AUTON

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

       rightIn = -200;
		  leftIn = 200;
      
      pros::delay(1500);
      left.moveVelocity(65);
      right.moveVelocity(65);
      pros::delay(2700);
      robotChassis.stop();
      pros::delay(400);
      left.tarePosition();
			right.tarePosition();
      robotChassis.setMaxVelocity(150);
   robotChassis.turnAngle(-23_deg);

      pros::delay(300);
       left.moveVelocity(80);
      right.moveVelocity(80);
      pros::delay(700);
      robotChassis.stop();
      pros::delay(300);
      left.tarePosition();
			right.tarePosition();
      robotChassis.turnAngle(20_deg);
      robotChassis.setMaxVelocity(200);

      pros::delay(300);
      left.moveVelocity(-200);
      right.moveVelocity(-200);
      pros::delay(450);
      rightIn = 0;
		  leftIn = 0;
      pros::delay(100);
      left.moveVelocity(-120);
      right.moveVelocity(-120);
      pros::delay(1050);
      robotChassis.stop();
      pros::delay(500);
      left.tarePosition();
			right.tarePosition();
      robotChassis.setMaxVelocity(90);
      robotChassis.turnAngle(120_deg);
      robotChassis.setMaxVelocity(200);
      pros::delay(100);
      left.moveVelocity(70);
      right.moveVelocity(70);
      pros::delay(300);
       rightIn = 100;
  leftIn = -100;
  pros::delay(400);
  robotChassis.stop();
  rightIn = 0;
  leftIn = 0;
  pros::delay(100);
	while(tilt.get_position() > -1300)
           {
             tilt = -120;
             pros::delay(10);
           }
    while(tilt.get_position() < -1200 && tilt.get_position() > -3900)
           {
               tilt = -70;
               pros::delay(10);
           }
           tilt = 0;
            left.moveVelocity(40);
      right.moveVelocity(40);
      pros::delay(250);
      robotChassis.stop();
    
           //pros::delay(400);
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





