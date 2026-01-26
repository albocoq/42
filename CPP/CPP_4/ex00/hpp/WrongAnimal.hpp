#ifndef WrongAnimal_00
#define WrongAnimal_00

#include <string>
#include <iostream>

class WrongCat;
class WrongDog;

class WrongAnimal {
  protected:
    std::string _type;
  public:
    WrongAnimal();
    WrongAnimal(std::string type);
    WrongAnimal(const WrongAnimal &other);
    virtual ~WrongAnimal();

    void setType(std::string type);
    WrongAnimal &operator=(const WrongAnimal &other);
    virtual std::string getType() const;
    void makeSound() const;
};

#endif