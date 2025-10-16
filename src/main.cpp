#include "cleaner.hPP"
#include "cxxopts.hpp"

int main(int argc, char* argv[]) {
  std::string fileExtension = "";

  cxxopts::Options options("ZZClean",  "A Basic cli tool to rid build directories of certain files.");

  options.add_options()
    ("h,help", "Help page.")
    ("r,recursive", "Search recursivly from current directory.")
    ("p,path", "Path to start search from", cxxopts::value<std::string>())
    ("e", "File extension to be deleted", cxxopts::value<std::string>()) 
  ;

  try {
    auto result = options.parse(argc, argv);

    if(result.count("e")) {
      fileExtension = result["e"].as<std::string>();
    }

    if(result.count("r")) {
      for(const auto &file : Cleaner::searchCurrentDirRecursively(fileExtension)) {
        std::cout << file << "\n";
      }

      std::cout << "Delete all [Y][N]: ";
      char confirmation;
      std::cin >> confirmation;

      switch (confirmation) {
      case 'y':case 'Y':
        Cleaner::deleteFiles(Cleaner::searchCurrentDirRecursively(fileExtension));
        std::cout << "Files Deleted!\n";
        break;

      case 'n':case 'N':
        std::cout << "Operation Cancelled!\n";
      
      default:
        break;
      }

    }

  }
  catch (const std::exception &e) {
    std::cerr << "Error parsing arguments: " << e.what() << std::endl; 
  }



  return 0;
}