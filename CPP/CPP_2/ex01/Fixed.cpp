#include "Fixed.hpp"

Fixed::Fixed(): _a(0) {
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int a) {
  std::cout << "Int constructor called" << std::endl;

  _a = a << _fract;
}

Fixed::Fixed(const float a) {
  std::cout << "Float constructor called" << std::endl;

  _a = (int)(roundf(a * (1 << _fract)));
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

std::ostream& operator<<(std::ostream& os, Fixed const& f) {
  os << f.toFloat();

  return os;
}

int Fixed::getRawBits() const {
  std::cout << "getRawBits member function called" << std::endl;

  return _a;
}

void Fixed::setRawBits( int const raw ) {
  std::cout << "setRawBits member function called" << std::endl;

  _a = raw;
}

int Fixed::toInt( void ) const {
  return _a >> _fract;
}

float Fixed::toFloat( void ) const {
  return (float)(_a) / (1 << _fract);
}