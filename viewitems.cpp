#include "viewitems.h"
#include "ui_viewitems.h"

ViewItems::ViewItems(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ViewItems)
{
    ui->setupUi(this);
    dbManager.openDatabase();

    connect(ui->clientShow, &QPushButton::clicked, this, &ViewItems::showClients);
    connect(ui->employeeShow, &QPushButton::clicked, this, &ViewItems::showEmployees);
    connect(ui->managerShow, &QPushButton::clicked, this, &ViewItems::showManagers);
    connect(ui->medicineShow, &QPushButton::clicked, this, &ViewItems::showMedicines);
}

ViewItems::~ViewItems()
{
    delete ui;
}

void ViewItems::showClients()
{
    QSqlQueryModel *model = dbManager.viewAllClients();
    model->setParent(this); // ensure cleanup
    ui->tableView->setModel(model);
}

void ViewItems::showEmployees()
{
    QSqlQueryModel *model = dbManager.viewAllEmployees();
    model->setParent(this);
    ui->tableView->setModel(model);
}

void ViewItems::showManagers()
{
    QSqlQueryModel *model = dbManager.viewAllManagers();
    model->setParent(this);
    ui->tableView->setModel(model);
}

void ViewItems::showMedicines()
{
    QSqlQueryModel *model = dbManager.viewAllMedicines();
    model->setParent(this);
    ui->tableView->setModel(model);
}
