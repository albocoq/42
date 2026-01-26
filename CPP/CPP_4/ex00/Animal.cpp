#include "hpp/Animal.hpp"

Animal::Animal() {
  std::cout << "Animal has been created." << std::endl;
}

Animal::Animal(std::string type): _type(type) {
  std::cout << "Animal " << type << " has been created." << std::endl;
}

Animal::~Animal() {
  std::cout << "A animal " << _type << " has been destroyed." << std::endl;
}

Animal::Animal(const Animal &other): _type(other._type) {
  std::cout << "Animal copy constructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &other) {
  std::cout << "Animal assignment operator called" << std::endl;

  if (this != &other) {
    _type = other._type;
  }

  return *this;
}

void Animal::setType(std::string type) {
  _type = type;
}

std::string Animal::getType() const {
  return _type;
}

void Animal::makeSound() const {
  std::cout << "GRRRRRRRRRRR" << std::endl;
}

