# src/fire_platform/test/integration/test_fire_node_launch.py

# Copyright 2025 Willi
# Licensed under the Apache License, Version 2.0

import os
import unittest

import launch
import launch_ros.actions
import launch_testing
import launch_testing.actions
import pytest
from launch.actions import SetEnvironmentVariable
from launch_testing.asserts import assertExitCodes


@pytest.mark.launch_test
def generate_test_description():
    # Підхоплюємо ваш PYTHONPATH, щоб нода змогла знайти встановлені пакети
    pythonpath = os.environ.get("PYTHONPATH", "")
    env_action = SetEnvironmentVariable("PYTHONPATH", pythonpath)

    node = launch_ros.actions.Node(
        package="fire_platform",
        executable="fire_node",
        name="fire_node_test",
        output="screen",
    )

    return (
        launch.LaunchDescription(
            [
                env_action,
                node,
                launch_testing.actions.ReadyToTest(),
            ]
        ),
        {"node": node},
    )


def test_fire_node_starts(proc_output):
    # Переконаємося, що в логах є інфо про старт
    proc_output.assertWaitFor("Fire node started", timeout=5)


@launch_testing.post_shutdown_test()
class TestFireNodeShutdown(unittest.TestCase):
    def test_fire_node_exit_code(self, proc_info):
        # Чекаємо, поки процес коректно завершиться
        proc_info.assertWaitForShutdown(process="fire_node_test")
        # Дозволяємо код 0 (успішне завершення)
        assertExitCodes(proc_info, allowable_exit_codes=[0])
