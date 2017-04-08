#include <unistd.h>

int main() {
  // `read` sets c to one byte from standard input
  char c;
  while(read(STDIN_FILENO, &c, 1) == 1);
  return 0;
}
