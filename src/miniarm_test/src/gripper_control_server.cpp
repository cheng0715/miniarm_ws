#include "ros/ros.h"
#include "miniarm_test/ServoControl.h"
#include <serial/serial.h>

serial::Serial arduino_serial;

bool handle_gripper_control(miniarm_test::ServoControl::Request &req,
                            miniarm_test::ServoControl::Response &res) {
    std::string command = req.command;

    if (command != "open" && command != "close") {
        res.success = false;
        res.message = "Invalid command. Use 'open' or 'close'.";
        ROS_ERROR("%s", res.message.c_str());
        return true;
    }

    try {
        arduino_serial.write(command + "\n");
        ROS_INFO("Sent command '%s' to gripper.", command.c_str());

        // 等待 Arduino 回應
        std::string feedback = arduino_serial.readline(1000, "\n");
        feedback.erase(std::remove(feedback.begin(), feedback.end(), '\r'), feedback.end());
        feedback.erase(std::remove(feedback.begin(), feedback.end(), '\n'), feedback.end());

        if (feedback.find("opened") != std::string::npos || feedback.find("closed") != std::string::npos) {
            res.success = true;
            res.message = "Gripper " + command + "ed successfully.";
            ROS_INFO("%s", res.message.c_str());
        } else {
            res.success = false;
            res.message = "Gripper failed to execute command.";
            ROS_ERROR("%s", res.message.c_str());
        }
    } catch (serial::IOException &e) {
        res.success = false;
        res.message = "Serial communication error.";
        ROS_ERROR("%s", res.message.c_str());
    }

    return true;
}

int main(int argc, char **argv) {
    ros::init(argc, argv, "gripper_control_server");
    ros::NodeHandle nh;

    std::string port;
    int baud_rate;

    nh.param<std::string>("gripper_serial_port", port, "/dev/ttyACM0");
    nh.param<int>("gripper_baud_rate", baud_rate, 4000000);

    try {
        arduino_serial.setPort(port);
        arduino_serial.setBaudrate(baud_rate);
        serial::Timeout to = serial::Timeout::simpleTimeout(1000);
        arduino_serial.setTimeout(to);
        arduino_serial.open();
    } catch (serial::IOException &e) {
        ROS_ERROR("Unable to open serial port %s", port.c_str());
        return -1;
    }

    if (arduino_serial.isOpen()) {
        ROS_INFO("Serial port %s initialized.", port.c_str());
    } else {
        ROS_ERROR("Failed to open serial port %s", port.c_str());
        return -1;
    }

    ros::ServiceServer service = nh.advertiseService("gripper_control", handle_gripper_control);
    ROS_INFO("Gripper Control Service is ready.");

    ros::spin();

    return 0;
}
