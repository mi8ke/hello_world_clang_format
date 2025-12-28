#include <chrono>
#include <memory>

#include "gtest/gtest.h"
#include "rclcpp/rclcpp.hpp"

// 単純なサンプルテスト：1+1=2 を確認
TEST(SimpleMathTest, OnePlusOne) { EXPECT_EQ(1 + 1, 2); }

// ROS2 ノードが作れるかを軽く確認（起動テストのミニ版）
TEST(RclcppInitTest, InitAndShutdown)
{
  int argc = 0;
  char ** argv = nullptr;

  // 複数回 init されていたらリセットしておく
  if (rclcpp::ok()) {
    rclcpp::shutdown();
  }

  rclcpp::init(argc, argv);
  EXPECT_TRUE(rclcpp::ok());

  auto node = std::make_shared<rclcpp::Node>("test_node");
  EXPECT_NE(node, nullptr);

  rclcpp::shutdown();
  EXPECT_FALSE(rclcpp::ok());
}
