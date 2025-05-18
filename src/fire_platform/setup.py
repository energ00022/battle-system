from setuptools import setup

package_name = "fire_platform"

setup(
    name=package_name,
    version="0.0.0",
    packages=[package_name],
    data_files=[
        ("share/ament_index/resource_index/packages", ["resource/" + package_name]),
        ("share/" + package_name, ["package.xml"]),
        ("share/" + package_name + "/launch", ["launch/platform_tf.launch.py"]),
        ("share/" + package_name + "/urdf", ["urdf/dummy.urdf.xacro"]),
    ],
    install_requires=["setuptools"],
    zip_safe=True,
    maintainer="willi",
    maintainer_email="willi@todo.todo",
    description="Fire module node",
    license="TODO: License declaration",
    tests_require=["pytest"],
    entry_points={
        "console_scripts": [
            "fire_node = fire_platform.fire_node:main",
        ],
    },
)
