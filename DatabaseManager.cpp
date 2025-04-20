#include "DatabaseManager.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QSqlQueryModel>
#include <QFile>
#include <QTextStream>
#include "Client.h"
#include "Employee.h"
#include "Manager.h"
#include "Medicine.h"
#include <QCryptographicHash>

// Hash function to hash passwords
QString hashPassword(const QString& password) {
    QByteArray hash = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256);
    return QString(hash.toHex());
}


DatabaseManager::DatabaseManager() {
    openDatabase();
}

DatabaseManager::~DatabaseManager() {
    closeDatabase();
}

bool DatabaseManager::openDatabase() {
    if (QSqlDatabase::contains("qt_sql_default_connection")) {
        db = QSqlDatabase::database("qt_sql_default_connection");
    } else {
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("pharmacy.db");
    }

    if (!db.open()) {
        qDebug() << "Database open error:" << db.lastError().text();
        return false;
    }

    QSqlQuery query;
    // Clients
    query.exec("CREATE TABLE IF NOT EXISTS Clients ("
               "ID INTEGER PRIMARY KEY AUTOINCREMENT, "
               "Name TEXT, Contact TEXT, Address TEXT, Email TEXT, DOB TEXT)");

    // Employees
    query.exec("CREATE TABLE IF NOT EXISTS Employees ("
               "ID INTEGER PRIMARY KEY AUTOINCREMENT, "
               "Name TEXT, Email TEXT, Address TEXT, DOB TEXT, "
               "Position TEXT, Salary REAL, Password TEXT)");

    // Managers
    query.exec("CREATE TABLE IF NOT EXISTS Managers ("
               "ID INTEGER PRIMARY KEY AUTOINCREMENT, "
               "Name TEXT, Email TEXT, Address TEXT, DOB TEXT, "
               "Position TEXT, Salary REAL, Password TEXT)");
    // Sales
    query.exec("CREATE TABLE IF NOT EXISTS Sales ("
               "ID INTEGER PRIMARY KEY AUTOINCREMENT, "
               "ClientID INTEGER, Date TEXT, TotalAmount REAL)");

    // Sales Items
    query.exec("CREATE TABLE IF NOT EXISTS SalesItems ("
               "ID INTEGER PRIMARY KEY AUTOINCREMENT, "
               "SaleID INTEGER, "
               "MedicineName TEXT, "
               "Quantity INTEGER, UnitPrice REAL, Subtotal REAL, "
               "FOREIGN KEY (MedicineName) REFERENCES Medicines(Name))");

    // Medicines
    query.exec("CREATE TABLE IF NOT EXISTS Medicines ("
               "Name TEXT PRIMARY KEY, "
               "Description TEXT, Category TEXT, PricePerUnit REAL, Stock INTEGER)");
    return true;
}

void DatabaseManager::closeDatabase() {
    db.close();
}

bool DatabaseManager::addClient(QString name, QString contact, QString address, QString email, QString dob) {
    // Instantiate a Client object with the given parameters (optional ID = 0 here, or auto-gen if needed)
    Client c(0, name.toStdString(), email.toStdString(), address.toStdString(), dob.toStdString(), contact.toStdString());

    QSqlQuery query;
    query.prepare("INSERT INTO Clients (Name, Contact, Address, Email, DOB) "
                  "VALUES (:name, :contact, :address, :email, :dob)");
    query.bindValue(":name", QString::fromStdString(c.getName()));
    query.bindValue(":contact", QString::fromStdString(c.getPhoneNumber()));
    query.bindValue(":address", QString::fromStdString(c.getAddress()));
    query.bindValue(":email", QString::fromStdString(c.getEmail()));
    query.bindValue(":dob", QString::fromStdString(c.getDateOfBirth()));

    return query.exec();
}

