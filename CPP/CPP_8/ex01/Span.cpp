#include "Span.hpp"

Span::Span(int n): _n(n) {
  _arr.reserve(n);
}

Span::~Span() {}

void Span::addNumber(int n) {
  if (_arr.size() >= _n) {
    throw std::runtime_error("Array is already full");
    return;
  }

  _arr.push_back(n);
}

void Span::addNumbers(std::vector<int> ar) {
  if (ar.size() + _arr.size() > _n)
    throw std::runtime_error("Too many numbers added");

  _arr.insert(_arr.end(), ar.begin(), ar.end());
}


int Span::shortestSpan() {
  if (_arr.empty() || _arr.size() == 1)
    throw std::runtime_error("Not enough numbers in array");

  int shortest = _arr.at(0);

  for (int i = 1; i < (int)_arr.size(); i++) {
    if (shortest > _arr.at(i))
      shortest = _arr.at(i);
  }

  return shortest;
}

int Span::longestSpan() {
  if (_arr.empty() || _arr.size() == 1)
    throw std::runtime_error("Not enough numbers in array");

  int longest = _arr.at(0);

  for (int i = 1; i < (int)_arr.size(); i++) {
    if (longest < _arr.at(i))
      longest = _arr.at(i);
  }

  return longest;
}

