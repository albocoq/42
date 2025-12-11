#include "Weapon.hpp"

HumanB::HumanB(const std::string name): _weapon(NULL), _name(name) {}

void HumanB::attack() const {
  if (_weapon->getType().empty())
    std::cout << _name << " has no weapon"  << std::endl;
  else
    std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon& weapon) {
  _weapon = &weapon;
}