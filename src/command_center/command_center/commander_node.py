#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from battle_interfaces.msg import TargetArray, Target
from battle_interfaces.srv import Pointing

class CommanderNode(Node):
    def __init__(self):
        super().__init__('commander_node')

        # список бойових платформ (namespace ↔ сервіс/топік)
        self.fire_platforms = ['fp1', 'fp3']

        # створюємо клієнти Pointing і паблішери fire_command
        self.pointing_clients = {}
        self.fire_publishers = {}
        for ns in self.fire_platforms:
            self.pointing_clients[ns] = self.create_client(
                Pointing, f'/{ns}/Pointing')
            self.fire_publishers[ns] = self.create_publisher(
                Target, f'/{ns}/fire_command', 10)

        # підписка на масив цілей
        self.subscription = self.create_subscription(
            TargetArray,
            '/target_array',
            self.target_array_callback,
            10
        )

        self.get_logger().info('Command center node started')

    def target_array_callback(self, array_msg: TargetArray):
        # якщо немає цілей — нічого не робимо
        if not array_msg.targets:
            return

        # беремо першу ціль з масиву
        target = array_msg.targets[0]
        self.get_logger().info(
            f'🎯 Got {len(array_msg.targets)} targets; ID={target.id}'
        )

        # пробуємо кожну платформу
        for ns in self.fire_platforms:
            client = self.pointing_clients[ns]
            if not client.wait_for_service(timeout_sec=0.1):
                continue  # сервіс недоступний

            # формуємо запит і чекаємо результат
            req = Pointing.Request()
            req.target = target
            future = client.call_async(req)
            rclpy.spin_until_future_complete(self, future, timeout_sec=0.3)

            # якщо платформа прийняла — публікуємо команду та виходимо
            result = future.result() if future.done() else None
            if result and result.accepted:
                self.get_logger().info(
                    f'🚀 Target {target.id} assigned to {ns}')
                self.fire_publishers[ns].publish(target)
                return

        # якщо жодна не прийняла    
        self.get_logger().warn(
            f'❌ No platform accepted target {target.id}'
        )

def main(args=None):
    rclpy.init(args=args)
    node = CommanderNode()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()
