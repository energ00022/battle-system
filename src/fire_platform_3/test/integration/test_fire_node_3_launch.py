#!/usr/bin/env python3

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
                package="fire_platform_3_3",
                executable="fire_node_3",
                name="fire_node_3_test",
                output="screen",
            ),
            launch_testing.actions.ReadyToTest(),
        ]
    )


def test_node_exit_and_code(proc_info):
    # Чекаємо, поки процес fire_node_3_test коректно завершиться
    proc_info.assertWaitForShutdown(process="fire_node_3_test")
    # Перевіряємо, що код виходу = 0
    proc_info.assertExitCodes(process="fire_node_3_test", allowed_exit_codes=[0])
