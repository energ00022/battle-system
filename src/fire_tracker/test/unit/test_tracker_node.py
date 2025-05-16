import rclpy

from fire_tracker.tracker_node import TrackerNode


def test_node_creation():
    rclpy.init()
    node = TrackerNode()
    assert node.get_name() == "tracker_node"
    rclpy.shutdown()
