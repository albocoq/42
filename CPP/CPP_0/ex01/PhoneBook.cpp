#include "PhoneBook.hpp"

int main(void)
{
  PhoneBook phone = {};
  std::string command;
  int phone_size = 0;

  while (1) {
    command.clear();
    std::cout << "What do you want to do ? ADD | SEARCH | EXIT" << std::endl;
    if (!std::getline(std::cin, command)) {
      std::cout << "EOF. Closing the program." << std::endl;
      break;
    }

    if (command == "ADD") {
      addCommand(phone, phone_size);
    } else if (command == "SEARCH") {
      searchCommand(phone, phone_size);
    } else if (command == "EXIT") {
      break;
    }
  }
  return 0;
}