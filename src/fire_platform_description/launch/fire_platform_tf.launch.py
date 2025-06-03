from launch import LaunchDescription
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node


def generate_launch_description():
    namespace = LaunchConfiguration("namespace")
    x = LaunchConfiguration("x")
    y = LaunchConfiguration("y")

    static_tf = Node(
        package="tf2_ros",
        executable="static_transform_publisher",
        namespace=namespace,
        arguments=[x, y, "0", "0", "0", "0", "map", "odom"],
        output="screen",
    )

    return LaunchDescription([static_tf])
