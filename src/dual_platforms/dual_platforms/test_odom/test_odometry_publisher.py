import rclpy
from nav_msgs.msg import Odometry
from rclpy.node import Node


class TestOdomPublisher(Node):
    def __init__(self):
        super().__init__("test_odom_publisher")
        self.publisher_ = self.create_publisher(Odometry, "odom", 10)
        self.timer = self.create_timer(0.1, self.timer_callback)
        self.t = 0.0

    def timer_callback(self):
        odom = Odometry()
        odom.header.stamp = self.get_clock().now().to_msg()
        odom.header.frame_id = "odom"
        odom.child_frame_id = "base_link"

        odom.pose.pose.position.x = self.t
        odom.pose.pose.position.y = 0.0
        odom.pose.pose.position.z = 0.0

        odom.pose.pose.orientation.x = 0.0
        odom.pose.pose.orientation.y = 0.0
        odom.pose.pose.orientation.z = 0.0
        odom.pose.pose.orientation.w = 1.0

        self.publisher_.publish(odom)
        self.t += 0.05


def main(args=None):
    rclpy.init(args=args)
    node = TestOdomPublisher()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == "__main__":
    main()
