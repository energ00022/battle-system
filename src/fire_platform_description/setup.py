from setuptools import setup

package_name = "fire_platform_description"

setup(
    name=package_name,
    version="0.0.1",
    packages=[],
    data_files=[
        # щоб пакет став видимим через ament_index
        ("share/ament_index/resource_index/packages", ["resource/" + package_name]),
        # встановлюємо package.xml
        (f"share/{package_name}", ["package.xml", "package.sh"]),
        # встановлюємо всi launch-файли (якщо вони будуть)
        # ('share/'+package_name+'/launch', ['launch/...']),
        # встановлюємо urdf
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
