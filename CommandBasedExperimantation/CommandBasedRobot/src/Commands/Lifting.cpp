#include "Lifting.h"



Lifting::Lifting()
{

	magnitude_lift = 0;
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis)

	Requires(CommandBase::lift);
}

///////////////////////////////////////////////////////////////////////////////////////
// Called just before this Command runs the first time
void Lifting::Initialize()
{
}

///////////////////////////////////////////////////////////////////////////////////////

// Called repeatedly when this Command is scheduled to run
void Lifting::Execute()
{

	if(oi->GetRightTrigger_2() > .25) {
		magnitude_lift = oi->GetRightTrigger_2()+ 0.02;
	}
	else if (oi->GetLeftTrigger_2() > .25) {
		magnitude_lift = -oi->GetLeftTrigger_2();
	}
	else {
		magnitude_lift = 0;
	}

	//opens rollers if lifting up

	CommandBase::lift->move(magnitude_lift);
}

///////////////////////////////////////////////////////////////////////////////////////



// Make this return true when this Command no longer needs to run execute()
bool Lifting::IsFinished()
{
	return false;
}

///////////////////////////////////////////////////////////////////////////////////////

// Called once after isFinished returns true
void Lifting::End()
{

}

///////////////////////////////////////////////////////////////////////////////////////

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Lifting::Interrupted()
{

}

///////////////////////////////////////////////////////////////////////////////////////
