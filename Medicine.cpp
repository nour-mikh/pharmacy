#include "Medicine.h"
#include <iostream>

// Constructor
Medicine::Medicine(std::string n, std::string d, std::string c, double p, int s)
    : name(n), description(d), category(c), pricePerUnit(p), currentStock(s) {}

// Getters
std::string Medicine::getName() const { return name; }
std::string Medicine::getDescription() const { return description; }
double Medicine::getPricePerUnit() const { return pricePerUnit; }
int Medicine::getCurrentStock() const { return currentStock; }
std::string Medicine::getCategory() const {return category; }

// Setters
void Medicine::setName(const std::string& n) { name = n; }
void Medicine::setDescription(const std::string& d) { description = d; }
void Medicine::setPricePerUnit(double p) { pricePerUnit = p; }
void Medicine::setCurrentStock(int s) { currentStock = s; }

// Display method
void Medicine::displayInfo() const {
    std::cout << "Name: " << name << "\n"
              << "Description: " << description << "\n"
              << "Category: " << category << "\n"
              << "Price per Unit: $" << pricePerUnit << "\n"
              << "Current Stock: " << currentStock << std::endl;
}
