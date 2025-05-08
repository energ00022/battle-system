from setuptools import find_packages, setup

package_name = 'fire_tracker'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        (
            'share/ament_index/resource_index/packages',
            ['resource/' + package_name]
        ),
        (
            'share/' + package_name,
            ['package.xml']
        ),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='willi',
    maintainer_email='willi@todo.todo',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'tracker_node = fire_tracker.tracker_node:main',
            'tracker_node_fp3 = fire_tracker.tracker_node_fp3:main',
        ],
    },
)
