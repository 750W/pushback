#include "headers/autons.hpp"
#include "lemlib/api.hpp"
#include "headers/robot_config.hpp"


void progskills1()
{
    // set position to x:0, y:0, heading:0
    chassis.setPose(0, 0, 0);
    // turn to face heading 90 with a very long timeout
    chassis.turnToHeading(90, 100000);
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
    chassis.moveToPoint(6.11, 15, 1200, {.maxSpeed = 50});
    pros::delay(300);
    chassis.turnToHeading(132, 1000);
    loaderPiston.set_value(true);
    pros::delay(200);
    chassis.moveToPoint(15, -6, 1400, {.maxSpeed = 90});
    pros::delay(300);
    loaderPiston.set_value(true);
    pros::delay(300);
    chassis.turnToHeading(180, 1000);
    pros::delay(200);
    chassis.moveToPoint(11.4, -13, 1400, {.maxSpeed = 81});
    pros::delay(1000);
    chassis.moveToPoint(7.65, 15.3, 2300, {.forwards = false, .maxSpeed = 81});
    pros::delay(800);
    wingPiston.set_value(false);
    highScoring_motors.move(127);
    pros::delay(400);
    loaderPiston.set_value(false);
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


    


}