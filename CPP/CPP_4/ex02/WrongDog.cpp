#include "hpp/WrongDog.hpp"

WrongDog::WrongDog(): _type("WrongDog") {
  std::cout << "A " << _type << " has been created." << std::endl;
}

WrongDog::~WrongDog() {
  std::cout << "A " << _type << " has been destroyed." << std::endl;
}

WrongDog::WrongDog(const WrongDog &other) {
  std::cout << "Copy constructor called" << std::endl;

  WrongDog *wrongDog = new WrongCat();

  wrongDog->setType(other._type);
}

WrongDog &WrongDog::operator=(WrongDog const& other) {
  std::cout << "Copy assignment operator called" << std::endl;

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