#ifndef Cut_Power_H
#define Cut_Power_H

#include "../../CommandBase.h"
#include "WPILib.h"

class Cut_Power: public CommandBase
{
public:
	Cut_Power();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();


};

#endif
