#include "Materia.hpp"

Character::Character(): _name("random character") {
  _inventory[0] = NULL;
  _inventory[1] = NULL;
  _inventory[2] = NULL;
  _inventory[3] = NULL;
}

Character::Character(std::string const & name): _name(name) {
  _inventory[0] = NULL;
  _inventory[1] = NULL;
  _inventory[2] = NULL;
  _inventory[3] = NULL;
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
    if (_inventory[i] == NULL){
      _inventory[i] = m;
      break;
    }
  }
}

void Character::unequip(int idx) {
  if (idx < 0 || idx > 3)
    return;

  _inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) {
  if (idx < 0 || idx > 3 || !_inventory[idx])
    return;

  _inventory[idx]->use(target);
}

Character::Character(Character const &other) {
  _name = other._name;

  for (int i = 0; i < 4; i++) {
    if (other._inventory[i] != NULL)
      _inventory[i] = other._inventory[i]->clone();
    else
      _inventory[i] = NULL;

  }
}

Character &Character::operator=(Character const &other) {
  if (this != &other) {
    _name = other._name;

    for (int i = 0; i < 4; i++) {
      delete _inventory[i];
      if (other._inventory[i] != NULL)
        _inventory[i] = other._inventory[i]->clone();
      else
        _inventory[i] = NULL;
    }
  }

  return *this;
}

