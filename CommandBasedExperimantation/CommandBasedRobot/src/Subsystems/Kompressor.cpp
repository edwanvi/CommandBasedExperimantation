#include "Kompressor.h"
#include "../RobotMap.h"

Kompressor::Kompressor() :
		Subsystem("Kompressor")
{
	compressor = new Compressor(COMPRESSOR);

	//starts off false because it will be switched to true the first tuime called
	//On  = false;
	compressor->SetClosedLoopControl(true);
}

void Kompressor::InitDefaultCommand()
{
	// Set the default command for a subsystem here.

	//SetDefaultCommand(new Compressor_Closed_Loop());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void Kompressor::Kompressor_Toggle()
{
/*	if(On)
	{
		On = false;


	}
	else if(!On)
	{
		On = true;

	}
	SmartDashboard::PutBoolean("CompisON",On);
*/
//compressor->SetClosedLoopControl(On);

}












