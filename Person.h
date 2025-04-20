#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <ostream>

class Person {
protected:
    int personID;
    std::string name;
    std::string email;
    std::string address;
    std::string dateOfBirth;

public:
    Person(int id, std::string n, std::string mail, std::string addr, std::string dob);
    virtual ~Person() = default;

    virtual void displayInfo() const;

    int getPersonID() const;
    std::string getName() const;
    std::string getEmail() const;
    std::string getAddress() const;
    std::string getDateOfBirth() const;

    void setName(const std::string& n);
    void setEmail(const std::string& mail);
    void setAddress(const std::string& addr);
    void setDateOfBirth(const std::string& dob);

    friend std::ostream& operator<<(std::ostream& os, const Person& p);
    friend std::istream& operator>>(std::istream& is, Person& p);

};

#endif
