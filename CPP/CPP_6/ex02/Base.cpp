#include "Base.hpp"

A::A(): Base() {}

B::B(): Base() {}

C::C(): Base() {}

A::~A() {}
B::~B() {}
C::~C() {}

Base::~Base() {}

Base* generate(void) {
  int randomNum = rand() % 3;

  std::cout << "random: " << randomNum << std::endl;

  switch (randomNum)
  {
    case 0:
      return new A();
      break;

    case 1:
      return new B();
      break;

    case 2:
      return new C();
      break;

    default:
      std::cout << "Error random num" << std::endl;
      break;
  }
  return new A();
}

void identify(Base* p) {
  if (dynamic_cast<A*>(p) != NULL) {
    std::cout << "A" << std::endl;
  } else if (dynamic_cast<B*>(p) != NULL) {
    std::cout << "B" << std::endl;
  } else if (dynamic_cast<C*>(p) != NULL) {
    std::cout << "C" << std::endl;
  }
}

void identify(Base& p) {

  try {
    dynamic_cast<A&>(p);

    std::cout << "A" << std::endl;
    return;
  } catch (std::exception & e) {

  }

  try {
    dynamic_cast<B&>(p);

    std::cout << "B" << std::endl;
    return;

  } catch (std::exception & e) {

  }

  try {
    dynamic_cast<C&>(p);

    std::cout << "C" << std::endl;
    return;
  } catch (std::exception & e) {

  }
}