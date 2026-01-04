#include <string>
#include <iostream>

class Bureaucrat {
  private:
    std::string _name;
    int _grade;

  public:
    Bureaucrat(std::string name, int grade);
    ~Bureaucrat();
    const std::string getName() const;
    const int getGrade() const;
    void incrementGrade();
    void decrementGrade();
    void GradeTooHighException();
    void GradeTooLowException();
};


