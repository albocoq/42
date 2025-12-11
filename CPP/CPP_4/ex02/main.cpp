#include "Animal.hpp"

int main()
{
  // Animal a; // ejemplo que ya no se puede

  const Animal* animals[10];

  for (int i = 0; i < 10; i++) {
    if (i < 10 / 2)
      animals[i] = new Dog();
    else
      animals[i] = new Cat();
  }

  for (int i = 0; i < 10; i++)
    delete animals[i];

  const Animal* dog = new Dog();
  const Animal* cat = new Cat();

  std::cout << dog->getType() << " " << std::endl;
  std::cout << cat->getType() << " " << std::endl;


  cat->makeSound();
  dog->makeSound();

  delete dog;
  delete cat;

  return 0;
}
