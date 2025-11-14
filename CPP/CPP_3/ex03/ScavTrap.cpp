#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name): ClapTrap(name) {
  std::cout << "ScavTrap " << name << " has been created." << std::endl;

  _name = name;
  _HitPoint = 100;
  _EnergyPoint = 50;
  _AttackDamage = 20;
};

ScavTrap::~ScavTrap() {
  std::cout << "ScavTrap " << _name << " has been destroyed" << std::endl;
};

void ScavTrap::attack(const std::string& target) {
  if (!_EnergyPoint || !_HitPoint)
    return;

  _EnergyPoint--;
  std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _AttackDamage << " points of damage!" << std::endl;
}


void ScavTrap::guardGate() {
  std::cout << "ScavTrap " << _name << " is now in Gate keeper mode." << std::endl;
};

