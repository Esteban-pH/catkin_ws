#!/usr/bin/env python
import rospy
from geometry_msgs.msg import Twist

def callback(msg):
    if msg.linear.x > 0.0:
        rospy.loginfo("GOING FORWARD")
    elif msg.linear.x < 0.0:
        rospy.loginfo("GOING BAKWARD")

    if msg.angular.z > 0.0:
        rospy.loginfo("TURNING LEFT")
    elif msg.angular.z < 0.0:
        rospy.loginfo("TURNING RIGHT")

def listener():

    rospy.init_node('Perez_listener_py', anonymous=True)

    rospy.Subscriber('cmd_vel', Twist, callback)

    rospy.spin()

if __name__ == '__main__':
    listener()
