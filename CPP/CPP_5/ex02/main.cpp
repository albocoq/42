#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	std::srand(std::time(NULL));

	try {
		Bureaucrat signer("Alice", 140);
		Bureaucrat executor("Bob", 130);

		ShrubberyCreationForm shrub("home");

		std::cout << "-- Attempt to execute unsigned form --" << std::endl;
		executor.executeForm(shrub);

		std::cout << "\n-- Signing with Alice --" << std::endl;
		signer.signForm(shrub);

		std::cout << "\n-- Executing with Bob --" << std::endl;
		executor.executeForm(shrub);

		std::cout << "\n-- Try signing with low grade bureaucrat --" << std::endl;
		Bureaucrat low("Charlie", 150);
		ShrubberyCreationForm shrub2("garden");
		low.signForm(shrub2);

		std::cout << "\n-- RobotomyRequestForm tests --" << std::endl;
		Bureaucrat roboSigner("DrillMaster", 70);
		Bureaucrat roboExec("Operator", 40);
		RobotomyRequestForm robo("Marvin");

		roboExec.executeForm(robo);
		roboSigner.signForm(robo);

		roboExec.executeForm(robo);
		roboExec.executeForm(robo);

		std::cout << "\n-- PresidentialPardonForm tests --" << std::endl;
		Bureaucrat presSigner("PresidentAssistant", 20);
		Bureaucrat presExec("President", 3);
		PresidentialPardonForm pres("Ford");

		presExec.executeForm(pres);
		presSigner.signForm(pres);
		presExec.executeForm(pres);
	}
	catch (std::exception &e) {
		std::cerr << "Unexpected exception: " << e.what() << std::endl;
	}

	return 0;
}