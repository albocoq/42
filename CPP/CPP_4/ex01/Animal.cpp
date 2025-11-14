#include "Animal.hpp"

Animal::Animal() {}

Animal::Animal(std::string type): _type(type) {
  std::cout << "Animal " << type << " has been created." << std::endl;
}

Animal::~Animal() {
  std::cout << "A animal " << _type << " has been destroyed." << std::endl;
}

std::string Animal::getType() const {
  return _type;
}

void Animal::makeSound() const {
  std::cout << "GRRRRRRRRRRR" << std::endl;
}

