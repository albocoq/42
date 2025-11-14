#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main() {
  ClapTrap bob("bob");

  bob.attack("charle");
  bob.takeDamage(10);
  bob.beRepaired(10);

  std::cout << "\n";

  ScavTrap charle("charle");

  charle.attack("bob");
  charle.takeDamage(20);
  charle.beRepaired(20);
  charle.guardGate();

  std::cout << "\n";

  FragTrap paul("paul");
  paul.highFivesGuys();

  std::cout << "\n";

  DiamondTrap salade("salade");
  salade.whoAmI();

  std::cout << "\n";
}