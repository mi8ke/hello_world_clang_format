# hello_world_clang_format

Minimal ROS 2 (rclcpp) publisher package that integrates `ament_clang_format`
and VSCode clang-format settings.

## Build

```bash
# 例: ROS 2 Humble, ~/ros2_ws/src 以下に配置した場合
cd ~/ros2_ws
colcon build --packages-select hello_world_clang_format
source install/setup.bash
```

## Run

```bash
ros2 run hello_world_clang_format hello_world_publisher
```

## ament_clang_format チェック

```bash
colcon test --packages-select hello_world_clang_format
```

## VSCode

`.vscode/settings.json` で

- 保存時に自動フォーマット
- `.clang-format` をスタイルとして使用

する設定になっています。拡張機能として

- `ms-vscode.cpptools`
- `xaver.clang-format`

を入れてください。
