

#ifndef Idiot_Lift_H
#define Idiot_Lift_H

#include "../../CommandBase.h"
#include "WPILib.h"

class Idiot_Lift: public CommandBase
{
public:
	Idiot_Lift(float _time, bool _direction);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	bool direction;
	float letime;
};

#endif
