#include "Lift.h"
#include "../RobotMap.h"
#include "../Commands/Lifting.h"
#include <math.h>
//#include "CommandBase.h"



///////////////////////////////////////////////////////////////////////////////////////

Lift::Lift() : Subsystem("Lift")
{
	talonLeft = new CANTalon(LEFT_LIFT);
	talonRight = new CANTalon(RIGHT_LIFT);

	talonLeft->EnableControl();
	talonRight->EnableControl();

	talonLeft->SetSafetyEnabled(false);
	talonLeft->SetExpiration(0.100);
	talonLeft->Set(0);

	talonRight->SetSafetyEnabled(false);
	talonRight->SetExpiration(0.100);
	talonRight->Set(0);

	Clip = new Solenoid( CLIPSOL_2);
	Clip_ = new DoubleSolenoid(SOL_H, SOL_H1);

	limit = false;
	power = 1.0;

	frontSensor = new AnalogInput(Front_Sensor);
	rearSensor = new AnalogInput(Rear_Sensor);
	topSensor = new AnalogInput(Top_Sensor);
	frontVoltage = 0.0;
	rearVoltage = 0.0;
	topVoltage = 0.0;
	//rightVoltage = 0;
	//leftVoltage = 0 ;

	SmartDashboard::init();
	lw = LiveWindow::GetInstance();

	//leftMeters = 0.0;
	//rightMeters = 0.0;

	limitSwitchDown = new DigitalInput(0);
	mode = false;
	location = true;
	//roller = new Rollers();
	closed = false;
	open = true;
	test = 0.0;
	loadTote = true;
	toteIn = true;


}

///////////////////////////////////////////////////////////////////////////////////////

void Lift::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	SetDefaultCommand(new Lifting());
}


///////////////////////////////////////////////////////////////////////////////////////

// Put methods for controlling this subsystem
// here. Call these from Commands.

///////////////////////////////////////////////////////////////////////////////////////

void Lift::move(float magnitude) {
	SmartDashboard::PutBoolean("Lift Fast Mode", mode);
	limit = limitSwitchDown->Get();

	//if fast
	if (mode){
		magnitude = magnitude * 0.95;
	} else {
		magnitude = magnitude/1.5;
	}

	//bottomed lift
	if (magnitude < 0 && limit){
		magnitude = magnitude * 0.3;
	}
	talonRight->Set(-magnitude);
	talonLeft->Set(magnitude+0.02);


	SmartDashboard::PutBoolean("Bottom Limit",limit);
}

///////////////////////////////////////////////////////////////////////////////////////

void Lift::ChangeMode(bool fast){
	mode = fast;
}

///////////////////////////////////////////////////////////////////////////////////////

void Lift::L_Sol_Set() {

	Clip->Set(false);

}

///////////////////////////////////////////////////////////////////////////////////////

// Put methods for controlling this subsystem
// here. Call these from Commands.

///////////////////////////////////////////////////////////////////////////////////////

void Lift::L_Sol_Off() {
	Clip->Set(true);
}

///////////////////////////////////////////////////////////////////////////////////////

void Lift::H_Sol_Set() {

	Clip_->Set(Clip_->kForward);

}

///////////////////////////////////////////////////////////////////////////////////////
// Put methods for controlling this subsystem
// here. Call these from Commands.

///////////////////////////////////////////////////////////////////////////////////////

void Lift::H_Sol_Off() {
	Clip_->Set(Clip_->kReverse);
}

///////////////////////////////////////////////////////////////////////////////////////

void Lift::isSensorTripped(){
frontVoltage = frontSensor->GetVoltage();
rearVoltage = rearSensor->GetVoltage();
topVoltage = topSensor->GetVoltage();
SmartDashboard::PutNumber("topVoltage",topVoltage);
SmartDashboard::PutNumber("frontVoltage",frontVoltage);
SmartDashboard::PutNumber("rearVoltage",rearVoltage);

if(rearVoltage <= 1){

	SmartDashboard::PutBoolean("can go",true);

}
//CommandBase::lift->isSensorTripped
else
{
	SmartDashboard::PutBoolean("can go",false);
}

if (frontVoltage <=1 && rearVoltage >= 3 && loadTote == true)
{

//close and roll
	if(closed == false){
CommandBase::roller->SolenoidOff();
	closed = true;
	}
	CommandBase::roller->Roll(0.8);
	Wait(1.0);
	CommandBase::roller->Roll(0);
	loadTote = false;
}



if ((frontVoltage <= 1) && (rearVoltage<=1))
{
toteIn = true;
}

if(toteIn == true)
{
	if (closed == true)
	{
	CommandBase::roller->TriggerSolenoid();
		closed = false;

	}
	//true = up
	if (topVoltage >= 3)
	{
		if(location == true)
		{


			location = false;
			move (0.15);
			Wait(0.01);
			move (0.0);
			//rollers open
			//;

		}

		else
		{

			location = true;
			move (-0.125);
			Wait(0.01);
			move (0.0);
			loadTote = true;
			toteIn = false;

		}

	}
}


	if (location == true)
	{
		if(loadTote == false)
		{
		move(-2);
		Wait(0.4);
		}
	}
	else
	{
	move (2);
	Wait(0.4);
	}
	// topVoltage >= 3 is not tripped


	//SmartDashboard::PutBoolean("tripped",true);
	/*if (topVoltage <= 1 && location == true)
	{
		move(-0.3);

	}
	else if (topVoltage >= 3  && location == true)
	{
		move(0.3);
	}
	else if (topVoltage <= 1 && location == false)
	{

	}


	else if (topVoltage >= 3 && location == false)
	{

	}*/

}
/*else
{
	//SmartDashboard::PutBoolean("tripped",false);


}*/

/*if (topVoltage >= 3)
{
	SmartDashboard::PutBoolean("locationwehf",location);
	if(location == true) {
		if(topVoltage >= 3) {
			move (0.7);
				Wait(0.2);
					move (0.0);
		}

	else {
		location = true;
		move (-0.7);
		Wait(0.2);
		move (0.0);

	}*/
