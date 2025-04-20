#include "selectroleui.h"
#include "ui_selectroleui.h"
#include <QMessageBox>
#include <QUrlQuery>
#include <QSqlQuery>
#include "DatabaseManager.h"


SelectRoleUI::SelectRoleUI(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SelectRoleUI)
{
    ui->setupUi(this);
    connect(ui->loginButton, &QPushButton::clicked, this, &SelectRoleUI::handleLogin);
}

SelectRoleUI::~SelectRoleUI()
{
    delete ui;
}

void SelectRoleUI::handleLogin()
{
    QString email = ui->emailInputLogin->text();
    QString password = ui->passwordInputLogin->text();
    QString role = ui->roleInputLogin->currentText();

    DatabaseManager db;

    bool success = false;
    QString name;

    if (role == "Employee") {
        if (db.verifyEmployeeLogin(email, password)) {
            name = email;
            success = true;
        }
    } else if (role == "Manager") {
        if (db.verifyManagerLogin(email, password)) {
            name = email;
            success = true;
        }
    } else if (role == "Client") {
        name = email;
        success = true;
    }

    else {
        QMessageBox::warning(this, "Login Failed", "Invalid role selected.");
        return;
    }

    if (success) {
        emit loginSuccessful(name);
        QMessageBox::information(this, "Login Success", "Welcome, " + name + "!");
        this->close();
    } else {
        QMessageBox::warning(this, "Login Failed", "Incorrect email or password.");
    }
}


//THIS IS THE ONE U DID -- I KEPT IT TO AVOID GETTING YELLED AT
// void SelectRoleUI::handleLogin()
// {
//     QString email = ui->emailInputLogin->text();
//     QString password = ui->passwordInputLogin->text();
//     QString role = ui->roleInputLogin->currentText();

//     QSqlQuery query;
//     QString table;

//     if (role == "Client") table = "Clients";
//     else if (role == "Employee") table = "Employees";
//     else if (role == "Manager") table = "Managers";
//     else {
//         QMessageBox::warning(this, "Login Failed", "Invalid role selected.");
//         return;
//     }

//     query.prepare("SELECT name FROM " + table + " WHERE email = :email AND password = :password");
//     query.bindValue(":email", email);
//     query.bindValue(":password", password);

//     if (query.exec() && query.next()) {
//         QString name = query.value(0).toString();
//         emit loginSuccessful(name);  // Send name to main window
//         QMessageBox::information(this, "Login Success", "Welcome, " + name + "!");
//         this->close(); // Optional: close the login dialog
//     } else {
//         QMessageBox::warning(this, "Login Failed", "Incorrect email or password.");
//     }
// }
