from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    return LaunchDescription(
        [
            Node(
                package="scanner_platform",
                executable="scanner_node",
                name="scanner_node",
                output="screen",
            ),
        ]
    )
