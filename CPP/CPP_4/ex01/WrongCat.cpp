#include "hpp/WrongCat.hpp"

WrongCat::WrongCat(): _type("WrongCat") {
  std::cout << "A " << _type << " has been created." << std::endl;
}

WrongCat::~WrongCat() {
  std::cout << "A " << _type << " has been destroyed." << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) {
  std::cout << "WrongCat copy constructor called" << std::endl;
  this->_type = other._type;
}

WrongCat &WrongCat::operator=(const WrongCat &other) {
  std::cout << "WrongCat assignment operator called" << std::endl;

  if (this != &other) {
    _type = other._type;
  }

  return *this;
}

void WrongCat::setType(std::string type) {
  _type = type;
}

std::string WrongCat::getType() const {
  return _type;
}

void WrongCat::makeSound() const {
  std::cout << "Waouf Waouf" << std::endl;
}