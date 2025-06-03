import math

import rclpy
from geometry_msgs.msg import PointStamped
from rclpy.node import Node
from tf2_geometry_msgs import do_transform_point
from tf2_ros import Buffer, TransformListener

from battle_interfaces.msg import AimVector


class AimingNode(Node):
    def __init__(self):
        super().__init__("aiming_node")

        self.declare_parameter("target_topic", "/target_point")
        target_topic = (
            self.get_parameter("target_topic").get_parameter_value().string_value
        )

        self.subscription = self.create_subscription(
            PointStamped, target_topic, self.target_callback, 10
        )

        self.aim_publisher = self.create_publisher(AimVector, "aim_vector", 10)

        self.tf_buffer = Buffer()
        self.tf_listener = TransformListener(self.tf_buffer, self)

        self.get_logger().info("Aiming Node started.")

    def target_callback(self, msg: PointStamped):
        try:
            namespace = self.get_namespace().lstrip("/")
            target_frame = namespace + "/base_link"

            transform = self.tf_buffer.lookup_transform(
                target_frame, msg.header.frame_id, rclpy.time.Time()
            )

            target_in_base = do_transform_point(msg, transform)

            x = target_in_base.point.x
            y = target_in_base.point.y

            angle = math.atan2(y, x)
            distance = math.hypot(x, y)

            aim_msg = AimVector()
            aim_msg.angle = angle
            aim_msg.distance = distance

            self.aim_publisher.publish(aim_msg)

            self.get_logger().info(
                f"Aim angle: {math.degrees(angle):.2f}°, Distance: {distance:.2f}m"
            )

        except Exception as e:
            self.get_logger().warn(f"Failed to transform target point: {e}")


def main(args=None):
    rclpy.init(args=args)
    node = AimingNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == "__main__":
    main()
