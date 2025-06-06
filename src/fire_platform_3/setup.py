from setuptools import setup

package_name = "fire_platform_3"

setup(
    name=package_name,
    version="0.0.1",
    packages=[package_name],
    data_files=[
        ("share/ament_index/resource_index/packages", ["resource/" + package_name]),
        ("share/" + package_name, ["package.xml"]),
        ("share/" + package_name + "/launch", ["launch/fire_platform_launch.py"]),
        # ("share/" + package_name + "/urdf", ["urdf/fire_platform.urdf.xacro"]),
    ],
    install_requires=["setuptools"],
    zip_safe=True,
    maintainer="willi",
    maintainer_email="willi@example.com",
    description="Fire platform 3 node",
    license="Apache License 2.0",
    entry_points={
        "console_scripts": [
            "fire_node = fire_platform_3.fire_node:main",
            "aiming_node = fire_platform_3.aiming_node:main",
            "test_tf_target = test.test_tf_target:main",
        ],
    },
)
