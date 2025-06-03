#!/usr/bin/env python3

from os.path import join

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare


def generate_launch_description():
    ns = LaunchConfiguration("robot_namespace")
    urdf_file = LaunchConfiguration("urdf_file")

    return LaunchDescription(
        [
            DeclareLaunchArgument(
                "robot_namespace",
                default_value="fp1",
                description="Namespace for this Fire Platform",
            ),
            DeclareLaunchArgument(
                "urdf_file",
                default_value=join(
                    FindPackageShare("fire_platform_description").find(
                        "fire_platform_description"
                    ),
                    "urdf",
                    "fire_platform.urdf.xacro",
                ),
                description="Path to Fire Platform Xacro URDF",
            ),
            # Static TF: map → ns/odom
            Node(
                package="tf2_ros",
                executable="static_transform_publisher",
                name="map_to_odom_tf",
                arguments=["0", "0", "0", "0", "0", "0", "map", [ns, "/odom"]],
            ),
            # Static TF: ns/odom → ns/base_link
            Node(
                package="tf2_ros",
                executable="static_transform_publisher",
                name="odom_to_base_tf",
                arguments=[
                    "1",
                    "2",
                    "0",
                    "0",
                    "0",
                    "0",
                    [ns, "/odom"],
                    [ns, "/base_link"],
                ],
            ),
            # Robot State Publisher
            Node(
                package="robot_state_publisher",
                executable="robot_state_publisher",
                namespace=ns,
                parameters=[{"use_sim_time": False, "frame_prefix": [ns, "/"]}],
                arguments=[urdf_file],
                output="screen",
            ),
            # Основна нода платформи
            Node(
                package="fire_platform",
                executable="fire_node",
                namespace=ns,
                output="screen",
            ),
            # Додаємо новий aiming_node
            Node(
                package="fire_platform",
                executable="aiming_node",
                namespace=ns,
                output="screen",
                parameters=[{"target_topic": "/target_point"}],
            ),
        ]
    )
