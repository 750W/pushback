#include "main.h"
#include "lemlib/api.hpp"
#include "headers/robot_config.hpp"
#include "headers/autons.hpp"


void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		pros::lcd::set_text(2, "I was pressed!");
	} else {
		pros::lcd::clear_line(2);
	}
}

// initialize function. Runs on program startup
void initialize() {
    pros::lcd::initialize(); // initialize brain screen
	
    chassis.calibrate(); // calibrate sensors
    // print position to brain screen
    pros::Task screen_task([&]() {
        while (true) {
            // print robot location to the brain screen
            
            pros::lcd::print(1, "Y: %f", chassis.getPose().y); // y
            pros::lcd::print(2, "Theta: %f", chassis.getPose().theta); // heading
			pros::lcd::print(3, "X: %f", chassis.getPose().x); // x
            // delay to save resources
            pros::delay(200);
        }
    });
}


void disabled() {}


void competition_initialize() {}


void autonomous() {

	/*
	//loader #1
	wingPiston.set_value(true); // close wings
    chassis.setPose(0, 0, 0);
    chassis.moveToPoint(0, 25.1, 1000); 
	pros::delay(100);
	chassis.turnToHeading(-90, 1000); //turn towards first loader
	pros::delay(100);
	loaderPiston.set_value(true); // open loader
	intake_motors.move(127);
	pros::delay(200);
	chassis.moveToPoint(-27.9, 36.5, 2000, {.maxSpeed = 40}); //move towards loader
	pros::delay(2000);
	chassis.moveToPoint(-17.9, 36.5, 1000, {.forwards = false});
	pros::delay(200);
	chassis.moveToPoint(-29.9, 36.5, 1000, {.maxSpeed = 40}); //back up a bit
	pros::delay(800);
	chassis.moveToPoint(-5, 36.5, 1000, {.forwards = false});
	loaderPiston.set_value(false); // close loader
	pros::delay(200);


	//chassis.swingToPoint(5, 27, lemlib::DriveSide::LEFT, 1000);
	chassis.swingToHeading(-270, lemlib::DriveSide::LEFT, 1000);
	pros::delay(200);
	//chassis.moveToPoint(4, -60, 1000);
	*/

	chassis.setPose(0, 0, 0);
    // turn to face heading 90 with a very long timeout
    chassis.turnToHeading(90, 100000);






}


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
			//if(master.get_digital(DIGITAL_L1)) // changed 01/12/26 -> if both outtake motors are triggered, hood will automatically open
			//wingPiston.set_value(!wingToggled); 		// *if you dont like this, make it hold instead of toggle*
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
		pros::delay(20);                              
	}
}