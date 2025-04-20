#include "Sale.h"
#include <iostream>

Sale::Sale(int sId, int cId, const std::string& date)
    : saleId(sId), customerId(cId), saleDate(date), totalAmount(0.0) {}

void Sale::addItem(const SalesItem& item) {
    items.push_back(item);
    calculateTotal();
}

void Sale::calculateTotal() {
    totalAmount = 0.0;
    for (const auto& item : items) {
        totalAmount += item.getSubTotal();
    }
}

double Sale::getTotalAmount() const {
    return totalAmount;
}

int Sale::getSaleId() const { return saleId; }
int Sale::getCustomerId() const { return customerId; }
std::string Sale::getSaleDate() const { return saleDate; }

void Sale::displaySale() const {
    std::cout << "Sale ID: " << saleId << "\n"
              << "Customer ID: " << customerId << "\n"
              << "Sale Date: " << saleDate << "\n"
              << "Items:\n";

    for (const auto& item : items) {
        std::cout << "------------------\n";
        item.displayInfo();
    }

    std::cout << "Total Amount: $" << totalAmount << "\n";
}

std::ostream& operator<<(std::ostream& os, const Sale& sale) {
    os << "Sale ID: " << sale.getSaleId() << "\n"
       << "Customer ID: " << sale.getCustomerId() << "\n"
       << "Sale Date: " << sale.getSaleDate() << "\n"
       << "Items:\n";

    for (const auto& item : sale.items) {
        os << "------------------\n";
        os << item << "\n"; // use overloaded SalesItem <<
    }

    os << "Total Amount: $" << sale.getTotalAmount() << "\n";
    return os;
}