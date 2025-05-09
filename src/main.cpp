#include "first_app.hpp"
#include <iostream>
#include <stdexcept>

int main(){
  lve::FirstApp app{};

  try{
    app.run();
  } catch(const std::exception& err){
      std::cerr << err.what() << std::endl;
      return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}