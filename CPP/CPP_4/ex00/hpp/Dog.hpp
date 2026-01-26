#ifndef Dog_00
#define Dog_00

#include "Animal.hpp"
#include <string>
#include <iostream>

class Dog: public Animal {
  private:
    std::string _type;
  public:
    Dog();
    ~Dog();
    Dog(const Dog &other);

    void setType(std::string type);
    Dog &operator=(const Dog &other);
    std::string getType() const;
    void makeSound() const;
};

#endif