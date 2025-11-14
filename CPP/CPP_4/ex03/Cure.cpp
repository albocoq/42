#include "Materia.hpp"

void Cure::use(ICharacter& target) {
  std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

Cure::Cure(): AMateria("cure") {}

Cure::~Cure() {}

AMateria* Cure::clone() const {
  return new Cure();
};
