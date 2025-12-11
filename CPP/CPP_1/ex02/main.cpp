#include <string>
#include <bits/stdc++.h>

int main(void) {
  std::string s = "HI THIS IS BRAIN";
  std::string *stringPTR = &s;
  std::string &stringREF = s;

  std::cout << "Memory address of the string variable: " << &s << std::endl;
  std::cout << "Memory address held by stringPTR: " << stringPTR << std::endl;
  std::cout << "Memory address held by stringREF: " << &stringREF << std::endl;

  std::cout << "\n";

  s = "salade";

  std::cout << "Value of the string variable: " << s << std::endl;
  std::cout << "Value pointed to by stringPTR: " << *stringPTR << std::endl;
  std::cout << "Value pointed to by stringREF: " << stringREF << std::endl;
}