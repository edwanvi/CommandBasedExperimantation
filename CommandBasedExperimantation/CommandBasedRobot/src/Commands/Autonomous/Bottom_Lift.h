#ifndef Bottom_Lift_H
#define Bottom_Lift_H

#include "../../CommandBase.h"
#include "WPILib.h"

class Bottom_Lift: public CommandBase
{
public:
	Bottom_Lift();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
