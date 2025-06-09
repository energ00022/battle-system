import os

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    urdf_fp = "/home/willi/battle_ws/src/fire_platform_description/urdf/fire_platform.urdf.xacro"
    with open(urdf_fp, "r") as infp:
        urdf_content = infp.read()

    config_dir = os.path.join(get_package_share_directory("dual_platforms"), "config")
    ekf_fp1 = os.path.join(config_dir, "ekf_fp1.yaml")
    ekf_fp2 = os.path.join(config_dir, "ekf_fp2.yaml")

    return LaunchDescription(
        [
            Node(
                package="tf2_ros",
                executable="static_transform_publisher",
                namespace="fp1",
                arguments=["0.0", "0.0", "0", "0", "0", "0", "map", "odom"],
                output="screen",
            ),
            Node(
                package="tf2_ros",
                executable="static_transform_publisher",
                namespace="fp2",
                arguments=["5.0", "3.0", "0", "0", "0", "0", "map", "odom"],
                output="screen",
            ),
            Node(
                package="robot_state_publisher",
                executable="robot_state_publisher",
                namespace="fp1",
                parameters=[{"robot_description": urdf_content}],
                output="screen",
            ),
            Node(
                package="robot_state_publisher",
                executable="robot_state_publisher",
                namespace="fp2",
                parameters=[{"robot_description": urdf_content}],
                output="screen",
            ),
            Node(
                package="robot_localization",
                executable="ekf_node",
                namespace="fp1",
                name="ekf_filter_node",
                parameters=[ekf_fp1],
                output="screen",
            ),
            Node(
                package="robot_localization",
                executable="ekf_node",
                namespace="fp2",
                name="ekf_filter_node",
                parameters=[ekf_fp2],
                output="screen",
            ),
            # ✅ Ось головна зміна:
            Node(
                package="dual_platforms",
                executable="fake_odom_publisher",
                namespace="fp1",
                output="screen",
            ),
            Node(
                package="dual_platforms",
                executable="fake_odom_publisher",
                namespace="fp2",
                output="screen",
            ),
            Node(
                package="fire_platform",
                executable="aiming_node",
                namespace="fp1",
                parameters=[{"target_topic": "/target_point"}],
                output="screen",
            ),
            Node(
                package="fire_platform_3",
                executable="aiming_node",
                namespace="fp2",
                parameters=[{"target_topic": "/target_point"}],
                output="screen",
            ),
            Node(
                package="scanner_platform",
                executable="scanner_node",
                name="scanner_node",
                output="screen",
            ),
        ]
    )