bool DatabaseManager::addEmployee(QString name, QString email, QString address, QString dob, QString position, double salary, QString password) {
    QString hashed = hashPassword(password);
    Employee e(0, name.toStdString(), email.toStdString(), address.toStdString(), dob.toStdString(),
           position.toStdString(), salary, hashed.toStdString());


    QSqlQuery query;
    query.prepare("INSERT INTO Employees (Name, Email, Address, DOB, Position, Salary, Password) "
              "VALUES (:name, :email, :address, :dob, :position, :salary, :password)");

    query.bindValue(":name", QString::fromStdString(e.getName()));
    query.bindValue(":email", QString::fromStdString(e.getEmail()));
    query.bindValue(":address", QString::fromStdString(e.getAddress()));
    query.bindValue(":dob", QString::fromStdString(e.getDateOfBirth()));
    query.bindValue(":position", QString::fromStdString(e.getPosition()));
    query.bindValue(":salary", e.getSalary());
    query.bindValue(":password", QString::fromStdString(e.getPassword()));

    return query.exec();
}

bool DatabaseManager::addManager(QString name, QString email, QString address,
    QString dob, QString position, double salary, QString password) {
        QString hashed = hashPassword(password);
    Manager m(0, name.toStdString(), email.toStdString(), address.toStdString(), dob.toStdString(),
        position.toStdString(), salary, hashed.toStdString());
                                    

    QSqlQuery query;
    query.prepare("INSERT INTO Managers (Name, Email, Address, DOB, Position, Salary, Password) "
              "VALUES (:name, :email, :address, :dob, :position, :salary, :password)");


    query.bindValue(":name", QString::fromStdString(m.getName()));
    query.bindValue(":email", QString::fromStdString(m.getEmail()));
    query.bindValue(":address", QString::fromStdString(m.getAddress()));
    query.bindValue(":dob", QString::fromStdString(m.getDateOfBirth()));
    query.bindValue(":position", QString::fromStdString(m.getPosition()));
    query.bindValue(":salary", m.getSalary());
    query.bindValue(":password", QString::fromStdString(m.getPassword()));

    // Debugging output
    qDebug() << "[addManager] Inserting manager with values:";
    qDebug() << "Name:" << name;
    qDebug() << "Email:" << email;
    qDebug() << "Address:" << address;
    qDebug() << "DOB:" << dob;
    qDebug() << "Position:" << position;
    qDebug() << "Salary:" << salary;
   // qDebug() << "Password:" << password; I DONT THINK WE WANT TO LOG HASHED PASSWORDS

    if (!query.exec()) {
        qDebug() << "[addManager] SQL Error:" << query.lastError().text();
        return false;
    }

    qDebug() << "[addManager] Manager inserted successfully.";
    return true;
}

bool DatabaseManager::addSale(int clientId, QString date) {
    QSqlQuery query;
    query.prepare("INSERT INTO Sales (ClientID, Date, TotalAmount) "
                  "VALUES (:clientId, :date, 0.0)");
    query.bindValue(":clientId", clientId);
    query.bindValue(":date", date);

    return query.exec();
}


void DatabaseManager::searchClient(QString name) {
    QSqlQuery query;
    query.prepare("SELECT * FROM Clients WHERE Name LIKE :name");
    query.bindValue(":name", "%" + name + "%");

    if (query.exec()) {
        while (query.next()) {
            int id = query.value("ID").toInt();
            QString clientName = query.value("Name").toString();
            QString contact = query.value("Contact").toString();
            QString address = query.value("Address").toString();
            qDebug() << "Client: ID=" << id << ", Name=" << clientName << ", Contact=" << contact << ", Address=" << address;
        }
    } else {
        qDebug() << "Search error: " << query.lastError().text();
    }
}

