#!/usr/bin/env python3

from os.path import join

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare


def generate_launch_description():
    # 1) Оголошуємо параметри
    ns = LaunchConfiguration("robot_namespace")
    x = LaunchConfiguration("x")
    y = LaunchConfiguration("y")
    urdf_file = LaunchConfiguration("urdf_file")

    # 2) Шлях до xacro беремо з пакета опису
    default_urdf = join(
        FindPackageShare("fire_platform_description").find("fire_platform_description"),
        "urdf",
        "fire_platform.urdf.xacro",
    )

    return LaunchDescription(
        [
            # 3) Аргументи з дефолтами
            DeclareLaunchArgument(
                "robot_namespace",
                default_value="fp2",
                description="Namespace for this Fire Platform",
            ),
            DeclareLaunchArgument(
                "x", default_value="4.0", description="X coordinate in map"
            ),
            DeclareLaunchArgument(
                "y", default_value="1.0", description="Y coordinate in map"
            ),
            DeclareLaunchArgument(
                "urdf_file",
                default_value=default_urdf,
                description="Path to Fire Platform Xacro URDF",
            ),
            # 4) Static TF: map → ns/odom
            Node(
                package="tf2_ros",
                executable="static_transform_publisher",
                name="map_to_odom_tf",
                arguments=[x, y, "0", "0", "0", "0", "map", [ns, "/odom"]],
            ),
            # 5) Static TF: ns/odom → ns/base_link
            Node(
                package="tf2_ros",
                executable="static_transform_publisher",
                name="odom_to_base_tf",
                arguments=[
                    "0",
                    "0",
                    "0",
                    "0",
                    "0",
                    "0",
                    [ns, "/odom"],
                    [ns, "/base_link"],
                ],
            ),
            # 6) robot_state_publisher з префіксом
            Node(
                package="robot_state_publisher",
                executable="robot_state_publisher",
                namespace=ns,
                parameters=[{"use_sim_time": False, "frame_prefix": [ns, "/"]}],
                arguments=[urdf_file],
                output="screen",
            ),
            # 7) Основний вузол платформи 3
            Node(
                package="fire_platform_3",
                executable="fire_node_3",
                namespace=ns,
                output="screen",
            ),
        ]
    )
