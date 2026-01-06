#include "Convert.hpp"


ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string& s) {

  const std::string specials[] = {"nan", "nanf", "+inf", "+inff", "-inf", "-inff"};

  if (s.length() == 1 && !isdigit(s[0])) {
    std::cout << "char: " << s[0] << std::endl;
    std::cout << "int: " << static_cast<int>(s[0]) << std::endl;
    std::cout << "float: " <<  std::fixed << std::setprecision(1) << static_cast<float>(s[0]) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(s[0]) << std::endl;

    return;
  }

  char* end;
  double val = strtod(s.c_str(), &end);

  if (*end != '\0' && strcmp(end, "f") != 0) {
    std::cout << "Invalid Enter" << std::endl;
    return;
  }

  const size_t n_specials = sizeof(specials) / sizeof(specials[0]);
  for (size_t i = 0; i < n_specials; ++i) {
    if (s == specials[i]) {
      std::cout << "char: impossible" << std::endl;
      std::cout << "int: impossible" << std::endl;
      std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(val) << "f" << std::endl;
      std::cout << "double: " << std::fixed << std::setprecision(1) << val << std::endl;
      return;
    }
  }

  std::cout << "char: ";
  if (std::isnan(val) || std::isinf(val) || val < 0 || val > 127)
    std::cout << "impossible" << std::endl;
  else if (!isprint(val))
    std::cout << "Non displayable" << std::endl;
  else
    std::cout << static_cast<char>(val) << std::endl;

  std::cout << "int: ";
  if (val < INT_MIN || val > INT_MAX || std::isnan(val))
    std::cout << "impossible" << std::endl;
  else
    std::cout << static_cast<int>(val) << std::endl;

  std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(val) << "f" << std::endl;
  std::cout << "double: " << std::fixed << std::setprecision(1) << val << std::endl;

}

