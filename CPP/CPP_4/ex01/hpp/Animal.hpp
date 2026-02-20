#ifndef Animal_01
#define Animal_01

#include <string>
#include <iostream>
#include "Brain.hpp"

class Dog;
class Cat;

class Animal {
  protected:
    std::string _type;
  public:
    Animal();
    Animal(std::string type);
    Animal(const Animal &other);
    virtual ~Animal();

    void setType(std::string type);
    Animal &operator=(const Animal &other);
    virtual std::string getType() const;
    virtual void makeSound() const;
};

#endif