#include "Arm.h"
# define _USE_MATH_DEFINES // 使用 M_PI
#include <cmath>
#include <opencv2/opencv.hpp>
#include <opencv2/core/matx.hpp>
#include "../MotorUnion/MotorUnion.h"
#include <math.h> 
using namespace std;

// 9/24 version(Ginger Ubuntu)
// DH table
// -180~180, limitation, better solution, 鋁件相撞

//  120.44 -75.25 27 -163.429 72.967 -64.3516 35.2527
double a[6] = { 0, 0, 24.5, 0, 0, 0};
double d[6] = { 0, 0, 0, 30.8, 0, 0}; //30.4
double alpha[6] = { 0, -M_PI/2, 0, -M_PI/2, M_PI/2, -M_PI/2};
cv::Matx44d TransMatrix_B0 = {1.0, 0.0, 0.0, 0.0,
							0.0, 1.0, 0.0, 0.0,
							0.0, 0.0, 1.0, 10.5,
							0.0, 0.0, 0.0, 1.0};
cv::Matx44d TransMatrix_6E = {1.0, 0.0, 0.0, 0.0,
							0.0, 1.0, 0.0, 0.0,
							0.0, 0.0, 1.0, 19.6, //20
							0.0, 0.0, 0.0, 1.0};
float J0 = 0.0;

Arm *Arm::inst_ = nullptr;

Arm *Arm::getArm()
{
	if (inst_ == nullptr)
		inst_ = new Arm();
	return inst_;
}

Arm::Arm()
    : MotorUnion({1, 2, 3, 4, 5, 6}, {"Mx106", "Mx106", "Mx106","Mx106", "Mx106", "Mx106"}), // motor_id_0~6
	// : MotorUnion({0, 1, 2, 3, 4, 5, 6}, {"Mx106", "Mx106", "Mx106", "Mx106","Mx106", "Mx106", "Mx106"}), // motor_id_0~6
	  //J2_sign(-1),//Joint 2 direction, due to the machanic, Joint 2 has to be inverted (by ScaraArm.h)
	  Arm1_Length(100), // Length from Joint 0 to 1
	  Arm2_Length(100), // Length from Joint 1 to 2
	  Arm3_Length(100), // Length from Joint 2 to 3
	  Arm4_Length(100), // Length from Joint 3 to 4
      Arm5_Length(100), // Length from Joint 4 to 5
	  Arm6_Length(100), // Length from Joint 5 to 6
	  Arm7_Length(100), // Length from Joint 6 to 7
	  FIRST_HAND_ID(0), // first motor id
	  Degree2Resolution(4096 / 360), // Resolution of Mx106 (length per angle)
      MX106_RESOL(4096), // Resolution of Mx106
	  REV_2_SCREW(226), // 1 rev equal to how many screw
	  Acc_Factor(2)  // Accelleration fector for move straight
{
	Start(); //
	// Stop(); // All Motors Torque false
	SetAllMotorsOperatingMode(3);  // position control(angle)
	cout << "\t\tClass constructed: MiniArm" << endl; // print
}

// void Arm::Start()
// {
// 	SetMotor_Velocity(FIRST_HAND_ID, 50); // first motor velocity = 500
// 	SetMotor_Accel(FIRST_HAND_ID, 25); // first motor accelocity = 250
// 	SetMotor_Velocity(FIRST_HAND_ID + 1, 50); // second motor velocity = 500
// 	SetMotor_Accel(FIRST_HAND_ID + 1, 25); // second motor accelocity = 250
// 	SetMotor_Velocity(FIRST_HAND_ID + 2, 50); // third motor velocity = 500
// 	SetMotor_Accel(FIRST_HAND_ID + 2, 25); // third motor accelocity = 250
// 	SetMotor_Velocity(FIRST_HAND_ID + 3, 50); // fourth motor velocity = 1000
// 	SetMotor_Accel(FIRST_HAND_ID + 3, 25); // fourth motor accelocity = 250
//     SetMotor_Velocity(FIRST_HAND_ID + 4, 50); // fifth motor velocity = 500
// 	SetMotor_Accel(FIRST_HAND_ID + 4, 25); // second motor accelocity = 250
// 	SetMotor_Velocity(FIRST_HAND_ID + 5, 50); // sixth motor velocity = 500
// 	SetMotor_Accel(FIRST_HAND_ID + 5, 25); // third motor accelocity = 250
// 	SetMotor_Velocity(FIRST_HAND_ID + 6, 50); // seventh motor velocity = 1000
// 	SetMotor_Accel(FIRST_HAND_ID + 6, 25); // fourth motor accelocity = 250
// 	SetAllMotorsTorqueEnable(true);
// 	SetMotor_TorqueEnable(5, true);
// 	SetMotor_TorqueEnable(6, true);
// 	cout << "start ok!" << endl;
// }

