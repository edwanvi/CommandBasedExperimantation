#ifndef COMMAND_BASE_H
#define COMMAND_BASE_H

#include <string>
#include "Commands/Scheduler.h"
#include "Commands/Command.h"
#include "Subsystems/DriveTrain.h"
#include "Subsystems/Lift.h"
#include "Subsystems/Rollers.h"
#include "Subsystems/Kompressor.h"
//#include "Subsystems/Solenoids.h"
#include "OI.h"
#include "WPILib.h"


/**
 * The base for all commands. All atomic commands should subclass CommandBase.
 * CommandBase stores creates and stores each control system. To access a
 * subsystem elsewhere in your code in your code use CommandBase.examplesubsystem
 */
class CommandBase: public Command
{
public:
	CommandBase(char const *name);
	CommandBase();
	static void init();
	static void autonomous(bool mode);
	// Create a single static instance of all of your subsystems

	static OI *oi;
	static bool AUTONOMOUS;
	static DriveTrain* driveTrain;
	static Lift* lift;
	static Rollers* roller;
	static Kompressor* kompressor;
	//static Solenoids* solenoids;
};

#endif
