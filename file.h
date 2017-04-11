#include <string>
#include <vector>

class File {
  public:
    File(int, char **);
  private:
    std::string filename;
    std::vector<std::string> contents;

    bool fileExists();
    void populateContents();

    static std::string absolutePath(std::string);
};
