#ifndef DriveTrain_H
#define DriveTrain_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "Gyro/IMU.h"
#include "Gyro/IMUAdvanced.h"
#include "Gyro/AHRS.h"
#define ENABLE_IMU
#define ENABLE_IMU_ADVANCED
#define ENABLE_AHRS

/**
 * This is a demo program showing the use of the RobotBase class.
 * The SimpleRobot class is the base of a robot application that will automatically call your
 * Autonomous and OperatorControl methods at the right time as controlled by the switches on
 * the driver station or the field controls.
 */

class DriveTrain: public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	CANTalon* talonLeftMaster;
	CANTalon* talonLeftFollowerA;
	CANTalon* talon_strafe;
	CANTalon* talonRightMaster;
	CANTalon* talonRightFollowerA;
	double position;
	DoubleSolenoid* solenoid_Shifter;
	double velocityRight;
	double velocityLeft;
	bool cutPower;

	NetworkTable *table;
#if defined(ENABLE_AHRS)
	AHRS *imu;
#elif defined(ENABLE_IMU_ADVANCED)
	IMUAdvanced *imu;
#else // ENABLE_IMU
	IMU *imu;
#endif
	SerialPort *serial_port;

	//true is low gear and false is second gear(numbers are too hard for me)

public:
	DriveTrain();
	void InitDefaultCommand();
	void TankDrive(float leftAxis, float rightAxis);
	float GetAngle();
	void ResetGyro();
	void ChangeGear(bool _gear);
	void ResetEncoders();
	float GetPosition();
	void BrakeTalons();
	void HalfPower();
	void _Strafe(float strafe_axis);

	bool currentGear;

};

#endif

/*#ifndef DriveTrain_
 #define DriveTrain_H

 #include "Commands/Subsystem.h"
 #include "WPILib.h"

 class DriveTrain: public Subsystem {
 private:
 // It's desirable that everything possible under private except
 // for methods that implement subsystem capabilities
 public:
 DriveTrain();
 void InitDefaultCommand();

 CANTalon* talon_1;
 CANTalon* talon_2;
 CANTalon* talon_3;
 CANTalon* talon_4;


 void TankDrive(float leftAxis, float rightAxis);
 };

 #endif
 */
