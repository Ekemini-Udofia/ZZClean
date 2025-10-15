#include <iostream>
#include <vector>
#include <filesystem>
#include <fstream>


class Cleaner {
  public:
    Cleaner() = delete;

    // Searches only the current directory
    static std::vector<std::string> searchCurrentDir(std::string fileExtension) {
      std::vector<std::string> files_found;

      if(fileExtension.empty()) return files_found; // No file Extension given
      
      // Add a '.' to the front incase the user passed in sth like 'exe' instead of '.exe'
      if(fileExtension.front() != '.') fileExtension.insert(fileExtension.begin(), '.');

      try {
        for(const auto& entry : std::filesystem::directory_iterator(std::filesystem::current_path())) {
          if(!entry.is_regular_file()) continue;
          if(entry.path().extension() == fileExtension) {
            files_found.push_back(entry.path().string());
          }
        }
      }
      catch (const std::filesystem::filesystem_error &e) {
        std::cerr << "Error scanning current directory: " << e.what() << '\n';
      }


      return files_found; // returns a list of files found with the given extension in the current folder
    }

    static std::vector<std::string> searchCurrentDirRecursively(std::string fileExtension) {
     std::vector<std::string> files_found;



     return files_found; // returns a list of files found with the given extension in the current folder
    }

    // Deletes the files passed to it
    static bool deleteFiles(std::vector<std::string> files_to_delete) {
      for(auto file : files_to_delete) {
        // Remove the files one by one
        if(true /*Change this to if file could not be deleted*/) {
          return false;
        }
      }
      return true;
    }

    // Make a confirmation function?

};


// For testing
int main() {
  std::vector<std::string> list = Cleaner::searchCurrentDir(".exe");

  for(auto &i : list) std::cout << i << '\n';

  return 0;
}