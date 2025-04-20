#include "Manager.h"
#include <iostream>

// Constructor
Manager::Manager(int id, std::string n, std::string mail, std::string addr,
                 std::string dob, std::string pos, double sal, std::string pass)
    : Employee(id, n, mail, addr, dob, pos, sal, pass) {} // pass forwarded

// Overridden display
void Manager::displayInfo() const {
    std::cout << "[Manager Info]\n";
    Employee::displayInfo();
}

// Output stream overload
std::ostream& operator<<(std::ostream& os, const Manager& m) {
    os << static_cast<const Employee&>(m);  // Reuse Employee's output
    return os;
}

// Input stream overload
std::istream& operator>>(std::istream& is, Manager& m) {
    is >> static_cast<Employee&>(m);  // Reuse Employee's input
    return is;
}

// Getters
int Manager::getId() const { return id; }
std::string Manager::getName() const { return name; }
std::string Manager::getEmail() const { return email; }
std::string Manager::getAddress() const { return address; }
std::string Manager::getDOB() const { return dob; }
std::string Manager::getPosition() const { return position; }
double Manager::getSalary() const { return salary; }
std::string Manager::getPassword() const { return password; }

// Setters
void Manager::setId(int idVal) { id = idVal; }
void Manager::setName(const std::string& n) { name = n; }
void Manager::setEmail(const std::string& mail) { email = mail; }
void Manager::setAddress(const std::string& addr) { address = addr; }
void Manager::setDOB(const std::string& date) { dob = date; }
void Manager::setPosition(const std::string& pos) { position = pos; }
void Manager::setSalary(double sal) { salary = sal; }
void Manager::setPassword(const std::string& pass) { password = pass; }
