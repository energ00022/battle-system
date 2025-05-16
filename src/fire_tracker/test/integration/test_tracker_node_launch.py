# src/fire_tracker/test/integration/test_tracker_node_launch.py

# Copyright 2025 Willi
# Licensed under the Apache License, Version 2.0

import launch
import launch_ros.actions
import launch_testing
import launch_testing.actions
import pytest
from launch_testing.asserts import assertExitCodes


@pytest.mark.launch_test
def generate_test_description():
    tracker = launch_ros.actions.Node(
        package="fire_tracker",
        executable="tracker_node",
        name="tracker_node_test",
        output="screen",
    )
    return (
        launch.LaunchDescription(
            [
                tracker,
                launch_testing.actions.ReadyToTest(),
            ]
        ),
        {"tracker": tracker},
    )


def test_tracker_node_started(proc_output):
    proc_output.assertWaitFor("Tracker node started", timeout=5)


@launch_testing.post_shutdown_test()
class TestTrackerNodeShutdown:
    def test_exit_code(self, proc_info):
        assertExitCodes(proc_info, allowable_exit_codes=[-2, 0])
