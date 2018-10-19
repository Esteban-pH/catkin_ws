#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "std_msgs/String.h"

void velCallback(const geometry_msgs::Twist& msg)
{
  if(msg.linear.x > 0.0)
    ROS_INFO("GOING FORWARD");
  else if(msg.linear.x < 0.0)
    ROS_INFO("GOING BAKWARD");

  if(msg.angular.z > 0.0)
    ROS_INFO("TURNING LEFT");
  else if(msg.angular.z < 0.0)
    ROS_INFO("TURNING RIGHT");

}

int main(int argc, char **argv){
  ros::init(argc, argv, "listener");
  ros::NodeHandle n;
  ros::Subscriber sub = n.subscribe("cmd_vel", 1000, velCallback);
  ros::spin();

  return 0;
}
