#include "polymorphism.hpp"

Cat::Cat(): _type("Cat") {
  std::cout << "A " << _type << " has been created." << std::endl;
}

Cat::~Cat() {
  std::cout << "A " << _type << " has been destroyed." << std::endl;
}

std::string Cat::getType() const {
  return _type;
}

void Cat::makeSound() const {
  std::cout << "MIAOOOOUUUU" << std::endl;
}