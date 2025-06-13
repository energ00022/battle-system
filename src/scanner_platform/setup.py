import os
from glob import glob

from setuptools import find_packages, setup

package_name = "scanner_platform"

setup(
    name=package_name,
    version="0.0.1",
    packages=find_packages(include=[package_name, f"{package_name}.*"]),
    data_files=[
        ("share/ament_index/resource_index/packages", ["resource/" + package_name]),
        ("share/" + package_name, ["package.xml"]),
        (
            os.path.join("share", package_name, "launch"),
            glob("scanner_platform/launch/*.py"),
        ),
        (os.path.join("share", package_name, "urdf"), glob("scanner_platform/urdf/*")),
    ],
    install_requires=["setuptools", "numpy", "pcl_py", "sensor_msgs_py"],
    zip_safe=True,
    maintainer="willi",
    maintainer_email="energ00022@gmail.com",
    description="Scanner platform package for battle ROS 2 system",
    license="MIT",
    tests_require=["pytest"],
    entry_points={
        "console_scripts": [
            "scanner_node = scanner_platform.scan_node:main",
        ],
    },
)
