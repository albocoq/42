#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}

Intern::~Intern() {}

AForm* Intern::makeForm(std::string name, std::string target) {
  std::string forms[] = {"robotomy request", "presidential pardon", "shrubbery creation"};

  int i = 0;

	while (i < 4 && forms[i].compare(name))
		i++;

  if (i < 3)
    std::cout << "Intern creates " << target << std::endl;

  switch (i)
  {
    case 0:
      return new RobotomyRequestForm(target);
      break;
    case 1:
      return new PresidentialPardonForm(target);
      break;
    case 2:
      return new ShrubberyCreationForm(target);
      break;
    default:
      throw std::invalid_argument("Intern::makeForm: unknown form name");
      break;
  }
}