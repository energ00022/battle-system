#!/usr/bin/env python3

import math

import rclpy
from geometry_msgs.msg import Point, Quaternion
from nav_msgs.msg import Odometry
from rclpy.node import Node


class FakeOdomPublisher(Node):
    def __init__(self):
        super().__init__("fake_odom")
        self.pub = self.create_publisher(Odometry, "odom", 10)
        self.timer = self.create_timer(0.1, self.timer_callback)
        self.x = 0.0
        self.y = 0.0
        self.theta = 0.0

    def timer_callback(self):
        msg = Odometry()
        now = self.get_clock().now().to_msg()
        msg.header.stamp = now
        msg.header.frame_id = "odom"
        msg.child_frame_id = "base_link"
        msg.pose.pose.position = Point(x=self.x, y=self.y, z=0.0)
        q = Quaternion()
        q.z = math.sin(self.theta / 2.0)
        q.w = math.cos(self.theta / 2.0)
        msg.pose.pose.orientation = q
        self.pub.publish(msg)


def main(args=None):
    rclpy.init(args=args)
    node = FakeOdomPublisher()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    node.destroy_node()
    rclpy.shutdown()
