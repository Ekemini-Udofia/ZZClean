#include <string>
#include "cleaner.h"
#include "cxxopts.hpp"

int main(int argc, char* argv[]) {

  cxxopts::Options options("ZZClean",  "A Basic cli tool to rid build directories of certain files.");

  options.add_options()
  ("-r,recursive", "Delete from all folder and sub folders within current directory") // a bool parameter
  ("-f,force", "Force Remove")
  ("-e,extension", "File extension", cxxopts::value<std::string>())
  ("-h,help", "Help")
  ;

  auto result = options.parse(argc, argv);


  return 0;
}