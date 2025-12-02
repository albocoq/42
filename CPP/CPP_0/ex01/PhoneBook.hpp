#include <string>
#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>

class Contact {
  private:
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;
  public:
    void setFirstName(const std::string& fn);
    void setLastName(const std::string& ln);
    void setNickName(const std::string& nn);
    void setPhoneNumber(const std::string& pn);
    void setDarkestSecret(const std::string& ds);

    std::string getFirstName();
    std::string getLastName();
    std::string getNickName();
    std::string getPhoneNumber();
    std::string getDarkestSecret();

};

class PhoneBook {
  public:
    Contact contact[8];
};

void addCommand(PhoneBook &phone, int &phone_size);
void searchCommand(PhoneBook phone, int phone_size);