#include "PhoneBook.hpp"

void parse_text(std::string s) {
  int len_s = s.length();

  if (len_s > 10) {
    std::cout << std::setw(10) << s.substr(0, 9) + "." << "|";
  } else {
    std::cout << std::setw(10) << s << "|";
  }
}

void searchCommand(PhoneBook phone, int phone_size) {

  if (phone_size == 0) {
    std::cout << "You have no contact :(\n";
    return;
  }

  std::cout << std::setw(10) << "Index" << "|" << std::setw(10) << "First Name" << "|" << std::setw(10) << "Last Name" << "|" << std::setw(10) << "NickName" << "|" << "\n";

  for (int i = 0; i < phone_size; i++) {
    std::cout << std::setw(10) << i << "|";
    parse_text(phone.contact[i].getFirstName());
    parse_text(phone.contact[i].getLastName());
    parse_text(phone.contact[i].getNickName());
    std::cout << "\n";
  }

  std::string index;

  std::cout << "Index: ";
  std::getline(std::cin, index);
  std::stringstream ss(index);

  int idx;
  ss >> idx;
  if (idx > phone_size - 1) {
    std::cout << "This contact does not exist" << std::endl;
    return;
  }
  std::cout << "First Name: " << phone.contact[idx].getFirstName() << "\n";
  std::cout << "Last Name: " << phone.contact[idx].getLastName() << "\n";
  std::cout << "Nickname: " << phone.contact[idx].getNickName() << "\n";
  std::cout << "Phone number: " << phone.contact[idx].getPhoneNumber() << "\n";
  std::cout << "Darkest Secret: " << phone.contact[idx].getDarkestSecret() << "\n";
}