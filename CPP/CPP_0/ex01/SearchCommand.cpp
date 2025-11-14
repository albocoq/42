#include "My_Awesome_PhoneBook.hpp"

std::string parse_text(std::string s) {
  int len_s = s.length();

  if (len_s > 10)
    s.substr(0, 9).append(".");
  else {
    std::cout << std::setw(10) << s << "|";
  }
  return s;
}

void searchCommand(PhoneBook phone, int phone_size) {

  if (phone_size == 0) {
    std::cout << "You have no contact :(\n";
    return;
  }

  std::cout << std::setw(10) << "Index" << "|" << std::setw(10) << "First Name" << "|" << std::setw(10) << "Last Name" << "|" << std::setw(10) << "NickName" << "|" << "\n";

  for (int i = 0; i < phone_size; i++) {
    std::cout << std::setw(10) << i << "|";
    parse_text(phone.contact[i].firstName);
    parse_text(phone.contact[i].lastName);
    parse_text(phone.contact[i].nickname);
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
  std::cout << "First Name: " << phone.contact[idx].firstName << "\n";
  std::cout << "Last Name: " << phone.contact[idx].lastName << "\n";
  std::cout << "Nickname: " << phone.contact[idx].nickname << "\n";
  std::cout << "Phone number: " << phone.contact[idx].phoneNumber << "\n";
  std::cout << "Darkest Secret: " << phone.contact[idx].darkestSecret << "\n";
}