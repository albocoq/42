#include "My_Awesome_PhoneBook.hpp"

int main(void)
{
  PhoneBook phone = {};
  std::string command;
  int phone_size = 0;

  while (1) {
    command.clear();
    std::cout << "What do you want to do ? ADD | SEARCH | EXIT" << std::endl;
    std::getline(std::cin, command);

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