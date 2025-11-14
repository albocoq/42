#include <string>
#include <bits/stdc++.h>

class Harl {
  public:
    void complain( std::string level );

  private:
    void debug( void );
    void info( void );
    void warning( void );
    void error( void );
};


typedef void (Harl::*t_func) ( void );