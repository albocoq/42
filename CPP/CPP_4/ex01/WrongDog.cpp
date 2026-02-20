#include "hpp/WrongDog.hpp"

WrongDog::WrongDog(): _type("WrongDog") {
  std::cout << "A " << _type << " has been created." << std::endl;
}

WrongDog::~WrongDog() {
  std::cout << "A " << _type << " has been destroyed." << std::endl;
}

WrongDog::WrongDog(const WrongDog &other) {
  std::cout << "WrongDog copy constructor called" << std::endl;
  this->_type = other._type;
}

WrongDog &WrongDog::operator=(const WrongDog &other) {
  std::cout << "WrongDog assignment operator called" << std::endl;

  if (this != &other) {
    _type = other._type;
  }

  return *this;
}

void WrongDog::setType(std::string type) {
  _type = type;
}

std::string WrongDog::getType() const {
  return _type;
}

void WrongDog::makeSound() const {
  std::cout << "Miaou Miaou" << std::endl;
}