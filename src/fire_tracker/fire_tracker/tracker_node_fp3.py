#!/usr/bin/env python3

import math
import random

import rclpy
from rclpy.node import Node

from battle_interfaces.msg import AimVector, Target


class TrackerNode(Node):
    def __init__(self):
        super().__init__("tracker_node_fp3")

        ns = "fp3"
        self.goal_sub = self.create_subscription(
            Target, f"/{ns}/fire_command", self.goal_cb, 10
        )
        self.aim_pub = self.create_publisher(AimVector, f"/{ns}/aim_vector", 10)

        self.current_goal = None
        self.ready = False
        self.timer = self.create_timer(0.1, self.track_loop)

        self.get_logger().info("📷 Fire tracker fp3 ready")

    def goal_cb(self, msg: Target):
        self.current_goal = msg
        self.ready = False
        self.get_logger().info(f"🆕 New goal {msg.id}")

    def track_loop(self):
        if self.current_goal is None:
            return

        vec = AimVector()
        vec.yaw = math.atan2(self.current_goal.y, self.current_goal.x) + random.uniform(
            -0.05, 0.05
        )
        vec.pitch = math.atan2(
            self.current_goal.z, math.hypot(self.current_goal.x, self.current_goal.y)
        ) + random.uniform(-0.05, 0.05)
        vec.roll = 0.0
        self.aim_pub.publish(vec)

        if not self.ready and random.random() < 0.07:
            self.ready = True
            self.get_logger().info(
                f"✅ Aim stabilised for target {self.current_goal.id}"
            )


def main(args=None):
    rclpy.init(args=args)
    node = TrackerNode()
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()
