#pragma once
#include <string>
#include <iostream>

class Bureaucrat;

class AForm
{
  private:
    const std::string _name;
    bool _signed;
    const int _signGrade;
    const int _execGrade;

  public:
    AForm(std::string name, int signGrade, int execGrade);
    virtual ~AForm() = 0;

    std::string getName() const;
    int getExecGrade() const;
    int getSignGrade() const;
    bool isSigned() const;

    void beSigned(Bureaucrat const & bureaucrat);
    void GradeTooHighException();
    void GradeTooLowException();

    void execute(Bureaucrat const & executor) const;

  protected:
    virtual void action() const = 0;
};