void Arm::Start()
{
	// 9/23!!
	SetAllMotorsOperatingMode(1);  // position control(angle)
	SetMotor_Velocity(FIRST_HAND_ID, 1); // first motor velocity = 50
	// SetMotor_Accel(FIRST_HAND_ID, 25); // first motor accelocity = 25
	SetMotor_Velocity(FIRST_HAND_ID + 1, 1); // second motor velocity = 50
	// SetMotor_Accel(FIRST_HAND_ID + 1, 25); // second motor accelocity = 25
	SetMotor_Velocity(FIRST_HAND_ID + 2, 1); // third motor velocity = 50
	// SetMotor_Accel(FIRST_HAND_ID + 2, 25); // third motor accelocity = 25
	SetMotor_Velocity(FIRST_HAND_ID + 3, 1); // fourth motor velocity = 100
	// SetMotor_Accel(FIRST_HAND_ID + 3, 25); // fourth motor accelocity = 25
    SetMotor_Velocity(FIRST_HAND_ID + 4, 1); // fifth motor velocity = 50
	// SetMotor_Accel(FIRST_HAND_ID + 4, 25); // second motor accelocity = 25
	SetMotor_Velocity(FIRST_HAND_ID + 5, 1); // sixth motor velocity = 50
	// SetMotor_Accel(FIRST_HAND_ID + 5, 25); // third motor accelocity = 25
	// SetMotor_Velocity(FIRST_HAND_ID + 6, 25); // seventh motor velocity = 50
	// SetMotor_Accel(FIRST_HAND_ID + 6, 25); // fourth motor accelocity = 25
	SetAllMotorsTorqueEnable(true);
	SetMotor_TorqueEnable(5, true);
	cout << "start ok!" << endl;
}

void Arm::Stop(){
	SetAllMotorsTorqueEnable(false);
	// cout << "angle 2: "<< GetMotor_PresentAngle(FIRST_HAND_ID + 2) << endl;
	// cout << "angle 3: "<< GetMotor_PresentAngle(FIRST_HAND_ID + 3) << endl;
	// cout << "angle 5: "<< GetMotor_PresentAngle(FIRST_HAND_ID + 5) << endl;
}

