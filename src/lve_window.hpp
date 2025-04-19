#pragma once

#define GLEW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <string>

namespace lve {
class LveWindow {
private:
  GLFWwindow *window;
  const int WIDTH;
  const int HEIGHT;
  std::string windowName;
public:
  LveWindow(const int& w, const int& h, const std::string name);
  ~LveWindow();
  LveWindow(const LveWindow&) = delete;
  LveWindow& operator=(const LveWindow&) = delete;

  bool shouldClose() const;
private:
  void initWindow();
};

} // namespace lve