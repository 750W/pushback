#include "headers/robot_config.hpp"
#include "lemlib/api.hpp"

// Controller
pros::Controller master(pros::E_CONTROLLER_MASTER);

// Motors 
pros::MotorGroup left_motors({18,19, 20});    
pros::MotorGroup right_motors({-11, -12, -13});  

pros::MotorGroup intake_motors({9,10});
pros::Motor outtake_motors(1);

//Pneumatics
pros::adi::DigitalOut wingPiston('A');
pros::adi::DigitalOut loaderPiston('B'); //change later

// Sensors (change port!)
pros::Imu imu(7);

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

lemlib::ControllerSettings linearController(10, 0, 0, 3, 1, 100, 3, 500, 20);
lemlib::ControllerSettings angularController(4, 0, 0, 3, 1, 100, 3, 500, 20);

lemlib::Chassis chassis(drivetrain, linearController, angularController, sensors);
