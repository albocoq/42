#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {

  if (argc != 2 || !argv[1][0])
    return 1;

  std::ifstream f(argv[1]);
  if (!f.is_open()) {
    std::cout << "file does not exist or can not be open" << std::endl;
    return 1;
  }

  try {
    BitcoinExchange A;

    A.loadDatabase();

    A.processInput(f);

    
  } catch (std::exception & e) {
    std::cout << "Error: " << e.what() << std::endl;
  }
}