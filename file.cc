#include <fstream>
#include <iostream>
#include <iterator>
#include <stdexcept>
#include <string>
#include <vector>
#include <unistd.h>

#include "file.h"

/* @param [argc] The number of arguments supplied to isomer
 * @param [argv] The arguments supplied to isomer
 * @return A new File object with the proper file's contents
 * @raise [invalid_argument] If too few or many arguments were given
 */
File::File(int argc, char * argv[]) {
  if(argc == 1) {
    // TODO: Support new files being created
    throw std::invalid_argument("No file given.");
  } else if(argc == 2) {
    this->filename = this->absolutePath(argv[1]);
    this->populateContents();
  } else {
    // TODO: Support multiple files being created
    throw std::invalid_argument("Too many inputs given.");
  }
}

/* @return True if the filename as-is exists, otherwise False
 */
bool File::fileExists() {
  std::ifstream file(this->filename.c_str());
  return file.good();
}

/* @effect Sets the contents based on the filename
 */
void File::populateContents() {
  if(this->fileExists()) {
    std::ifstream file(this->filename);
    std::string line;

    while(std::getline(file, line)) {
      this->contents.push_back(line);
    }
  }
}

/* @param [filename] The name of the file to get the absolute path of
 * @return The absolute path of the given filename
 */
std::string File::absolutePath(std::string filename) {
  if(filename.at(0) == '/') {
    return filename;
  } else {
    char * cwd = (char *) malloc(FILENAME_MAX * sizeof(char));
    getcwd(cwd, FILENAME_MAX);
    return std::string(cwd) + '/' + filename;
  }
}
