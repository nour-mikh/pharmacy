#include "SalesItem.h"
#include <iostream>

SalesItem::SalesItem(int itemId, int sId, const std::string& medName, int qty, double unitP)
    : salesItemId(itemId), saleId(sId), medicineName(medName),
      quantityPurchased(qty), unitPrice(unitP) {
    calculateSubTotal();
}

int SalesItem::getSalesItemId() const { return salesItemId; }
int SalesItem::getSaleId() const { return saleId; }
std::string SalesItem::getMedicineName() const { return medicineName; }
int SalesItem::getQuantityPurchased() const { return quantityPurchased; }
double SalesItem::getUnitPrice() const { return unitPrice; }
double SalesItem::getSubTotal() const { return subTotal; }

void SalesItem::setQuantityPurchased(int qty) {
    quantityPurchased = qty;
    calculateSubTotal();
}

void SalesItem::setUnitPrice(double price) {
    unitPrice = price;
    calculateSubTotal();
}

void SalesItem::calculateSubTotal() {
    subTotal = unitPrice * quantityPurchased;
}

void SalesItem::displayInfo() const {
    std::cout << "Sales Item ID: " << salesItemId << "\n"
              << "Sale ID: " << saleId << "\n"
              << "Medicine Name: " << medicineName << "\n"
              << "Quantity: " << quantityPurchased << "\n"
              << "Unit Price: $" << unitPrice << "\n"
              << "Subtotal: $" << subTotal << std::endl;
}

std::ostream& operator<<(std::ostream& os, const SalesItem& item) {
    os << "Sales Item ID: " << item.getSalesItemId() << "\n"
       << "Sale ID: " << item.getSaleId() << "\n"
       << "Medicine Name: " << item.getMedicineName() << "\n"
       << "Quantity Purchased: " << item.getQuantityPurchased() << "\n"
       << "Unit Price: $" << item.getUnitPrice() << "\n"
       << "Subtotal: $" << item.getSubTotal();
    return os;
}
