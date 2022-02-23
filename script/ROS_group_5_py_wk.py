#!/usr/bin/env python
from ctypes.wintypes import POINT
import rospy
from nav_msgs.msg import Odometry
from tf.transformations import euler_from_quaternion
from geometry_msgs.msg import Point, Twist
from math import atan2
from math import sqrt

x = 0.0
y = 0.0 
theta = 0.0

def newOdom(msg):
    global x
    global y
    global theta

    x = msg.pose.pose.position.x
    y = msg.pose.pose.position.y

    rot_q = msg.pose.pose.orientation
    (roll, pitch, theta) = euler_from_quaternion([rot_q.x, rot_q.y, rot_q.z, rot_q.w])

def update_speed(goal, state):
    inc_x = goal.x -x
    inc_y = goal.y -y

    angle_to_goal = atan2(inc_y, inc_x)
    distance_to_goal = sqrt(inc_x**2 + inc_y**2)

    print('Distance from Goal: ', distance_to_goal)

    # account for angle
    if angle_to_goal - theta > 0.05: 
        speed.linear.x = 0.0
        speed.angular.z = 0.3
    elif angle_to_goal - theta < -0.1: 
        speed.linear.x = 0.0
        speed.angular.z = -0.3
    else:  #car moving forward
        if state != -1:
            speed.linear.x = 0.8
            speed.angular.z = 0.0
        else: 
            speed.linear.x = 0.0
            speed.angular.z = 0.0

    pass

rospy.init_node("speed_controller")

sub = rospy.Subscriber("/odometry/filtered", Odometry, newOdom)
pub = rospy.Publisher("/cmd_vel", Twist, queue_size = 1)

speed = Twist()

r = rospy.Rate(4)

goal = Point()
goal.x = 0
goal.y = 8
state = 0

print('Inital Goal: ', goal.x, ',' , goal.y)

while not rospy.is_shutdown():
    inc_x = goal.x -x
    inc_y = goal.y -y
    distance_to_goal = sqrt(inc_x**2 + inc_y**2)    

    if distance_to_goal < 0.1:
        if state == 0:
            print('Goal 1 Reached')
            print('New Goal: ', goal.x, ',' , goal.y)
            goal.x=goal.x+8
            state == 1

        if state == 1:
            print('Goal 2 Reached')
            print('Proceed to Stop')
            state == -1
    
    update_speed(goal, state)

    pub.publish(speed)
    r.sleep() 
