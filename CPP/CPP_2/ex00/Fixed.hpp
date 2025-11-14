#include <string>
#include <iostream>

class Fixed {
  private:
    int _a;
    static const int _fract = 8;

  public:
    Fixed();
    Fixed &operator=(const Fixed &other);
    Fixed(const Fixed &other);
    ~Fixed();
    int getRawBits( void ) const;
    void setRawBits( int const raw );
};