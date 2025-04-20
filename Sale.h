#ifndef SALE_H
#define SALE_H

#include <string>
#include <vector>
#include "SalesItem.h"
#include <ostream>

class Sale {
private:
    int saleId;
    int customerId;
    std::string saleDate;
    std::vector<SalesItem> items;
    double totalAmount;

public:
    // Constructor
    Sale(int sId, int cId, const std::string& date);

    // Methods
    void addItem(const SalesItem& item);
    void calculateTotal();
    double getTotalAmount() const;

    // Getters
    int getSaleId() const;
    int getCustomerId() const;
    std::string getSaleDate() const;

    // Display
    void displaySale() const;

    // Overloaded operators
    friend std::ostream& operator<<(std::ostream& os, const Sale& sale);
};

#endif
