#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(std::string const & target)
: AForm(target, 72, 45), _target(target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::action() const {
  std::cout << "Bzzzzzzzzzzzzzz..." << std::endl;
  int randomNumber = rand() % 2; // 0 or 1
  if (randomNumber == 1)
    std::cout << _target << " has been robotomized" << std::endl;
  else
    std::cout << "The robotomy failed" << std::endl;
}