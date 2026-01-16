#include "headers/robot_config.hpp"
#include "lemlib/api.hpp"

// Controller
pros::Controller master(pros::E_CONTROLLER_MASTER);

// Motors 
pros::MotorGroup left_motors({18,19, 20});    
pros::MotorGroup right_motors({-11, -12, -13});  

pros::MotorGroup intake_motors({9,10});
pros::Motor outtake_motors(1);

pros::MotorGroup highScoring_motors({9,10,1});

//Pneumatics
pros::adi::DigitalOut wingPiston('A');
pros::adi::DigitalOut loaderPiston('B'); //change later

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

lemlib::ControllerSettings linearController(11, -0.000000001, 30, 0, 0, 0, 0, 0, 0);




lemlib::ControllerSettings angularController(-0.84, // proportional gain (kP)
                                              0, // integral gain (kI)
                                              -0.01, // derivative gain (kD)
                                              0, // anti windup
                                              0, // small error range, in inches
                                              0, // small error range timeout, in milliseconds
                                              0, // large error range, in inches
                                              0, // large error range timeout, in milliseconds
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
