#include "Harl.hpp"

void Harl::complain( std::string level ) {
	t_func functions[] = { &Harl::debug, &Harl::error, &Harl::info, &Harl::warning};
	std::string levels[] = {"DEBUG", "ERROR", "INFO", "WARNING"};

	int i = 0;

	while (i < 4 && levels[i].compare(level))
		i++;

	switch (i)
	{
		case 0:
			(this->*functions[0])();
			break;
		case 1:
			(this->*functions[0])();
			(this->*functions[1])();
			break;
		case 2:
			(this->*functions[0])();
			(this->*functions[1])();
			(this->*functions[2])();
			break;
		case 3:
			(this->*functions[0])();
			(this->*functions[1])();
			(this->*functions[2])();
			(this->*functions[3])();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}
}

void Harl::debug( void ) {
	std::string sentence = "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!";

	std::cout << "[DEBUG] " << sentence << std::endl;
}

void Harl::info( void ) {
	std::string sentence = "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!";

	std::cout << "[INFO] " << sentence << std::endl;
}

void Harl::warning( void ) {
	std::string sentence = "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month.";

	std::cout << "[WARNING] " << sentence << std::endl;
}

void Harl::error( void ) {
	std::string sentence = "This is unacceptable! I want to speak to the manager now.";

	std::cout << "[ERROR] " << sentence << std::endl;
}