#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat(std::string name, int grade): _name(name), _grade(grade) {
  if (grade < 1)
    GradeTooHighException();
  else if (grade > 150)
    GradeTooLowException();

  std::cout << name << ", bureaucrat grade " << grade << "." << std::endl;
}

Bureaucrat::~Bureaucrat() {}

void Bureaucrat::incrementGrade() {
  if (_grade <= 1) {
    GradeTooHighException();
    return;
  }
  _grade--;
}

void Bureaucrat::decrementGrade() {
  if (_grade >= 150) {
    GradeTooLowException();
    return;
  }
  _grade++;
}

const int Bureaucrat::getGrade() const {
  return _grade;
}

const std::string Bureaucrat::getName() const {
  return _name;
}

void Bureaucrat::GradeTooHighException() {
  throw std::invalid_argument("Grade too high");
}

void Bureaucrat::GradeTooLowException() {
  throw std::invalid_argument("Grade too low");
}