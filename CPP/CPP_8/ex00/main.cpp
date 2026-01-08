#include "easyfind.hpp"

int main() {
  std::array<int,6> ar = {4, 2, 3, 4, 5, 6};
  int number =  4;

  try {
    int find = easyfind(ar, number);

    std::cout << "Number " << number << " was find in " << find << " place in ar" << std::endl;
  } catch (std::exception & e) {
    std::cout << e.what() << std::endl;
  }
}