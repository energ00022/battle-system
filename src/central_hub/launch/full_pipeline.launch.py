import os

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch_ros.actions import Node


def generate_launch_description():
    # шляхи до share-папок інших пакетів
    pkg_scanner = get_package_share_directory("scanner_platform")
    pkg_combat = get_package_share_directory("combat_platform")

    # 1) TF + scan_node
    scanner_tf = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(pkg_scanner, "launch", "platform_tf.launch.py")
        ),
        launch_arguments={
            "robot_name": "scanner",
            "x": "0.0",
            "y": "0.0",
            "yaw": "0.0",
        }.items(),
    )
    scanner_node = Node(
        package="scan_platform",
        executable="scan_node",
        name="scan_node",
    )

    # 2) Commander node
    commander = Node(
        package="central_hub",
        executable="commander_node",
        name="commander_node",
    )

    # 3) Усі бойові платформи
    combat_multi = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(pkg_combat, "launch", "multi_combat_tf.launch.py")
        ),
    )

    return LaunchDescription(
        [
            scanner_tf,
            scanner_node,
            commander,
            combat_multi,
        ]
    )
