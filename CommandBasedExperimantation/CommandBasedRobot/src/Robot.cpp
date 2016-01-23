
#include "Commands/Autonomous/Autonomous_Sequences.h"
#include "WPILib.h"
#include "Commands/Command.h"
#include "CommandBase.h"
#include "OI.h"
#include "Commands/Rollers/Set_Roller.h"
#include "Commands/Autonomous/Idiot_Lift.h"
#include "Commands/Autonomous/Autonomous_Move.h"
//#include "Commands/Autonomous/Autonomous_Sequences2.h"

class Robot: public IterativeRobot {
private:
	LiveWindow *lw;
	Command * autonomousSequence;
	SendableChooser *chooser;


	void RobotInit() {
		CommandBase::init();
		SmartDashboard::init();
		lw = LiveWindow::GetInstance();
		chooser = new SendableChooser();
		chooser->AddDefault("Auto 1",new Autonomous_Sequences(1));
		chooser->AddObject("Auto 2", new Autonomous_Sequences(2));
		chooser->AddObject("Auto 3",new Autonomous_Sequences(3));
		chooser->AddObject("Auto 4",new Autonomous_Sequences(4));
		chooser->AddObject("Auto 5", new Autonomous_Sequences(5));


		SmartDashboard::PutData("Auto Modes",chooser);

	}

	void DisabledPeriodic() {
		Scheduler::GetInstance()->Run();
	}

	void AutonomousInit() {
		autonomousSequence = (Command*)chooser->GetSelected();
		if (autonomousSequence != NULL)
			autonomousSequence->Start();


	}

	void AutonomousPeriodic() {
		Scheduler::GetInstance()->Run();
	}

	void TeleopInit() {
		// This makes sure that the autonomous stops running when
		// teleop starts running. If you want the autonomous to 
		// continue until interrupted by another command, remove
		// this line or comment it out.

		if (autonomousSequence != NULL)
			autonomousSequence->Cancel();


	}

	void TeleopPeriodic() {
		Scheduler::GetInstance()->Run();
	}

	void TestPeriodic() {
		lw->Run();
	}
};

START_ROBOT_CLASS(Robot);
