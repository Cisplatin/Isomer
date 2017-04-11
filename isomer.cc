#include <iostream>

#include "file.h"
#include "editor.h"

int main(int argc, char * argv[]) {
  File * file = new File(argc, argv);
  Editor * editor = new Editor();

  editor->enableRawMode();

  delete file;
  delete editor;

  return 0;
}
