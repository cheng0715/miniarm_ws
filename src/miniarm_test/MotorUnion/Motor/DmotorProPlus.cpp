#include "DmotorProPlus.h"

DmotorProPlus::DmotorProPlus()
	: Dmotor(57600, 0, 512, 552, 556, 560, 564, 574, 576, 580, 11, 550, 570, 1, 4, 4, 4, 4, 2, 4, 4, 2 ,1) {}

DmotorProPlus::DmotorProPlus(const unsigned char &MotorID, const string &MotorModel)
	: Dmotor(4000000, MotorID, 512, 552, 556, 560, 564, 574, 576, 580, 11, 550, 570, 1, 4, 4, 4, 4, 2, 4, 4, 2, 1)
{
	if (MotorModel == "Pro20+")
	{
		Motor_CenterScale = 0;
		Max_Position_Limit = 303454;
		Min_Position_Limit = -303454;
		Max_Velocity_Limit = 2920;
		Min_Velocity_Limit = -2920;
		Max_Accel_Limit = 10765;
		Max_Torque_Limit = 4500;

		Angle2MotorScale = (Max_Position_Limit - Min_Position_Limit) / 360.0;
		MotorScale2Angle = 1.0 / Angle2MotorScale;
		Scale2RPM = 0.01;
		Scale2RPMM = 1;
	}
}