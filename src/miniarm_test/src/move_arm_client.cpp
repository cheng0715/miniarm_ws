#include "ros/ros.h"
#include "miniarm_test/MoveArm.h"
#include "miniarm_test/ServoControl.h"
#include "geometry_msgs/Point.h"
#include <iostream>

int main(int argc, char **argv) {
    ros::init(argc, argv, "move_arm_client");
    ros::NodeHandle nh;

    ros::ServiceClient arm_client = nh.serviceClient<miniarm_test::MoveArm>("move_arm");
    ros::ServiceClient gripper_client = nh.serviceClient<miniarm_test::ServoControl>("gripper_control");

    while (ros::ok()) {
        double x, y, z;
        std::string gripper_command;

        std::cout << "Enter target position (x y z): ";
        std::cin >> x >> y >> z;

        miniarm_test::MoveArm arm_srv;
        arm_srv.request.target_position.x = x;
        arm_srv.request.target_position.y = y;
        arm_srv.request.target_position.z = z;

        if (arm_client.call(arm_srv)) {
            if (arm_srv.response.success) {
                ROS_INFO("Arm moved successfully: %s", arm_srv.response.message.c_str());

                std::cout << "Enter gripper command ('open' or 'close'): ";
                std::cin >> gripper_command;

                miniarm_test::ServoControl gripper_srv;
                gripper_srv.request.command = gripper_command;

                if (gripper_client.call(gripper_srv)) {
                    if (gripper_srv.response.success) {
                        ROS_INFO("Gripper action successful: %s", gripper_srv.response.message.c_str());
                    } else {
                        ROS_ERROR("Gripper action failed: %s", gripper_srv.response.message.c_str());
                    }
                } else {
                    ROS_ERROR("Failed to call gripper service.");
                }
            } else {
                ROS_ERROR("Arm movement failed: %s", arm_srv.response.message.c_str());
            }
        } else {
            ROS_ERROR("Failed to call arm movement service.");
        }

        std::cout << "Do you want to perform another action? (y/n): ";
        char continue_choice;
        std::cin >> continue_choice;
        if (continue_choice != 'y' && continue_choice != 'Y') {
            break;
        }
    }

    return 0;
}
