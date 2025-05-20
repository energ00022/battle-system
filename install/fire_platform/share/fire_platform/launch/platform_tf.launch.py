# ===== platform_tf.launch.py =====

from os.path import join

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare


def generate_launch_description():
    robot_namespace = LaunchConfiguration("robot_namespace")
    urdf_file = LaunchConfiguration("urdf_file")

    return LaunchDescription(
        [
            DeclareLaunchArgument(
                "robot_namespace",
                default_value="fp1",
                description="Ім’я платформи (namespace)",
            ),
            DeclareLaunchArgument(
                "urdf_file",
                default_value=join(
                    FindPackageShare("fire_platform").find("fire_platform"),
                    "urdf/fire_platform.urdf.xacro",
                ),
                description="Шлях до Xacro URDF-файлу",
            ),
            # Static tf map -> odom
            Node(
                package="tf2_ros",
                executable="static_transform_publisher",
                name="map_to_odom_tf",
                arguments=[
                    "0",
                    "0",
                    "0",
                    "0",
                    "0",
                    "0",
                    "map",
                    [robot_namespace, "/odom"],
                ],
            ),
            # Static tf odom -> base_link
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
                    [robot_namespace, "/odom"],
                    [robot_namespace, "/base_link"],
                ],
            ),
            # Robot state publisher with prefix
            Node(
                package="robot_state_publisher",
                executable="robot_state_publisher",
                name="robot_state_publisher",
                namespace=robot_namespace,
                parameters=[
                    {"use_sim_time": False, "frame_prefix": [robot_namespace, "/"]}
                ],
                arguments=[urdf_file],
                output="screen",
            ),
            # Fire node (у своєму namespace)
            Node(
                package="fire_platform",
                executable="fire_node",
                name="fire_node",
                namespace=robot_namespace,
                output="screen",
            ),
        ]
    )
