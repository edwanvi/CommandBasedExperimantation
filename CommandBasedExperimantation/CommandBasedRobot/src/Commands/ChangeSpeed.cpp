#include "ChangeSpeed.h"
#include "Subsystems/DriveTrain.h"

ChangeSpeed::ChangeSpeed(bool _mode)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	mode = _mode;
}

///////////////////////////////////////////////////////////////////////////////////////

// Called just before this Command runs the first time
void ChangeSpeed::Initialize()
{

}

///////////////////////////////////////////////////////////////////////////////////////

// Called repeatedly when this Command is scheduled to run
void ChangeSpeed::Execute()
{
	CommandBase::lift->ChangeMode(mode);
	//SmartDashboard::PutBoolean("is it workin?",true);
	CommandBase::lift->PrintStuff();
}

///////////////////////////////////////////////////////////////////////////////////////

// Make this return true when this Command no longer needs to run execute()
bool ChangeSpeed::IsFinished()
{
	return true;
}

///////////////////////////////////////////////////////////////////////////////////////

// Called once after isFinished returns true
void ChangeSpeed::End()
{

}

///////////////////////////////////////////////////////////////////////////////////////

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ChangeSpeed::Interrupted()
{

}

///////////////////////////////////////////////////////////////////////////////////////
