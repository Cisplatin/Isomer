#include <string>
#include <vector>

class File {
  public:
    File(int, char **);
  private:
    std::string filename;
    std::vector<std::string> contents;

    void populateContents(std::string);
    std::string absolutePath(std::string);
};
