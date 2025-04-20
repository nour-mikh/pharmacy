#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Person.h"
#include <string>
#include <ostream>

class Employee : public Person {
protected:
    int id;
    std::string position;
    double salary;
    std::string password;
    std::string dob;

public:
    Employee(int id, std::string n, std::string mail, std::string addr, std::string dob,
             std::string pos, double sal, std::string pass);

    void displayInfo() const override;

    // Getters
    int getId() const;
    std::string getPosition() const;
    double getSalary() const;
    std::string getPassword() const;
    std::string getDOB() const;

    // Setters
    void setId(int id);
    void setPosition(const std::string& pos);
    void setSalary(double sal);
    void setPassword(const std::string& pass);
    void setDOB(const std::string& dob);

    // Friends
    friend std::ostream& operator<<(std::ostream& os, const Employee& e);
    friend std::istream& operator>>(std::istream& is, Employee& e);
};

#endif
