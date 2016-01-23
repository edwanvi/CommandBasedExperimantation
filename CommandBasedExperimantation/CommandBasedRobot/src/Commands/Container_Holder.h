#ifndef Container_Holder_H
#define Container_Holder_H

#include "../CommandBase.h"
#include "WPILib.h"

class Container_Holder: public CommandBase
{
public:
	Container_Holder(bool Hold);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	bool Open;
};

#endif
