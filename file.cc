#include <iostream>
#include <stdexcept>

#include "file.h"

/* @param [argc] The number of arguments supplied to isomer
 * @param [argv] The arguments supplied to isomer
 * @return A new File object with the proper file's contents
 * @raise [ArgumentError] If too few or many arguments were given
 */
File::File(int argv, char * argc[]) {
  if(argv == 1) throw std::invalid_argument("No file given.");
  else          throw std::invalid_argument("Too many inputs given.");
}
