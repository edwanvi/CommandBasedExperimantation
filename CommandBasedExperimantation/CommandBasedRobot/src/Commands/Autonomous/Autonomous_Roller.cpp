#include <Commands/Autonomous/Autonomous_Roller.h>

Autonomous_Roller::Autonomous_Roller(float _time2, int _mode)
{
	//1: OFF
	//2: Suck in
	//3: Throw out
	//4: Throw both to the right (i.e. left is out, right talon in)
	mode = _mode;
	leime = _time2;

}

///////////////////////////////////////////////////////////////////////////////////////

// Called just before this Command runs the first time
void Autonomous_Roller::Initialize()
{

}

///////////////////////////////////////////////////////////////////////////////////////

// Called repeatedly when this Command is scheduled to run
void Autonomous_Roller::Execute()
{
	oi->SetAuto(mode);
	Wait(leime);
	oi->SetAuto(1);
}

///////////////////////////////////////////////////////////////////////////////////////

// Make this return true when this Command no longer needs to run execute()
bool Autonomous_Roller::IsFinished()
{
	return true;
}

///////////////////////////////////////////////////////////////////////////////////////

// Called once after isFinished returns true
void Autonomous_Roller::End()
{
	//mode = 1;
}

///////////////////////////////////////////////////////////////////////////////////////

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Autonomous_Roller::Interrupted()
{

}

///////////////////////////////////////////////////////////////////////////////////////
