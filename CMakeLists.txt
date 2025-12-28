cmake_minimum_required(VERSION 3.8)
project(hello_world_clang_format)

if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

add_executable(hello_world_publisher src/hello_world_publisher.cpp)
ament_target_dependencies(hello_world_publisher rclcpp std_msgs)

install(TARGETS
  hello_world_publisher
  DESTINATION lib/${PROJECT_NAME}
)

if(BUILD_TESTING)
  find_package(ament_cmake_clang_format REQUIRED)
  ament_clang_format()
endif()

ament_package()
