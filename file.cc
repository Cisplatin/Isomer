#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

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
    this->populateContents(std::string(argv[0]));
  } else {
    // TODO: Support multiple files being created
    throw std::invalid_argument("Too many inputs given.");
  }
}

/* @param [filename] The name of the file to read contents from
 * @effect Sets the contents and filename of the File object
 */
void File::populateContents(std::string filename) {
  this->filename = filename;
}
