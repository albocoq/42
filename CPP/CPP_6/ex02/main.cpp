#include "Base.hpp"

int main() {
  srand(time(NULL));
  for (int i = 0; i < 5; i++) {
    std::cout << "--- Test " << i << " ---" << std::endl;
    Base *b = generate();
    identify(b);
    identify(*b);
    delete b;
    std::cout << std::endl;
  }

}