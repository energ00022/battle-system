#!/usr/bin/env python3
import rclpy
from rclpy.node import Node

from battle_interfaces.msg import Target
from battle_interfaces.srv import Pointing


class FireNode3(Node):
    """Бойовий модуль fp3: приймає Pointing-сервіс і fire_command."""

    def __init__(self):
        super().__init__("fire_node_3")

        # ---------------------------------------------------------------
        # 1. Підписка на топік /fp3/fire_command
        # ---------------------------------------------------------------
        self.subscription = self.create_subscription(
            Target,
            "/fp3/fire_command",
            self.fire_callback,
            10,
        )

        # ---------------------------------------------------------------
        # 2. Сервер сервісу /fp3/Pointing
        # ---------------------------------------------------------------
        self.pointing_srv = self.create_service(
            Pointing,
            "/fp3/Pointing",
            self.pointing_callback,
        )

        # Статус зайнятості
        self.busy = False
        self.reset_timer = None

        self.get_logger().info("🔥 Fire platform fp3 ready")

    def pointing_callback(self, request, response):
        """Приймає чи відхиляє запропоновану ціль."""
        if self.busy:
            response.accepted = False
            response.remark = "busy"
        else:
            self.busy = True
            response.accepted = True
            response.remark = "accepted"
            self.get_logger().info(f"✅ [FP3] Accepted target {request.target.id}")
        return response

    def fire_callback(self, msg: Target):
        """Імітуємо постріл і через 3 с звільняємо платформу."""
        self.get_logger().info(
            f"💥 [FP3] Firing at target {msg.id} "
            f"({msg.x:.1f}, {msg.y:.1f}, {msg.z:.1f})"
        )
        # Перезапускаємо таймер one-shot на 3 с
        if self.reset_timer is not None:
            self.reset_timer.cancel()
        self.reset_timer = self.create_timer(3.0, self._reset_busy_once)

    def _reset_busy_once(self):
        self.busy = False
        if self.reset_timer is not None:
            self.reset_timer.cancel()
            self.reset_timer = None
        self.get_logger().info("🟢 [FP3] Ready for a new target")


def main(args=None):
    rclpy.init(args=args)
    node = FireNode3()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.get_logger().info("🔌 Shutdown requested, exiting cleanly...")
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == "__main__":
    main()
