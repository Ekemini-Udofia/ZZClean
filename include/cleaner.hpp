#ifndef INC_CLEANER_HPP_
#define INC_CLEANER_HPP_

#include <iostream>
#include <vector>
#include <filesystem>

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

      if(fileExtension.empty()) return files_found; // No file Extension given
      
      // Add a '.' to the front incase the user passed in sth like 'exe' instead of '.exe'
      if(fileExtension.front() != '.') fileExtension.insert(fileExtension.begin(), '.');

      try {
        for(const auto& entry : std::filesystem::recursive_directory_iterator(std::filesystem::current_path())) {
          if(!entry.is_regular_file()) continue;
          if(entry.path().extension() == fileExtension) {
            files_found.push_back(entry.path().string());
          }
        }
      }
      catch (const std::filesystem::filesystem_error &e) {
        std::cerr << "Error scanning current directory recursively : " << e.what() << '\n';
      }

     return files_found; // returns a list of files found with the given extension in the current folder
    }

    // Deletes the files passed to it
    static bool deleteFiles(std::vector<std::string> files_to_delete) {
      bool all_ok = true;
      for(const auto &file : files_to_delete) {
        try {
          std::error_code ec;
          if(!std::filesystem::remove(std::filesystem::path(file), ec) || ec) {
            std::cerr << "Failed to delete " << file << " (" << ec.message() << ")\n";
            all_ok = false;
          }
        }
        catch(const std::filesystem::filesystem_error &e) {
          std::cerr << "Exception deleting file " << file << " : " << e.what() << '\n';
          all_ok = false;
        }
      }
      return all_ok;
    }

    // Make a confirmation function?

};

// Make an excpetion for __FILE__(the cleaner executable itself)


#endif // INC_CLEANER_HPP_
