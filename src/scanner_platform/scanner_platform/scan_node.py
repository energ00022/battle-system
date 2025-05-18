#!/usr/bin/env python3
import signal
import sys
import time

import rclpy
from rclpy.node import Node


class ScanNode(Node):
    """Сканирующий узел LiDAR-платформы."""

    def __init__(self):
        super().__init__("scan_node")
        self.get_logger().info("🔍 Scan node started")


def main(args=None):
    rclpy.init(args=args)
    node = ScanNode()

    # Обробник сигналу SIGINT → викликає shutdown
    def shutdown_handler(signum, frame):
        node.get_logger().info("👋 SIGINT received — shutting down cleanly")
        rclpy.shutdown()

    signal.signal(signal.SIGINT, shutdown_handler)

    try:
        while rclpy.ok():
            rclpy.spin_once(node, timeout_sec=0.1)
            time.sleep(0.01)
    finally:
        node.destroy_node()
        return 0


if __name__ == "__main__":
    sys.exit(main())
