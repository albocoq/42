#include "My_Awesome_PhoneBook.hpp"

void addCommand(PhoneBook &phone, int &phone_size) {
  if (phone_size >= 8) {
    std::cout << "PhoneBook is full! Oldest contact will be replaced.\n";
    phone_size = 0;
  }

  std::cout << "Please enter the First Name: \n";
  std::getline(std::cin, phone.contact[phone_size].firstName);
  while (phone.contact[phone_size].firstName.empty())
  {
    std::cout << "First name cannot be empty!\n";
    std::cout << "Please enter the First Name: \n";
    std::getline(std::cin, phone.contact[phone_size].firstName);
  }

  std::cout << "Please enter the Last Name: \n";
  std::getline(std::cin, phone.contact[phone_size].lastName);
  while (phone.contact[phone_size].lastName.empty())
  {
    std::cout << "Last name cannot be empty!\n";
    std::cout << "Please enter the Last Name: \n";
    std::getline(std::cin, phone.contact[phone_size].lastName);
  }

  std::cout << "Please enter the NickName: \n";
  std::getline(std::cin, phone.contact[phone_size].nickname);
  while (phone.contact[phone_size].nickname.empty())
  {
    std::cout << "Nickname cannot be empty!\n";
    std::cout << "Please enter the NickName: \n";
    std::getline(std::cin, phone.contact[phone_size].nickname);
  }

  std::cout << "Please enter the Phone Number: \n";
  std::getline(std::cin, phone.contact[phone_size].phoneNumber);
  while (phone.contact[phone_size].phoneNumber.empty())
  {
    std::cout << "Phone number cannot be empty!\n";
    std::cout << "Please enter the Phone number: \n";
    std::getline(std::cin, phone.contact[phone_size].phoneNumber);
  }

  std::cout << "Please enter the Darkest Secret: \n";
  std::getline(std::cin, phone.contact[phone_size].darkestSecret);
  while (phone.contact[phone_size].darkestSecret.empty()) {
    std::cout << "Darkest secret cannot be empty!\n";
    std::cout << "Please enter the Darkest secret: \n";
    std::getline(std::cin, phone.contact[phone_size].darkestSecret);
  }

  std::cout << "User added to your contacts\n";
  phone_size++;
}