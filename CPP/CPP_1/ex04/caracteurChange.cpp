#include "sedIsForLosers.hpp"

std::string caracteurChange(std::string line, std::string s1, std::string s2) {
  int res = -1;

  while ((res = line.find(s1, res + 1)) != std::string::npos) {
    line.erase(res, s1.length());
    line.insert(res, s2);
    res += s2.length();
  }

  return line;
}