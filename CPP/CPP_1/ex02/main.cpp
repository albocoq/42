#include <string>
#include <bits/stdc++.h>

int main(void) {
  std::string s = "HI THIS IS BRAIN";
  const char* stringPTR = s.c_str();
  std::string *stringREF = &s;

  std::cout << "Memory address of the string variable: " << &s << std::endl;
  std::cout << "Memory address held by stringPTR: " << &stringPTR << std::endl;
  std::cout << "Memory address held by stringREF: " << &stringREF << std::endl;

  std::cout << "\n";

  std::cout << "Value of the string variable: " << s << std::endl;
  std::cout << "Value pointed to by stringPTR: " << stringPTR << std::endl;
  std::cout << "Value pointed to by stringREF: " << stringREF << std::endl;
}