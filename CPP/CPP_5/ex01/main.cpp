#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
  try {
    Bureaucrat b("carlos", 2);
    std::cout << b.getName() << " grade " << b.getGrade() << '\n';
    b.decrementGrade();
    std::cout << "after decrement: " << b.getGrade() << '\n';
    b.incrementGrade();
    std::cout << "after increment: " << b.getGrade() << '\n';
  } catch (std::exception &e) {
    std::cout << e.what() << '\n';
  }

  try {
    Bureaucrat signer("Alice", 2);
    Form formA("FormA", 2, 10);
    std::cout << "Before signing: " << formA.getName() << '\n';
    signer.signForm(formA);
  } catch (std::exception &e) {
    std::cout << "Unexpected error: " << e.what() << '\n';
  }

  try {
    Bureaucrat low("Bob", 3);
    Form formB("FormB", 2, 10);
    low.signForm(formB);
  } catch (std::exception &e) {
    std::cout << "Unexpected error: " << e.what() << '\n';
  }

  try {
    Form bad("BadForm", 0, 10);
    (void)bad;
  } catch (std::exception &e) {
    std::cout << "expected construction error: " << e.what() << '\n';
  }

  return 0;
}