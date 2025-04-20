#include "lve_pipeline.hpp"

#include <fstream>
#include <stdexcept>
#include <iostream>
namespace lve{
  LvePipeline::LvePipeline(LveDevice& device, const std::string& vertFilePath, const std::string& fragFilePath, const PipelineConfigInfo& configInfo)
  :
  lveDevice(device)
  {
    createGraphicsPipeline(vertFilePath, fragFilePath, configInfo);
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
  void LvePipeline::createGraphicsPipeline(const std::string& vertFilePath, const std::string& fragFilePath, const PipelineConfigInfo& configInfo){
    auto vertCode = readFile(vertFilePath);
    auto fragCode = readFile(fragFilePath);

    std::cout << "Vertex shader code size = " << vertCode.size() << std::endl;
    std::cout << "Frag shader code size = " << fragCode.size() << std::endl;
  }
  void LvePipeline::createShaderModule(const std::vector<char>& code, VkShaderModule* shaderModule){
    VkShaderModuleCreateInfo createInfo{};
    createInfo.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
    createInfo.codeSize = code.size();
    createInfo.pCode = reinterpret_cast<const uint32_t*>(code.data());
    if(vkCreateShaderModule(lveDevice.device(), &createInfo, nullptr, shaderModule) != VK_SUCCESS){
      throw std::runtime_error("Faild to create shader module");
    }
  }
  PipelineConfigInfo LvePipeline::defaultPipelineConfigInfo(uint32_t width, uint32_t height){
    PipelineConfigInfo configInfo{};

    return configInfo;
  } 
}