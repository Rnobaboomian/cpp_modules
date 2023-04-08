#include "Phonebook.hpp"

Contact::Contact(){}

Contact::~Contact(){}



std::string Contact::getFirstname() {
    return this->name;
}
std::string Contact::getLastname() {
    return this->last_name;
}
std::string Contact::getNickname() {
    return this->nickname;
}
std::string Contact::getPhoneNumber() {
    return this->phone_number;
}
std::string Contact::getSecret() {
    return this->darkest_secret;
}

void        Contact::setFirstname(std::string fname) {
    this->name = fname;
}
void        Contact::setLastname(std::string lname) {
    this->last_name = lname;
}
void        Contact::setPhoneNumber(std::string nb) {
    this->phone_number = nb;
}
void        Contact::setNickname(std::string nick) {
   this-> nickname = nick;
}
void        Contact::setSecret(std::string secret) {
    this->darkest_secret = secret;
}