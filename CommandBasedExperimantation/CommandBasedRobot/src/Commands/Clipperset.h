#ifndef Clipperset_H
#define Clipperset_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "../Subsystems/Lift.h"

class Clipperset: public CommandBase
{
public:
	Clipperset(bool clip);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	bool Clip;
};

#endif
