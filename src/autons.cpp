#include "headers/autons.hpp"
#include "lemlib/api.hpp"
#include "headers/robot_config.hpp"

/// @brief  Moves the motors a little to keep match loader pressed
void load_hold() {
    left_motors.move(19);
    right_motors.move(19);
}

void hold_stop() {
    left_motors.move(0);
    right_motors.move(0);
}

void score_hold() {
    left_motors.move(-42);
    right_motors.move(-42);
}


void progskills1()
{
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



	chassis.moveToPoint(74.9, 24.5, 1000, {.forwards = false, .maxSpeed = 100});
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
}

void progskills2()
{
    chassis.setPose(0, 0, 0);
    // wingPiston.set_value(true); // close wings
    // intake_motors.move(127);
    // outtake_motors.move(40);
    // chassis.moveToPose(-8, 23, -39.1, 2000);
    // pros::delay(100);
    // chassis.moveToPoint(-9, 24, 2000);
    // pros::delay(100);
    // chassis.turnToHeading(-130.4, 1000);
    // pros::delay(200);
    // chassis.moveToPoint(-14.7, 38, 700, {.forwards = false, .maxSpeed = 60});
    // pros::delay(1000);
    // intake_motors.move(70);
    // outtake_motors.move(-70);
    // pros::delay(2000);
    // intake_motors.move(0);
    // outtake_motors.move(0);
    // chassis.moveToPoint(-46, 13, 2500, { .maxSpeed = 90});
    // chassis.turnToHeading(-180, 1000);
    // intake_motors.move(127);
    // outtake_motors.move(40);
    // loaderPiston.set_value(true); // open loader
    // pros::delay(500);
    // chassis.moveToPoint(-52, -12, 3000, {.maxSpeed = 40});
    // pros::delay(3000);
    // intake_motors.move(0);
    // outtake_motors.move(0);

    // chassis.moveToPoint(-51, 0, 2000, {.forwards = false});
    // pros::delay(1000);
    // loaderPiston.set_value(false); // close loader
    // chassis.turnToHeading(-207, 1000);
    // pros::delay(1000);
    // chassis.moveToPoint(-56, 8, 1400, {.forwards = false});
    // pros::delay(1000);
    // chassis.turnToHeading(-180, 1000);
    // pros::delay(500);
    // chassis.moveToPoint(-56, 78, 5000, {.forwards = false, .maxSpeed = 90});
    // pros::delay(2000);
    // chassis.turnToHeading(-90, 1000);
    // pros::delay(500);
    // chassis.moveToPoint(-33, 87, 3000, {.forwards = false});
    // pros::delay(2000);
    // chassis.turnToHeading(0, 1000);
    // pros::delay(500);
    // chassis.moveToPoint(-23, 67, 4000, {.forwards = false});
    // pros::delay(2000);
    // wingPiston.set_value(false); // open wings
    // highScoring_motors.move(-100);
    // pros::delay(100);
    // highScoring_motors.move(100);
    // pros::delay(2500);
    // chassis.setPose(0, 0, 0);
    // pros::delay(100);
    // loaderPiston.set_value(true); 
    // wingPiston.set_value(true);
    // highScoring_motors.move(0);
    // outtake_motors.move(40);
    // intake_motors.move(127);

    // chassis.moveToPoint(0, 33, 3200, {.maxSpeed = 45, .minSpeed = 20});
    // pros::delay(3000);
    // chassis.moveToPoint(0,0,3000, {.forwards = false, .maxSpeed = 81});
    // pros::delay(550);
    // highScoring_motors.move(-100);
    // pros::delay(100);
    // highScoring_motors.move(100);
    // wingPiston.set_value(false); // open wings
    // loaderPiston.set_value(false); // close loader wings
    // pros::delay(2000);
    // wingPiston.set_value(true); // open loader wings
    // pros::delay(500);
    // chassis.turnToHeading(30, 1000);
    // pros::delay(500);

    // wingPiston.set_value(true); // close wings
    // intake_motors.move(100);
    // outtake_motors.move(40);

    chassis.setPose(0, 0, 0);
    intake_motors.move(120);
    outtake_motors.move(40);
    wingPiston.set_value(true); // close wings
    chassis.moveToPoint(0, 8, 2000, {.maxSpeed = 100});
    pros::delay(100);
    chassis.turnToHeading(30, 1000);
    pros::delay(100);
    chassis.moveToPoint(11,19.5 , 2500, {.maxSpeed = 90});
    pros::delay(1000);

    chassis.swingToHeading(80, lemlib::DriveSide::LEFT, 1000);
    pros::delay(500);

    
    chassis.moveToPoint(65, 24, 2000, {.maxSpeed = 60});
    chassis.moveToPoint(75, 24, 2000, {.maxSpeed = 100});
    

    pros::delay(3000);
    chassis.swingToHeading(18, lemlib::DriveSide::LEFT, 1000);
    pros::delay(1000);
    chassis.moveToPoint(66, -14, 10000, {.forwards = false, .maxSpeed = 80});
    pros::delay(500);
    chassis.swingToHeading(45, lemlib::DriveSide::RIGHT, 1000);
    pros::delay(2000);
    intake_motors.move(90);
    outtake_motors.move(-50);

    pros::delay(3000);
    intake_motors.move(0);
    outtake_motors.move(0);
    
}


