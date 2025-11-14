#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name) {

  _HitPoint = FragTrap::_HitPoint;
  _EnergyPoint = ScavTrap::_EnergyPoint;
  _AttackDamage = FragTrap::_AttackDamage;
}

void DiamondTrap::attack(const std::string& target) {
  ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() {
  std::cout << "both names: " << _name << " and " << ClapTrap::_name << std::endl;
}

DiamondTrap::~DiamondTrap() {
  std::cout << "DiamondTrap " << _name << " has been destroyed" << std::endl;
};
