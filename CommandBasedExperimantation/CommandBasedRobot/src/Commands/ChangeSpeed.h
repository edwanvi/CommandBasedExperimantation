#ifndef ChangeSpeed_H
#define ChangeSpeed_H

#include "../CommandBase.h"
#include "WPILib.h"

class ChangeSpeed: public CommandBase
{
public:
	bool mode;
	ChangeSpeed(bool _mode);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