void Arm::Reset(){
	cout << "進入Reset!" << endl;
	this_thread::sleep_for(chrono::milliseconds(3000));
	for (int i = 0; i < 6; i++){  //motor id : 1~6
		SetMotor_Angle(FIRST_HAND_ID + i, 0);
		this_thread::sleep_for(chrono::milliseconds(1000));
		cout << "angle " << i+1 << ": " << GetMotor_Angle(FIRST_HAND_ID + i)<< endl;
	}
	cout << "[MiniArm] Arm Reset Successfully !" << endl;
}
void Arm::Angle_test(){
	cout << "進入 Angle_test!" << endl;
	int input;
	// this_thread::sleep_for(chrono::milliseconds(1000));
	// SetMotor_Angle(0, 0);// deg
	// this_thread::sleep_for(chrono::milliseconds(1000));
	// SetMotor_Angle(0, 10);// deg
	// this_thread::sleep_for(chrono::milliseconds(1000));
	// cout << "angle " << i << ": " << GetMotor_Angle(0)<< endl;
	for (int i = 0; i < 6; i++){  //motor id : 1~6
		SetMotor_Angle(FIRST_HAND_ID + i, 0);
		this_thread::sleep_for(chrono::milliseconds(1000));
		cout << "angle " << i << ": " << GetMotor_Angle(FIRST_HAND_ID + i)<< endl;
		cin >> input;
		SetMotor_Angle(FIRST_HAND_ID + i, -20);// deg
		this_thread::sleep_for(chrono::milliseconds(1000));
		cout << "angle " << i << ": " << GetMotor_Angle(FIRST_HAND_ID + i)<< endl;
	}
	cout << "[MiniArm] Arm Reset Successfully !" << endl;
}
// T_B6
cv::Matx44d Arm::Calculate_ArmForwardKinematics(const float &J0, const float &J1, const float &J2, const float &J3, const float &J4, const float &J5) {
	
	cv::Matx44d TransMatrix_01 = {cos(J0), -sin(J0), 0.0, a[0],
							   sin(J0)*cos(alpha[0]), cos(J0)*cos(alpha[0]), -sin(alpha[0]), -sin(alpha[0])*d[0],
							   sin(J0)*sin(alpha[0]),  cos(J0)*sin(alpha[0]), cos(alpha[0]),  cos(alpha[0])*d[0],
							   0.0, 0.0, 0.0, 1.0};
	cv::Matx44d TransMatrix_12 = {cos(J1), -sin(J1), 0.0, a[1],
							   sin(J1)*cos(alpha[1]), cos(J1)*cos(alpha[1]), -sin(alpha[1]), -sin(alpha[1])*d[1], 
							   sin(J1)*sin(alpha[1]),  cos(J1)*sin(alpha[1]), cos(alpha[1]),  cos(alpha[1])*d[1],
							   0.0, 0.0, 0.0, 1.0};
	cv::Matx44d TransMatrix_23 = {cos(J2), -sin(J2), 0.0, a[2],
							   sin(J2)*cos(alpha[2]), cos(J2)*cos(alpha[2]), -sin(alpha[2]), -sin(alpha[2])*d[2], 
							   sin(J2)*sin(alpha[2]),  cos(J2)*sin(alpha[2]), cos(alpha[2]),  cos(alpha[2])*d[2],
							   0.0, 0.0, 0.0, 1.0};
	cv::Matx44d TransMatrix_34 = {cos(J3), -sin(J3), 0.0, a[3],
							   sin(J3)*cos(alpha[3]), cos(J3)*cos(alpha[3]), -sin(alpha[3]), -sin(alpha[3])*d[3], 
							   sin(J3)*sin(alpha[3]),  cos(J3)*sin(alpha[3]), cos(alpha[3]),  cos(alpha[3])*d[3],
							   0.0, 0.0, 0.0, 1.0};
    cv::Matx44d TransMatrix_45 = {cos(J4), -sin(J4), 0.0, a[4],
							   sin(J4)*cos(alpha[4]), cos(J4)*cos(alpha[4]), -sin(alpha[4]), -sin(alpha[4])*d[4], 
							   sin(J4)*sin(alpha[4]),  cos(J4)*sin(alpha[4]), cos(alpha[4]),  cos(alpha[4])*d[4],
							   0.0, 0.0, 0.0, 1.0};
	cv::Matx44d TransMatrix_56 ={cos(J5), -sin(J5), 0.0, a[5],
							   sin(J5)*cos(alpha[5]), cos(J5)*cos(alpha[5]), -sin(alpha[5]), -sin(alpha[5])*d[5], 
							   sin(J5)*sin(alpha[5]),  cos(J5)*sin(alpha[5]), cos(alpha[5]),  cos(alpha[5])*d[5],
							   0.0, 0.0, 0.0, 1.0};
	cv::Matx44d Temp = (TransMatrix_B0 * TransMatrix_01 * TransMatrix_12 * TransMatrix_23 * TransMatrix_34 * TransMatrix_45 * TransMatrix_56 * TransMatrix_6E);
	// cv::Matx44d Temp = (TransMatrix_B0 * TransMatrix_01 * TransMatrix_12 * TransMatrix_23 * TransMatrix_34 * TransMatrix_45 * TransMatrix_56);
	cout<<"Calculate_ArmForwardKinematics Temp:"<<endl;
	cout<<Temp<<endl;
	return Temp;
}

