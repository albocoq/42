#include "polymorphism.hpp"

Dog::Dog(): _type("Dog") {
  std::cout << "A " << _type << " has been created." << std::endl;
}

Dog::~Dog() {
  std::cout << "A " << _type << " has been destroyed." << std::endl;
}

std::string Dog::getType() const {
  return _type;
}

void Dog::makeSound() const {
  std::cout << "WOAFFFFFF" << std::endl;
}
