#!/usr/bin/env python3

from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    return LaunchDescription(
        [
            Node(
                package="fire_platform",
                executable="fire_node",  # назва твого файлу без .py
                name="fire_node",
                namespace="fp1",
                output="screen",
            )
        ]
    )
