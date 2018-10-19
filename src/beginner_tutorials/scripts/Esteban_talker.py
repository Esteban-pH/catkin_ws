#!/usr/bin/env python
import rospy
from geometry_msgs.msg import Twist

def talker():
    pub = rospy.Publisher('cmd_vel', Twist, queue_size=10)
    rospy.init_node('Esteban_talker_py', anonymous=True)
    rate = rospy.Rate(1) # 1hz
    msg = Twist()
    count = 0

    while not rospy.is_shutdown():
        if count<5:
            msg.linear.x=0.5
            msg.angular.z=0.0
        elif count>5 and count<10:
            msg.linear.x=0.0
            msg.angular.z=1.0
        elif count>10 and count <15:
            msg.linear.x=-0.5
            msg.angular.z=0.0
        elif count>15 and count<20:
            msg.linear.x=0.0
            msg.angular.z=-1.0
        elif count == 20:
            count=0
        pub.publish(msg)
        rate.sleep()
        count+=1

if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException:
        pass
