import os

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node


def generate_launch_description():
    namespace = LaunchConfiguration("namespace")

    urdf_file = os.path.join(
        get_package_share_directory("fire_platform_description"),
        "urdf",
        "fire_platform.urdf.xacro",
    )

    with open(urdf_file, "r") as infp:
        robot_description_content = infp.read()

    return LaunchDescription(
        [
            Node(
                package="robot_state_publisher",
                executable="robot_state_publisher",
                namespace=namespace,
                output="screen",
                parameters=[{"robot_description": robot_description_content}],
            ),
        ]
    )
