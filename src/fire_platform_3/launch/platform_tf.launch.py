#!/usr/bin/env python3

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node


def generate_launch_description():
    robot_namespace = LaunchConfiguration("robot_namespace")

    return LaunchDescription(
        [
            DeclareLaunchArgument(
                "robot_namespace",
                default_value="fp1",
                description="Namespace for the robot",
            ),
            Node(
                package="fire_platform_3",
                executable="fire_node_3",
                name="fire_node_3",
                namespace=robot_namespace,
                output="screen",
            ),
        ]
    )
