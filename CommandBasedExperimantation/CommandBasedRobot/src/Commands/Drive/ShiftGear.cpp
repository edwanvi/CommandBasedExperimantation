#include <Commands/Drive/ShiftGear.h>
#include "Subsystems/DriveTrain.h"

//true: shift up
//false: shift down
ShiftGear::ShiftGear(bool _mode)
{
	mode = _mode;
	// Use Requires() here to declare subsystem dependencies
	//Requires(CommandBase::driveTrain);
	// eg. Requires(chassis);
}

///////////////////////////////////////////////////////////////////////////////////////

// Called just before this Command runs the first time
void ShiftGear::Initialize()
{

}

///////////////////////////////////////////////////////////////////////////////////////

// Called repeatedly when this Command is scheduled to run
void ShiftGear::Execute()
{
	CommandBase::driveTrain->ChangeGear(mode);
	SmartDashboard::PutBoolean("High Gear", mode);
}

///////////////////////////////////////////////////////////////////////////////////////

// Make this return true when this Command no longer needs to run execute()
bool ShiftGear::IsFinished()
{
	return true;
}

///////////////////////////////////////////////////////////////////////////////////////

// Called once after isFinished returns true
void ShiftGear::End()
{

}

///////////////////////////////////////////////////////////////////////////////////////

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ShiftGear::Interrupted()
{

}

///////////////////////////////////////////////////////////////////////////////////////
