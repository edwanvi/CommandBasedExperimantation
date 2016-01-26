#include "Drive.h"
#include "../Container_Holder.h"

Drive::Drive()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis)
	Requires(CommandBase::driveTrain);
	strafe_axis = 0;
}

///////////////////////////////////////////////////////////////////////////////////////

// Called just before this Command runs the first time
void Drive::Initialize()
{
}

///////////////////////////////////////////////////////////////////////////////////////

// Called repeatedly when this Command is scheduled to run
void Drive::Execute()
{
	float leftThrottle = oi->GetLeftJoystick();
	float rightThrottle = oi->GetRightJoystick();
	int dpad = oi->GetDPad();

	CommandBase::driveTrain->TankDrive(leftThrottle, rightThrottle);

	if ( oi->GetLeftTrigger()){
		strafe_axis = oi->GetLeftTrigger();
	}
	else if ( oi->GetRightTrigger()){
		strafe_axis = -1 * oi->GetRightTrigger();
	}
	if (dpad == 0){
		CommandBase::driveTrain->TankDrive(-0.5, 0.5);
	}
	else if (dpad == 180){
		CommandBase::driveTrain->TankDrive(0.5, -0.5);
	}
	else if (dpad == 90){
		CommandBase::driveTrain->TankDrive(-0.5, -0.5);
	}
	else if (dpad == 270){
		CommandBase::driveTrain->TankDrive(0.5, 0.5);
	}
	else {
		strafe_axis = 0;
	}
	CommandBase::driveTrain->_Strafe( strafe_axis);
}

///////////////////////////////////////////////////////////////////////////////////////

// Make this return true when this Command no longer needs to run execute()
bool Drive::IsFinished()
{
	return false;
}

///////////////////////////////////////////////////////////////////////////////////////

// Called once after isFinished returns true
void Drive::End()
{

}

///////////////////////////////////////////////////////////////////////////////////////

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Drive::Interrupted()
{

}

///////////////////////////////////////////////////////////////////////////////////////
