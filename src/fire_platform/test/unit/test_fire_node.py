import rclpy

from fire_platform.fire_node import FireNode


def test_node_creation():
    rclpy.init()
    node = FireNode()
    assert node.get_name() in ["fire_node", "FireNode"]
    rclpy.shutdown()
