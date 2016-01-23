#ifndef ShiftGear_H
#define ShiftGear_H

#include "../../CommandBase.h"
#include "WPILib.h"

class ShiftGear: public CommandBase
{
public:
	ShiftGear(bool _mode);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	bool mode;
};

#endif
