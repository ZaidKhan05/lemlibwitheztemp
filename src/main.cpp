#include "main.h"
#include "lemlib/api.hpp"
#include "pros/adi.hpp"
#include "pros/misc.h"
#include "pros/motors.h"
#include "pros/motors.hpp"
#include "pros/rtos.h"
#include "pros/rtos.hpp"

/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */
 ///////////////////////////////////////////
////////////////////////////////////////////
//motors
pros::Controller master(pros::E_CONTROLLER_MASTER);
pros::Motor left_back_motor(8, pros::E_MOTOR_GEARSET_06, false);
pros::Motor left_middle_motor(6, pros::E_MOTOR_GEARSET_06, true);
pros::Motor left_front_motor(9, pros::E_MOTOR_GEARSET_06, true);
pros::Motor right_back_motor(3, pros::E_MOTOR_GEARSET_06, true);
pros::Motor right_middle_motor(2, pros::E_MOTOR_GEARSET_06, false);
pros::Motor right_front_motor(1, pros::E_MOTOR_GEARSET_06, false);
pros::MotorGroup leftMotors({left_front_motor,left_middle_motor});
pros::MotorGroup rightMotors({right_front_motor,right_middle_motor});
// inertial sensor
pros::Imu imu(10); // port 2    

lemlib::Drivetrain_t drivetrain {
    &leftMotors, // left drivetrain motors
    &rightMotors, // right drivetrain motors
    10, // track width
    4.25, // wheel diameter
    200 // wheel rpm
};

 


// forward/backward PID
lemlib::ChassisController_t lateralController {
    30, // kP
    20, // kD
    0, // smallErrorRange
    100, // smallErrorTimeout
    0, // largeErrorRange   
    500, // largeErrorTimeout
    0 // slew rate
};
 
// turning PID
lemlib::ChassisController_t angularController {
    4, // kP
    30, // kD
    1, // smallErrorRange
    100, // smallErrorTimeout
    3, // largeErrorRange
    500, // largeErrorTimeout
    0 // slew rate
};
// odometry struct
lemlib::OdomSensors_t sensors {
    nullptr, // vertical tracking wheel 1
    nullptr, // vertical tracking wheel 2
    nullptr, // horizontal tracking wheel 1
    nullptr, // we don't have a second tracking wheel, so we set it to nullptr
    &imu // inertial sensor
};
// create the chassis
lemlib::Chassis chassis(drivetrain, lateralController, angularController, sensors);

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void screen() {
    // loop forever
    while (true) {
        lemlib::Pose pose = chassis.getPose(); // get the current position of the robot
        pros::lcd::print(0, "x: %f", pose.x); // print the x position
        pros::lcd::print(1, "y: %f", pose.y); // print the y position
        pros::lcd::print(2, "heading: %f", pose.theta); // print the heading
        pros::delay(10);
    }
}

void initialize() {
	pros::lcd::initialize();
	chassis.calibrate();
    chassis.setPose(0, 0, 0);

	pros::Task screenTask(screen); // create a task to print the position to the screen

}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {

}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {
    
}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
    //	pros::Task screenTask(screen); // create a task to print the position to the screen

 //chassis.moveTo(0, 10, 10000, 60);
 	//	pros::delay(20);
    //chassis.turnTo(30, 0, 10000, false, 50);

}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {

  master.clear();
	while (true) {
        arcade_flipped();
		
        
        

		pros::delay(20);
	}
}
