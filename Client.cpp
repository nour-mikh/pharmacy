#include "Client.h"
#include <iostream>

Client::Client(int id, std::string n, std::string mail, std::string addr, std::string dob,
               std::string phone)
    : Person(id, n, mail, addr, dob), phoneNumber(phone) {}

void Client::displayInfo() const {
    Person::displayInfo();
    std::cout << "Phone Number: " << phoneNumber << std::endl;
}

std::string Client::getPhoneNumber() const {
    return phoneNumber;
}

std::ostream& operator<<(std::ostream& os, const Client& c) {
    os << static_cast<const Person&>(c) << "\n"
       << "Phone Number: " << c.phoneNumber;
    return os;
}

std::istream& operator>>(std::istream& is, Client& c) {
    is >> static_cast<Person&>(c);
    std::cout << "Enter Phone Number: ";
    std::getline(is >> std::ws, c.phoneNumber);
    return is;
}
