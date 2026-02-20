#include "hpp/WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {}

WrongAnimal::WrongAnimal(std::string type): _type(type) {
  std::cout << "WrongAnimal " << type << " has been created." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other): _type(other._type) {
  std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal() {
  std::cout << "A Wronganimal " << _type << " has been destroyed." << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) {
  std::cout << "WrongAnimal assignment operator called" << std::endl;
  if (this != &other) {
    this->_type = other._type;
  }
  return *this;
}

void WrongAnimal::setType(std::string type) {
  _type = type;
}

std::string WrongAnimal::getType() const {
  return _type;
}

void WrongAnimal::makeSound() const {
  std::cout << "GRRRRRRRRRRR" << std::endl;
}

