cmake_minimum_required(VERSION 3.8)

set(CMAKE_CXX_STANDARD 20)

# 手动指定INSTALL_RPATH, 否则
# install之后二进制文件的linker就会找不到路径
set(CMAKE_INSTALL_RPATH ${CMAKE_SOURCE_DIR}/lib)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_BUILD_TYPE Release)

project(simulate)
set(CMAKE_EXPORT_COMPILE_COMMANDS, 1)
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

add_definitions(-DMODELS_PATH="${CMAKE_SOURCE_DIR}/../models/")

find_package(ament_cmake REQUIRED)

find_package(glfw3 REQUIRED)
find_package(rclcpp REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(interface REQUIRED)

set(EIGEN3_INCLUDE_DIR "/usr/include/eigen3")

include_directories(
  include/simulate
  include/
  ../utils
  ${EIGEN3_INCLUDE_DIR}
)

aux_source_directory(src SRC)

add_executable(simulate_node
  ${SRC}
  # ../utils/orientation_tools.cpp
)

ament_target_dependencies(simulate_node
  rclcpp
  sensor_msgs
  geometry_msgs
  # quad
  interface
)

target_link_libraries(simulate_node
  ${CMAKE_SOURCE_DIR}/lib/libmujoco.so.3.1.1
  glfw
)

install(
  TARGETS simulate_node
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
