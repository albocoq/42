#include <string>
#include "Bureaucrat.hpp"
#include <iostream>

class Form
{
  private:
    const std::string _name;
    bool _signed;
    const int _signGrade;
    const int _execGrade;

  public:
    Form(std::string name, int signGrade, int execGrade);
    ~Form();
    const std::string getName() const;
    void beSigned(Bureaucrat bureaucrat);
    void GradeTooHighException();
    void GradeTooLowException();
};

