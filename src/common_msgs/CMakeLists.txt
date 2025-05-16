cmake_minimum_required(VERSION 3.5)
project(common_msgs)

# Необхідні пакети
find_package(ament_cmake REQUIRED)
find_package(std_msgs REQUIRED)
find_package(builtin_interfaces REQUIRED)
find_package(rosidl_default_generators REQUIRED)

# Генерація інтерфейсів
rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/Target.msg"
  "msg/TargetArray.msg"
  "msg/PlatformStatus.msg"
  "srv/PointAndFire.srv"
  "srv/HealthCheck.srv"
  DEPENDENCIES builtin_interfaces std_msgs
)

# Завершення
ament_package()

