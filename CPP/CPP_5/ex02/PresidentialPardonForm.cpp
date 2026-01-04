#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string const & target)
: AForm(target, 25, 5), _target(target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::action() const {
  std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}