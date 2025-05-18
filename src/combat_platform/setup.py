import os
from glob import glob

from setuptools import find_packages, setup

package_name = "combat_platform"

setup(
    name=package_name,
    version="0.0.0",
    # Знаходимо весь Python-код у combat_platform/
    packages=find_packages(exclude=["test"]),
    # package_data тут не потрібен, бо всі ресурси ми вказуємо в data_files
    data_files=[
        # реєстрація пакета в ament_index
        ("share/ament_index/resource_index/packages", ["resource/combat_platform"]),
        # сам package.xml
        (f"share/{package_name}", ["package.xml"]),
        # всі ваші launch-файли
        (
            f"share/{package_name}/launch",
            glob(os.path.join(package_name, "launch", "*.py")),
        ),
        # URDF/XACRO-моделі
        (
            f"share/{package_name}/urdf",
            glob(os.path.join(package_name, "urdf", "*.xacro")),
        ),
        # конфігурація позицій
        (
            f"share/{package_name}/config",
            glob(os.path.join(package_name, "config", "*.yaml")),
        ),
    ],
    install_requires=["setuptools"],
    zip_safe=True,
    maintainer="willi energ",
    maintainer_email="willi@battle.system",
    description="Бойова платформа з tf і трекером",
    license="MIT",
    entry_points={
        "console_scripts": [
            "tracker_node = combat_platform.tracker_node:main",
        ],
    },
)
