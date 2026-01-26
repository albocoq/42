#ifndef Animal_00
#define Animal_00

#include <string>
#include <iostream>

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