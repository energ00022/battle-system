#!/usr/bin/env python3

from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    return LaunchDescription(
        [
            Node(
                package="fire_platform_3",
                executable="fire_node_3",
                name="fire_node_fp3",
                namespace="fp3",
                output="screen",
            )
        ]
    )
