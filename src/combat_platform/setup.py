import os
from glob import glob

from setuptools import setup

package_name = "combat_platform"

setup(
    name=package_name,
    version="0.0.0",
    packages=[package_name],
    data_files=[
        (os.path.join("share", package_name), ["package.xml"]),
        (
            os.path.join("share", package_name, "launch"),
            glob("combat_platform/launch/*.py"),
        ),
        (
            os.path.join("share", package_name, "urdf"),
            glob("combat_platform/urdf/*.xacro"),
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
