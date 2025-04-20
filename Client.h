#ifndef CLIENT_H
#define CLIENT_H

#include "Person.h"

#include <string>
#include <ostream>


class Client : public Person {
private:
    std::string phoneNumber;

public:
    Client(int id, std::string n, std::string mail, std::string addr, std::string dob,
           std::string phone);

    std::string getPhoneNumber() const;

    void displayInfo() const override;

    friend std::ostream& operator<<(std::ostream& os, const Client& c);
    friend std::istream& operator>>(std::istream& is, Client& c);

};

#endif
