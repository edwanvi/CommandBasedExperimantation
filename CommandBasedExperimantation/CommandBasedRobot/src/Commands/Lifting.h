#ifndef Lifting_H
#define Lifting_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "Subsystems/Lift.h"


class Lifting: public CommandBase
{
public:
	Lifting();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	float magnitude_lift;
	float SLOWLIFTGAIN = 0.10;
	//LiftingTrain* LiftingTrain;
};

#endif
