# src/fire_platform/test/integration/test_fire_node_launch.py

import launch
import launch_ros.actions
import launch_testing
import launch_testing.actions
import pytest


@pytest.mark.launch_test
def generate_test_description():
    return launch.LaunchDescription(
        [
            launch_ros.actions.Node(
                package="fire_platform",
                executable="fire_node",
                name="fire_node_test",
                output="screen",
            ),
            launch_testing.actions.ReadyToTest(),
        ]
    )


def test_node_exit_and_code(proc_info):
    # Чекаємо, поки процес fire_node_test коректно завершиться
    proc_info.assertWaitForShutdown(process="fire_node_test")

    # Перевіряємо, що код виходу = 0
    proc_info.assertExitCodes(process="fire_node_test", allowed_exit_codes=[0])
