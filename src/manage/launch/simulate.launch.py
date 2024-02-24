import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, Shutdown
from launch_ros.actions import Node


def generate_launch_description():
    config = os.path.join(
        get_package_share_directory("manage"),
        'config',
        'simulate_cfg.yaml'
    )

    return LaunchDescription([
        Node(
            package="simulate",
            executable="simulate_node",
            name="sim",
            namespace="",
            parameters=[
                config
            ]
        ),
    
    ])
