#ifndef EDITOR_H
#define EDITOR_H

#include <termios.h>

class Editor {
  public:
    void enableRawMode();

  private:
    struct termios original_termios;

    void disableRawMode();
    void loadTermios(struct termios&);
};

#endif
