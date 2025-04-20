#ifndef MEDICINE_H
#define MEDICINE_H

#include <string>

class Medicine {
private:
    std::string name;
    std::string description;
    std::string category;
    double pricePerUnit;
    int currentStock;

public:
    // Constructor
    Medicine(std::string n, std::string d, std::string c, double p, int s);

    // Getters
    std::string getName() const;
    std::string getDescription() const;
    double getPricePerUnit() const;
    int getCurrentStock() const;
    std::string getCategory() const;

    // Setters
    void setName(const std::string& n);
    void setDescription(const std::string& d);
    void setPricePerUnit(double p);
    void setCurrentStock(int s);
    void setCategory(const std::string category);

    // Display method
    void displayInfo() const;
};

#endif
