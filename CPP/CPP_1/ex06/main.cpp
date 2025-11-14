#include "Harl.hpp"

int main(int argc, char **argv) {
  if (argc != 2 || !argv[1][0]) {
    std::cout << "Must look like this: ./harlFilter 'STATE' " << std::endl;
    return 1;
  }
  Harl harl;

  harl.complain(argv[1]);
  return 0;
}