#include "main.h"
#include "lemlib/api.hpp" // IWYU pragma: keep

// controller
pros::Controller controller(pros::E_CONTROLLER_MASTER);

// motor groups
pros::MotorGroup leftMotors({-13, 17, 18}, pros::MotorGearset::blue);
pros::MotorGroup rightMotors({-16, -9, 5}, pros::MotorGearset::blue);
pros::Motor intake(19, pros::MotorGearset::blue);
pros::Motor arm(6, pros::MotorGearset::red); 
pros::adi:: DigitalOut wing('G');
pros::adi:: DigitalOut scraper('C');
pros::adi:: DigitalOut blockStopper('B');
pros::adi:: DigitalOut lever('G');
pros::Imu imu(4);


// drivetrain settings
lemlib::Drivetrain drivetrain(&leftMotors, // left motor group
                              &rightMotors, // right motor group
                              10.966, // 10.966 inch track width
                              lemlib::Omniwheel::NEW_325, // using new 3.25" omnis
                              450, // drivetrain rpm is 450
                              2 // horizontal drift is 2. 
);

// lateral motion controller
lemlib::ControllerSettings linearController(1, // proportional gain (kP)
                                            0, // integral gain (kI)
                                            0, // derivative gain (kD)
                                            0, // anti windup
                                            0, // small error range, in inches
                                            0, // small error range timeout, in milliseconds
                                            0, // large error range, in inches
                                            0, // large error range timeout, in milliseconds
                                            83 // maximum acceleration (slew)
);

// angular motion controller
lemlib::ControllerSettings angularController(1, // proportional gain (kP)
                                             0, // integral gain (kI)
                                             0, // derivative gain (kD)
                                             0, // anti windup
                                             0, // small error range, in degrees
                                             0, // small error range timeout, in milliseconds
                                             0, // large error range, in degrees
                                             0, // large error range timeout, in milliseconds
                                             0 // maximum acceleration (slew)
);

// sensors
lemlib::OdomSensors sensors(nullptr, // vertical tracking wheel
                            nullptr, // vertical tracking wheel 2, set to nullptr as we don't have a second one
                            nullptr, // horizontal tracking wheel
                            nullptr, // horizontal tracking wheel 2, set to nullptr as we don't have a second one
                            &imu // inertial sensor
);


lemlib::ExpoDriveCurve throttleCurve(4, // joystick deadband out of 127
                                     8, // minimum output where drivetrain will move out of 127
                                     0.6 // expo curve gain
);

// input curve for steer input during driver control
lemlib::ExpoDriveCurve steerCurve(6, // joystick deadband out of 127
                                  10, // minimum output where drivetrain will move out of 127
                                  0.65 // expo curve gain
);

// create the chassis
lemlib::Chassis chassis(drivetrain, linearController, angularController, sensors, &throttleCurve, &steerCurve);