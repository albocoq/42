#include "Bureaucrat.hpp"

int main() {


  try {
    Bureaucrat A("carlos", 1);

    A.decrementGrade();

    std::cout << A.getName() << " new grade is " << A.getGrade() << std::endl;

    A.incrementGrade();

    std::cout << A.getName() << " new grade is " << A.getGrade() << std::endl;

    A.incrementGrade();

    std::cout << A.getName() << " new grade is " << A.getGrade() << std::endl;

  } catch (std::exception & e) {
    std::cout << e.what() << std::endl;
  }
}