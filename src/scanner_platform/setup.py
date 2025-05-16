from setuptools import setup

package_name = "scanner_platform"

setup(
    name=package_name,
    version="0.0.0",
    packages=["scanner_platform"],
    include_package_data=True,
    data_files=[
        (
            "share/" + package_name + "/launch",
            ["scanner_platform/launch/platform_tf.launch.py"],
        ),
        (
            "share/" + package_name + "/urdf",
            ["scanner_platform/urdf/scanner.urdf.xacro"],
        ),
    ],
    install_requires=["setuptools"],
    zip_safe=True,
    maintainer="willi energ",
    maintainer_email="willi@battle.system",
    description="Сканувальна платформа з tf і LiDAR",
    license="MIT",
    tests_require=["pytest"],
    entry_points={
        "console_scripts": [
            "scan_node = scanner_platform.scan_node:main",
        ],
    },
)
