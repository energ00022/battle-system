#!/usr/bin/env python3


import rclpy
from rclpy.node import Node

from battle_interfaces.msg import Target, TargetArray
from battle_interfaces.srv import Pointing


class CommanderNode(Node):
    def __init__(self):
        super().__init__("commander_node")
        self.get_logger().info("🧠 Commander node started, waiting for targets...")

        # Платформи для виклику Pointing + публікації fire_command
        self.fire_platforms = ["fp1", "fp3"]
        self.pointing_clients = {}
        self.fire_publishers = {}

        for ns in self.fire_platforms:
            self.pointing_clients[ns] = self.create_client(Pointing, f"/{ns}/Pointing")
            self.fire_publishers[ns] = self.create_publisher(
                Target, f"/{ns}/fire_command", 10
            )

        # Підписка на топік із масивом цілей
        self.create_subscription(
            TargetArray, "/target_array", self.target_array_callback, 10
        )

    def target_array_callback(self, msg: TargetArray):
        if not msg.targets:
            self.get_logger().warn("No targets received")
            return

        # Беремо першу ціль
        target = msg.targets[0]
        self.get_logger().info(
            f"🎯 Received {len(msg.targets)} targets; picking ID={target.id}"
        )

        # Надсилаємо запит першій доступній платформі
        for ns in self.fire_platforms:
            client = self.pointing_clients[ns]
            if not client.wait_for_service(timeout_sec=0.5):
                self.get_logger().warn(f"Service /{ns}/Pointing not available")
                continue

            # Формуємо та відправляємо запит
            req = Pointing.Request()
            req.id = target.id
            req.x = target.x
            req.y = target.y
            req.z = target.z

            future = client.call_async(req)
            future.add_done_callback(
                lambda fut, p=ns, t=target: self.on_pointing_response(fut, p, t)
            )
            # Чекаємо відповіді тільки від першої
            return

    def on_pointing_response(self, future, platform_ns: str, target: Target):
        try:
            resp = future.result()
        except Exception as e:
            self.get_logger().error(f"Error from {platform_ns}/Pointing: {e}")
            return

        if resp.accepted:
            self.get_logger().info(
                f"✅ {platform_ns} accepted target {target.id}; firing"
            )
            self.fire_publishers[platform_ns].publish(target)
        else:
            self.get_logger().warn(
                f"❌ {platform_ns} rejected target {target.id}: {resp.message}"
            )


def main(args=None):
    rclpy.init(args=args)
    node = CommanderNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == "__main__":
    main()
