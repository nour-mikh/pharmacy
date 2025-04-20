#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QSqlDatabase>
#include <QString>
#include <QSqlQueryModel>

class DatabaseManager {
public:
    DatabaseManager();
    ~DatabaseManager();

    bool openDatabase();
    void closeDatabase();

    // Insert methods
    bool addClient(QString name, QString contact, QString address, QString email, QString dob);
    bool addEmployee(QString name, QString email, QString address, QString dob, QString position, double salary, QString password);
    bool addManager(QString name, QString email, QString address, QString dob, QString position, double salary, QString password);
    bool addSale(int clientId, QString date);
    bool addSalesItem(int saleId, QString medicineName, int quantity, double unitPrice);
    bool exportSalesToCSV(const QString& filename);
    bool addMedicine(QString name, QString description, QString category, double pricePerUnit, int stock);

    bool verifyEmployeeLogin(QString email, QString password);
    bool verifyManagerLogin(QString email, QString password);
    

    // Example query
    void searchClient(QString name);

    // View methods
    QSqlQueryModel* viewAllMedicines();
    QSqlQueryModel* viewAllClients();
    QSqlQueryModel* viewAllEmployees();
    QSqlQueryModel* viewAllManagers();

private:
    QSqlDatabase db;
};

#endif
