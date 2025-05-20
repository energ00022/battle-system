from setuptools import find_packages
from setuptools import setup

setup(
    name="battle_interfaces",
    version="0.0.2",
    packages=find_packages(include=("battle_interfaces", "battle_interfaces.*")),
)
