#ifndef Lift_H
#define Lift_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "RobotMap.h"
//#include "Commands/Rollers/Solenoid_Roller_Set.h"
//#include "Subsystems/Rollers.h"

class Lift: public Subsystem {
private:
	CANTalon* talonLeft;
	CANTalon* talonRight;
AnalogInput* frontSensor;
AnalogInput* rearSensor;
AnalogInput* topSensor;

//Rollers* roller;
float frontVoltage;
float rearVoltage;
float topVoltage;
bool location;
bool closed;
bool open;
float test;
bool loadTote;
bool toteIn;

	DigitalInput* limitSwitchDown;
	//DigitalInput* limitSwitchUp;
	//double rightVoltage;
	//double leftVoltage;



	//double leftMeters;
	//double rightMeters;
	bool mode;

	Solenoid* Clip;
	DoubleSolenoid* Clip_;
	float power;


public:
	Lift();
	void InitDefaultCommand();

	void MovePusher(float speed);

	void ChangeMode(bool fast);
	//positive: move up
	//negative: move down
	void move(float magnitude);
	void L_Sol_Set();
	void L_Sol_Off();
	void H_Sol_Set();
	void H_Sol_Off();
	bool limit;
	void isSensorTripped();
	void setLocation();
	LiveWindow *lw;
};

#endif

