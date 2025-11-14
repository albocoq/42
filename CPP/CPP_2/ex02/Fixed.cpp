#include "Fixed.hpp"

Fixed::Fixed(): _a(0) {}

Fixed::Fixed(const int a) {
  _a = a << _fract;
}

Fixed::Fixed(const float a) {
  _a = (int)(roundf(a * (1 << _fract)));
}

Fixed::Fixed(const Fixed &other) {
  this->setRawBits(other.getRawBits());
}

Fixed::~Fixed() {}

Fixed &Fixed::operator=(Fixed const& other) {
  if (this != &other) {
    _a = other._a;
  }

  return *this;
}

Fixed Fixed::operator*(const Fixed &other) const {
  Fixed result;
  long tmp = (long)this->_a * (long)other._a;

  result.setRawBits((int)(tmp >> _fract));
  return result;
}

Fixed Fixed::operator+(const Fixed &other) const {
  Fixed result;
  long tmp = (long)this->_a + (long)other._a;

  result.setRawBits((int)(tmp >> _fract));
  return result;
}

Fixed Fixed::operator-(const Fixed &other) const {
  Fixed result;
  long tmp = (long)this->_a - (long)other._a;

  result.setRawBits((int)(tmp >> _fract));
  return result;
}

Fixed Fixed::operator/(const Fixed &other) const {
  Fixed result;
  long tmp = (long)this->_a / (long)other._a;

  result.setRawBits((int)(tmp >> _fract));
  return result;
}

Fixed &Fixed::max( Fixed &a, Fixed &b ) {
  if (a.getRawBits() > b.getRawBits())
    return a;

  return b;
}

const Fixed &Fixed::max( const Fixed &a, const Fixed &b ) {
  if (a.getRawBits() > b.getRawBits())
    return a;

  return b;
}

Fixed &Fixed::min( Fixed &a, Fixed &b ) {
  if (a.getRawBits() < b.getRawBits())
    return a;

  return b;
}

const Fixed &Fixed::min( const Fixed &a, const Fixed &b ) {
  if (a.getRawBits() < b.getRawBits())
    return a;

  return b;
}

std::ostream& operator<<(std::ostream& os, Fixed const& f) {
  os << f.toFloat();

  return os;
}

bool Fixed::operator<( Fixed const& other) const {
  return this->_a < other._a;
}

bool Fixed::operator>( Fixed const& other) const {
  return this->_a > other._a;
}

bool Fixed::operator>=( Fixed const& other) const {
  return this->_a < other._a;
}

bool Fixed::operator<=( Fixed const& other) const {
  return this->_a <= other._a;
}

bool Fixed::operator==( Fixed const& other) const {
  return this->_a == other._a;
}

bool Fixed::operator!=( Fixed const& other) const {
  return this->_a != other._a;
}

Fixed &Fixed::operator++() {
  _a++;
  return *this;
}

Fixed Fixed::operator++(int) {
  Fixed tmp(*this);
  _a++;
  return tmp;
}


int Fixed::getRawBits() const {
  return _a;
}

void Fixed::setRawBits( int const raw ) {
  _a = raw;
}

int Fixed::toInt( void ) const {
  return _a >> _fract;
}

float Fixed::toFloat( void ) const {
  return (float)(_a) / (1 << _fract);
}