float* Arm::Arm_InverseKinematics(const cv::Mat &T)
{	
	//參數宣告
	ArmMotionEnable = false;
	float J1, J2, J3, J4, J5, J6;
	double k1, k2, k; //原：double
	float nx, ny, nz, ox, oy, oz, ax, ay, az, px, py, pz;
	double o1, o2, o3, o4, j1, j2, j3; // 原：double(Expressions with numerators and denominators)
	int SolNum = 0;
	//將 alpha 角轉為弧度
	// for (int i = 0; i < 6; i++){
	// 	alpha[i] = alpha[i] * Angle2Rad;
	// }
	// normal of end effector
	nx = T.at<float>(0, 0);
	ny = T.at<float>(1, 0);
	nz = T.at<float>(2, 0);
	// orientation of end effector
	ox = T.at<float>(0, 1); // orientation along x axis, in degree
	oy = T.at<float>(1, 1);
	oz = T.at<float>(2, 1);
	// acceleration of end effector
	ax = T.at<float>(0, 2);
	ay = T.at<float>(1, 2);
	az = T.at<float>(2, 2);
	cv::Matx44f Tt = {T.at<float>(0, 0), T.at<float>(0, 1), T.at<float>(0, 2), T.at<float>(0, 3), 
					T.at<float>(1, 0), T.at<float>(1, 1), T.at<float>(1, 2), T.at<float>(1, 3),
					T.at<float>(2, 0), T.at<float>(2, 1), T.at<float>(2, 2), T.at<float>(2, 3),
					T.at<float>(3, 0), T.at<float>(3, 1), T.at<float>(3, 2), T.at<float>(3, 3)};
	// calculate T06
	cv::Matx44f TransMatrix_B0_inv = TransMatrix_B0.inv(); // inverse TB0
	// cv::Matx44f T_final = TransMatrix_B0_inv * Tt; // TB6,下面註解
	cv::Matx44f T_0E = TransMatrix_B0_inv * Tt;
	cv::Matx44f TransMatrix_6E_inv = TransMatrix_6E.inv(); // inverse T6E
	cv::Matx44f T_final = T_0E * TransMatrix_6E_inv;
	// position of end effector
	px = T_final(0, 3);
	py = T_final(1, 3);
	pz = T_final(2, 3);
	cout<<"Arm_InverseKinematics Tt:"<<endl;
	cout<<Tt<<endl;
	cout<< "gogo" <<endl;
	double theta1[2] ; // J1
	double theta2    = -999 ; // J2
	double theta3[2] ; // J3
	double theta4[2] = {-999, -999}; // J4
	double theta5[2] = {-999, -999}; // J5
	double theta6[2] = {-999, -999}; // J6
	float totall[8][6]; //暫存所有得到的解
	float *Solution = new float[6]; // 回傳值：J1～J6
	for (int i = 0; i < 6; i++)
	{
		Solution[i] = 0;
	}

	// J1 solution
	for (int i = 0; i < 2; i++){
		// theta1 (rad)
		theta1[i] = atan2(py,px) - atan2(0, pow(-1,i)*sqrt( pow(px,2)+pow(py,2)));
	}
	for (int i = 0; i < 2; i++)
	{
		// J3 solution
		k1 = cos(theta1[i])*px + sin(theta1[i])*py - a[1];
		k2 = -pz + d[0];
		k = (pow(k1,2) + pow(k2,2) - (pow(a[2],2) + pow(a[3],2) + pow(d[3],2))) / (2 * a[2]);
		// cout<< "k: " << k <<endl;
		// cout<< "k1: " << k1 <<endl;
		// cout<< "k2: " << k2 <<endl;
		for (int j = 0; j < 2; j++)
		{
			// theta3
			theta3[j] = atan2(a[3],d[3])-atan2(k, pow(-1,j)*sqrt(pow(a[3],2) + pow(d[3],2)-pow(k,2)));
			// cout<< "theta3_square: " << sqrt(pow(a[3],2) + pow(d[3],2)-pow(k,2)) <<endl;
			// cout<< "theta3_a[3]: " << a[3] <<endl;
			// cout<< "theta3_d[3]: " << d[3] <<endl;
			// cout<< "theta3_k: " << k <<endl;
			if (isnan(theta3[j])){
				cout<< "theta3 nan"<<endl;
				theta3[j] = 0.0;
			}
			if (theta3[j] > (M_PI/2)){
				theta3[j] = theta3[j] - 2*M_PI;
			}
			// J2 solution
			o1 = d[3] - sin(theta3[j]) * a[2];
			o2 = sin(theta1[i])*py - a[1] + cos(theta1[i])*px;
			o3 = cos(theta3[j])*a[2] + a[3];
			o4 = d[0] - pz;
			j1 = a[1] - cos(theta1[i])*px - sin(theta1[i])*py;
			j2 = sin(theta1[i])*py - a[1] + cos(theta1[i])*px;
			j3 = d[0] - pz ;
			k1 = (o1*o2-o3*o4) / (j1*j2 - pow(j3,2) );

			o1 = d[3] - sin(theta3[j]) * a[2];
			o2 = d[0] - pz;
			o3 = cos(theta3[j])*a[2] + a[3];
			o4 = a[1] - cos(theta1[i])*px - sin(theta1[i])*py;
			j1 = d[0] - pz;
			j2 = sin(theta1[i])*py - a[1] + cos(theta1[i])*px;
			j3 = a[1] - cos(theta1[i])*px - sin(theta1[i])*py;
			k2 = (o1*o2 - o3*o4) / ( pow(j1,2) - j2*j3 );
			
			theta2 = atan2(k1,k2) - theta3[j];
           
			if (theta2 > (M_PI / 2)){
				theta2 = theta2 - 2*M_PI;
			}
			if (theta2 < (-3 * M_PI / 2)){
				theta2 = theta2 + 2*M_PI;
			}
            cout<<"theta3 : "<<theta3[j]<<" theta2 : "<<theta2<<" theta1 : "<<theta1[i]<<endl;
            cout<<"alpha : "<<alpha[1]<<" a : "<<a[1]<<" d : "<<d[1]<<endl;
			// J4~J6 solution
		    cv::Matx44d t_23 = {cos(theta3[j]), -sin(theta3[j]), 0.0, a[2],
							   sin(theta3[j])*cos(alpha[2]), cos(theta3[j])*cos(alpha[2]), -sin(alpha[2]), -sin(alpha[2])*d[2],
							   sin(theta3[j])*sin(alpha[2]), cos(theta3[j])*sin(alpha[2]), cos(alpha[2]), cos(alpha[2])*d[2],
							   0.0, 0.0, 0.0, 1.0};
			cv::Matx44d t_12 = {cos(theta2), -sin(theta2), 0.0, a[1],
							   sin(theta2)*cos(alpha[1]), cos(theta2)*cos(alpha[1]), -sin(alpha[1]), -sin(alpha[1])*d[1],
							   sin(theta2)*sin(alpha[1]), cos(theta2)*sin(alpha[1]), cos(alpha[1]), cos(alpha[1])*d[1],
							   0.0, 0.0, 0.0, 1.0};	
			cv::Matx44d t_01 = {cos(theta1[i]), -sin(theta1[i]), 0.0, a[0],
							   sin(theta1[i])*cos(alpha[0]), cos(theta1[i])*cos(alpha[0]), -sin(alpha[0]), -sin(alpha[0])*d[0],
							   sin(theta1[i])*sin(alpha[0]), cos(theta1[i])*sin(alpha[0]), cos(alpha[0]), cos(alpha[0])*d[0],
							   0.0, 0.0, 0.0, 1.0};					   
			cv::Matx44d t_03 = t_01 * t_12 * t_23;
            cout<<"t_01 : "<<endl;
            cout<<t_01<<endl;
			cout<<"t_12 : "<<endl;
            cout<<t_12<<endl;
			cout<<"t_23 : "<<endl;
            cout<<t_23<<endl;
			cout<<"t_03 : "<<endl;
            cout<<t_03<<endl;
			cv::Matx33d r_03 = {t_03(0,0), t_03(0,1), t_03(0,2),
							   t_03(1,0), t_03(1,1), t_03(1,2),
							   t_03(2,0), t_03(2,1), t_03(2,2)};
			cout<<"r_03 : "<<endl;
            cout<<r_03<<endl;				   
			cv::Matx33d r_x3 = {1.0, 0.0, 0.0,
							   0.0, cos(-90*Angle2Rad), -sin(-90*Angle2Rad),
							   0.0, sin(-90*Angle2Rad), cos(-90*Angle2Rad)};	
			cv::Matx33d r_06 = {nx, ox, ax,
							   ny, oy, ay,
							   nz, oz, az};
			cv::Matx33d inverseMatrix = r_03 * r_x3;
			//求反矩陣
            inverseMatrix = inverseMatrix.inv();
			cv::Matx33d rzyz = inverseMatrix * r_06;
			cout<<"rzyz : "<<endl;
            cout<<rzyz<<endl;

			for (int l = 0; l < 2; l++){
				theta5[l] = pow(-1,l)*atan2(sqrt(pow(rzyz(2,0),2) + pow(rzyz(2,1),2)), rzyz(2,2));
				theta4[l] = atan2(rzyz(1,2)/sin(theta5[l]),  rzyz(0,2)/sin(theta5[l])) + M_PI;
				theta6[l] = atan2(rzyz(2,1)/sin(theta5[l]), -rzyz(2,0)/sin(theta5[l])) + M_PI;
				
                totall[SolNum][0] = double(theta1[i]);
                totall[SolNum][1] = double(theta2);
                totall[SolNum][2] = double(theta3[j]);
                totall[SolNum][3] = double(theta4[l]);
                totall[SolNum][4] = double(theta5[l]);
                totall[SolNum][5] = double(theta6[l]);
				SolNum++;
            }	
		}
    }

	cout<<"Total solution ======================================================> "<<endl;
	for (int o = 0; o < SolNum; o++)
	{
		cout<<"	Solution_"<<o+1<<" : " <<totall[o][0]* Rad2Angle<<" "<<totall[o][1]* Rad2Angle<<" "<<totall[o][2]* Rad2Angle<<" "<<totall[o][3]* Rad2Angle<<" "<<totall[o][4]* Rad2Angle<<" "<<totall[o][5]* Rad2Angle<<" "<<endl;
	}
	cout<<"The End <============================================================= \n"<<endl;
	
	// 對得到的解 (totall) 進行篩選
	bool check = true;
	// 創建一個大小為 n 個 bool 的 vector，每個值都設為 false
	vector<bool> sol_TF(SolNum, false);
	
	for(int choose = 0 ; choose < SolNum ; choose++){
		check = true;
		J1 = totall[choose][0];
		J2 = totall[choose][1];
		J3 = totall[choose][2];
		J4 = totall[choose][3];
		J5 = totall[choose][4];
		J6 = totall[choose][5];
		cout<<"IF SOL " << choose+1 << ": " <<J1* Rad2Angle<<" "<<J2* Rad2Angle<<" "<<J3* Rad2Angle<<" "<<J4* Rad2Angle<<" "<<J5* Rad2Angle<<" "<<J6* Rad2Angle<<" "<<endl;
		
		cv::Matx44d tmpT = Calculate_ArmForwardKinematics(J1, J2, J3, J4, J5, J6);

		for (int o = 0; o < 4; o++)
		{
			for (int p = 0; p < 4; p++)
			{
				// check whether inverse solution and forward are the same
				if (abs(round(tmpT(o, p)) - round(T.at<float>(o, p))) > 1)
				{
					cout << "tmpT : " << tmpT << endl;
					cout << "Tt : " << Tt << endl;
					check = false;
					cout << choose <<":"<< " forward kinematics is different from inverse kinematics" << endl; 
					break;
				}
			}
		}
		if (check){
			cout << choose << ":" << " ok!" << endl; 
			sol_TF[choose] = true;
		}
		cout<< "--------------------------------------------------------------- " <<endl;
	}

	J1 = 0.0, J2 = 0.0, J3 = 0.0, J4 = 0.0, J5 = 0.0, J6 = 0.0;
	for (int output = SolNum-1; output > -1; output--) {
		if (sol_TF[output]) //正逆向相同
		{
			J1 = totall[output][0];
			J2 = totall[output][1];
			J3 = totall[output][2];
			J4 = totall[output][3];
			J5 = totall[output][4];
			J6 = totall[output][5];
			cout << "IF final solutions : " <<J1* Rad2Angle<<" "<<J2* Rad2Angle<<" "<<J3* Rad2Angle<<" "<<J4* Rad2Angle<<" "<<J5* Rad2Angle<<" "<<J6* Rad2Angle<<" "<<endl;
			cout << "forward kinematics is the same to inverse kinematics" << endl; 
			float temp_theta[6] = {J1 * Rad2Angle, J2 * Rad2Angle, J3 * Rad2Angle, J4 * Rad2Angle, J5 * Rad2Angle, J6 * Rad2Angle};
			for (int o = 0; o < 6; o++)
			{
				// 讓馬達角度範圍落在 -180~180 之間
				if (temp_theta[o] > 180)
				{
					temp_theta[o] = temp_theta[o] - 360.0;
				}
				else if (temp_theta[o] < -180)
				{
					temp_theta[o] = temp_theta[o] + 360.0;
				}
			}
			cout<<"IF modified final solutions : " <<temp_theta[0]<<" "<<temp_theta[1]<<" "<<temp_theta[2]<<" "<<temp_theta[3]<<" "<<temp_theta[4]<<" "<<temp_theta[5]<<endl;
			
			// 先刪掉鋁件會相撞的解
			bool check_collision = limitation(temp_theta[0]*Angle2Rad, temp_theta[1]*Angle2Rad, temp_theta[2]*Angle2Rad, temp_theta[3]*Angle2Rad, temp_theta[4]*Angle2Rad, temp_theta[5]*Angle2Rad);
			// 再取角度改變最小的解(待完成)
			// 目前會取正逆向相同，通過limitation，的最後一組解(因為for loop要跑完)

			if(check_collision)  // safe solution
			{
				cout << "It's a safe and suitable solution." << endl; 
				for (int o = 0; o < 6; o++){
					Solution[o] = float(temp_theta[o]);
				}
				ArmMotionEnable = true; // let torque enable be true
			}
			else
				cout << "It isn't a safe solution !!!!!" << endl;
		}
	}
	if (J1 == 0.0 && J2 == 0.0 && J3 == 0.0 && J4 == 0.0 && J5 == 0.0 && J6 == 0.0) {
		for (int o = 0; o < 7; o++)
		{
			Solution[o] = 0.0;
		}
		cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
		cout << "No suitable inverse kinematics solution." << endl; 
		ArmMotionEnable = false;
	}
	cout << "\n" <<endl;
	cout << "------------------------------------------------------------------------------" << endl;
	cout << "|  Returned Solution : " <<Solution[0]<<" "<<Solution[1]<<" "<<Solution[2]<<" "<<Solution[3]<<" "<<Solution[4]<<" "<<Solution[5]<<"    |"<< endl; 
	cout << "------------------------------------------------------------------------------" << endl;
	return Solution;
}

