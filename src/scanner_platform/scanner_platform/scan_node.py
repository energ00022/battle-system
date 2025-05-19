#!/usr/bin/env python3

import rclpy
from rclpy.node import Node

from battle_interfaces.msg import Target, TargetArray


class ScanNode(Node):
    def __init__(self):
        super().__init__("scan_node")
        self.publisher_ = self.create_publisher(TargetArray, "/target_array", 10)
        self.timer = self.create_timer(1.0, self.timer_callback)
        self.get_logger().info("🔍 Scan node started")

    def timer_callback(self):
        target = Target()
        target.id = 1
        target.x = 1.0
        target.y = 2.0
        target.z = 0.5
        target.confidence = 0.85
        target.frame_id = "map"

        msg = TargetArray()
        msg.targets = [target]
        self.publisher_.publish(msg)
        self.get_logger().info(f"Published {len(msg.targets)} targets")


def main(args=None):
    rclpy.init(args=args)
    node = ScanNode()
    exit_code = 0

    def shutdown():
        node.destroy_node()
        rclpy.shutdown()

    try:
        rclpy.spin(node)
    except Exception as e:
        node.get_logger().error(f"Spin failed: {e}")
        exit_code = 1

    shutdown()
    return exit_code


if __name__ == "__main__":
    main()
