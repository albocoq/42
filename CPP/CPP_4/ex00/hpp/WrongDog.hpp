#ifndef WrongDog_00
#define WrongDog_00

#include <string>
#include <iostream>
#include "WrongAnimal.hpp"

class WrongDog: public WrongAnimal {
  private:
    std::string _type;
  public:
    WrongDog();
    ~WrongDog();
    WrongDog(const WrongDog &other);

    void setType(std::string type);
    WrongDog &operator=(const WrongDog &other);
    std::string getType() const;
    void makeSound() const;
};

#endif