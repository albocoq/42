#include "Zombie.hpp"

int main(void) {
  Zombie *new_zombie = newZombie("Zombie 1");

  new_zombie->announce();
  new_zombie->~Zombie();

  randomChump("Zombie 2");
}