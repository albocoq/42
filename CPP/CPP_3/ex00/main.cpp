#include "ClapTrap.hpp"

int main() {
  ClapTrap bob("bob");
  ClapTrap charle("charle");

  bob.attack("charle");

  charle.takeDamage(10);

  charle.beRepaired(10);
}