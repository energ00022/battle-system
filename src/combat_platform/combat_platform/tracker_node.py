import random

import rclpy
from rclpy.node import Node
from std_msgs.msg import String

from battle_interfaces.msg import AimVector


class TrackerNode(Node):
    def __init__(self):
        super().__init__("tracker_node")
        robot_name = self.get_namespace().strip("/") or "fpX"
        self.publisher_ = self.create_publisher(
            AimVector, f"/{robot_name}/aim_vector", 10
        )

        self.subscription = self.create_subscription(
            String, f"/{robot_name}/fire_command", self.fire_command_callback, 10
        )

        self.get_logger().info(
            f"�� Tracker for {robot_name} ready, listening to fire commands..."
        )

    def fire_command_callback(self, msg):
        self.get_logger().info(f"🔥 Received fire command: {msg.data}")
        aim = AimVector()
        aim.x = random.uniform(-10.0, 10.0)
        aim.y = random.uniform(-10.0, 10.0)
        aim.z = random.uniform(0.0, 5.0)
        self.publisher_.publish(aim)
        self.get_logger().info(
            f"🎯 Published aim_vector: ({aim.x:.2f}, {aim.y:.2f}, {aim.z:.2f})"
        )


def main(args=None):
    rclpy.init(args=args)
    node = TrackerNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()
