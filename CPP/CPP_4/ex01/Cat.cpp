#include "hpp/Cat.hpp"

Cat::Cat(): _type("Cat") {
  std::cout << "A " << _type << " has been created." << std::endl;
  _brain = new Brain();
}

Cat::~Cat() {
  std::cout << "A " << _type << " has been destroyed." << std::endl;
}

Cat::Cat(const Cat &other) {
  std::cout << "Copy constructor called" << std::endl;

  Animal *cat = new Cat();

  cat->setType(other._type);
}

Cat &Cat::operator=(Cat const& other) {
  std::cout << "Copy assignment operator called" << std::endl;

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