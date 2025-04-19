#include "lve_pipeline.hpp"

#include <fstream>
#include <stdexcept>
#include <iostream>
namespace lve{
  LvePipeline::LvePipeline(const std::string& vertFilePath, const std::string& fragFilePath){
    createGraphicsPipeline(vertFilePath, fragFilePath);
  }

  std::vector<char> LvePipeline::readFile(const std::string& filepath){
    std::ifstream file(filepath, std::ios::ate | std::ios::binary);
    #if 0
    if(!file)
      throw std::runtime_error("Failed to open file: " + filepath + '\n');
      #endif
    size_t fileSize = static_cast<size_t>(file.tellg());
    std::vector<char> buffer(fileSize);
    file.seekg(0);
    file.read(buffer.data(), fileSize);
    file.close();
    return buffer;
  }
  void LvePipeline::createGraphicsPipeline(const std::string& vertFilePath, const std::string& fragFilePath){
    auto vertCode = readFile(vertFilePath);
    auto fragCode = readFile(fragFilePath);

    std::cout << "Vertex shader code size = " << vertCode.size() << std::endl;
    std::cout << "Frag shader code size = " << fragCode.size() << std::endl;
  }
}