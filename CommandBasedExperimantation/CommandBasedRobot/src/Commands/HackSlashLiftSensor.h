#ifndef HackSlashLiftSensor_H
#define HackSlashLiftSensor_H

#include "../CommandBase.h"
#include "WPILib.h"

class HackSlashLiftSensor: public CommandBase
{
public:
	HackSlashLiftSensor();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
