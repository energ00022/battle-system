import rclpy
from rclpy.node import Node

from battle_interfaces.msg import Target, TargetArray      # ← нові типи
from builtin_interfaces.msg import Time                    # для stamp

import random
import time


class ScanNode(Node):                                      # назва на твій смак
    def __init__(self):
        super().__init__('scanner_node')                    # ім’я вузла не міняємо
        self.publisher_ = self.create_publisher(
            TargetArray,
            '/target_array',                               # ← новий топік
            10
        )
        self.timer = self.create_timer(1.0, self.publish_targets)
        self.get_logger().info('Scanner node started (TargetArray mode)')

    def publish_targets(self):
        msg = TargetArray()
        msg.frame_id = 'world'

        # часова мітка
        now = self.get_clock().now()
        sec, nsec = now.seconds_nanoseconds()
        msg.stamp = Time(sec=sec, nanosec=nsec)

        # емітуємо 1‑3 цілі
        count = random.randint(1, 3)
        base_id = int(time.time() * 1000) % 100000
        for i in range(count):
            tgt = Target()
            tgt.id = base_id + i
            tgt.x = random.uniform(0.0, 10.0)
            tgt.y = random.uniform(0.0, 10.0)
            tgt.z = random.uniform(0.0, 5.0)
            tgt.confidence = random.uniform(0.6, 0.95)
            tgt.frame_id = 'world'
            msg.targets.append(tgt)

        self.publisher_.publish(msg)
        self.get_logger().info(f'📡 Published {count} target(s)')


def main(args=None):
    rclpy.init(args=args)
    node = ScanNode()
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == '__main__':
    main()