bool Arm::limitation(const float &J1, const float &J2, const float &J3, const float &J4, const float &J5, const float &J6)
{
	// J2, J3, J5 (radian)
	// 鋁件會相撞的角度要再測
	double  larger_than[3] = {   10 * Angle2Rad,  10 * Angle2Rad,  100 * Angle2Rad};
	double smaller_than[3] = { -180 * Angle2Rad, -180 * Angle2Rad, -100 * Angle2Rad};
	
	if ((J5 > larger_than[2]) || (J5 < smaller_than[2])){
		cout << "angle5 : limit" << endl;
		return false;
	}
    else
	{
        cout << "angle5 : ok " << endl; // J5 pass
        if( (J2 > larger_than[0] ) || (J2 < smaller_than[0]) )
		{
            cout << "angle2 : limit" << endl;
            return false;
		}
        else
		{
            cout << "angle2 : ok " <<endl; // J2 pass
            if( (J3 > larger_than[1]) || (J3 < smaller_than[0]) )
			{
				cout << "angle3 : limit" << endl;
                return false;
			}
            else{
				cout << "angle3 : ok" << endl; // J3 pass
				cout << "The solution pass limitation." << endl;
                return true;
			}       
		}
	}
}

void Arm::GotoPosition(const int &ox, const int &oy, const int &oz, const int &x, const int &y, const int &z) {
	cv::Mat T = TransRotate(ox, oy, oz);
	float data[16] = {T.at<float>(0, 0), T.at<float>(0, 1), T.at<float>(0, 2), float(x),
					  T.at<float>(1, 0), T.at<float>(1, 1), T.at<float>(1, 2), float(y),
					  T.at<float>(2, 0), T.at<float>(2, 1), T.at<float>(2, 2), float(z),
					  0.0, 0.0, 0.0, 1.0};
	cv::Mat tmp = cv::Mat(4, 4, CV_32FC1, data);
	cout<<"GotoPosition tmp:"<<endl;
	cout<<tmp<<endl;
	GotoPosition(tmp);
}

