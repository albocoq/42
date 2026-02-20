#include "PmergeMe.hpp"


void PmergeMe::parseToContainers(char **argv) {

  for (int i = 0; argv[i]; i++) {
    for (int j = 0; argv[i][j]; j++) {
      char caracter = argv[i][j];

      _before.push_back(static_cast<int>(caracter));
      _after.push_back(static_cast<int>(caracter));

    }
  }
}

bool isValidInput(char **argv) {

  for (int i = 0; argv[i]; i++) {
    for (int j = 0; argv[i][j]; j++) {
      char caracter = argv[i][j];

      if (!isdigit(caracter))
        throw std::runtime_error("caracter is not a digit");
      if (caracter < 0)
        throw std::runtime_error("number is not positive");
      if (caracter > INT_MAX)
        throw std::runtime_error("number is too large");
    }
  }
}