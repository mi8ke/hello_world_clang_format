cmake_minimum_required(VERSION 3.8)
project(hello_world_clang_format)

if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

# -----------------------------
# メインの publisher ノード
# -----------------------------
add_executable(hello_world_publisher src/hello_world_publisher.cpp)
ament_target_dependencies(hello_world_publisher
  rclcpp
  std_msgs
)

install(TARGETS
  hello_world_publisher
  DESTINATION lib/${PROJECT_NAME}
)

# -----------------------------
# テスト設定
# -----------------------------
if(BUILD_TESTING)
  # フォーマットチェック
  find_package(ament_cmake_clang_format REQUIRED)
  ament_clang_format()

  # gtest
  find_package(ament_cmake_gtest REQUIRED)

  ament_add_gtest(test_hello_world
    test/test_hello_world.cpp
  )

  if(TARGET test_hello_world)
    # ここで rclcpp への依存を宣言すると、
    # インクルードパスやリンクオプションが自動で入る
    ament_target_dependencies(test_hello_world
      rclcpp
    )
  endif()
endif()

ament_package()
