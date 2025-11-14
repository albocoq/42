#include "Zombie.hpp"

int main(void) {
  Zombie *z = zombieHorde(5, "salade");

  z[0].announce();
  z[1].announce();
  z[2].announce();

  delete[] z;
}