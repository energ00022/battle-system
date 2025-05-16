import rclpy
from rclpy.node import Node

from battle_interfaces.msg import AimVector, TargetArray


class CommanderNode(Node):
    def __init__(self):
        super().__init__("commander_node")
        self.subscription = self.create_subscription(
            TargetArray, "/target_array", self.target_callback, 10
        )

        # Публікація fire_command для кожної бойової платформи
        self.fire_pub_combat1 = self.create_publisher(
            AimVector, "/combat1/fire_command", 10
        )

        self.get_logger().info("🧠 Commander node started, waiting for targets...")

    def target_callback(self, msg):
        if not msg.targets:
            self.get_logger().info("❌ No targets received.")
            return

        target = msg.targets[0]  # Поки що — перша ціль
        aim = AimVector()
        aim.x = target.x
        aim.y = target.y
        aim.z = target.z
        aim.label = target.label

        self.fire_pub_combat1.publish(aim)
        self.get_logger().info(
            f"🎯 Sent fire command to combat1: {target.label} at "
            f"({target.x:.2f}, {target.y:.2f}, {target.z:.2f})"
        )


def main(args=None):
    rclpy.init(args=args)
    node = CommanderNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()
