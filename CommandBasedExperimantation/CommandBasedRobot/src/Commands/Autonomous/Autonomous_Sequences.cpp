#include"Commands/Autonomous/Autonomous_Roller.h"
#include <Commands/Autonomous/Autonomous_Sequences.h>
#include "Subsystems/DriveTrain.h"
#include "Subsystems/Lift.h"
#include "Commands/Autonomous/Autonomous_Move.h"
#include "Commands/Drive/ShiftGear.h"
#include "Idiot_Lift.h"
#include "Commands/Autonomous/Turn.h"
#include "Commands/Rollers/Solenoid_Roller_Set.h"
#include "../../OI.h"
#include "Commands/Autonomous/Bottom_Lift.h"
#include "Commands/Container_Holder.h"
#include "Commands/Clipperset.h"
#include "Commands/Autonomous/NewTurn.h"

Autonomous_Sequences::Autonomous_Sequences(int autoMode) {

	SmartDashboard::init();
	one = false;
	two = false;
	three = false;
	four = false;
	if (autoMode == 1){
		auto1();
		one = true;
	} else if (autoMode == 2){
		auto2();
		two = true;
	} else if (autoMode == 3){
		auto3();
		three = true;
	} else if(autoMode == 4){
		auto4();
		four = true;
	} else if (autoMode == 5){
		auto5();
	}

	// Add Commands here:omo
	// e.g. AddSequential(new Command1());
	//      AddSequential(new Command2());
	// these will run in order.

	//SETS LOW GEAR, LIFTS CONTAINER, OPENS ROLLERS, RUN ROLLERS, MOVE FORWARD, TURN LEFT 90 DEGREEs, THEN MOVE FORWARD
	//low gear
	//ORIGINAL AUTO CODE

	//typeAutonomous = SmartDashboard::GetNumber("Autonomouse Type");

	//SmartDashboard::PutNumber("AutoState",typeAutonomous);

	/*AddSequential(new ShiftGear(false));
	 AddSequential(new Idiot_Lift(1.5,true));
	 AddParallel(new Solenoid_Roller_Set(true));

	 //move forward
	 AddSequential(new Autonomous_Move(0.90, 0.55));
	 AddParallel(new Solenoid_Roller_Set(false));

	 AddSequential(new Turn(86, 0.65, true));
	 AddSequential(new Autonomous_Move(2.85, .85));
	 */

	/**
	 AddSequential(new Autonimous_Roller(true));
	 AddSequential(new ShiftGear(false));
	 AddSequential(new Idiot_Lift(1.4, true));
	 AddSequential(new Solenoid_Roller_Set(true));
	 AddSequential(new Autonomous_Move(0.85, 0.65));
	 AddSequential(new Solenoid_Roller_Set(false));
	 AddSequential(new Idiot_Lift(2.15, false));
	 Wait(0.5);
	 AddSequential(new Idiot_Lift(1.7,true));
	 AddSequential(new Solenoid_Roller_Set(true));

DRIVE FORWARDS WITH ROLLESR
GET IT OUT

	 AddSequential(new Autonomous_Move(2.1, 0.65));
	 AddSequential(new Solenoid_Roller_Set(false));
	 AddSequential(new Idiot_Lift(1.8, false));
	 Wait(0.5);
	 AddSequential(new Idiot_Lift(1.7,true));
	 AddSequential(new Solenoid_Roller_Set(true));
	 AddSequential(new Autonomous_Move(1.5, 0.65));
	 AddSequential(new Solenoid_Roller_Set(false));
	 AddSequential(new Idiot_Lift(1.5,false));
	 AddSequential(new Idiot_Lift(1,true));
	 AddSequential(new Turn(90, 0.65, true));
	 AddSequential(new Autonomous_Move(2.85, .65));
	 AddSequential(new Idiot_Lift(1,false));
	 AddSequential(new Solenoid_Roller_Set(true));
	 CommandBase::oi->SetAuto(false);
	 AddSequential(new Autonimous_Roller(false));
	 **/

// To run multiple commands at the same time,
// use AddParallel()
// e.g. AddParallel(new Command1());
//      AddSequential(new Command2());
// Command1 and Command2 will run in parallel.
// A command group will require all of the subsystems that each member
// would require.
// e.g. if Command1 requires chassis, and Command2 requires arm,
// a CommandGroup containing them would require both the chassis and the
}

///////////////////////////////////////////////////////////////////////////////////////

//Low gear mode
//Lift container
//Clamp it with holder
//Open rollers
//Move forward
//Close rollers
//Turn 90 degrees
//Move forward

void Autonomous_Sequences::auto1() {
	AddSequential(new Autonomous_Roller(1, 1));
	AddSequential(new Container_Holder(false));
	AddSequential(new ShiftGear(false));
	AddSequential(new Idiot_Lift(2.3, true));
	AddSequential(new Solenoid_Roller_Set(true));
	AddSequential(new Autonomous_Move(0.40, 0.75));
	AddSequential(new Clipperset(true));
	//AddSequential(new Bottom_Lift());
	//AddSequential(new Idiot_Lift(0.25, false));
	//AddSequential(new Idiot_Lift(1.25, true));
	//AddSequential(new Container_Holder(true));
	//AddSequential(new Idiot_Lift(1.5, false));

	//Turn and move into autozone
	 //AddSequential(new Turn(81, 0.65, true));
	 //AddSequential(new Autonomous_Move(1.2, .80));

SmartDashboard::PutBoolean("Auto1 State",one);
}

///////////////////////////////////////////////////////////////////////////////////////

//Grab 2 totes and lift them
void Autonomous_Sequences::auto2() {
	while (CommandBase::lift->frontVoltage > 1){
		new Autonomous_Move(0.5, 0.5);
	}
	SmartDashboard::PutBoolean("Auto2 State",two);
}

///////////////////////////////////////////////////////////////////////////////////////

void Autonomous_Sequences::auto3() {
	//AddSequential(new Autonomous_Roller(4));
	AddSequential(new Solenoid_Roller_Set(false));
	//AddSequential(new Idiot_Lift(2.3, true));
	AddSequential(new Autonomous_Roller(2, 2));
	AddSequential(new Autonomous_Move(-1.2, 0.75));
	//AddSequential(new Turn(44, 0.65, true));
	SmartDashboard::PutBoolean("Auto3 State",three);

}

///////////////////////////////////////////////////////////////////////////////////////

void Autonomous_Sequences::auto4() {
	//AddSequential(new Autonomous_Roller(5));
	//SmartDashboard::PutBoolean("Auto4 State",four);
	/* AddSequential(new Container_Holder(false));
			AddSequential(new ShiftGear(false));
			AddSequential(new Idiot_Lift(2.3, true));
			AddSequential(new Solenoid_Roller_Set(true));
			AddSequential(new Autonomous_Move(0.36, 0.75));
			AddSequential(new Clipperset(true));
			//AddSequential(new Bottom_Lift());
			//AddSequential(new Idiot_Lift(0.25, false));
			//AddSequential(new Idiot_Lift(1.25, true));
			//AddSequential(new Container_Holder(true));
			//AddSequential(new Idiot_Lift(1.5, false));

			//Turn and move into autozone
			 AddSequential(new Turn(81, 0.65, true));
			AddSequential(new Autonomous_Move(1.4, 1.0));
*/
			//SmartDashboard::PutBoolean("Auto2 State",two);
}

///////////////////S////////////////////////////////////////////////////////////////////

void Autonomous_Sequences::auto5() {
	AddSequential(new NewTurn(true, 4.5, 0.5));
}

///////////////////////////////////////////////////////////////////////////////////////
