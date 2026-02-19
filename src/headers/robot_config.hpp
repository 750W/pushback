#pragma once
//#include "pros/motors.hpp"
//#include "pros/imu.hpp"
#include "lemlib/api.hpp"

// Controller
extern pros::Controller master;

// Motors
extern pros::MotorGroup left_motors;
extern pros::MotorGroup right_motors;

extern pros::MotorGroup intake_motors;
extern pros::Motor outtake_motors;
extern pros::MotorGroup highScoring_motors;
extern pros::Motor bottom_intake_motor;
extern pros::Motor top_intake_motor;

extern pros::adi::DigitalOut wingPiston;
extern pros::adi::DigitalOut loaderPiston;
extern pros::adi::DigitalOut intakePiston;

extern pros::adi::Ultrasonic ultrasonic;

// Sensors (example: IMU)
extern pros::Imu imu;

// LemLib chassis
extern lemlib::Chassis chassis;

// PID Controllers
extern lemlib::ControllerSettings angularController;
extern lemlib::ControllerSettings linearController;
extern lemlib::ControllerSettings swingController;
