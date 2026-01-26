#ifndef Cat_00
#define Cat_00

#include "Animal.hpp"
#include <string>
#include <iostream>

class Cat: public Animal {
  private:
    std::string _type;
  public:
    Cat();
    ~Cat();
    Cat(const Cat &other);

    void setType(std::string type);
    Cat &operator=(const Cat &other);
    std::string getType() const;
    void makeSound() const;
};

#endif