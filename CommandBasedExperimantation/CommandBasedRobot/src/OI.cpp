#include "OI.h"
#include "RobotMap.h"

#include "Commands/Rollers/Set_Roller.h"
#include "Commands/Rollers/Double_Power_Rollers.h"
#include "Commands/Lifting.h"
#include "Commands/Rollers/Solenoid_Roller_Set.h"
#include "Commands/Container_Holder.h"

#include "Commands/ResetEncoders.h"
#include "Commands/Autonomous/Autonomous_Move.h"

#include "Commands/Drive/Cut_Power.h"
//Drive/ Folder

#include "Commands/Autonomous/Turn.h"
#include "Commands/Drive/ShiftGear.h"
#include "Subsystems/DriveTrain.h"
#include "Commands/ChangeSpeed.h"
#include "Commands/Clipperset.h"
#include "Commands/Container_Holder.h"


#include "Subsystems/Lift.h"

//
OI::OI() {
	// Process operator interface input here.
	controller = new Joystick(FIRST_CONTROLLER);
	controller_2 = new Joystick(SECOND_CONTROLLER);

	/**
	 * XBOX 360 Axes:
	 * 1: Left Y Axis
	 * 2: Left Trigger
	 * 3: Right Trigger
	 * 5: Right Y Axis
	 */
	rollerMode = 1;
	buttonA = new JoystickButton(controller, 1);
	buttonB = new JoystickButton(controller, 2);
	buttonX = new JoystickButton(controller, 3);
	buttonY = new JoystickButton(controller, 4);
	buttonLB = new JoystickButton(controller, 5);
	buttonRB = new JoystickButton(controller, 6);
	buttonStart = new JoystickButton(controller, 8);
	buttonSelect = new JoystickButton(controller, 7);

	buttonA_2 = new JoystickButton(controller_2, 2);//2  //  xbox or whats
	buttonB_2 = new JoystickButton(controller_2, 3);
	buttonX_2 = new JoystickButton(controller_2, 1);
	buttonY_2 = new JoystickButton(controller_2, 4);
	buttonLB_2 = new JoystickButton(controller_2, 5);
	buttonRB_2 = new JoystickButton(controller_2, 6);
	buttonStart_2 = new JoystickButton(controller_2, 8);
	buttonSelect_2 = new JoystickButton(controller_2, 7);

//open
	buttonA->WhenPressed(new Solenoid_Roller_Set(false));

//close
	buttonY->WhenPressed(new Solenoid_Roller_Set(true));

//gear down
	buttonX->WhenPressed(new ShiftGear(true));

//gear up
	buttonB->WhenPressed(new ShiftGear(false));

	buttonStart->WhenPressed(new Double_Power_Rollers());
	buttonSelect->WhenPressed(new Cut_Power());
	//buttonStart_2->WhenActive(new ResetEncoders());

	buttonStart_2->WhileHeld(new ResetEncoders());
	//buttonStart_2->WhenReleased(new )

	buttonY_2->WhenPressed(new ChangeSpeed(true));
	buttonA_2->WhenPressed(new ChangeSpeed(false));

	buttonX_2->WhenPressed(new Clipperset(true));
	buttonB_2->WhenPressed(new Clipperset(false));

	buttonLB_2->WhenPressed(new Container_Holder(true));
	buttonRB_2->WhenPressed(new Container_Holder(false));

	//buttonStart_2->WhenPressed(new void isSensorTripped());
}

float OI::GetLeftJoystick() {
	return 1 * controller->GetRawAxis(1);
}

float OI::GetRightJoystick() {
	return -1 * controller->GetRawAxis(5);
}

float OI::GetLeftJoystick_2(){
	return -1 * controller_2->GetRawAxis(1);
}

float OI::GetRightJoystick_2(){
	return -1 * controller_2->GetRawAxis(5);
}

float OI::GetLeftTrigger() {
	return controller->GetRawAxis(2);
}

float OI::GetRightTrigger() {
	return controller->GetRawAxis(3);
}
int OI::GetDPad_2() {
	return controller_2->GetPOV();
}

int OI::GetDPad() {
	return controller->GetPOV();
}
float OI::GetLeftTrigger_2() {
	return controller_2->GetRawAxis(2);
}

float OI::GetRightTrigger_2() {
	return controller_2->GetRawAxis(3);
}

float OI::GetLeftBumper() {
	return controller->GetRawButton(5);
}

float OI::GetRightBumper() {
	return controller->GetRawButton(6);
}

int OI::Auto(){
	//true for auto, false for teleop
	return rollerMode;
}

void OI::SetAuto(int _mode){
	rollerMode = _mode;
}
/*#include "OI.h"
 #include "Commands/Print.h"
 #include "Commands/Drive.h"

 OI::OI()
 {
 // Process operator interface input here.

 controller = new Joystick(1);


 }
 */
