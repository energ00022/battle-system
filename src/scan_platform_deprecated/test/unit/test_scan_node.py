import rclpy
from scan_platform.scan_node import ScanNode  # перевір назву класу


def test_scan_node_creation():
    rclpy.init()
    node = ScanNode()
    assert node is not None
    node.destroy_node()
    rclpy.shutdown()
