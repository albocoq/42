#ifndef Brain_02
#define Brain_02

#include <string>
#include <iostream>

class Brain {
  private:
    std::string ideas[100];
  public:
    Brain();
    Brain(const Brain &other);
    ~Brain();
    Brain &operator=(const Brain &other);
};

#endif