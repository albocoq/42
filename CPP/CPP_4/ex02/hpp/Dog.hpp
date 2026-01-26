#ifndef Dog_02
#define Dog_02

#include "Animal.hpp"
#include "Brain.hpp"
#include <string>
#include <iostream>

class Dog: public Animal {
  private:
    std::string _type;
    Brain* _brain;
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