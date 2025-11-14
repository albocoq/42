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
    friend std::ostream& operator<<(std::ostream& os, Fixed const& f);

    int getRawBits( void ) const;
    void setRawBits( int const raw );

    int toInt( void ) const;
    float toFloat( void ) const;
};