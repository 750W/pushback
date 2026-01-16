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

void swing_turn(float heading, lemlib::DriveSide side, float timeout, bool clockwise = false) 
{
	left_motors.brake();
	right_motors.brake();
	float last_error = 0;
	float total_error = 0;
	float dt = 20;
	float error_threshold = 1.0;
	float start_time = pros::millis();
	while((pros::millis() - start_time) < timeout) {
		float error = heading - chassis.getPose().theta;

        while (error > 180) error -= 360;
        while (error < -180) error += 360;
        
        if (clockwise && error < 0) error += 360;
		
        if (!clockwise && error > 0) error -= 360;
        
        if(std::abs(error) < error_threshold) break;
        
		total_error += error * (dt / 1000.0);
		float P = swingController.kP * error;
		float I = swingController.kI * total_error;
		float D = swingController.kD * (error - last_error) / (dt / 1000.0);
		float output = P + I + D;
		output = std::clamp(output, -127.0f, 127.0f);
		if(side == lemlib::DriveSide::LEFT) {
			left_motors.move(-output);
			right_motors.move(0);
		} else {
			left_motors.move(0);
			right_motors.move(output);
		}

		last_error = error;
		pros::delay(dt);
	}
	left_motors.move(0);
    right_motors.move(0);
}


void autonomous() {

	
	//loader #1
	
	wingPiston.set_value(true); // close wings
    chassis.setPose(0, 0, 0);
    chassis.moveToPoint(0, 25.9, 1000); 
	pros::delay(100);
	chassis.turnToHeading(-90, 1000); //turn towards first loader
	pros::delay(100);
	loaderPiston.set_value(true); // open loader
	intake_motors.move(127);
	outtake_motors.move(40);
	pros::delay(200);
	chassis.moveToPoint(-29, 36.5, 2400, {.maxSpeed = 45}); //move towards loader
	pros::delay(2700);
	chassis.moveToPoint(-5, 36.5, 1000, {.forwards = false});
	loaderPiston.set_value(false); // close loader wings
	pros::delay(200);

	chassis.turnToHeading(-130, 1000);
	pros::delay(200);

	chassis.moveToPoint(6.5, 46, 1000, {.forwards = false});
	pros::delay(500);

	intake_motors.move(0);
	outtake_motors.move(0);

	chassis.turnToHeading(-78.5, 1000);
	pros::delay(200);



	chassis.moveToPoint(66, 45,  2000, {.forwards = false});
	pros::delay(2000);

	chassis.turnToHeading(0, 1000);
	pros::delay(500);

	

	chassis.moveToPoint(73, 24.95, 1500, {.forwards = false, .maxSpeed = 70});
	pros::delay(500);

	chassis.turnToHeading(90, 1000); // face goal
	pros::delay(500);

	

	chassis.moveToPoint(56.5, 12.5, 3000, {.forwards = false});
	pros::delay(2000);
	
	outtake_motors.move(-127);
	intake_motors.move(-127);

	pros::delay(100);
	wingPiston.set_value(false); // open wings
	outtake_motors.move(99);
	intake_motors.move(99);

	pros::delay(2500);
	

	chassis.setPose(0, 0, 0);

	loaderPiston.set_value(true); // open loader wings
	wingPiston.set_value(true); // close wings
	chassis.moveToPoint(0.3, 29, 3000, {.maxSpeed = 40});

	pros::delay(1000);
	chassis.moveToPoint(0,0,5000, {.forwards = false, .maxSpeed = 81});
	pros::delay(2000);

	highScoring_motors.move(-100);
	pros::delay(100);
	wingPiston.set_value(false); // open wings
	highScoring_motors.move(100);
	loaderPiston.set_value(false); // close loader wings
	pros::delay(2500);
	wingPiston.set_value(true); // open loader wings
	swing_turn(85, lemlib::DriveSide::RIGHT, 250, true); // turn to face second loader
	pros::delay(500);


	chassis.moveToPoint(0, 10.6, 1000);
	pros::delay(500);
	loaderPiston.set_value(true); // open loader wings
	wingPiston.set_value(true); // close wings
	intake_motors.move(0);
	chassis.turnToHeading(90, 1000);
	
	

	chassis.moveToPose(72, 3, 90, 4000, {.maxSpeed = 100});
	pros::delay(1000);
	chassis.turnToHeading(0, 1000); // face goal
	pros::delay(500);
	intake_motors.move(127);
	outtake_motors.move(40);


	chassis.moveToPoint(80.5, 37, 2300, {.maxSpeed = 43});
	pros::delay(3700);
	intake_motors.move(0);
	outtake_motors.move(0);

	//bs code
	chassis.moveToPoint(80.5, 14.6, 1000, {.forwards = false, .maxSpeed = 70});
	pros::delay(300);
	chassis.turnToHeading(-45, 1000);
	pros::delay(200);
	chassis.moveToPoint(90, 0, 800, { .forwards = false, .maxSpeed = 100}); //move towards loader
	pros::delay(300);
	chassis.turnToHeading(0, 600);
	pros::delay(200);
	chassis.moveToPoint(95, -57, 2000, {.forwards = false, .maxSpeed = 100});
	pros::delay(800);
	loaderPiston.set_value(false); // close loader wing
	pros::delay(500);
	chassis.turnToHeading(90, 800);
	pros::delay(500);

	
	chassis.moveToPoint(74, -69, 1000, {.forwards = false, .maxSpeed = 70});
	pros::delay(1000);
	chassis.turnToHeading(180, 800);
	pros::delay(500);
	chassis.moveToPoint(61, -45, 2500, {.forwards = false, .maxSpeed = 70});
	pros::delay(500);
	wingPiston.set_value(false); // open wings
	highScoring_motors.move(-100);
	pros::delay(100);
	highScoring_motors.move(100);
	pros::delay(2500);
	loaderPiston.set_value(true); // open loader wings
	chassis.setPose(0, 0, 0);
	highScoring_motors.move(0);
	pros::delay(500);
	intake_motors.move(100);
	outtake_motors.move(40);
	chassis.moveToPoint(0.3, 29, 2500, {.maxSpeed = 40});
	pros::delay(2000);
	chassis.moveToPoint(0,0,5000, {.forwards = false, .maxSpeed = 70});
	pros::delay(2000);
	highScoring_motors.move(-100);
	pros::delay(100);
	wingPiston.set_value(false); // open wings
	highScoring_motors.move(100);
	loaderPiston.set_value(false); // close loader wings









	 

	return;
	chassis.moveToPoint(80.5, -0.3, 1000, {.forwards = false, .maxSpeed = 70});
	pros::delay(500);
	//pros::delay(500);
	highScoring_motors.move(-100);
	pros::delay(100);
	wingPiston.set_value(false);
	highScoring_motors.move(100);
	pros::delay(2000);
	chassis.setPose(0, 0, 0);


	chassis.moveToPoint(0, 10.6, 1000);
	pros::delay(800);
	chassis.turnToHeading(-45, 1000);
	pros::delay(200);
	chassis.moveToPoint(10, 0, 800, { .forwards = false, .maxSpeed = 100}); //move towards loader
	pros::delay(300);
	chassis.turnToHeading(0, 600); 
	pros::delay(200);
	chassis.moveToPoint(19, -43, 4000, {.forwards = false, .maxSpeed = 100});
	pros::delay(800);
	loaderPiston.set_value(false); // close loader wings
	
	swing_turn(175, lemlib::DriveSide::LEFT, 800, true); //just changed to 87 , initially 85
	
	pros::delay(500);
	
	//idk if it works
	pros::delay(1000);
	highScoring_motors.move(-100);
	pros::delay(100);
	loaderPiston.set_value(true); // open loader wings
	wingPiston.set_value(false); // open wings
	highScoring_motors.move(100);
	pros::delay(2500);
	chassis.setPose(0,0,0);
	wingPiston.set_value(true); // close wings
	chassis.moveToPoint(0, 25.9, 7000);
	pros::delay(2000);
	chassis.moveToPoint(0,0, 1200, {.forwards = false, .maxSpeed = 81});
	pros::delay(2000);
	loaderPiston.set_value(false); // close loader wings
	highScoring_motors.move(-100);
	pros::delay(100);
	wingPiston.set_value(false); // open wings
	highScoring_motors.move(100);
	pros::delay(2500);
	//wingPiston.set_value(true); // close wings






	

	








	 // outtake

	//chassis.moveToPoint(45, 17, 2000, {.forwards = false});
	
	
	/*
	chassis.moveToPoint(-17.9, 36.5, 1000, {.forwards = false});
	pros::delay(200);
	chassis.moveToPoint(-29.9, 36.5, 1000, {.maxSpeed = 40}); //back up a bit
	pros::delay(800);
	*/
	/*
	chassis.moveToPoint(-5, 36.5, 1000, {.forwards = false});
	pros::delay(200);

	chassis.turnToHeading(-175.44, 1000);
	pros::delay(200);

	loaderPiston.set_value(false); // close loader wings

	chassis.moveToPoint(-14.6, 35.14, 1000, {.forwards = false}); //move to outtake zone
	pros::delay(500);

	chassis.turnToHeading(-90, 1000); // align to goal
	pros::delay(200);

	chassis.moveToPoint(70, 43.6, 2000, {.forwards = false});
	pros::delay(700);

	chassis.turnToHeading(0, 2000); // face goal
	pros::delay(700);

	//
	chassis.moveToPoint(79, 25, 2000, {.forwards = false});
	pros::delay(500);
	
	chassis.turnToHeading(90, 1000); // face goal
	pros::delay(700);

	
	chassis.moveToPoint(60.1, 11.7, 1000, {.forwards = false});
	pros::delay(500);

	wingPiston.set_value(false); // open wings
	pros::delay(500);

	highScoring_motors.move(127); // outtake
	pros::delay(1200);
	
	*/


	

	/*
	chassis.turnToHeading(0, 1000);
	pros::delay(200);
	chassis.moveToPoint(-5, 40, 1000);
	pros::delay(200);
	*/
	
	// swing_turn(180, lemlib::DriveSide::LEFT, 1300); // turn to face first loader
	// pros::delay(200);


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