#include "Materia.hpp"

Character::Character() {}

Character::Character(std::string const & name): _name(name) {
  _inventory[0] = nullptr;
  _inventory[1] = nullptr;
  _inventory[2] = nullptr;
  _inventory[3] = nullptr;
}

Character::~Character() {
  for (int i = 0; i < 4; i++)
    delete _inventory[i];
}

std::string const & Character::getName() const {
  return _name;
}

void Character::equip(AMateria* m) {
  for (int i = 0; i < 4; i++) {
    if (_inventory[i] == nullptr){
      _inventory[i] = m;
      break;
    }
  }
}

void Character::unequip(int idx) {
  if (idx < 0 || idx > 3)
    return;

  _inventory[idx] = nullptr;
}

void Character::use(int idx, ICharacter& target) {
  if (idx < 0 || idx > 3 || !_inventory[idx])
    return;

  _inventory[idx]->use(target);
}

Character::Character(Character const &other) {
  _name = other._name;

  for (int i = 0; i < 4; i++) {
    if (other._inventory[i] != nullptr)
      _inventory[i] = other._inventory[i]->clone();
    else
      _inventory[i] = nullptr;

  }
}

Character &Character::operator=(Character const &other) {
  if (this != &other) {
    _name = other._name;

    for (int i = 0; i < 4; i++) {
      delete _inventory[i];
      if (other._inventory[i] != nullptr)
        _inventory[i] = other._inventory[i]->clone();
      else
        _inventory[i] = nullptr;
    }
  }

  return *this;
}

