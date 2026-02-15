#include "headers/robot_config.hpp"
#include "lemlib/api.hpp"

// Controller
pros::Controller master(pros::E_CONTROLLER_MASTER);

// Motors 
pros::MotorGroup left_motors({1,2, 3});    
pros::MotorGroup right_motors({-4, -5, -6});  

pros::MotorGroup intake_motors({7,-8});
pros::Motor outtake_motors(1);

pros::MotorGroup highScoring_motors({9,10,1});

//Pneumatics
pros::adi::DigitalOut wingPiston('E');
pros::adi::DigitalOut loaderPiston('B'); //change later
pros::adi::DigitalOut intakePiston('A'); //change later

// Sensors (change port!)
pros::Imu imu(2);

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

lemlib::ControllerSettings linearController(10,0, 3, 
                                              3, // anti windup
                                              1, // small error range, in inches
                                              100, // small error range timeout, in milliseconds
                                              3, // large error range, in inches
                                              500, // large error range timeout, in milliseconds
                                              20 // maximum acceleration (slew)
);




lemlib::ControllerSettings angularController(-2, // proportional gain (kP)
                                              0, // integral gain (kI)
                                              -10, // derivative gain (kD)
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
