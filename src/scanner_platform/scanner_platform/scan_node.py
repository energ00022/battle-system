#!/usr/bin/env python3

import math
import threading

import numpy as np
import pcl  # pcl_py
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import LaserScan
from std_msgs.msg import Float64

from battle_interfaces.msg import Target, TargetArray


class ScannerNode(Node):
    def __init__(self):
        super().__init__("scanner_node")

        # ПУБЛІКАТОР TargetArray
        self.target_pub = self.create_publisher(TargetArray, "/target_array", 10)

        # ПІДПИСКИ НА ДВА ГОРИЗОНТАЛЬНІ LIDAR
        self.scan_h1_sub = self.create_subscription(
            LaserScan, "/scanner/scan_h1", self.scan_h1_callback, 10
        )
        self.scan_h2_sub = self.create_subscription(
            LaserScan, "/scanner/scan_h2", self.scan_h2_callback, 10
        )

        # ПІДПИСКА НА TILT
        self.tilt_sub = self.create_subscription(
            Float64, "/scanner/tilt_angle", self.tilt_callback, 10
        )

        # БУФЕРИ ДАНИХ
        self.lock = threading.Lock()
        self.h1_data = None
        self.h2_data = None
        self.tilt_angle = None

        # Лічильник ID
        self.next_id = 0

        # Таймер 5 Hz
        self.create_timer(0.2, self.timer_callback)

        self.get_logger().info("🔍 Scanner node started (PCL pipeline, 2×70° + tilt)")

    def scan_h1_callback(self, msg: LaserScan):
        with self.lock:
            self.h1_data = msg

    def scan_h2_callback(self, msg: LaserScan):
        with self.lock:
            self.h2_data = msg

    def tilt_callback(self, msg: Float64):
        with self.lock:
            # обмежуємо ±0.9599 rad (~±55°)
            t = msg.data
            self.tilt_angle = max(min(t, 0.9599), -0.9599)

    def timer_callback(self):
        with self.lock:
            h1, h2, tilt = self.h1_data, self.h2_data, self.tilt_angle

        if h1 is None or h2 is None or tilt is None:
            return

        # 1) LASERSCAN → numpy (x,y,z) в локальній горизонталі
        pts_h1 = self.laserscan_to_points(h1, offset_yaw=-0.610)
        pts_h2 = self.laserscan_to_points(h2, offset_yaw=+0.610)
        cloud_pts = np.vstack((pts_h1, pts_h2))

        # 2) Накладення tilt (поворот навколо Y)
        ct, st = math.cos(tilt), math.sin(tilt)
        R = np.array([[ct, 0, st], [0, 1, 0], [-st, 0, ct]], dtype=np.float32)
        cloud_rot = cloud_pts.dot(R.T)

        # 3) numpy → pcl.PointCloud
        pcl_cloud = pcl.PointCloud(np.array(cloud_rot, dtype=np.float32))

        # 4) Voxel Grid Downsample
        vox = pcl_cloud.make_voxel_grid_filter()
        vox.set_leaf_size(0.05, 0.05, 0.05)
        cloud_down = vox.filter()

        # 5) GROUND REMOVAL — ВИМКНЕНО
        cloud_no_ground = cloud_down

        # 6) Euclidean clustering
        tree = cloud_no_ground.make_kdtree()
        ec = cloud_no_ground.make_EuclideanClusterExtraction()
        ec.set_ClusterTolerance(0.1)
        ec.set_MinClusterSize(50)
        ec.set_MaxClusterSize(50000)
        ec.set_SearchMethod(tree)
        clusters = ec.Extract()

        self.get_logger().info(f"Found {len(clusters)} clusters")

        # 7) Формуємо і публікуємо TargetArray
        targ_arr = TargetArray()
        targ_arr.stamp = self.get_clock().now().to_msg()
        targ_arr.frame_id = "map"

        for idx_list in clusters:
            pts = cloud_no_ground.extract(idx_list).to_array()
            centroid = np.mean(pts, axis=0)
            t = Target()
            t.id = self.next_id
            t.x, t.y, t.z = map(float, centroid)
            t.confidence = 1.0
            t.frame_id = "map"
            targ_arr.targets.append(t)
            self.next_id += 1

        if targ_arr.targets:
            self.target_pub.publish(targ_arr)
            self.get_logger().info(f"Published {len(targ_arr.targets)} targets")

    def laserscan_to_points(self, scan: LaserScan, offset_yaw: float):
        # Робимо масив значень так, щоб rng.size == count of ranges
        rng = np.array(scan.ranges, dtype=np.float32)
        ang = (
            scan.angle_min
            + np.arange(rng.size, dtype=np.float32) * scan.angle_increment
        )

        valid = (rng >= scan.range_min) & (rng <= scan.range_max)
        rng = rng[valid]
        ang = ang[valid] + offset_yaw

        x = rng * np.cos(ang)
        y = rng * np.sin(ang)
        z = np.zeros_like(x)
        return np.vstack((x, y, z)).T


def main(args=None):
    rclpy.init(args=args)
    node = ScannerNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    node.destroy_node()
    rclpy.shutdown()


if __name__ == "__main__":
    main()
