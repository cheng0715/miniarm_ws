#include "ros/ros.h"
#include "miniarm_test/MoveArm.h"
#include "geometry_msgs/Point.h"
#include "Arm.h"

Arm *arm = Arm::getArm();

bool move_to_position(double x, double y, double z) {
    // cout<< "gogo1" <<endl;
    try {
        // cout<< "gogo2" <<endl;
        // arm->Start();
        // arm->Stop();
        
        // arm->Angle_test();
        // arm->GotoPosition(0, 180, 0, 13 ,-43 ,0); // 調用 GotoPosition, 影片:(-22,-47,-4) 桌上:(30,-17,5) 13 -43 3
        // int ifok;
        // cin >> ifok;

        arm->Reset();
        arm->GotoPosition(0, 180, 0, 13 ,-43 ,-2.2); // 調用 GotoPosition, 影片:(-22,-47,-4) 桌上:(30,-17,5) 13 -43 3
        
        // arm->Start();

        // arm->GotoPosition(0, 180, 0, -22,-47,0);
        // 目標向右抓(degree)
        // ox = 90, oy = 0.0, oz = 90
        // 目標向下抓(degree)
        // ox = 0.0, oy = 180, oz = 0.0
        
        return true;  // 調用成功
    } catch (const std::exception &e) {
        ROS_ERROR("Failed to move arm: %s", e.what());
        return false;  // 發生錯誤，返回 false
    }
}

bool handle_move_arm(miniarm_test::MoveArm::Request &req,
                     miniarm_test::MoveArm::Response &res) {
    ROS_INFO("Received request to move arm to position: x=%f, y=%f, z=%f",
             req.target_position.x, req.target_position.y, req.target_position.z);

    bool success = move_to_position(req.target_position.x, req.target_position.y, req.target_position.z);

    if (success) {
        res.success = true;
        res.message = "Arm moved to target position successfully.";
        ROS_INFO("Arm movement successful.");
    } else {
        res.success = false;
        res.message = "Failed to move arm to target position.";
        ROS_ERROR("Arm movement failed.");
    }

    return true;
}


int main(int argc, char **argv) {
    ros::init(argc, argv, "move_arm_server");
    ros::NodeHandle nh;
   
    // arm = Arm::createInstance();
    
    ros::ServiceServer service = nh.advertiseService("move_arm", handle_move_arm);
    ROS_INFO("Move Arm Service is ready.");

    ros::spin();

    delete arm;  // 釋放內存
    return 0;
}


