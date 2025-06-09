import os
from glob import glob

from setuptools import find_packages, setup

package_name = "dual_platforms"

setup(
    name=package_name,
    version="0.0.1",
    packages=find_packages(include=[package_name, f"{package_name}.*"]),
    data_files=[
        ("share/ament_index/resource_index/packages", [f"resource/{package_name}"]),
        (f"share/{package_name}", ["package.xml"]),
        (
            os.path.join(f"share/{package_name}", "launch"),
            glob("dual_platforms/launch/*.py"),
        ),
        (
            os.path.join(f"share/{package_name}", "config"),
            glob("dual_platforms/config/*.yaml"),
        ),
    ],
    install_requires=["setuptools"],
    zip_safe=True,
    maintainer="Your Name",
    maintainer_email="you@example.com",
    description="Launch package for dual platforms",
    license="Apache-2.0",
    entry_points={
        "console_scripts": [
            "fake_odom_publisher = dual_platforms.fake_odom_publisher:main",
        ],
    },
)
