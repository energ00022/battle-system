import rclpy
from fire_platform_3_3.fire_node_3 import \
    FireNode3  # або FireNode, якщо така назва в коді


def test_fire_node3_creation():
    rclpy.init()
    node = FireNode3()
    assert node is not None
    node.destroy_node()
    rclpy.shutdown()
