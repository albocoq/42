#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
  ClapTrap bob("bob");

  bob.attack("charle");
  bob.takeDamage(10);
  bob.beRepaired(10);

  ScavTrap charle("charle");

  charle.attack("bob");
  charle.takeDamage(20);
  charle.beRepaired(20);
  charle.guardGate();
}