bool DatabaseManager::addSalesItem(int saleId, QString medicineName, int quantity, double unitPrice) {
    double subtotal = quantity * unitPrice;

    // Step 1: Check current stock
    QSqlQuery stockQuery;
    stockQuery.prepare("SELECT Stock FROM Medicines WHERE Name = :name");
    stockQuery.bindValue(":name", medicineName);

    if (!stockQuery.exec() || !stockQuery.next()) {
        qDebug() << "Error fetching medicine stock: " << stockQuery.lastError().text();
        return false;
    }

    int currentStock = stockQuery.value("Stock").toInt();
    if (currentStock < quantity) {
        qDebug() << "Not enough stock! Available:" << currentStock << ", Requested:" << quantity;
        return false;
    }

    // Step 2: Subtract from stock
    int newStock = currentStock - quantity;
    QSqlQuery updateStock;
    updateStock.prepare("UPDATE Medicines SET Stock = :stock WHERE Name = :name");
    updateStock.bindValue(":stock", newStock);
    updateStock.bindValue(":name", medicineName);

    if (!updateStock.exec()) {
        qDebug() << "Failed to update stock: " << updateStock.lastError().text();
        return false;
    }

    // Step 3: Insert into SalesItems
    QSqlQuery query;
    query.prepare("INSERT INTO SalesItems (SaleID, MedicineName, Quantity, UnitPrice, Subtotal) "
                  "VALUES (:saleId, :medName, :qty, :unitPrice, :subtotal)");
    query.bindValue(":saleId", saleId);
    query.bindValue(":medName", medicineName);
    query.bindValue(":qty", quantity);
    query.bindValue(":unitPrice", unitPrice);
    query.bindValue(":subtotal", subtotal);

    // Step 4: Update total in Sales table
    QSqlQuery updateSaleTotal;
    updateSaleTotal.prepare(R"(
        UPDATE Sales
        SET TotalAmount = (
            SELECT SUM(Subtotal)
            FROM SalesItems
            WHERE SaleID = :saleId
        )
        WHERE ID = :saleId
    )");
    updateSaleTotal.bindValue(":saleId", saleId);
    if (!updateSaleTotal.exec()) {
        qDebug() << "Failed to update sale total: " << updateSaleTotal.lastError().text();
    }

    // Step 5: Return result of SalesItem insert
    return query.exec();
}

bool DatabaseManager::exportSalesToCSV(const QString& filename) {
    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Failed to open file for writing:" << filename;
        return false;
    }

    QTextStream out(&file);
    out << "SaleID,ClientID,Date,TotalAmount\n";

    QSqlQuery query("SELECT ID, ClientID, Date, TotalAmount FROM Sales");
    while (query.next()) {
        int id = query.value("ID").toInt();
        int clientId = query.value("ClientID").toInt();
        QString date = query.value("Date").toString();
        double total = query.value("TotalAmount").toDouble();

        out << id << "," << clientId << "," << date << "," << total << "\n";
    }

    file.close();
    qDebug() << "Exported sales report to:" << filename;
    return true;
}

bool DatabaseManager::addMedicine(QString name, QString description, QString category, double pricePerUnit, int stock) {
    if (!db.isOpen()) {
        qDebug() << "Database is not open.";
        return false;
    }

    // Create a Medicine object
    Medicine med(name.toStdString(), description.toStdString(), category.toStdString(), pricePerUnit, stock);

    // Prepare insert query
    QSqlQuery query;
    query.prepare("INSERT INTO Medicines (Name, Description, Category, PricePerUnit, Stock) "
                  "VALUES (:name, :description, :category, :price, :stock)");
    query.bindValue(":name", QString::fromStdString(med.getName()));
    query.bindValue(":description", QString::fromStdString(med.getDescription()));
    query.bindValue(":category", QString::fromStdString(med.getCategory()));
    query.bindValue(":price", med.getPricePerUnit());
    query.bindValue(":stock", med.getCurrentStock());

    // Execute query
    if (!query.exec()) {
        qDebug() << "Failed to insert medicine:" << query.lastError().text();
        return false;
    }

    qDebug() << "Medicine has been added to DB";

    return true;
}

QSqlQueryModel* DatabaseManager::viewAllMedicines() {
    auto* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM Medicines");
    return model;
}

QSqlQueryModel* DatabaseManager::viewAllClients() {
    auto* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM Clients");
    return model;
}

QSqlQueryModel* DatabaseManager::viewAllEmployees() {
    auto* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM Employees");
    return model;
}

QSqlQueryModel* DatabaseManager::viewAllManagers() {
    auto* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM Managers");
    return model;
}

//FOR LOGGING IN
bool DatabaseManager::verifyEmployeeLogin(QString email, QString password) {
    QString hashed = hashPassword(password);
    QSqlQuery query;
    query.prepare("SELECT * FROM Employees WHERE Email = :email AND Password = :password");
    query.bindValue(":email", email);
    query.bindValue(":password", hashed);
    return query.exec() && query.next();
}
bool DatabaseManager::verifyManagerLogin(QString email, QString password) {
    QString hashed = hashPassword(password);
    QSqlQuery query;
    query.prepare("SELECT * FROM Managers WHERE Email = :email AND Password = :password");
    query.bindValue(":email", email);
    query.bindValue(":password", hashed);
    return query.exec() && query.next();
}
