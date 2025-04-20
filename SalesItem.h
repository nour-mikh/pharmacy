#ifndef SALESITEM_H
#define SALESITEM_H

#include <string>
#include <ostream>

class SalesItem {
private:
    int salesItemId;
    int saleId;
    std::string medicineName;
    int quantityPurchased;
    double unitPrice;
    double subTotal;

public:
    // Constructor
    SalesItem(int itemId, int sId, const std::string& medName, int qty, double unitP);

    // Getters
    int getSalesItemId() const;
    int getSaleId() const;
    std::string getMedicineName() const;
    int getQuantityPurchased() const;
    double getUnitPrice() const;
    double getSubTotal() const;

    // Setters
    void setQuantityPurchased(int qty);
    void setUnitPrice(double price);
    void calculateSubTotal();

    // Display
    void displayInfo() const;

    // Overloaded operators
    friend std::ostream& operator<<(std::ostream& os, const SalesItem& item);
};

#endif
