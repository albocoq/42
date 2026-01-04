#include <string>
#include "AForm.hpp"

class Intern
{
  public:
    Intern();
    ~Intern();
    AForm* makeForm(std::string name, std::string target);
};

typedef void (*t_func) ( void );
