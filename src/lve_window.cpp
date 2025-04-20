#include "lve_window.hpp"

#include <stdexcept>
namespace lve{
  LveWindow::LveWindow(const int& w, const int& h, const std::string name) : WIDTH(w), HEIGHT(h), windowName(name) {
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

  void LveWindow::createWindowSurface(VkInstance instance, VkSurfaceKHR* surface){
    if(glfwCreateWindowSurface(instance, window, nullptr, surface) != VK_SUCCESS)
      throw std::runtime_error("Failed to create window surface!\n");
  }

  bool LveWindow::shouldClose() const{
    return glfwWindowShouldClose(window);
  }
}