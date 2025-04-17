#include "lve_window.hpp"

namespace lve{
  LveWindow::LveWindow(const int& h, const int& w, const std::string name) : WIDTH(w), HEIGHT(h), windowName(name) {
    initWindow();
  }

  LveWindow::~LveWindow(){
    glfwDestroyWindow(window);
    glfwTerminate();
  }

  void LveWindow::initWindow(){
    glfwInit();
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    window = glfwCreateWindow(WIDTH, HEIGHT, windowName.c_str(), nullptr, nullptr);
  }

  bool LveWindow::shouldClose() const{
    return glfwWindowShouldClose(window);
  }
}