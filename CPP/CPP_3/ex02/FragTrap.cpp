#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name): ClapTrap(name) {
  std::cout << "FragTrap " << name << " has been created." << std::endl;

  _name = name;
  _HitPoint = 100;
  _EnergyPoint = 100;
  _AttackDamage = 30;
}

FragTrap::~FragTrap() {
  std::cout << "FragTrap " << _name << " has been destroyed" << std::endl;
};

void FragTrap::highFivesGuys(void) {
  std::cout << "FragTrap " << _name << " want's to hive five guys" << std::endl;
}