#ifndef WrongAnimal_02
#define WrongAnimal_02

#include <string>
#include <iostream>

class WrongAnimal {
  protected:
    std::string _type;
  public:
    WrongAnimal();
    WrongAnimal(std::string type);
    WrongAnimal(const WrongAnimal &other);
    ~WrongAnimal();

    void setType(std::string type);
    WrongAnimal &operator=(const WrongAnimal &other);
    virtual std::string getType() const;
    virtual void makeSound() const;
};

#endif