#include "DriveTrain.h"
#include "../RobotMap.h"
#include "../Commands/Drive/Drive.h"
#include <math.h>

//0.478779 meters per revolution
//20166 encoder units per meter
//9451 encoder units per revolution
///////////////////////////////////////////////////////////////////////////////////////
DriveTrain::DriveTrain() :
		Subsystem("DriveTrain") {
	talonLeftMaster = new CANTalon(LEFT_MOTOR_MASTER);
	talon_strafe = new CANTalon(Strafe_);
	talonLeftFollowerA = new CANTalon(LEFT_MOTOR_FOLLOWER_A);
	talonRightMaster = new CANTalon(RIGHT_MOTOR_MASTER);
	talonRightFollowerA = new CANTalon(RIGHT_MOTOR_FOLLOWER_A);
	//talonRightFollowerB = new CANTalon(RIGHT_MOTOR_FOLLOWER_B);

	talonLeftMaster->EnableControl();
	talonRightMaster->EnableControl();

	talonRightFollowerA->EnableControl();
	//talonRightFollowerB->EnableControl();

	talonLeftFollowerA->EnableControl();
	talon_strafe->EnableControl();

	talonLeftMaster->SetSafetyEnabled(false);
	talonLeftFollowerA->SetSafetyEnabled(false);
	talon_strafe->SetSafetyEnabled(false);
	talonLeftMaster->SetExpiration(0.100);
	talonLeftMaster->Set(0);

	talonRightMaster->SetSafetyEnabled(false);
	talonRightFollowerA->SetSafetyEnabled(false);
	//talonRightFollowerB->SetSafetyEnabled(false);
	talonRightMaster->SetExpiration(0.100);
	talonRightMaster->Set(0);

//////////////////////////////////////////////////////////////////////////
	//table = NetworkTable::GetTable("datatable");
	//serial_port = new SerialPort(57600, SerialPort::kMXP);
	//uint8_t update_rate_hz = 50;
//#if defined(ENABLE_AHRS)
	//imu = new AHRS(serial_port, update_rate_hz);
//#elif defined(ENABLE_IMU_ADVANCED)
	//imu = new IMUAdvanced(serial_port,update_rate_hz);
//#else // ENABLE_IMU
	//imu = new IMU(serial_port, update_rate_hz);
//#endif
///////////////////////////////////////////////////////////////////////
	solenoid_Shifter = new DoubleSolenoid(SOL_SHIFT_1, SOL_SHIFT_2);

	//false equals low gear
	currentGear = false;

	position = 0.0;
	velocityLeft = 0.0;
	velocityRight = 0.0;

	cutPower = false;

}
///////////////////////////////////////////////////////////////////////////////////////
//float DriveTrain::GetAngle() {
	//return imu->GetYaw();
//}
///////////////////////////////////////////////////////////////////////////////////////
/*void DriveTrain::ResetGyro() {
	imu->ZeroYaw();
}
*/
///////////////////////////////////////////////////////////////////////////////////////
float DriveTrain::GetPosition() {
	return ((talonRightMaster->GetEncPosition()
			- talonLeftMaster->GetEncPosition()) / 2);

}
///////////////////////////////////////////////////////////////////////////////////////
void DriveTrain::ResetEncoders() {
	talonRightMaster->SetPosition(0);
	talonLeftMaster->SetPosition(0);
}
///////////////////////////////////////////////////////////////////////////////////////
void DriveTrain::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	SetDefaultCommand(new Drive());

}

// Put methods for controlling this subsystem
// here. Call these from Commands.

///////////////////////////////////////////////////////////////////////////////////////
void DriveTrain::TankDrive(float leftAxis, float rightAxis) {
	SmartDashboard::PutNumber("Position", GetPosition());
	top_optical_sensor = new AnalogInput(Top_Sensor);
	SmartDashboard::PutData("Top Sensor", top_optical_sensor);
	if (cutPower == true) {
		leftAxis /= 2;
		rightAxis /= 2;

	}
	velocityRight = talonRightMaster->GetEncVel();
	velocityLeft = talonLeftMaster->GetEncVel();

	SmartDashboard::PutBoolean("High Gear", currentGear);
	SmartDashboard::PutBoolean("Half Power", cutPower);

	float power = 2;

	int leftSign = 1;
	int rightSign = 1;

	if (leftAxis < 0) {
		leftSign = -1;
		leftAxis = leftAxis * -1;
	}

	if (rightAxis < 0) {
		rightSign = -1;
		rightAxis = rightAxis * -1;
	}

	float leftValue = leftSign * pow(leftAxis, power);
	float rightValue = rightSign * pow(rightAxis, power);

	talonLeftMaster->Set(leftValue);
	talonLeftFollowerA->Set(leftValue);
	// talon_strafe->Set(leftAxis);

	//deadband for Right!!!!!!!!!!!!!!!!!!!

	talonRightMaster->Set(rightValue);
	talonRightFollowerA->Set(rightValue);
}
///////////////////////////////////////////////////////////////////////////////////////
void DriveTrain::ChangeGear(bool _gear) {
	if (currentGear != _gear) {
		if (_gear) {
			//shifts up
			solenoid_Shifter->Set(solenoid_Shifter->kReverse);

		} else if (!_gear) {
			//shifts down
			solenoid_Shifter->Set(solenoid_Shifter->kForward);
		}
		currentGear = _gear;
	}

}
///////////////////////////////////////////////////////////////////////////////////////
void DriveTrain::_Strafe(float strafe_axis) {

	talon_strafe->Set(strafe_axis);

}
///////////////////////////////////////////////////////////////////////////////////////
void DriveTrain::HalfPower() {

	if (cutPower == false) {
		cutPower = true;
	} else if (cutPower == true) {
		cutPower = false;
	}
	SmartDashboard::PutBoolean("Half Power", cutPower);
}
///////////////////////////////////////////////////////////////////////////////////////
