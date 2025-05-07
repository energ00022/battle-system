from setuptools import setup

package_name = 'scan_platform'

setup(
    name=package_name,
    version='0.0.1',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages', ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='willi',
    maintainer_email='willi@example.com',
    description='Scan platform node',
    license='Apache License 2.0',
    entry_points={
        'console_scripts': [
            'scanner_node = scan_platform.scan_node:main',
        ],
    },
)
