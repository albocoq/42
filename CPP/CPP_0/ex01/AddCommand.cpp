#include "PhoneBook.hpp"

static bool readField(const std::string &fieldName, std::string &out) {
  std::string prompt = "Please enter the " + fieldName + ": \n";
  while (true) {
    std::cout << prompt;
    if (!std::getline(std::cin, out)) {
      std::cout << "EOF. Closing the program." << std::endl;
      return false;
    }
    if (!out.empty())
      return true;
    std::cout << fieldName << " cannot be empty!\n";
  }
}


void addCommand(PhoneBook &phone, int &phone_size) {
  int copy_size = phone_size;
  static int oldest_index = 0;

  if (phone_size >= 8) {
    std::cout << "PhoneBook is full! Oldest contact will be replaced.\n";

    copy_size = oldest_index;
    oldest_index++;

    if (oldest_index >= 8)
      oldest_index = 0;
  }

  Contact &c = phone.contact[copy_size];
  std::string fn, ln, nn, pn, ds;

  if (!readField("First Name", fn)) return;
  if (!readField("Last Name", ln)) return;
  if (!readField("NickName", nn)) return;
  if (!readField("Phone Number", pn)) return;
  if (!readField("Darkest Secret", ds)) return;

  c.setFirstName(fn);
  c.setLastName(ln);
  c.setNickName(nn);
  c.setPhoneNumber(pn);
  c.setDarkestSecret(ds);

  std::cout << "User added to your contacts\n";
  if (phone_size < 8)
    phone_size++;
}