#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat A("salade", 1000);
        std::cout << A.getGrade() << " " << A.getName() << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << e.what() << std::endl;
        return 1;
    }

    try {
        Bureaucrat A("salade", 10);
        std::cout << A.getGrade() << " " << A.getName() << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << e.what() << std::endl;
        return 1;
    }

    try {
        Bureaucrat A("salade", -10);
        std::cout << A.getGrade() << " " << A.getName() << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << e.what() << std::endl;
        return 1;
    }
}