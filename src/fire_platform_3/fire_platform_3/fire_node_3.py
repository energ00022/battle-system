#!/usr/bin/env python3
import rclpy
from rclpy.node import Node

from battle_interfaces.msg import Target
from battle_interfaces.srv import Pointing


class FireNode3(Node):
    """Бойовий модуль fp3: приймає Pointing‑сервіс і fire_command."""

    def __init__(self):
        super().__init__('fire_node_3')

        # ---------------------------------------------------------------
        # 1. Підписка на топік fire_command для fp3
        # ---------------------------------------------------------------
        self.subscription = self.create_subscription(
            Target,
            '/fp3/fire_command',           # ← власний топік
            self.fire_callback,
            10
        )

        # ---------------------------------------------------------------
        # 2. Сервер сервісу Pointing
        # ---------------------------------------------------------------
        self.pointing_srv = self.create_service(
            Pointing,
            '/fp3/Pointing',               # ← власний сервіс
            self.pointing_callback
        )

        # Статус зайнятості
        self.busy = False
        self.reset_timer = None            # для таймера one‑shot

        self.get_logger().info('🔥 Fire platform fp3 ready')

    # ------------------------------------------------------------------
    #   Pointing service callback
    # ------------------------------------------------------------------
    def pointing_callback(self, request, response):
        """Приймає чи відхиляє запропоновану ціль."""
        if self.busy:
            response.accepted = False
            response.remark = 'busy'
        else:
            self.busy = True
            response.accepted = True
            response.remark = 'accepted'
            self.get_logger().info(
                f'✅ [FP3] Accepted target {request.target.id}')
        return response

    # ------------------------------------------------------------------
    #   fire_command topic callback
    # ------------------------------------------------------------------
    def fire_callback(self, msg: Target):
        """Імітуємо постріл і через 3 с звільняємо платформу."""
        self.get_logger().info(
            f'💥 [FP3] Firing at target {msg.id} '
            f'({msg.x:.1f}, {msg.y:.1f}, {msg.z:.1f})'
        )

        # Створюємо/перезапускаємо таймер one‑shot 3 с
        if self.reset_timer is not None:
            self.reset_timer.cancel()

        self.reset_timer = self.create_timer(
            3.0, self._reset_busy_once)

    # ------------------------------------------------------------------
    #   допоміжний метод для таймера
    # ------------------------------------------------------------------
    def _reset_busy_once(self):
        self.busy = False
        if self.reset_timer is not None:
            self.reset_timer.cancel()
            self.reset_timer = None
        self.get_logger().info('🟢 [FP3] Ready for a new target')


# ----------------------------------------------------------------------
def main(args=None):
    rclpy.init(args=args)
    node = FireNode3()
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == '__main__':
    main()