void Arm::GotoPosition(const cv::Mat &T) {
	float *tmp = Arm_InverseKinematics(T);

	// 確認軸向的轉向是否相反
	// tmp[1] = -tmp[1];
	// tmp[4] = -tmp[4];
	int if_ok;
	if (ArmMotionEnable)
	{
		this_thread::sleep_for(chrono::milliseconds(500));
		

		// 先動第二顆馬達
		cin >> if_ok;
		if(abs(GetMotor_Angle(1)-tmp[1]) > 90){
			// 角度大於90，分兩次轉
			
			SetMotor_Angle(1, tmp[1] / 2);
			cout << "Wait for another movement... " << endl;
			this_thread::sleep_for(chrono::milliseconds(3000));
			SetMotor_Angle(1, tmp[1]);
		}
		else
			SetMotor_Angle(1, tmp[1]);// 直接轉
		this_thread::sleep_for(chrono::milliseconds(2000));
		cout << "angle 2: "<< GetMotor_Angle(1) << endl;

		// 再動第三顆馬達
		cin >> if_ok;
		if(abs(GetMotor_Angle(2)-tmp[2]) > 90){
			// 角度大於90，分兩次轉
			SetMotor_Angle(2, tmp[2] / 2);
			cout << "Wait for another movement... " << endl;
			this_thread::sleep_for(chrono::milliseconds(3000));
			SetMotor_Angle(2, tmp[2]);
		}
		else
			SetMotor_Angle(2, tmp[2]); // 直接轉
		this_thread::sleep_for(chrono::milliseconds(2000));
		cout << "angle 3: "<< GetMotor_Angle(2) << endl;
		
		for (int i = 5; i > -1 ; i--){
			cin >> if_ok;
			cout << "i = " << i << endl;
			if (if_ok && i != 1 && i != 2){
				cout << "i = " << i << endl;
				if(abs(GetMotor_Angle(FIRST_HAND_ID + i)-tmp[i]) > 90){
					// 角度大於90，分兩次轉
					
					SetMotor_Angle(FIRST_HAND_ID + i, tmp[i] / 2);
					cout << "Wait for another movement... " << endl;
					this_thread::sleep_for(chrono::milliseconds(3000));
					SetMotor_Angle(FIRST_HAND_ID + i, tmp[i]);
				}
				else
					SetMotor_Angle(FIRST_HAND_ID + i, tmp[i]); // 直接轉
				this_thread::sleep_for(chrono::milliseconds(1000)); //等待馬達轉到位
				cout << "angle " << i+1 << ": " << GetMotor_Angle(FIRST_HAND_ID + i)<< endl;
			}
			if_ok=0;
		}
		cout << "[MiniArm] Arm arrival !" << endl;
	}
	else
	{
		cout << "[MiniArm] Arm fail to arrive !" << endl;
	}
	delete tmp;
	cout << "all angle " << endl;
	int if_need = 1;
	while(if_need){
		cout << "是否需要進行夾取（低一點）？ " << endl;
		cin >> if_need;
		if(if_need){
			SetMotor_Angle(2, GetMotor_Angle(2)+2);
		}
		else{
			break;
		}
	}
	
	for (int i = 0; i < 6 ; i++){
		cout << " "<< GetMotor_Angle(FIRST_HAND_ID + i);
	}
}

