#include "Animal.hpp"

Cat::Cat(): Animal("Cat") {
  std::cout << "A " << _type << " has been created." << std::endl;

  _brain = new Brain();
}

Cat::~Cat() {
  std::cout << "A " << _type << " has been destroyed." << std::endl;

  delete _brain;
}

std::string Cat::getType() const {
  return _type;
}

void Cat::makeSound() const {
  std::cout << "MIAOOOOUUUU" << std::endl;
}