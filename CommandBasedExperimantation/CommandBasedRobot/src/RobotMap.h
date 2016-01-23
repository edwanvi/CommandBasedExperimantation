#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "WPILib.h"

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */
 
// For example to map the left and right motors, you could define the
// following variables to use with your drivetrain subsystem.
//const int LEFTMOTOR = 1;
//const int RIGHTMOTOR = 2;

// If you are using multiple modules, make sure to define both the port
// number and the module. For example you with a rangefinder:
//const int RANGE_FINDER_PORT = 1;
//const int RANGE_FINDER_MODULE = 1;

const int LEFT_MOTOR_MASTER = 5;  //1, 2, 3 are right MCs
const int LEFT_MOTOR_FOLLOWER_A = 6;
const int Strafe_ = 7;
const int RIGHT_MOTOR_MASTER = 1;
const int RIGHT_MOTOR_FOLLOWER_A = 2;
const int RIGHT_MOTOR_FOLLOWER_B = 3;


const int RIGHT_JOYSTICK    = 5;
const int LEFT_JOYSTICK     = 1;

//unsure about these
const int LEFT_LIFT = 8;
const int RIGHT_LIFT = 4;

const int FIRST_CONTROLLER = 0;
const int SECOND_CONTROLLER = 1;

const int LEFT_ROLLER = 2;
const int RIGHT_ROLLER = 0;

const int COMPRESSOR = 0;

//const int CLIPSOL = 6;
const int CLIPSOL_2 = 7;

const int SOL_ROLLER_1 = 2;
const int SOL_ROLLER_2 = 3;
const int SOL_SHIFT_1 = 0;
const int SOL_SHIFT_2 = 1;
const int SOL_H = 4;
const int SOL_H1 = 5;
const int LEFT_LIFT_LIMIT = 0;

//IR sensors

const int LEFT_IR = 1;
const int RIGHT_IR = 0;

const int SENSOR_UP = 0;
const int SENSOR_DOWN = 1;

//optical sensors
const int Front_Sensor = 1;
const int Rear_Sensor = 0;
const int Top_Sensor = 2;
//const int PUSHER_LEFT = 3;
//const int PUSHER_RIGHT = 4;

const int LIMITSWITCHDOWN = 0;
#endif
