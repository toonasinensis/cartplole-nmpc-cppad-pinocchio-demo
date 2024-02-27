cmake_minimum_required(VERSION 3.8)
project(control)
set(CMAKE_EXPORT_COMPILE_COMMANDS, 1)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
# find_package(glfw3 REQUIRED)
find_package(rclcpp REQUIRED)
# find_package(sensor_msgs REQUIRED)

find_package(casadi REQUIRED)
find_package(interface REQUIRED)

# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)

set(EIGEN3_INCLUDE_DIR "/usr/include/eigen3")

include_directories(
  include/control
  include/
  ../utils
  ${EIGEN3_INCLUDE_DIR}
)
include_directories(/usr/local/include)
link_directories(/usr/local/lib)

# 手动指定INSTALL_RPATH, 否则
# install之后二进制文件的linker就会找不到路径
set(CMAKE_INSTALL_RPATH ${CMAKE_SOURCE_DIR}/lib)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_BUILD_TYPE Release)

# project(simulate)
set(CMAKE_EXPORT_COMPILE_COMMANDS, 1)
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

aux_source_directory(src SRC)
set(CMAKE_EXPORT_COMPILE_COMMANDS, 1)
add_executable(control_node
  ${SRC}
  # casadi
  # ../utils/orientation_tools.cpp
)
# set(CMAKE_EXPORT_COMPILE_COMMANDS, 1)

target_link_libraries(
  control_node
  casadi
)

ament_target_dependencies(control_node
  rclcpp
  # sensor_msgs
  # geometry_msgs
  # quad
  interface
  casadi
)


install(
  TARGETS control_node
  DESTINATION lib/${PROJECT_NAME}
)




ament_package()
