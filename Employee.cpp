#include "Employee.h"
#include <iostream>

// Constructor
Employee::Employee(int id, std::string n, std::string mail, std::string addr, std::string dob,
                   std::string pos, double sal, std::string pass)
    : Person(id, n, mail, addr, dob), position(pos), salary(sal), password(pass), dob(dob) {}

// Display info
void Employee::displayInfo() const {
    Person::displayInfo();
    std::cout << "Position: " << position << "\n"
              << "Salary: $" << salary << std::endl;
    // Password intentionally not displayed
}

// Output stream
std::ostream& operator<<(std::ostream& os, const Employee& e) {
    os << static_cast<const Person&>(e) << "\n"
       << "Position: " << e.position << "\n"
       << "Salary: $" << e.salary << "\n"
       << "Password: " << e.password;
    return os;
}

// Input stream
std::istream& operator>>(std::istream& is, Employee& e) {
    is >> static_cast<Person&>(e);
    std::cout << "Enter Position: ";
    std::getline(is >> std::ws, e.position);
    std::cout << "Enter Salary: ";
    is >> e.salary;
    std::cout << "Enter Password: ";
    std::getline(is >> std::ws, e.password);
    return is;
}

// Getters
int Employee::getId() const { return id; }
std::string Employee::getPosition() const { return position; }
double Employee::getSalary() const { return salary; }
std::string Employee::getPassword() const { return password; }
std::string Employee::getDOB() const { return dob; }

// Setters
void Employee::setId(int newId) { id = newId; }
void Employee::setPosition(const std::string& pos) { position = pos; }
void Employee::setSalary(double sal) { salary = sal; }
void Employee::setPassword(const std::string& pass) { password = pass; }
void Employee::setDOB(const std::string& newDob) { dob = newDob; }
