#include "Container_Holder.h"

Container_Holder::Container_Holder(bool Hold)
{
	// Use Requires() here to declare subsystem dependencies
	Requires(CommandBase::lift);
	Open = Hold;
}

///////////////////////////////////////////////////////////////////////////////////////

// Called just before this Command runs the first time
void Container_Holder::Initialize()
{

}

///////////////////////////////////////////////////////////////////////////////////////

// Called repeatedly when this Command is scheduled to run
void Container_Holder::Execute()
{
	if(Open)
		{
			CommandBase::lift->H_Sol_Off();
		}
		else
		{
			CommandBase::lift->H_Sol_Set();
		}
}

///////////////////////////////////////////////////////////////////////////////////////

// Make this return true when this Command no longer needs to run execute()
bool Container_Holder::IsFinished()
{
	return true;
}

///////////////////////////////////////////////////////////////////////////////////////

// Called once after isFinished returns true
void Container_Holder::End()
{

}

///////////////////////////////////////////////////////////////////////////////////////

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Container_Holder::Interrupted()
{

}

///////////////////////////////////////////////////////////////////////////////////////
