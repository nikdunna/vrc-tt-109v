#include "main.h"
static lv_obj_t * background;



inline void intake()
	{
	   if(master.get_digital(pros::E_CONTROLLER_DIGITAL_R1))
	   {
		   rightIn = -127;
		   leftIn = 127;
	   }
	   else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_R2))
	   {
		   rightIn = 127;
		   leftIn = -127;
	   }
	}





void opcontrol()
{ 
	robotChassis.stop();
	/* 
	//CATA//
	pros::Task activityCata(cataActivity, NULL);
	pros::Task visAutoAim(visionAim, NULL);
	/* 
	//LVGL//
  background = lv_page_create(NULL, NULL);
  lv_scr_load(background);

   /* Creates Tab View 
    lv_obj_t * tabViewOne = lv_tabview_create(background, NULL);
    lv_tabview_add_tab(tabViewOne, "Motor Values");
    lv_tabview_add_tab(tabViewOne, "Sensor Values");
	lv_obj_set_size(tabViewOne, LV_HOR_RES, LV_VER_RES);
	/*
    //Left Drive Creation
	lv_obj_t * leftDriveLab = lv_label_create(tabViewOne, NULL);
	lv_obj_align(leftDriveLab, label, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 0);
    lv_obj_set_height(leftDriveLab, 80);


*/

	



	while (true)
	{
		//LVGL//


		//DRIVE
		
      robotChassis.arcade(controller.getAnalog(ControllerAnalog::leftY), controller.getAnalog(ControllerAnalog::leftX));
		

		//TILT
		int inSpeedNormal = master.get_analog(ANALOG_RIGHT_Y);
		int inSpeedFast = master.get_analog(ANALOG_RIGHT_X);
		tilt = inSpeedNormal;

		//INTAKE
		intake();
    


	}
}
