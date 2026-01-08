#include <vector>
#include <iostream>

class Span {
  private:
    unsigned int _n;
    std::vector<int> _arr;
  public:
    Span(int n);
    ~Span();
    void addNumber(int n);
    void addNumbers(std::vector<int> ar);
    int shortestSpan();
    int longestSpan();
};