#include "Subsystems/Rollers.h"
#include "../Commands/Rollers/Set_Roller.h"

///////////////////////////////////////////////////////////////////////////////////////

Rollers::Rollers() :
		Subsystem("Rollers") {
	talonleft = new Talon(LEFT_ROLLER);
	talonright = new Talon(RIGHT_ROLLER);

	talonleft->SetSafetyEnabled(false);
	talonleft->SetExpiration(0.100);
	talonleft->Set(0);

	talonright->SetSafetyEnabled(false);
	talonright->SetExpiration(0.100);
	talonright->Set(0);
	mode = false;
	//initializes as slow mode
	solenoid = new DoubleSolenoid(SOL_ROLLER_1,SOL_ROLLER_2 );
}

///////////////////////////////////////////////////////////////////////////////////////

void Rollers::InitDefaultCommand() {
	SetDefaultCommand(new Set_Roller());
}

///////////////////////////////////////////////////////////////////////////////////////

void Rollers::ToggleMode(){
	if (mode){
		mode = false;
	} else {
		mode = true;
	}
	SmartDashboard::PutBoolean("Rollers Double Power", mode);
}

///////////////////////////////////////////////////////////////////////////////////////

void Rollers::Roll(float on_roller) {
	SmartDashboard::PutBoolean("Rollers Double Power", mode);
	if (mode){
		talonright->Set(-2*on_roller);
		talonleft->Set(2*on_roller);
	} else {
		//-0.5 for out, 0.5 for in
		talonright->Set(-on_roller);
		talonleft->Set(on_roller);
	}
}

///////////////////////////////////////////////////////////////////////////////////////

void Rollers::Throw(bool right){
	if (right){
		//out
		talonright->Set(-0.5);
		//in
		talonleft->Set(-0.5);
	} else {
		talonright->Set(0.5);
		talonleft->Set(0.5);
	}
}

///////////////////////////////////////////////////////////////////////////////////////

//close
void Rollers::TriggerSolenoid() {
	solenoid->Set(solenoid->kForward);

}

///////////////////////////////////////////////////////////////////////////////////////

// Put methods for controlling this subsystem
// here. Call these from Commands.
void Rollers::SolenoidOff() {
	solenoid->Set(solenoid->kReverse);
}

///////////////////////////////////////////////////////////////////////////////////////
