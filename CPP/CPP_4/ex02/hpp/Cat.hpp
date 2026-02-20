#ifndef Cat_02
#define Cat_02

#include "Animal.hpp"
#include "Brain.hpp"
#include <string>
#include <iostream>

class Cat: public Animal {
  private:
    std::string _type;
    Brain* _brain;
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