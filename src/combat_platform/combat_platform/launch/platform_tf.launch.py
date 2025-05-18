import os

import yaml
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, OpaqueFunction
from launch.substitutions import Command, LaunchConfiguration
from launch_ros.actions import Node


def launch_setup(context, *args, **kwargs):
    robot_name = LaunchConfiguration("robot_name").perform(context)

    # Шлях до YAML-конфіга
    config_file = os.path.join(
        get_package_share_directory("combat_platform"),
        "config",
        "combat_positions.yaml",
    )
    with open(config_file, "r") as f:
        positions = yaml.safe_load(f)

    if robot_name not in positions:
        raise RuntimeError(f"Robot '{robot_name}' not found in config")

    pos = positions[robot_name]
    x, y, yaw = str(pos["x"]), str(pos["y"]), str(pos["yaw"])

    # Шлях до xacro-файла
    urdf_file = os.path.join(
        get_package_share_directory("combat_platform"), "urdf", "combat.urdf.xacro"
    )

    return [
        Node(
            package="robot_state_publisher",
            executable="robot_state_publisher",
            name="robot_state_publisher",
            parameters=[{"robot_description": Command(["xacro", urdf_file])}],
        ),
        Node(
            package="tf2_ros",
            executable="static_transform_publisher",
            name="map_to_odom_tf",
            arguments=[x, y, "0", "0", "0", yaw, "map", f"{robot_name}/odom"],
        ),
    ]


def generate_launch_description():
    return LaunchDescription(
        [
            DeclareLaunchArgument("robot_name", default_value="combat1"),
            OpaqueFunction(function=launch_setup),
        ]
    )