void seven_wingR()
{
    wingPiston.set_value(true);
    intake_motors.move(127);
    outtake_motors.move(40);
    chassis.moveToPoint(0.07, 2.8, 400, {.maxSpeed = 80});
    pros::delay(300);
    chassis.turnToHeading(23.8, 1000);
    pros::delay(500);
    chassis.moveToPoint(7.84, 17, 1200, {.maxSpeed = 40});
    chassis.waitUntil(14);
    loaderPiston.set_value(true);
    pros::delay(300);
    chassis.turnToHeading(132, 1000);
    pros::delay(200);
    chassis.moveToPoint(12.9, -7.1, 1400, {.maxSpeed = 90});
    
    pros::delay(300);
    loaderPiston.set_value(true);
    pros::delay(300);
    chassis.turnToHeading(180, 1000);
    pros::delay(200);
    chassis.moveToPoint(12.1, -15, 1700, {.maxSpeed = 70});
    
	//chassis.moveToPose(9.9, -15, 180, 1200);
    pros::delay(800);
    chassis.moveToPoint(9.1, 15.3, 2500, {.forwards = false, .maxSpeed = 70});
    pros::delay(800);
    intake_motors.move(-127);
    wingPiston.set_value(false);
    outtake_motors.move(0);
    pros::delay(200);
    highScoring_motors.move(127);
    pros::delay(400);
    loaderPiston.set_value(false);
    wingPiston.set_value(false);
    
    chassis.moveToPoint(8.5, 2.44, 1000, {.maxSpeed = 80});
    pros::delay(300);
    chassis.turnToHeading(120, 800);
    pros::delay(200);
    chassis.moveToPoint(4.6, 3.8, 1000, {.forwards = false, .maxSpeed = 70});
    pros::delay(500);
    //chassis.moveToPoint(7.08, 0.917, 1000, {.forwards = true, .maxSpeed = 60});
    //pros::delay(300);
    chassis.turnToHeading(174, 1000);
    pros::delay(200);
    chassis.moveToPoint(2.5, 30.3, 1800, {.forwards = false, .maxSpeed = 80});

    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
    
    

}

void seven_wingL()
{
	wingPiston.set_value(true);
    intake_motors.move(127);
    outtake_motors.move(40);
    chassis.moveToPoint(-0.07, 2.8, 400, {.maxSpeed = 80});
    pros::delay(300);
    chassis.turnToHeading(-24.2, 700);
    pros::delay(500);
    chassis.moveToPoint(-9, 23.3, 1200, {.maxSpeed = 50});
    chassis.waitUntil(10);
    loaderPiston.set_value(true);
    pros::delay(300);
    chassis.turnToHeading(-132, 1000);
	pros::delay(400);
	chassis.moveToPoint(-14, 39.6, 1950, {.forwards = false, .maxSpeed = 70}); // mid goal
	pros::delay(500);
	intake_motors.move_velocity(100);
	outtake_motors.move_velocity(-90);
    loaderPiston.set_value(false);
    pros::delay(800);
    chassis.moveToPoint(-45.5, 13.2, 1400, {.maxSpeed = 90});
    pros::delay(300);
    loaderPiston.set_value(true);
    pros::delay(300);
    chassis.turnToHeading(-178, 1000);
    intake_motors.move_velocity(127);
	outtake_motors.move_velocity(80);
    pros::delay(200);
    // chassis.moveToPoint(-50, -8, 1600, {.maxSpeed = 70}); // match load
    chassis.moveToPoint(-50.9, -8, 1600, {.maxSpeed = 40, .minSpeed = 24});
    load_hold();
    pros::delay(800); // LOADING TIME
    hold_stop();
    pros::delay(800);
    highScoring_motors.move(127);
	//dk if this works
    chassis.moveToPoint(-49, 19, 2700, {.forwards = false, .maxSpeed = 70});
    pros::delay(800);
    intake_motors.move(-127);
    wingPiston.set_value(false);
    outtake_motors.move(0);
    pros::delay(90);
    highScoring_motors.move(127);
    pros::delay(900);
    loaderPiston.set_value(false);
    wingPiston.set_value(false);
    chassis.moveToPoint(-49.6, 7.7, 1000, {.maxSpeed = 49, .minSpeed = 37});
    chassis.turnToHeading(-230, 400, {.minSpeed = 37});
    chassis.moveToPoint(-52, 2.7, 1400, {.forwards=false, .maxSpeed=45, .minSpeed=37});
    chassis.turnToHeading(-184, 800);
    chassis.moveToPoint(-58.4, 34.3, 1400, {.forwards = false, .maxSpeed = 60});
	

    /*
    chassis.moveToPoint(9.49, 2.44, 1000, {.maxSpeed = 80});
    pros::delay(300);
    chassis.turnToHeading(127, 800);
    pros::delay(200);
    chassis.moveToPoint(3.8, 4.2, 1000, {.forwards = false, .maxSpeed = 70});
    pros::delay(500);
    //chassis.moveToPoint(7.08, 0.917, 1000, {.forwards = true, .maxSpeed = 60});
    //pros::delay(300);
    chassis.turnToHeading(175, 1000);
    pros::delay(200);
    chassis.moveToPoint(0.5, 30.3, 1800, {.forwards = false, .maxSpeed = 50});
    */

}


