#include "Fixed.hpp"

Fixed::Fixed(): _a(0) {
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) {
  std::cout << "Copy constructor called" << std::endl;
  this->setRawBits(other.getRawBits());
}

Fixed::~Fixed() {
  std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(Fixed const& other) {
  std::cout << "Copy assignment operator called" << std::endl;
  if (this != &other) {
    _a = other._a;
  }

  return *this;
}


int Fixed::getRawBits() const {
  std::cout << "getRawBits member function called" << std::endl;

  return _a;
}

void Fixed::setRawBits( int const raw ) {
  std::cout << "setRawBits member function called" << std::endl;

  _a = raw;
}