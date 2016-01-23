#include "Clipperset.h"

Clipperset::Clipperset(bool clip)
{
	// Use Requires() here to declare subsystem dependencies
	Requires(CommandBase::lift);
	Clip = clip;
}

///////////////////////////////////////////////////////////////////////////////////////

// Called just before this Command runs the first time
void Clipperset::Initialize()
{

}

///////////////////////////////////////////////////////////////////////////////////////

// Called repeatedly when this Command is scheduled to run
void Clipperset::Execute()
{
	if(Clip)
	{
		CommandBase::lift->L_Sol_Set();

	}
	else
	{
		CommandBase::lift->L_Sol_Off();
	}
	SmartDashboard::PutBoolean("Clippers Open", Clip);
}

///////////////////////////////////////////////////////////////////////////////////////

// Make this return true when this Command no longer needs to run execute()
bool Clipperset::IsFinished()
{
	return true;
}

///////////////////////////////////////////////////////////////////////////////////////

// Called once after isFinished returns true
void Clipperset::End()
{

}

///////////////////////////////////////////////////////////////////////////////////////

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Clipperset::Interrupted()
{

}

///////////////////////////////////////////////////////////////////////////////////////
