from setuptools import setup

package_name = "fire_platform_description"

setup(
    name=package_name,
    version="0.0.1",
    packages=[],
    data_files=[
        ("share/ament_index/resource_index/packages", ["resource/" + package_name]),
        (f"share/{package_name}", ["package.xml", "package.sh"]),
        (
            "share/" + package_name + "/launch",
            [
                "launch/fire_platform_tf.launch.py",
                "launch/fire_platform_state.launch.py",
            ],
        ),
        (f"share/{package_name}/urdf", ["urdf/fire_platform.urdf.xacro"]),
    ],
    install_requires=["setuptools"],
    zip_safe=True,
    maintainer="willi",
    maintainer_email="willi@example.com",
    description="URDF/Xacro description for Fire Platform",
    license="Apache License 2.0",
    entry_points={
        # тут нічого не лінкуємо
    },
)
