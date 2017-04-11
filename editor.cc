#include <exception>
#include <iostream>
#include <stdlib.h>
#include <unistd.h>

#include "editor.h"

/* @effect Sets terminal settings to raw mode
 * @raise [runtime_error] If the termios could not be stored.
 */
void Editor::enableRawMode() {
  if(tcgetattr(STDIN_FILENO, &original_termios) == -1) {
    throw std::runtime_error("Could not store termios settings.");
  }

  // TODO: Set settings for raw mode
  // TODO: Call atexit(disableRawMode)
  struct termios new_termios = this->original_termios;
  this->loadTermios(new_termios);
}

/* @effect Sets the terminal settings to the original termios
 * @raise [runetime_error] If the termios could not be stored.
 */
void Editor::disableRawMode() {
  this->loadTermios(this->original_termios);
}

/* @param [termios] The termios to set the terminal to
 * @effect Loads the given termios
 * @raise [runtime_error] If the termios could not be loaded.
 */
void Editor::loadTermios(struct termios &load) {
  if(tcsetattr(STDIN_FILENO, TCSAFLUSH, &load) == -1) {
    throw std::runtime_error("Could not load termios settings.");
  }
}
