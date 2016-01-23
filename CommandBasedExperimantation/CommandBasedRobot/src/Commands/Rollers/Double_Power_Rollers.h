#ifndef Double_Power_Rollers_H
#define Double_Power_Rollers_H

#include "../../CommandBase.h"
#include "../../Subsystems/Rollers.h"
#include "WPILib.h"

class Double_Power_Rollers: public CommandBase
{
public:
	Double_Power_Rollers();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
