#include "main.h"
#include "pros/adi.hpp"
#include "pros/motors.h"

//Extra Motor Ports
pros::Motor FlywheelMotor1(11, MOTOR_GEARSET_36);
pros::Motor FlywheelMotor2(20, MOTOR_GEARSET_36);

pros::Motor intake1(19, MOTOR_GEARSET_6);
pros::Motor intake2(12, MOTOR_GEARSET_6);
pros::Motor roller(5, MOTOR_GEARSET_36);
pros::Motor indexer(7, MOTOR_GEARSET_36);

pros::Distance Hopper(16);

//ADI Ports
pros::ADIDigitalOut IndexerActuator('H', false);
pros::ADIDigitalOut IntakeActuator('G');
pros::ADIDigitalOut Endgame('A', false);
pros::ADIDigitalOut SageWall('B', false);
pros::ADIDigitalOut Tongue('F');
