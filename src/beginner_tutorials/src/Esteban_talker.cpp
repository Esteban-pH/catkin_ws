#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include <sstream>

int main(int argc, char **argv)
{

  ros::init(argc, argv, "Esteban_talker");

  ros::NodeHandle n;

  ros::Publisher pub = n.advertise<geometry_msgs::Twist>("cmd_vel", 1000);

  ros::Rate loop_rate(1);

  int count = 0;
  float velx = 0.0, velz = 0.0;
  while (ros::ok()){
    geometry_msgs::Twist msg;
    if(count<5){
      velx = 0.5;
      velz = 0.0;
    }else if (count>5 && count<10){
      velx = 0.0;
      velz = 1.0;
    }else if (count>10 && count<15){
      velx = -0.5;
      velz = 0.0;
    }else if (count>15 && count<20){
      velx = 0.0;
      velz = -1.0;
    }else if(count == 20){
      count = 0;
    }

    msg.linear.x = velx;
    msg.angular.z = velz;

    pub.publish(msg);

    loop_rate.sleep();
    ++count;
  }
  
  return 0;
}
