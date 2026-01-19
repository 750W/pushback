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
    chassis.moveToPoint(5.84, 17, 1200, {.maxSpeed = 50});
    chassis.waitUntil(14);
    loaderPiston.set_value(true);
    pros::delay(300);
    chassis.turnToHeading(132, 1000);
    pros::delay(200);
    chassis.moveToPoint(14.3, -6, 1400, {.maxSpeed = 90});
    pros::delay(300);
    loaderPiston.set_value(true);
    pros::delay(300);
    chassis.turnToHeading(180, 1000);
    pros::delay(200);
    chassis.moveToPoint(9.9, -15, 1200, {.maxSpeed = 70});
    pros::delay(800);
    chassis.moveToPoint(6.44, 15.3, 2700, {.forwards = false, .maxSpeed = 70});
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
    chassis.turnToHeading(127, 800);
    pros::delay(200);
    chassis.moveToPoint(4.2, 4.2, 1000, {.forwards = false, .maxSpeed = 70});
    pros::delay(500);
    //chassis.moveToPoint(7.08, 0.917, 1000, {.forwards = true, .maxSpeed = 60});
    //pros::delay(300);
    chassis.turnToHeading(175, 1000);
    pros::delay(200);
    chassis.moveToPoint(0.5, 30.3, 1800, {.forwards = false, .maxSpeed = 80});

    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);

}

void seven_wingL()
{
    wingPiston.set_value(true);
    intake_motors.move(127);
    outtake_motors.move(40);
    chassis.moveToPoint(0.07, 2.8, 400, {.maxSpeed = 80});
    pros::delay(300);
    chassis.turnToHeading(-20.8, 1000);
    pros::delay(500);
    loaderPiston.set_value(true);
    chassis.moveToPoint(6.11, 15, 1200, {.maxSpeed = 50});
    pros::delay(300);
    chassis.turnToHeading(-132, 1000);
    pros::delay(200);
    chassis.moveToPoint(14, -6, 1400, {.maxSpeed = 90});
    pros::delay(300);
    loaderPiston.set_value(true);
    pros::delay(300);
    chassis.turnToHeading(-180, 1000);
    pros::delay(200);
    chassis.moveToPoint(11.4, -13, 1400, {.maxSpeed = 81});
    pros::delay(1000);
    chassis.moveToPoint(7.65, 15.3, 2300, {.forwards = false, .maxSpeed = 81});
    pros::delay(800);
    wingPiston.set_value(false);
    highScoring_motors.move(127);
    pros::delay(400);
    loaderPiston.set_value(false);

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