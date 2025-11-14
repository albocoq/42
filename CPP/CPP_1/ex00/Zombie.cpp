#include "Zombie.hpp"

Zombie::~Zombie() {
    std::cout << name << " is destroyed!" << std::endl;
}

Zombie::Zombie(std::string name) {
  this->name = name;
}

void Zombie::announce( void ) {
  std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}