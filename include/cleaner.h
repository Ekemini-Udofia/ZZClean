#include <vector>
#include <iostream>

class Cleaner{
  public:
    Cleaner() = delete;

    static std::vector<std::string>  searchCurrentDir(std::string fileExtension);

    static std::vector<std::string> searchCurrentDirRecursively(std::string fileExtension);

    static bool deleteFiles(std::vector<std::string> files_to_delete);

};