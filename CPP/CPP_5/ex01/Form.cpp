#include "Form.hpp"

Form::Form(std::string name, int signGrade, int execGrade): _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade)
{
  if (signGrade < 1 || execGrade < 1)
    GradeTooHighException();
  else if (signGrade > 150 || execGrade > 150)
    GradeTooLowException();

  std::cout << "Form " << name << " create with sign grade: " << signGrade << " and execute grade: " << execGrade << std::endl;
}

Form::~Form() {}

const std::string Form::getName() const {
  return _name;
}

void Form::beSigned(Bureaucrat bureaucrat) {
  if (bureaucrat.getGrade() <= _signGrade)
    _signed = true;
  else
    GradeTooLowException();
}

void Form::GradeTooHighException() {
  throw std::invalid_argument("Form grade too high");
}

void Form::GradeTooLowException() {
  throw std::invalid_argument("Form grade too low");
}