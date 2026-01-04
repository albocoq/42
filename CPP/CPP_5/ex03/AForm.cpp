#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(std::string name, int signGrade, int execGrade): _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade)
{
  if (signGrade < 1 || execGrade < 1)
    GradeTooHighException();
  else if (signGrade > 150 || execGrade > 150)
    GradeTooLowException();

  std::cout << "AForm " << name << " create with sign grade: " << signGrade << " and execute grade: " << execGrade << std::endl;
}

AForm::~AForm() {}

int AForm::getExecGrade() const {
  return _execGrade;
}

int AForm::getSignGrade() const {
  return _signGrade;
}


std::string AForm::getName() const {
  return _name;
}

bool AForm::isSigned() const {
  if (_signed) return true;
  else return false;
}


void AForm::beSigned(Bureaucrat const &bureaucrat) {
  if (bureaucrat.getGrade() <= _signGrade)
    _signed = true;
  else
    GradeTooLowException();
}

void AForm::GradeTooHighException() {
  throw std::invalid_argument("AForm grade too high");
}

void AForm::GradeTooLowException() {
  throw std::invalid_argument("AForm grade too low");
}

void AForm::execute(Bureaucrat const & executor) const {
  if (!isSigned())
    throw std::runtime_error("Form is not signed");

  if (executor.getGrade() > _execGrade)
    throw std::runtime_error("Bureaucrat grade too low to execute");
  action();

}
