/*
 * Robot.h
 *
 *  Created on: Feb 2, 2015
 *      Author: michaelzman
 */

#ifndef ROBOT_H
#define ROBOT_H

#include "Subsystems/DriveTrain.h"
#include "Commands/Drive/Drive.h"
#include "WPILib.h"

class Robot: public IterativeRobot {
public:
	Command *autonomousCommand;
	LiveWindow *lw;
	DriveTrain* drivetrain;

	void RobotInit();
	void AutonomousInit();
	void AutonomousPeriodic();
	void TeleopInit();
	void TeleopPeriodic();
	void DisabledPeriodic();
	void TestPeriodic();

private:
};

#endif /* SRC_ROBOT_H_ */
