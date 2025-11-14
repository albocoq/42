#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) {
  std::cout << "ClapTrad " << name << " has been created." << std::endl;

  _name = name;
  _HitPoint = 100;
  _EnergyPoint = 50;
  _AttackDamage = 20;
};

ClapTrap::~ClapTrap() {
  std::cout << "ClapTrap " << _name << " has been destroyed" << std::endl;
};

void ClapTrap::attack(const std::string& target) {
  if (!_EnergyPoint || !_HitPoint)
    return;

  _EnergyPoint--;

  std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _HitPoint << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
  _HitPoint -= amount;

  std::cout << "ClapTrap " << _name << " took " << amount << " of damage, his health is now at " << _HitPoint << " hp !" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (!_EnergyPoint || !_HitPoint)
    return;

  _EnergyPoint--;

  std::cout << "ClapTrap " << _name << " repaired him self by passing from " << _HitPoint << " to " << _HitPoint + amount << " hp !" << std::endl;

  _HitPoint += amount;
}
