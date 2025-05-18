import os

import yaml
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.substitutions import Command
from launch_ros.actions import Node


def generate_platform_nodes(robot_name: str):
    # 1) Шлях до YAML з позиціями
    cfg = os.path.join(
        get_package_share_directory("combat_platform"),
        "config",
        "combat_positions.yaml",
    )
    with open(cfg, "r") as f:
        poses = yaml.safe_load(f)
    if robot_name not in poses:
        raise RuntimeError(f"Robot '{robot_name}' not found in config")
    p = poses[robot_name]

    # 2) Шлях до xacro-файла
    urdf_path = os.path.join(
        get_package_share_directory("combat_platform"),
        "urdf",
        "combat.urdf.xacro",
    )

    # 3) Створюємо два вузли – RSP та TF
    return [
        # robot_state_publisher через xacro
        Node(
            package="robot_state_publisher",
            executable="robot_state_publisher",
            name=f"{robot_name}_robot_state_publisher",
            parameters=[
                {
                    "robot_description": Command(
                        [
                            "xacro ",  # <-- ОБОВ’ЯЗКОВО перший елемент
                            urdf_path,  # <-- І другий – шлях до файлу
                        ]
                    )
                }
            ],
        ),
        # static_transform_publisher
        Node(
            package="tf2_ros",
            executable="static_transform_publisher",
            name=f"{robot_name}_static_tf",
            arguments=[
                str(p["x"]),
                str(p["y"]),
                "0",
                "0",
                "0",
                str(p["yaw"]),
                "map",
                f"{robot_name}/odom",
            ],
        ),
    ]


def generate_launch_description():
    ld = LaunchDescription()
    # тут перелік усіх платформ
    for rn in ["combat1", "combat2"]:
        for node in generate_platform_nodes(rn):
            ld.add_action(node)
    return ld
