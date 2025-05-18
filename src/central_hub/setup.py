import os
from glob import glob

from setuptools import find_packages, setup

package_name = "central_hub"

setup(
    name=package_name,
    version="0.0.0",
    packages=find_packages(exclude=["test"]),
    data_files=[
        # реєструємо ресурс
        ("share/ament_index/resource_index/packages", ["resource/central_hub"]),
        # основний package.xml
        (f"share/{package_name}", ["package.xml"]),
        # всі ваші launch-файли з launch/
        (
            os.path.join("share", package_name, "launch"),
            glob(os.path.join("launch", "*.launch.py")),
        ),
    ],
    install_requires=["setuptools"],
    zip_safe=True,
    maintainer="willi",
    maintainer_email="energ00022@gmail.com",
    description="Командний центр Battle Platform System",
    license="MIT",
    entry_points={
        "console_scripts": [
            "commander_node = central_hub.commander_node:main",
        ],
    },
)
