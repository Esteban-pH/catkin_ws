#include "ros/ros.h"
#include <std_msgs/Int32MultiArray.h>
#include <geometry_msgs/Twist.h>
#include <math.h>
#define PI 3.14159265358979323846

const double countrev    = 4480.0; //How many counts the encoders do per round
const double radio_in_m  = .120;   //Input the radio of the wheels in meters
const double rate_sen    = .01;    //The time between each reding of the encoders in seconds, this is defined in the arduino code
const double dis_wheels  = .29;    //Distance between the wheels in meters

//Variables to build twist
double linearx=0, lineary=0, linearz=0, angularx=0, angulary=0, angularz=0;
//Variables Encoder 1
double pos_1, rpm_1, deltapos_1=0, oldpos_1=0, rads_1;
//Variables Encoder 2
double pos_2, rpm_2, deltapos_2=0, oldpos_2=0, rads_2;
//Variables Encoder 3
double pos_3, rpm_3, deltapos_3=0, oldpos_3=0, rads_3;
//Variables Encoder 4
double pos_4, rpm_4, deltapos_4=0, oldpos_4=0, rads_4;
//Variables diferencial model
double v,w,wr,wi;

void velCallback(const std_msgs::Int32MultiArray::ConstPtr& msg){
  pos_1  = ((double)msg->data[0])/countrev; //Calculates what is the current position of the wheel
  deltapos_1 = pos_1 - oldpos_1;
  oldpos_1   = pos_1;
  rpm_1  = deltapos_1/rate_sen;
  rads_1 = rpm_1*2*PI;
  rpm_1 *= 60;

  pos_2  = ((double)msg->data[1])/countrev; //Calculates what is the current position of the wheel
  deltapos_2 = pos_2 - oldpos_2;
  oldpos_2   = pos_2;
  rpm_2  = deltapos_2/rate_sen;
  rads_2 = rpm_2*2*PI;
  rpm_2 *= 60;

  pos_3  = ((double)msg->data[2])/countrev; //Calculates what is the current position of the wheel
  deltapos_3 = pos_3 - oldpos_3;
  oldpos_3   = pos_3;
  rpm_3  = deltapos_3/rate_sen;
  rads_3 = rpm_3*2*PI;
  rpm_3 *= 60;

  pos_4  = ((double)msg->data[3])/countrev; //Calculates what is the current position of the wheel
  deltapos_4 = pos_4 - oldpos_4;
  oldpos_4   = pos_4;
  rpm_4  = deltapos_4/rate_sen;
  rads_4 = rpm_4*2*PI;
  rpm_4 *= 60;

  //Uncomment for debugging each motor speed
  ROS_INFO("Motor 1 RPM: [%lf]", fabs(rpm_1));
  ROS_INFO("Motor 1 Rad/s: [%lf]", rads_1);
  ROS_INFO("Motor 2 RPM: [%lf]", fabs(rpm_2));
  ROS_INFO("Motor 2 Rad/s: [%lf]", rads_2);
  ROS_INFO("Motor 3 RPM: [%lf]", fabs(rpm_3));
  ROS_INFO("Motor 3 Rad/s: [%lf]", rads_3);
  ROS_INFO("Motor 4 RPM: [%lf]", fabs(rpm_4));
  ROS_INFO("Motor 4 Rad/s: [%lf]", rads_4);

  wr = (rads_1+rads_2)/2.0;
  wi = (rads_3+rads_4)/2.0;

  linearx  = (radio_in_m*(wr+wi))/2.0;
  angularz = (radio_in_m*(wr-wi))/dis_wheels;
  // ROS_INFO("Linear x: [%lf]", linearx);
  // ROS_INFO("Angular z: [%lf]", angularz);
}

int main(int argc, char **argv){
  ros::init(argc, argv, "vel_reader");
  ros::NodeHandle n;
  //Publisher to pass the calculated twist to a topic
  ros::Publisher  pub = n.advertise<geometry_msgs::Twist>("robot_twist", 1000);
  ros::Subscriber sub = n.subscribe("robot_vel", 1000, velCallback);

  //Publishes at the same rate it gest the data from the Arduino, in this case each 10ms
  ros::Rate loop_rate(100);

  while (ros::ok()){
    //Defines the message type
    geometry_msgs::Twist msg;
    //The twist variables are modified accordingly
    msg.linear.x = linearx;
    msg.angular.z = angularz;
    //Publishes the message
    pub.publish(msg);
    loop_rate.sleep();
    //spinOnce is a MUST with spin it wont publish and without it, it won't suscribe
    ros::spinOnce();
  }
  ros::spin();
  return 0;
}
