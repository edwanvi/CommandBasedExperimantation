#include "ResetEncoders.h"
#include "Subsystems/DriveTrain.h"
#include "Subsystems/Lift.h"
ResetEncoders::ResetEncoders()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

///////////////////////////////////////////////////////////////////////////////////////

// Called just before this Command runs the first time
void ResetEncoders::Initialize()
{
//CommandBase::lift->setLocation();
}

///////////////////////////////////////////////////////////////////////////////////////

// Called repeatedly when this Command is scheduled to run
void ResetEncoders::Execute()
{
	//CommandBase::driveTrain->ResetEncoders();
	//CommandBase::driveTrain->ResetGyro();

	CommandBase::lift->isSensorTripped();

}

///////////////////////////////////////////////////////////////////////////////////////

// Make this return true when this Command no longer needs to run execute()
bool ResetEncoders::IsFinished()
{
	return true;
}

///////////////////////////////////////////////////////////////////////////////////////

// Called once after isFinished returns true
void ResetEncoders::End()
{

}

///////////////////////////////////////////////////////////////////////////////////////

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ResetEncoders::Interrupted()
{

}

///////////////////////////////////////////////////////////////////////////////////////
