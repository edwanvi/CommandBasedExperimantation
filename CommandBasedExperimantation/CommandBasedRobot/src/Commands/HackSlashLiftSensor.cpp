#include "HackSlashLiftSensor.h"

HackSlashLiftSensor::HackSlashLiftSensor()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(CommandBase::lift);
}

// Called just before this Command runs the first time
void HackSlashLiftSensor::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void HackSlashLiftSensor::Execute()
{
	lift->isSensorTripped();
}

// Make this return true when this Command no longer needs to run execute()
bool HackSlashLiftSensor::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void HackSlashLiftSensor::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void HackSlashLiftSensor::Interrupted()
{

}
