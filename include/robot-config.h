#pragma once
 
#include "main.h"
#include "lemlib/api.hpp" // IWYU pragma: keep
 
// ─── Controller ───────────────────────────────────────────────────────────────
extern pros::Controller controller;
 
// ─── Motors ───────────────────────────────────────────────────────────────────
extern pros::MotorGroup leftMotors;
extern pros::MotorGroup rightMotors;
extern pros::Motor      intake;
extern pros::Motor      arm;
 
// ─── Pneumatics ───────────────────────────────────────────────────────────────
extern pros::adi::DigitalOut wing;
extern pros::adi::DigitalOut scraper;
extern pros::adi::DigitalOut blockStopper;
extern pros::adi::DigitalOut lever;
 
// ─── Sensors ──────────────────────────────────────────────────────────────────
extern pros::Imu imu;
 
// ─── LemLib ───────────────────────────────────────────────────────────────────
extern lemlib::Drivetrain        drivetrain;
extern lemlib::ControllerSettings linearController;
extern lemlib::ControllerSettings angularController;
extern lemlib::OdomSensors        sensors;
extern lemlib::ExpoDriveCurve     throttleCurve;
extern lemlib::ExpoDriveCurve     steerCurve;
extern lemlib::Chassis            chassis;