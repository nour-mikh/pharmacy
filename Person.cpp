#include "Person.h"
#include <iostream>

Person::Person(int id, std::string n, std::string mail, std::string addr, std::string dob)
    : personID(id), name(n), email(mail), address(addr), dateOfBirth(dob) {}

void Person::displayInfo() const {
    std::cout << "Person ID: " << personID << "\n"
              << "Name: " << name << "\n"
              << "Email: " << email << "\n"
              << "Address: " << address << "\n"
              << "Date of Birth: " << dateOfBirth << std::endl;
}

int Person::getPersonID() const { return personID; }
std::string Person::getName() const { return name; }
std::string Person::getEmail() const { return email; }
std::string Person::getAddress() const { return address; }
std::string Person::getDateOfBirth() const { return dateOfBirth; }

void Person::setName(const std::string& n) { name = n; }
void Person::setEmail(const std::string& mail) { email = mail; }
void Person::setAddress(const std::string& addr) { address = addr; }
void Person::setDateOfBirth(const std::string& dob) { dateOfBirth = dob; }

std::ostream& operator<<(std::ostream& os, const Person& p) {
    os << "ID: " << p.personID << "\n"
       << "Name: " << p.name << "\n"
       << "Email: " << p.email << "\n"
       << "Address: " << p.address << "\n"
       << "Date of Birth: " << p.dateOfBirth;
    return os;
}

std::istream& operator>>(std::istream& is, Person& p) {
    std::cout << "Enter ID: ";
    is >> p.personID;
    is.ignore();
    std::cout << "Enter Name: ";
    std::getline(is, p.name);
    std::cout << "Enter Email: ";
    std::getline(is, p.email);
    std::cout << "Enter Address: ";
    std::getline(is, p.address);
    std::cout << "Enter Date of Birth: ";
    std::getline(is, p.dateOfBirth);
    return is;
}