void sawp_r()
{
    chassis.setPose(0, 0, 0);

    pros::delay(100); // let odometry stabilize after pose reset
    wingPiston.set_value(true); // close wings

    chassis.moveToPoint(0, 27, 1100);
    chassis.turnToHeading(90, 550);
    loaderPiston.set_value(true); // open loader wings
    intake_motors.move(127);
    outtake_motors.move(60);
    chassis.moveToPoint(1.5, 15.3, 1250, {.maxSpeed = 40, .minSpeed = 24});
    load_hold();
    pros::delay(100); // LOADING TIME
    hold_stop();
    chassis.moveToPoint(-31, 14.7, 3600, {.forwards = false, .maxSpeed = 76, .minSpeed = 42}); // into goal
    chassis.waitUntilDone();
    wingPiston.set_value(false); // open hood
    score_hold();
    highScoring_motors.move(-100);
    pros::delay(100);
    highScoring_motors.move(100);
    loaderPiston.set_value(false); // close loader
    pros::delay(1100); // SCORING TIME
    hold_stop();
    highScoring_motors.move(0);
    wingPiston.set_value(true); // open wings
    chassis.setPose(0, 0, 0);
    ///*
    pros::delay(100); // let odometry stabilize after pose reset
    // outtake_motors.move(-127);
    chassis.moveToPoint(0, 2.5, 800, {.minSpeed = 40});
    chassis.swingToHeading(145, lemlib::DriveSide::LEFT, 4000, {.minSpeed = 50}, true);
    pros::delay(100);
    wingPiston.set_value(true); // open hood
    highScoring_motors.move(127); // purge extra
    chassis.waitUntilDone();
    outtake_motors.move(60);
    chassis.moveToPoint(2, -14.3, 2000, {.maxSpeed = 50}, true); // grabs corners
    pros::delay(550);
    loaderPiston.set_value(true);
    chassis.waitUntilDone();
    pros::delay(500);
    //wingPiston.set_value(true); // close hood
    chassis.turnToHeading(90, 2000);
    loaderPiston.set_value(false);
    pros::delay(500);
    chassis.moveToPoint(52.5, -18, 4000, {.maxSpeed = 95}, true);
    pros::delay(777);
    loaderPiston.set_value(true);
    chassis.waitUntilDone();
    pros::delay(100);
    loaderPiston.set_value(false);
    chassis.turnToHeading(46, 550, {}, false);
    chassis.moveToPoint(47.7, -27.5, 1000, {.forwards = false, .maxSpeed = 50}, false); // goes to mid goal
    pros::delay(200);
    highScoring_motors.move(-127);
    pros::delay(100);
    intake_motors.move(127);
    outtake_motors.move(-127);
    pros::delay(300); // MID GOAL SCORING TIME
    highScoring_motors.move(0);
    pros::delay(300);
    chassis.moveToPoint(76, 2, 1000, {.minSpeed = 60});
    pros::delay(500);
    intake_motors.move(-127);
    outtake_motors.move(127);
    pros::delay(80);
    highScoring_motors.move(0);
    chassis.turnToHeading(0, 600);
    pros::delay(500);
    chassis.moveToPoint(80, -8, 1700, {.forwards = false});
    pros::delay(100);
    wingPiston.set_value(false); // open hood
    highScoring_motors.move(-100);
    pros::delay(100);
    highScoring_motors.move(100);
    pros::delay(1500); // SCORING TIME*/

}