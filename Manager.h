#ifndef MANAGER_H
#define MANAGER_H

#include "Employee.h"

class Manager : public Employee {
public:
    Manager(int id, std::string n, std::string mail, std::string addr, std::string dob,
            std::string pos, double sal, std::string pass);

    void displayInfo() const override;

    // Getters
    int getId() const;
    std::string getName() const;
    std::string getEmail() const;
    std::string getAddress() const;
    std::string getDOB() const;
    std::string getPosition() const;
    double getSalary() const;
    std::string getPassword() const;

    // Setters
    void setId(int id);
    void setName(const std::string& n);
    void setEmail(const std::string& mail);
    void setAddress(const std::string& addr);
    void setDOB(const std::string& dob);
    void setPosition(const std::string& pos);
    void setSalary(double sal);
    void setPassword(const std::string& pass);

    // Operator overloading
    friend std::ostream& operator<<(std::ostream& os, const Manager& m);
    friend std::istream& operator>>(std::istream& is, Manager& m);
};

#endif
