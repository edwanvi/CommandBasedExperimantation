#include "Idiot_Lift.h"

Idiot_Lift::Idiot_Lift(float _time, bool _direction)
{
	letime = _time;
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	direction = _direction;
}

///////////////////////////////////////////////////////////////////////////////////////

// Called just before this Command runs the first time
void Idiot_Lift::Initialize() {

}

///////////////////////////////////////////////////////////////////////////////////////

// Called repeatedly when this Command is scheduled to run
void Idiot_Lift::Execute() {
	//lift
	//wait
	//shut off lift
	if (direction) {
		CommandBase::lift->move(1);
	} else {
		CommandBase::lift->move(-1);
	}
	Wait(letime);
	CommandBase::lift->move(0);
}

///////////////////////////////////////////////////////////////////////////////////////

// Make this return true when this Command no longer needs to run execute()
bool Idiot_Lift::IsFinished() {
	return true;
}

///////////////////////////////////////////////////////////////////////////////////////

// Called once after isFinished returns true
void Idiot_Lift::End() {

}

///////////////////////////////////////////////////////////////////////////////////////

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Idiot_Lift::Interrupted() {

}

///////////////////////////////////////////////////////////////////////////////////////
