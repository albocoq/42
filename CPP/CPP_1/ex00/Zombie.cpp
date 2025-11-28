#include "Zombie.hpp"

Zombie::~Zombie() {
    std::cout << _name << " is destroyed!" << std::endl;
}

Zombie::Zombie(): _name("Random Zombie") {}

Zombie::Zombie(std::string name): _name(name) {}

void Zombie::announce( void ) {
  std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}