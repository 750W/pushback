#include "main.h"
#include "lemlib/api.hpp"
#include "headers/robot_config.hpp"
#include "headers/autons.hpp"
#include <iostream>
#include <fstream>

int readAuton();


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
	wingPiston.set_value(false);
	
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
	/*
	
	wingPiston.set_value(true); // close wings
    chassis.setPose(0, 0, 0);
    chassis.moveToPoint(0, 25.4, 1000); 
	pros::delay(100);
	chassis.turnToHeading(-90, 1000); //turn towards first loader
	pros::delay(100);
	loaderPiston.set_value(true); // open loader
	intake_motors.move(127);
	outtake_motors.move(40);
	pros::delay(200);
	chassis.moveToPoint(-28.9, 36.5, 2400, {.maxSpeed = 45}); //move towards loader
	pros::delay(100);
	chassis.moveToPoint(-10, 36.5, 1000, {.forwards = false});
	loaderPiston.set_value(false); // close loader wings
	pros::delay(200);

	chassis.turnToHeading(-130, 700);
	pros::delay(200);

	

	chassis.moveToPoint(3.5, 42.5, 700, {.forwards = false});
	pros::delay(100);


	intake_motors.move(0);
	outtake_motors.move(0);

	chassis.turnToHeading(-79, 1000);
	pros::delay(100);
	
	
	



	chassis.moveToPoint(67.3, 42.9,  2500, {.forwards = false, .maxSpeed = 100});
	pros::delay(500);
	

	chassis.turnToHeading(0, 1000);
	pros::delay(300);



	chassis.moveToPoint(74.9, 22.2, 1000, {.forwards = false, .maxSpeed = 100});
	pros::delay(100);



	chassis.turnToHeading(89, 1000); // face goal
	pros::delay(100);



	chassis.moveToPoint(56, 11, 3000, {.forwards = false, .maxSpeed = 70});
	pros::delay(500);
	right_motors.move(35);
	left_motors.move(35);
	//return;
	
	
	
	outtake_motors.move(-127);
	intake_motors.move(-127);

	pros::delay(150);
	wingPiston.set_value(false); // open wings
	outtake_motors.move(127);
	intake_motors.move(127);

	pros::delay(2500);
	outtake_motors.move(40);
	intake_motors.move(127);
	loaderPiston.set_value(true); // open loader wings
	wingPiston.set_value(true); // close wings
	chassis.waitUntilDone();

	

	chassis.setPose(0, 0, 0);
	pros::delay(100); // let odometry stabilize after pose reset

	


	
	chassis.moveToPoint(0, 34.5, 3200, {.maxSpeed = 45, .minSpeed = 20});
	

	pros::delay(2000);
	chassis.moveToPoint(0,-1,3000, {.forwards = false, .maxSpeed = 81});
	pros::delay(550);

	highScoring_motors.move(-100);
	pros::delay(100);
	highScoring_motors.move(100);
	wingPiston.set_value(false); // open wings
	loaderPiston.set_value(false); // close loader wings

	pros::delay(2000);
	wingPiston.set_value(true); // open loader wings
	//swing_turn(85, lemlib::DriveSide::RIGHT, 250, true); // turn to face second loader
	pros::delay(500);


	chassis.moveToPoint(0, 10.6, 1000);
	pros::delay(500);
	loaderPiston.set_value(true); // open loader wings
	wingPiston.set_value(true); // close wings
	intake_motors.move(0);
	chassis.turnToHeading(90, 1000);
	//return;
	
	

	chassis.moveToPoint(69.8, 8, 2000, {.maxSpeed = 100});
	pros::delay(600);
	chassis.turnToHeading(0, 1000); // face goal
	pros::delay(500);
	intake_motors.move(127);
	outtake_motors.move(40);


	chassis.moveToPoint(77.5, 39, 2500, {.maxSpeed = 43});
	pros::delay(3700);
	intake_motors.move(0);
	outtake_motors.move(0);

	//bs code
	loaderPiston.set_value(false); // close loader wing
	chassis.moveToPoint(80.5, 23, 1000, {.forwards = false, .maxSpeed = 70});
	pros::delay(300);
	chassis.turnToHeading(-47, 1000);
	pros::delay(200);
	chassis.moveToPoint(90, 0, 1200, { .forwards = false, .maxSpeed = 100}); //move towards loader
	pros::delay(300);
	chassis.turnToHeading(6.7, 600);
	pros::delay(200);
	chassis.moveToPoint(99, -54, 2000, {.forwards = false, .maxSpeed = 100});
	pros::delay(800);
	
	pros::delay(500);
	chassis.turnToHeading(90, 800);
	pros::delay(500);

	
	chassis.moveToPoint(73.6, -67, 1000, {.forwards = false, .maxSpeed = 70});
	pros::delay(1000);
	chassis.turnToHeading(180, 800);
	pros::delay(500);
	chassis.moveToPoint(62.4, -43, 2500, {.forwards = false, .maxSpeed = 70});
	pros::delay(500);
	wingPiston.set_value(false); // open wings
	highScoring_motors.move(-100);
	pros::delay(100);
	highScoring_motors.move(100);
	pros::delay(2500);
	loaderPiston.set_value(true); // open loader wings
	wingPiston.set_value(true); // close wings
	
	chassis.setPose(0, 0, 0);
	highScoring_motors.move(0);
	pros::delay(500);
	intake_motors.move(100);
	outtake_motors.move(40);
	chassis.moveToPoint(0.3, 29, 3500, {.maxSpeed = 40});
	pros::delay(2200);
	chassis.moveToPoint(0,0,5000, {.forwards = false, .maxSpeed = 70});
	intake_motors.move(0);
	outtake_motors.move(0);
	pros::delay(2000);
	highScoring_motors.move(-100);
	pros::delay(100);
	wingPiston.set_value(false); // open wings
	highScoring_motors.move(127);
	loaderPiston.set_value(false); // close loader wings
	

	//park
	chassis.moveToPose(10.7, 18, 90, 2500, {.maxSpeed = 110});
	pros::delay(200);
	chassis.moveToPoint(40, 25, 2000, {.minSpeed= 118});
	*/


	// seven_wingR();


	int autonNum = readAuton();

   switch(autonNum)
    {
     case 0: 
      master.print(0,0, "Prog Skills");
       progskills1();
       break;

     case 1: 
       master.print(0,0, "Seven Wing Left");
       seven_wingL();
       break;
    
     case 2:
      master.print(0,0, "Seven Wing Right");
      seven_wingR();
      break;
    }


   //chassis.moveToPoint(0, 4, 1000);

	
}

int readAuton() {
  std::ifstream autonFile("/usd/auton.txt");
  int auton;
  autonFile >> auton;
  autonFile.close();
  return auton;
}

void opcontrol() {

	bool wingToggled = true;
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