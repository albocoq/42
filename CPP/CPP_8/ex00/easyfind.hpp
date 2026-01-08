#include <iostream>
#include <array>

template <typename T> int easyfind(T ar, int n) {


  for (int i = 0; ar.size() > i; ++i) {
    if (ar.at(i) == n) {
      return i;
    }
  }
  throw std::runtime_error( "Number was not found int array");
};