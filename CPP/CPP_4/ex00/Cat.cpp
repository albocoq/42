#include "hpp/Cat.hpp"

Cat::Cat(): _type("Cat") {
  std::cout << "A " << _type << " has been created." << std::endl;
}

Cat::~Cat() {
  std::cout << "A " << _type << " has been destroyed." << std::endl;
}

Cat::Cat(const Cat &other) {
  std::cout << "Cat copy constructor called" << std::endl;
  this->_type = other._type;
}

Cat &Cat::operator=(const Cat &other) {
  std::cout << "Cat assignment operator called" << std::endl;

  if (this != &other) {
    _type = other._type;
  }

  return *this;
}

void Cat::setType(std::string type) {
  _type = type;
}

std::string Cat::getType() const {
  return _type;
}

void Cat::makeSound() const {
  std::cout << "MIAOOOOUUUU" << std::endl;
}