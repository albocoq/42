#include "hpp/Dog.hpp"

Dog::Dog(): _type("Dog") {
  std::cout << "A " << _type << " has been created." << std::endl;
  _brain = new Brain();
}

Dog::~Dog() {
  std::cout << "A " << _type << " has been destroyed." << std::endl;
}

Dog::Dog(const Dog &other) {
  std::cout << "Dog copy constructor called" << std::endl;
  this->_type = other._type;
}

Dog &Dog::operator=(const Dog &other) {
  std::cout << "Copy assignment operator called" << std::endl;

  if (this != &other) {
    _type = other._type;
  }

  return *this;
}

void Dog::setType(std::string type) {
  _type = type;
}

std::string Dog::getType() const {
  return _type;
}

void Dog::makeSound() const {
  std::cout << "WOAFFFFFF" << std::endl;
}
