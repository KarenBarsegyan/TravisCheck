#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "fsd_common_msgs/ControlCommand.h"

fsd_common_msgs::ControlCommand command;

void ScanCallBack(const geometry_msgs::Twist msg) {
    if (msg.linear.x > 0 && command.throttle.data < 1)
        command.throttle.data += 0.05;
    else if (msg.linear.x < 0 && command.throttle.data >= 0)
        command.throttle.data -= 0.05;

    if (msg.angular.z > 0)
        command.steering_angle.data = 0.25;
    else if (msg.angular.z < 0)
        command.steering_angle.data = -0.25;
    else
        command.steering_angle.data = 0;
}

int main(int argc, char **argv) {
    ros::init(argc, argv, "teleop_recieve_send");
    ros::NodeHandle scan;
    ros::NodeHandle pub;

    ros::Subscriber teleop_scan = scan.subscribe("turtle1/cmd_vel", 1000, ScanCallBack);

    ros::Publisher teleop_pub = pub.advertise<fsd_common_msgs::ControlCommand>(
            "/control/pure_pursuit/control_command", 0);

    ros::Rate rate(10);

    while (ros::ok()) {
        teleop_pub.publish(command);

        command.steering_angle.data = 0;

        ros::spinOnce();
        rate.sleep();
    }

    return 0;
}
