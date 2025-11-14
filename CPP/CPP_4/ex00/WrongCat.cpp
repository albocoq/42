#include "polymorphism.hpp"

WrongCat::WrongCat(): _type("WrongCat") {
  std::cout << "A " << _type << " has been created." << std::endl;
}

WrongCat::~WrongCat() {
  std::cout << "A " << _type << " has been destroyed." << std::endl;
}

std::string WrongCat::getType() const {
  return _type;
}

void WrongCat::makeSound() const {
  std::cout << "BAAAAAAAAAAAAAAAAAAAA" << std::endl;
}