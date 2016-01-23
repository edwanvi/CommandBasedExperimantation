#include "Solenoid_Roller_Set.h"
#include "Subsystems/Rollers.h"

Solenoid_Roller_Set::Solenoid_Roller_Set(bool FuckMichael)
{
	// Use Requires() here to declare subsystem dependencies
	//Requires(CommandBase::solenoids);
	 Mode = FuckMichael;
}

///////////////////////////////////////////////////////////////////////////////////////

// Called just before this Command runs the first time
void Solenoid_Roller_Set::Initialize()
{
	SmartDashboard::init();
}

///////////////////////////////////////////////////////////////////////////////////////

// Called repeatedly when this Command is scheduled to run
void Solenoid_Roller_Set::Execute()
{
	if(Mode)
	{
		CommandBase::roller->TriggerSolenoid();
	}else{
		CommandBase::roller->SolenoidOff();
	}
	SmartDashboard::PutBoolean("Rollers Open", Mode);

	//
	//SmartDashboard::PutString("Roller_State","Done");
	//BullShit++;
	//SmartDashboard::PutNumber("BullShit",BullShit);

}

///////////////////////////////////////////////////////////////////////////////////////

// Make this return true when this Command no longer needs to run execute()
bool Solenoid_Roller_Set::IsFinished()
{
	return true;
}

///////////////////////////////////////////////////////////////////////////////////////

// Called once after isFinished returns true
void Solenoid_Roller_Set::End()
{

}

///////////////////////////////////////////////////////////////////////////////////////

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Solenoid_Roller_Set::Interrupted()
{

}

///////////////////////////////////////////////////////////////////////////////////////
