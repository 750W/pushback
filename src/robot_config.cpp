#include "headers/robot_config.hpp"
#include "lemlib/api.hpp"

// Controller
pros::Controller master(pros::E_CONTROLLER_MASTER);

// Motors 
pros::MotorGroup left_motors({1,2, 3});    
pros::MotorGroup right_motors({-4, -5, -6});

//intake motors
pros::Motor bottom_intake_motor(7);
pros::Motor top_intake_motor(-8);

pros::MotorGroup intake_motors({7,-8});
pros::Motor outtake_motors(1);

pros::MotorGroup highScoring_motors({9,10,1});

//Pneumatics
pros::adi::DigitalOut wingPiston('E');
pros::adi::DigitalOut loaderPiston('B'); //change later
pros::adi::DigitalOut intakePiston('A'); //change later
pros::adi::DigitalOut midDescorePiston('H'); //change later

// Sensors (change port!)
pros::Imu imu(20);
pros::Distance front(18);
pros::Distance left(16);
pros::Distance right(17);


// ---- LemLib setup (YOU will fill in correct values) ----
// These are placeholders to show structure.
// You'll need: drivetrain, controllers, sensors config.

lemlib::Drivetrain drivetrain(
    &left_motors,
    &right_motors,
    10.0,   // track width (inches)
    2.75,   // wheel diameter (inches)
    450.0,  // rpm (depends on cartridge)
    2.0     // horizontal drift (tuning value)
);

lemlib::OdomSensors sensors(nullptr, nullptr, nullptr, nullptr, &imu);

lemlib::ControllerSettings linearController(8,0, 17, 
                                              3, // anti windup 3
                                              1, // small error range, in inches 1
                                              100, // small error range timeout, in milliseconds 100
                                              3, // large error range, in inches 3 
                                              500, // large error range timeout, in milliseconds 500
                                              20 // maximum acceleration (slew) 20

);



lemlib::ControllerSettings angularController(-3.5, // proportional gain (kP)
                                              0, // integral gain (kI)
                                              -24, // derivative gain (kD)
                                              3, // anti windup
                                              1, // small error range, in inches
                                              100, // small error range timeout, in milliseconds
                                              3, // large error range, in inches
                                              500, // large error range timeout, in milliseconds
                                              0 // maximum acceleration (slew)
);




lemlib::Chassis chassis(drivetrain, linearController, angularController, sensors);


//SWING TURN PID

lemlib::ControllerSettings swingController(2, // proportional gain (kP)
                                                 0, // integral gain (kI)
                                                 0.0, // derivative gain (kD)
                                                 0, // anti windup
                                                 0, // small error range, in inches
                                                 0, // small error range timeout, in milliseconds
                                                 0, // large error range, in inches
                                                 0, // large error range timeout, in milliseconds
                                                 0 // maximum acceleration (slew)
);


// funcs

float get_front_distance() {
    return front.get() / 25.4; // mm to inches
}

float get_left_distance() {
    return left.get() / 25.4; // mm to inches
}
float get_right_distance() {
    return right.get() / 25.4; // mm to inches
}