#include <string>
#include <iostream>
#include "Brain.hpp"

class Animal {
  protected:
    std::string _type;
  public:
    Animal();
    Animal(std::string type);
    ~Animal();
    virtual std::string getType() const;
    virtual void makeSound() const;
};

class Dog: public Animal {
  private:
    std::string _type;
  public:
    Dog();
    ~Dog();
    std::string getType() const;
    void makeSound() const;
};

class Cat: public Animal {
  private:
    std::string _type;
  public:
    Cat();
    ~Cat();
    std::string getType() const;
    void makeSound() const;
};

class WrongAnimal {
  protected:
    std::string _type;
  public:
    WrongAnimal();
    WrongAnimal(std::string type);
    ~WrongAnimal();
    virtual std::string getType() const;
    virtual void makeSound() const;
};

class WrongCat: public WrongAnimal {
  private:
    std::string _type;
  public:
    WrongCat();
    ~WrongCat();
    std::string getType() const;
    void makeSound() const;
};