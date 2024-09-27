#pragma once //To prevent header files from being included multiple times.
# define _USE_MATH_DEFINES
#include <cmath> //
#include <iostream> //cin,cout
#include <fstream> //ifstream,ofstream,fstream
#include <opencv2/opencv.hpp> //OpenCV
#include <opencv2/core/matx.hpp>
//#include <unistd.h> //sleep(10)
#include "../MotorUnion/MotorUnion.h"
// float a[6];
// float d[6];
// float alpha[6];
// float J0 ;
class Arm : public MotorUnion
{
public:
    static Arm *getArm();
    ~Arm() { inst_ = nullptr; };
    
    void Start();
    void Stop();
    void Angle_test();
    // Arm
    cv::Matx44d GetKinematics();
    void GotoPosition(const int &ox, const int &oy, const int &oz, const int &x, const int &y, const int &z);
    void Reset();

private:
    // Arm
   
    cv::Matx44d Calculate_ArmForwardKinematics(const float &J0, const float &J1, const float &J2, const float &J3, const float &J4, const float &J5);
    cv::Mat TransRotate(const float &ox, const float &oy, const float &oz);
    float* Arm_InverseKinematics(const cv::Mat &T);
    float *Arm_IK(const cv::Mat &T);
    void GotoPosition(const cv::Mat &T);
    bool limitation( const float &J1, const float &J2, const float &J3, const float &J4, const float &J5, const float &J6);
   
private:
    Arm();
    static Arm *inst_;

    const unsigned char FIRST_HAND_ID;
    
  
    const float Arm1_Length;        // Length from Joint 0 to 1
    const float Arm2_Length;        // Length from Joint 1 to 2
    const float Arm3_Length;        // Length from Joint 2 to 3
    const float Arm4_Length;        // Length from Joint 3 to 4
    const float Arm5_Length;        // Length from Joint 4 to 5
    const float Arm6_Length;        // Length from Joint 5 to 6
    const float Arm7_Length;        // Length from Joint 6 to 7

    const float Degree2Resolution;
    const int MX106_RESOL;          // Resolution of Mx106
    const int REV_2_SCREW;          // 1 rev equal to how many screw
    int Acc_Factor;                 // Accelleration fector for move straight


    bool ArmMotionEnable;
};