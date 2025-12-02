#include "PhoneBook.hpp"

void Contact::setFirstName(const std::string& fn) {
    firstName = fn;
}

void Contact::setLastName(const std::string& ln) {
    lastName = ln;
}

void Contact::setNickName(const std::string& nn) {
    nickname = nn;
}

void Contact::setPhoneNumber(const std::string& pn) {
    phoneNumber = pn;
}

void Contact::setDarkestSecret(const std::string& ds) {
    darkestSecret = ds;
}

std::string Contact::getFirstName() {
    return firstName;
}

std::string Contact::getLastName() {
    return lastName;
}

std::string Contact::getNickName() {
    return nickname;
}

std::string Contact::getPhoneNumber() {
    return phoneNumber;
}

std::string Contact::getDarkestSecret() {
    return darkestSecret;
}