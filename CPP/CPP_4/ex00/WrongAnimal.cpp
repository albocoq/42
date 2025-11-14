#include "polymorphism.hpp"

WrongAnimal::WrongAnimal() {}

WrongAnimal::WrongAnimal(std::string type): _type(type) {
  std::cout << "WrongAnimal " << type << " has been created." << std::endl;
}

WrongAnimal::~WrongAnimal() {
  std::cout << "A Wronganimal " << _type << " has been destroyed." << std::endl;
}

std::string WrongAnimal::getType() const {
  return _type;
}

void WrongAnimal::makeSound() const {
  std::cout << "GRRRRRRRRRRR" << std::endl;
}

