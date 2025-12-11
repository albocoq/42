#include "polymorphism.hpp"

int main()
{
  const Animal* random = new Animal();
  const Animal* dog = new Dog();
  const Animal* cat = new Cat();
  const WrongAnimal* wrongCat = new WrongCat();


  std::cout << dog->getType() << " " << std::endl;
  std::cout << cat->getType() << " " << std::endl;
  std::cout << wrongCat->getType() << " " << std::endl;

  cat->makeSound();
  dog->makeSound();
  random->makeSound();
  wrongCat->makeSound();

  delete random;
  delete dog;
  delete cat;
  delete wrongCat;
}
