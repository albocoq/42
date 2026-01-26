#ifndef Animal_02
#define Animal_02

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
    Animal &operator=(const Animal &other);
    virtual std::string getType() const;
    virtual void makeSound() const = 0;
};

#endif