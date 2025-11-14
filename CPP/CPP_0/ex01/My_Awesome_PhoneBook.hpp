#include <string>
#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>

class Contact {
  public:
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;
};

class PhoneBook {
  public:
    Contact contact[8];
};

void addCommand(PhoneBook &phone, int &phone_size);
void searchCommand(PhoneBook phone, int phone_size);