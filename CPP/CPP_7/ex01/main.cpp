#include "iter.hpp"
#include <iostream>
#include <cctype>
#include <string>

int main() {
  std::string arr1[] = {"dsadas", "salade", "sadade", "adieux"};
  std::size_t n = sizeof(arr1) / sizeof(arr1[0]);

  for (std::size_t i = 0; i < n; ++i)
    std::cout << arr1[i] << " ";

  std::cout << "\n";

  ::iter(arr1, n, [](std::string &s) {
    // toupper pero para una palabra

    for (char &c : s)
      c = static_cast<char>(std::toupper(static_cast<unsigned char>(c)));
  });

  for (std::size_t i = 0; i < n; ++i)
    std::cout << arr1[i] << " ";

  std::cout << "\n";
}