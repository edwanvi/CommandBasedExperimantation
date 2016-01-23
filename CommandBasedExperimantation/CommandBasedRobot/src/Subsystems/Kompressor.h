#ifndef Kompressor_H
#define Kompressor_H

#include "Commands/Subsystem.h"
#include "WPILib.h"


class Kompressor: public Subsystem
{
private:
	Compressor* compressor;

	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	Kompressor();
	void InitDefaultCommand();
	void Kompressor_Toggle();

private:
	//bool On;


};

#endif

