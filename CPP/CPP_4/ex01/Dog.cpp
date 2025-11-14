#include "Animal.hpp"

Dog::Dog(): _type("Dog") {
  std::cout << "A " << _type << " has been created." << std::endl;

  _brain = new Brain();
}

Dog::~Dog() {
  std::cout << "A " << _type << " has been destroyed." << std::endl;

  delete _brain;
}

std::string Dog::getType() const {
  return _type;
}

void Dog::makeSound() const {
  std::cout << "WOAFFFFFF" << std::endl;
}
