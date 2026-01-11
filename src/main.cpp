#include "main.h"
#include "lemlib/api.hpp"
#include "headers/robot_config.hpp"


void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		pros::lcd::set_text(2, "I was pressed!");
	} else {
		pros::lcd::clear_line(2);
	}
}

void initialize() {
	pros::lcd::initialize();
	pros::lcd::set_text(1, "Hello AJAY!");

	pros::lcd::register_btn1_cb(on_center_button);
}


void disabled() {}


void competition_initialize() {}


void autonomous() {}


void opcontrol() {
	

	bool wingToggled = false;
	bool loaderToggled = false;
	while (true) {
		pros::lcd::print(0, "%d %d %d", (pros::lcd::read_buttons() & LCD_BTN_LEFT) >> 2,
		                 (pros::lcd::read_buttons() & LCD_BTN_CENTER) >> 1,
		                 (pros::lcd::read_buttons() & LCD_BTN_RIGHT) >> 0);  

		// Arcade control scheme
		int dir = master.get_analog(ANALOG_LEFT_Y);    
		int turn = master.get_analog(ANALOG_RIGHT_X) * -1;  
		chassis.arcade(dir, turn);
		pros::delay(20);                              


		if(master.get_digital(DIGITAL_R1)) {
			intake_motors.move(127);
			if(!master.get_digital(DIGITAL_L1) && !master.get_digital(DIGITAL_L2))
			outtake_motors.move(40);
		} else if(master.get_digital(DIGITAL_R2)) {
			intake_motors.move(-127);
			if(!master.get_digital(DIGITAL_L1) && !master.get_digital(DIGITAL_L2))
			outtake_motors.move(-40);
		} else {
			intake_motors.move(0);
		}

		if(master.get_digital(DIGITAL_L1)) {
			outtake_motors.move(127);
		} else if(master.get_digital(DIGITAL_L2)) {
			outtake_motors.move(-127);
		} else {
			if(!master.get_digital(DIGITAL_R1) && !master.get_digital(DIGITAL_R2))
			outtake_motors.move(0);
		}

		if(master.get_digital_new_press(DIGITAL_B))
		{
			wingToggled = !wingToggled;
			wingPiston.set_value(wingToggled);
		}

		if(master.get_digital_new_press(DIGITAL_A))
		{
			loaderToggled = !loaderToggled;
			loaderPiston.set_value(loaderToggled);
		}
	}
}