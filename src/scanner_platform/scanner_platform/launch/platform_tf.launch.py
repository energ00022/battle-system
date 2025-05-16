from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import (Command, LaunchConfiguration,
                                  PathJoinSubstitution)
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare


def generate_launch_description():
    robot_name = LaunchConfiguration("robot_name", default="scanner")
    x = LaunchConfiguration("x", default="0.0")
    y = LaunchConfiguration("y", default="0.0")
    yaw = LaunchConfiguration("yaw", default="0.0")

    urdf_path = PathJoinSubstitution(
        [FindPackageShare("scanner_platform"), "urdf", "scanner.urdf.xacro"]
    )

    return LaunchDescription(
        [
            DeclareLaunchArgument("robot_name"),
            DeclareLaunchArgument("x"),
            DeclareLaunchArgument("y"),
            DeclareLaunchArgument("yaw"),
            Node(
                package="robot_state_publisher",
                executable="robot_state_publisher",
                name="robot_state_publisher",
                parameters=[{"robot_description": Command(["xacro ", urdf_path])}],
            ),
            Node(
                package="tf2_ros",
                executable="static_transform_publisher",
                arguments=[x, y, "0", "0", "0", yaw, "map", [robot_name, "/odom"]],
                name="map_to_odom_tf",
            ),
        ]
    )
