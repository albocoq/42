#include <string>
#include <iostream>
#include <cmath>

class Fixed {
  private:
    int _a;
    static const int _fract = 8;

  public:
    Fixed();
    Fixed(const int a);
    Fixed(const float a);
    Fixed(const Fixed &other);
    ~Fixed();

    Fixed &operator=(const Fixed &other);
    Fixed operator*(const Fixed &other) const;
    Fixed operator+(const Fixed &other) const;
    Fixed operator-(const Fixed &other) const;
    Fixed operator/(const Fixed &other) const;
    friend std::ostream& operator<<(std::ostream& os, Fixed const& f);

    bool operator<(Fixed const& other) const;
    bool operator>(Fixed const& other) const;
    bool operator>=(Fixed const& other) const;
    bool operator<=(Fixed const& other) const;
    bool operator==(Fixed const& other) const;
    bool operator!=(Fixed const& other) const;

    Fixed &operator++();
    Fixed operator++(int);

    static Fixed &max( Fixed &a, Fixed &b );
    static Fixed &min( Fixed &a, Fixed &b );
    static const Fixed &max( const Fixed &a, const Fixed &b );
    static const Fixed &min( const Fixed &a, const Fixed &b );

    int getRawBits( void ) const;
    void setRawBits( int const raw );

    int toInt( void ) const;
    float toFloat( void ) const;
};