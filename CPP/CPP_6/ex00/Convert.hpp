#include <string>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <climits>

class ScalarConverter {
  private:
    ScalarConverter();
    ~ScalarConverter();
    ScalarConverter(const ScalarConverter& other);
    ScalarConverter& operator=(const ScalarConverter& other);
  public:
    static void convert(const std::string &s);
};