//The rotation matrix assumes rotation first around the z-axis, then around the y-axis, and finally around the x-axis. ,0718
cv::Mat Arm::TransRotate(const float &ox, const float &oy, const float &oz) {
	float x_angle = float(ox * Angle2Rad);
	float y_angle = float(oy * Angle2Rad);
	float z_angle = float(oz * Angle2Rad);

	float temp_nx = cos(z_angle) * cos(y_angle);
	float temp_ny = sin(z_angle) * cos(y_angle);
	float temp_nz = -sin(y_angle);
	float temp_ox = cos(z_angle) * sin(y_angle) * sin(x_angle) - sin(z_angle) * cos(x_angle);
	float temp_oy = sin(z_angle) * sin(y_angle) * sin(x_angle) + cos(z_angle) * cos(x_angle);
	float temp_oz = cos(y_angle) * sin(x_angle);
	float temp_ax = cos(z_angle) * sin(y_angle) * cos(x_angle) + sin(z_angle) * sin(x_angle);
	float temp_ay = sin(z_angle) * sin(y_angle) * cos(x_angle) - cos(z_angle) * sin(x_angle);
	float temp_az = cos(y_angle) * cos(x_angle);
	float data[9] = {temp_nx, temp_ox, temp_ax,
					 temp_ny, temp_oy, temp_ay,
					 temp_nz, temp_oz, temp_az};
	cv::Mat tmpMat = cv::Mat(3, 3, CV_32FC1, data);
	return tmpMat.clone();
}

