#ifndef DRIVE_H
#define DRIVE_H

#include "../../CommandBase.h"
#include "WPILib.h"
#include "Subsystems/DriveTrain.h"

class Drive: public CommandBase
{
public:
	Drive();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	float strafe_axis;
};

#endif
