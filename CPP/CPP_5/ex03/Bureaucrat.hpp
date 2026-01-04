#pragma once
#include <string>
#include <iostream>

class AForm;

class Bureaucrat {
  private:
    std::string _name;
    int _grade;

  public:
    Bureaucrat(std::string name, int grade);
    ~Bureaucrat();

    std::string getName() const;
    int getGrade() const;

    void incrementGrade();
    void decrementGrade();

    void GradeTooHighException();
    void GradeTooLowException();

    void signForm(AForm & form);
    void executeForm(AForm const & form) const;
};