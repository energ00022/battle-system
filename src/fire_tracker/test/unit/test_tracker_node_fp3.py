import rclpy

from fire_tracker.tracker_node_fp3 import TrackerNode as TrackerNodeFP3


def test_node_fp3_creation():
    rclpy.init()
    node = TrackerNodeFP3()
    assert node.get_name() in ["tracker_node_fp3", "TrackerNode"]
    rclpy.shutdown()
