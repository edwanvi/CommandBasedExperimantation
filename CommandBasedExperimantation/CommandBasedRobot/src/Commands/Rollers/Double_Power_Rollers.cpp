#include "Double_Power_Rollers.h"
#include "../../Robot.h"

Double_Power_Rollers::Double_Power_Rollers()
{

	Requires(CommandBase::roller);
}

///////////////////////////////////////////////////////////////////////////////////////

// Called just before this Command runs the first time
void Double_Power_Rollers::Initialize()
{

}

///////////////////////////////////////////////////////////////////////////////////////

// Called repeatedly when this Command is scheduled to run
void Double_Power_Rollers::Execute()
{
	CommandBase::roller->ToggleMode();
}

///////////////////////////////////////////////////////////////////////////////////////

// Make this return true when this Command no longer needs to run execute()
bool Double_Power_Rollers::IsFinished()
{
	return true;
}

///////////////////////////////////////////////////////////////////////////////////////


// Called once after isFinished returns true
void Double_Power_Rollers::End()
{
	//CommandBase::roller->Roll(0);
}

///////////////////////////////////////////////////////////////////////////////////////

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Double_Power_Rollers::Interrupted()
{

}

///////////////////////////////////////////////////////////////////////////////////////
