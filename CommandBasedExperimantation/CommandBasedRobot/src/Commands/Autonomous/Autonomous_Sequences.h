#ifndef Autonomous_Sequences_H
#define Autonomous_Sequences_H

#include "Commands/CommandGroup.h"
#include "WPILib.h"
#include "../../OI.h"
#include "../../CommandBase.h"

class Autonomous_Sequences: public CommandGroup
{
public:
	Autonomous_Sequences(int autoMode);
private:
	void auto1();
	void auto2();
	void auto3();
	void auto4();
	void auto5();
	bool one;
	bool two;
	bool three;
	bool four;
};

#endif
