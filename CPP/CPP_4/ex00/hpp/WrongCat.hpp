#ifndef WrongCat_00
#define WrongCat_00

#include <string>
#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal {
  private:
    std::string _type;
  public:
    WrongCat();
    ~WrongCat();
    WrongCat(const WrongCat &other);

    void setType(std::string type);
    WrongCat &operator=(const WrongCat &other);
    std::string getType() const;
    void makeSound() const;
};

#endif