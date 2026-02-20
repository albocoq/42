#include "hpp/Animal.hpp"
#include "hpp/Dog.hpp"
#include "hpp/Cat.hpp"
#include "hpp/WrongAnimal.hpp"
#include "hpp/WrongCat.hpp"
#include "hpp/WrongDog.hpp"

int main()
{
  const Animal* random = new Animal();
  const Animal* dog = new Dog();
  const Animal* cat = new Cat();
  const WrongAnimal* wrongCat = new WrongCat();
  const WrongAnimal* wrongDog = new WrongDog();


  std::cout << dog->getType() << " " << std::endl;
  std::cout << cat->getType() << " " << std::endl;
  std::cout << wrongCat->getType() << " " << std::endl;
  std::cout << wrongDog->getType() << " " << std::endl;

  cat->makeSound();
  dog->makeSound();
  random->makeSound();
  wrongCat->makeSound();

  delete random;
  delete dog;
  delete cat;
  delete wrongCat;
}
