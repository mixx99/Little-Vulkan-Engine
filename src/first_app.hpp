#pragma once

#include "lve_window.hpp"
#include "lve_pipeline.hpp"

namespace lve{
  class FirstApp{
    public:
    const int WIDTH = 800;
    const int HEIGHT = 600;

    void run();
    private:
      LveWindow lveWindow{WIDTH, HEIGHT, "Little Vulkan Engine"};
      LvePipeline lvePipeline{"src/shaders/simple_shader.vert.spv", "src/shaders/simple_shader.frag.spv"};
  };
}