#include "Weapon.hpp"

HumanA::HumanA(const std::string& name, Weapon& weapon): _weapon(weapon), _name(name) {}

void HumanA::attack() {
  Weapon weapon = _weapon;
  std::string name = _name;
  std::string weapon_type = weapon.getType();

  std::cout << name << " attacks with their " << weapon_type << std::endl;
}
