#include "personui.h"
#include "ui_personui.h"
#include "DatabaseManager.h"
#include <QMessageBox>

PersonUI::PersonUI(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::PersonUI)
{
    ui->setupUi(this);

    connect(ui->addPersonButton, &QPushButton::clicked, this, &PersonUI::handleCreateUser);
}

PersonUI::~PersonUI()
{
    delete ui;
}

void PersonUI::handleCreateUser()
{
    DatabaseManager db;
    QString name = ui->nameInput->text();
    QString phone = ui->numberPhoneInput->text();
    QString email = ui->emailInput->text();
    QString password = ui->passInput->text();
    QString address = ui->addressInput->text();
    QString dob = ui->dateInput->date().toString("yyyy-MM-dd"); // Format as string
    QString role = ui->comboPersonRole->currentText();

    bool success = false;

    if (role == "Client") {
        success = db.addClient(name, phone, address, email, dob);
    } else if (role == "Employee") {
        QString position = "Employee";
        double salary = 1000; // Default
        success = db.addEmployee(name, email, address, dob, position, salary, password);
    } else if (role == "Manager") {
        QString position = "Manager";
        double salary = 2000; // Default
        success = db.addManager(name, email, address, dob, position, salary, password);
    }

    if (success) {
        QMessageBox::information(this, "Success", "Person added successfully!");
        this->accept();
    } else {
        QMessageBox::warning(this, "Error", "Failed to add person.");
    }
}
