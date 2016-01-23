#include <Math.h>
#include "Turn.h"


//direction is true: left
Turn::Turn(float _angle, float _speed, bool _direction)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis)

	Requires(CommandBase::driveTrain);
	CommandBase::driveTrain->ResetGyro();
	//sets target angle
	angle = _angle;
	speed = _speed;
	direction = _direction;
	diff = 1000;
}

///////////////////////////////////////////////////////////////////////////////////////

// Called just before this Command runs the first time
void Turn::Initialize()
{
	CommandBase::driveTrain->ResetGyro();
}

///////////////////////////////////////////////////////////////////////////////////////

// Called repeatedly when this Command is scheduled to run
void Turn::Execute()
{
	if (direction){
		//if left
		//left means delta is negative
		CommandBase::driveTrain->TankDrive(speed, speed);
		diff = angle + CommandBase::driveTrain->GetAngle();

	} else {
		CommandBase::driveTrain->TankDrive(-speed, -speed);
		diff = angle - CommandBase::driveTrain->GetAngle();
	}
	SmartDashboard::PutNumber("DIFF",diff);
}

///////////////////////////////////////////////////////////////////////////////////////

// Make this return true when this Command no longer needs to run execute()
bool Turn::IsFinished()
{
	//2 degree accuracy
	if (abs(diff) < 2){
		CommandBase::driveTrain->ResetGyro();
		CommandBase::driveTrain->TankDrive(0,0);
		return true;
	}
	return false;
}

///////////////////////////////////////////////////////////////////////////////////////

// Called once after isFinished returns true
void Turn::End()
{
	//resets everything
	CommandBase::driveTrain->ResetGyro();
	angle = 0;
}

///////////////////////////////////////////////////////////////////////////////////////

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Turn::Interrupted()
{

}

///////////////////////////////////////////////////////////////////////////////////////
