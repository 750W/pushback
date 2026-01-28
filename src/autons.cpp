#include "headers/autons.hpp"
#include "lemlib/api.hpp"
#include "headers/robot_config.hpp"


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
    wingPiston.set_value(true); // close wings
    intake_motors.move(127);
    outtake_motors.move(40);
    chassis.moveToPose(-8, 23, -39.1, 2000);
    pros::delay(100);
    chassis.moveToPoint(-9, 24, 2000);
    pros::delay(100);
    chassis.turnToHeading(-130.4, 1000);
    pros::delay(200);
    chassis.moveToPoint(-14.7, 38, 700, {.forwards = false, .maxSpeed = 60}); // mid goal
    pros::delay(1000);
    intake_motors.move(70);
    outtake_motors.move(-70);
    pros::delay(2000);
    intake_motors.move(0);
    outtake_motors.move(0);
    chassis.moveToPoint(-45.27, 13.5, 2500, { .maxSpeed = 90}); // move from mid goal to match loader
    chassis.turnToHeading(-180, 1000);
	
    intake_motors.move(127);
    outtake_motors.move(40);
    loaderPiston.set_value(true); // open loader
    pros::delay(500);
    chassis.moveToPoint(-50.765, -9, 3000, {.maxSpeed = 40}); // match loader 1
    pros::delay(3000);
    intake_motors.move(0);
    outtake_motors.move(0);

    chassis.moveToPoint(-50.565, 8, 2000, {.forwards = false});
    pros::delay(1000);
    loaderPiston.set_value(false); // close loader

	chassis.swingToHeading(1, lemlib::DriveSide::LEFT, 1700, {.maxSpeed = 90});
	pros::delay(500);

	chassis.moveToPoint(-36, 78, 2700, {.maxSpeed = 90});
	

	/*
    chassis.turnToHeading(-207, 1000);
    pros::delay(1000);
    chassis.moveToPoint(-57, 9, 1400, {.forwards = false});
    pros::delay(1000);
    chassis.turnToHeading(-180, 1000);
    pros::delay(500);
    chassis.moveToPoint(-56, 78, 5000, {.forwards = false, .maxSpeed = 90});
    pros::delay(2000);
    chassis.turnToHeading(-90, 1000);
    pros::delay(500);
    chassis.moveToPoint(-37, 87, 3000, {.forwards = false}); 
    pros::delay(2000);
    chassis.turnToHeading(0, 1000);
    pros::delay(500);
    chassis.moveToPoint(-23, 67, 4000, {.forwards = false}); // move into high goal
    pros::delay(2000);
    wingPiston.set_value(false); // open wings
    highScoring_motors.move(-100);
    pros::delay(100);
    highScoring_motors.move(100);
    pros::delay(2500);
    chassis.setPose(0, 0, 0);
    pros::delay(100);
    loaderPiston.set_value(true); 
    wingPiston.set_value(true);
    highScoring_motors.move(0);
    outtake_motors.move(40);
    intake_motors.move(127);

    chassis.moveToPoint(0, 33, 3200, {.maxSpeed = 45, .minSpeed = 20});
    pros::delay(3000);
    chassis.moveToPoint(0,0,3000, {.forwards = false, .maxSpeed = 81});
    pros::delay(550);
    highScoring_motors.move(-100);
    pros::delay(100);
    highScoring_motors.move(100);
    wingPiston.set_value(false); // open wings
    loaderPiston.set_value(false); // close loader wings
    pros::delay(2000);
    wingPiston.set_value(true); // open loader wings
    pros::delay(500);
    chassis.turnToHeading(30, 1000);
    pros::delay(500);

    wingPiston.set_value(true); // close wings
    intake_motors.move(100);
    outtake_motors.move(40);

   
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
	*/
    
}


void seven_wingR()
{
    /*
    wingPiston.set_value(true);
    intake_motors.move(127);
    outtake_motors.move(40);
    pros::delay(200);
    chassis.moveToPoint(1.2, 25.698, 1300, {.maxSpeed = 50});
    pros::delay(300);
    chassis.turnToHeading(109.85, 1000);
    pros::delay(200);
    loaderPiston.set_value(true);
    pros::delay(300);
    chassis.moveToPoint(9.5, 12.3, 1000, {.maxSpeed = 80});
    //return;
    pros::delay(300);
    chassis.turnToHeading(163, 1000);
    pros::delay(200);
    chassis.moveToPoint(16.5, -1.3, 1400, {.maxSpeed = 90});
    pros::delay(500);
    
    chassis.moveToPoint(2.447, 21.076, 2500, {.forwards = false, .maxSpeed = 81});
    pros::delay(500);
    highScoring_motors.move(-127);
    pros::delay(300);
    wingPiston.set_value(false);
    highScoring_motors.move(127);
    */

    wingPiston.set_value(true);
    intake_motors.move(127);
    outtake_motors.move(40);
    chassis.moveToPoint(0.07, 2.8, 400, {.maxSpeed = 80});
    pros::delay(300);
    chassis.turnToHeading(20.8, 1000);
    pros::delay(500);
    chassis.moveToPoint(5.84, 17, 1200, {.maxSpeed = 40});
    chassis.waitUntil(14);
    loaderPiston.set_value(true);
    pros::delay(300);
    chassis.turnToHeading(132, 1000);
    pros::delay(200);
    chassis.moveToPoint(11.1, -6, 1400, {.maxSpeed = 90});
    pros::delay(300);
    loaderPiston.set_value(true);
    pros::delay(300);
    chassis.turnToHeading(180, 1000);
    pros::delay(200);
    chassis.moveToPoint(9.9, -15, 1200, {.maxSpeed = 70});
	//chassis.moveToPose(9.9, -15, 180, 1200);
    pros::delay(800);
    chassis.moveToPoint(7.3, 15.3, 2500, {.forwards = false, .maxSpeed = 70});
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
    chassis.turnToHeading(-20.8, 1000);
    pros::delay(500);
    chassis.moveToPoint(-9, 23, 1200, {.maxSpeed = 40});
    chassis.waitUntil(14);
    loaderPiston.set_value(true);
    pros::delay(300);
    chassis.turnToHeading(-132, 1000);
	pros::delay(400);
	chassis.moveToPoint(-15, 40, 1200, {.forwards = false, .maxSpeed = 70}); // mid goal
	pros::delay(500);
	intake_motors.move_velocity(100);
	outtake_motors.move_velocity(-90);
	pros::delay(300);
	intake_motors.move_velocity(100);
	outtake_motors.move_velocity(-40);
    pros::delay(800);
    chassis.moveToPoint(-44.5, 12.9, 1400, {.maxSpeed = 90});
    pros::delay(300);
    loaderPiston.set_value(true);
    pros::delay(300);
    chassis.turnToHeading(-184, 1000);
    pros::delay(200);
    chassis.moveToPoint(-50, -8, 1600, {.maxSpeed = 70}); // match load
    pros::delay(800);
	//dk if this works
    chassis.moveToPoint(-50.5, 19, 2700, {.forwards = false, .maxSpeed = 70});
    pros::delay(800);
    intake_motors.move(-127);
    wingPiston.set_value(false);
    outtake_motors.move(0);
    pros::delay(200);
    highScoring_motors.move(127);
    pros::delay(400);
    loaderPiston.set_value(false);
    wingPiston.set_value(false);
	

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