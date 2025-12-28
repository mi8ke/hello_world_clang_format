# hello_world_clang_format

本プロジェクトは、**ROS 2 (ament_cmake) パッケージに `ament_clang_format` によるコードフォーマット検証を組み込み、開発環境 (VSCode) でも `.clang-format` と統一されたスタイルが自動適用されるテンプレート**です。

- 最小構成の `rclcpp` Publisher 実装
- `colcon test` による自動フォーマット検証 (`clang_format` テスト)
- VSCode 保存時自動整形のセットアップ例
- `.clang-format` は **ament_clang_format (Humble) の公式設定**を使用

---

## 📦 利用方法（テンプレとして使う場合）

1. このディレクトリをコピーし、任意のパッケージ名へ変更
2. `package.xml` の `<name>` と maintainer, description を変更
3. コードを書き始めるだけ  
　→ VSCode 保存時 & CI/colcon test で自動的に整形ルールが適用されます

---

## 🚀 Build

```bash
# 例: ROS 2 Humble / ~/ros2_ws/src に配置した場合
cd ~/ros2_ws
colcon build --packages-select hello_world_clang_format
source install/setup.bash
```

---

## ▶️ Run

```bash
ros2 run hello_world_clang_format hello_world_publisher
```

---

## 🧪 Format Test (ament_clang_format)

**コードフォーマットにズレがある場合 → TEST FAILURE になります**

```bash
colcon test --packages-select hello_world_clang_format
colcon test-result --verbose
```

手動で修正する場合：

```bash
cd ~/ros2_ws/src/hello_world_clang_format
ament_clang_format --reformat src test
```

---

## 🧰 VSCode 自動フォーマット設定

`.vscode/settings.json` により **保存時に自動整形**が有効化されています。

必要拡張：

- `ms-vscode.cpptools` (IntelliSense / CMake補助)
- `xaver.clang-format` (**clang-format 実行器**)

VSCode 側が `.clang-format` を必ず参照するための設定：

```jsonc
{
  "editor.formatOnSave": true,
  "[cpp]": {
    "editor.defaultFormatter": "xaver.clang-format"
  },
  "clang-format.style": "file",
  "C_Cpp.clang_format_style": "file",
  "clang-format.fallbackStyle": "none"
}
```

---

## 🧾 フォーマットルール (.clang-format)

本テンプレートの `.clang-format` は以下の公式定義を使用：

https://github.com/ament/ament_lint/blob/humble/ament_clang_format/ament_clang_format/configuration/.clang-format

```yaml
---
Language: Cpp
BasedOnStyle: Google

AccessModifierOffset: -2
AlignAfterOpenBracket: AlwaysBreak
BraceWrapping:
  AfterClass: true
  AfterFunction: true
  AfterNamespace: true
  AfterStruct: true
BreakBeforeBraces: Custom
ColumnLimit: 100
ConstructorInitializerIndentWidth: 0
ContinuationIndentWidth: 2
DerivePointerAlignment: false
PointerAlignment: Middle
ReflowComments: false
```

---

## 🧩 含まれる内容

```
src/
  hello_world_publisher.cpp      # 最小 rclcpp Publisher
test/
  test_hello_world.cpp           # gtest + rclcpp 起動テスト
.vscode/
  settings.json                  # VSCode 自動フォーマット設定
  extensions.json                # 推奨拡張
.clang-format                    # 公式スタイル
package.xml / CMakeLists.txt     # ament_cmake + clang_format テスト設定
```

---

## 📝 補足

このテンプレートは **"フォーマットを強制できるROS2 C++パッケージの最低限構成"** として利用できます。

- CI や GitHub Actions に `colcon test` を追加することで  
  → **PR のフォーマット違反を自動で検出**できます
- 大規模プロジェクトでもそのままコピーして適用可能です

---
