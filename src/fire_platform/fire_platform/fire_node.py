#!/usr/bin/env python3

from battle_interfaces.msg import Target
from battle_interfaces.srv import Pointing

import rclpy
from rclpy.node import Node


class FireNode(Node):
    def __init__(self):
        super().__init__('fire_node')

        self.subscription = self.create_subscription(
            Target, '/fp1/fire_command', self.fire_callback, 10
        )

        self.srv = self.create_service(
            Pointing, '/fp1/Pointing', self.pointing_cb
        )

        self.busy = False
        self.reset_timer = None
        self.get_logger().info('🔥 Fire platform fp1 ready')

    def pointing_cb(self, request, response):
        if self.busy:
            response.accepted = False
            response.remark = 'busy'
        else:
            self.busy = True
            response.accepted = True
            response.remark = 'accepted'
            self.get_logger().info(f'✅ Accepted target {request.target.id}')
        return response

    def fire_callback(self, msg: Target):
        self.get_logger().info(
            f'💥 fp1 firing at target {msg.id} '
            f'({msg.x:.1f}, {msg.y:.1f}, {msg.z:.1f})'
        )

        if self.reset_timer is not None:
            self.reset_timer.cancel()
        self.reset_timer = self.create_timer(3.0, self._reset_busy_once)

    def _reset_busy_once(self):
        self.busy = False
        if self.reset_timer is not None:
            self.reset_timer.cancel()
            self.reset_timer = None
        self.get_logger().info('🟢 fp1 is ready for a new target')


def main(args=None):
    rclpy.init(args=args)
    node = FireNode()
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == '__main__':
    main()
