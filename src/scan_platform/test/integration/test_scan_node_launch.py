# src/scan_platform/test/integration/test_scan_node_launch.py

import launch
import launch_ros.actions
import launch_testing
import launch_testing.actions
import pytest
from launch_testing.asserts import assertExitCodes


@pytest.mark.launch_test
def generate_test_description():
    node = launch_ros.actions.Node(
        package="scan_platform",
        executable="scan_node",
        name="scan_node_test",
        output="screen",
    )
    return (
        launch.LaunchDescription(
            [
                node,
                launch_testing.actions.ReadyToTest(),
            ]
        ),
        {"node": node},
    )


def test_node_startup(proc_output):
    proc_output.assertWaitFor("🔍 Scan node started", timeout=5)


@launch_testing.post_shutdown_test()
class TestScanNodeShutdown:
    def test_exit_code(self, proc_info):
        # Дозволяємо як штатне завершення, так і SIGINT (-2)
        assertExitCodes(proc_info, allowable_exit_codes=[0, -2])
