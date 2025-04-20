#include "medui.h"
#include "ui_medui.h"
#include <QMessageBox>
#include <QDebug>
#include "DatabaseManager.h"

MedUI::MedUI(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MedUI)
{
    ui->setupUi(this);

    connect(ui->addMed, &QPushButton::clicked, this, &MedUI::handleCreateMedicine);
}

MedUI::~MedUI()
{
    delete ui;
}

void MedUI::handleCreateMedicine() {

    DatabaseManager db;
    QString name = ui->medNameInput->text();
    QString category = ui->medCatInput->currentText();
    QString description = ui->medDescInput->toPlainText();
    int price = ui->medPriceInput->value();
    int stock = ui->medStockInput->value();

    // Basic validation
    if (name.isEmpty() || category.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please enter both name and category.");
        return;
    }

    qDebug() << "New Medicine Created:";
    qDebug() << "Name:" << name;
    qDebug() << "Category:" << category;
    qDebug() << "Description:" << description;
    qDebug() << "Price per unit:" << price;
    qDebug() << "Items in stock:" << stock;

    QMessageBox::information(this, "Success", "Medicine added successfully.");

    db.addMedicine(name, description, category, price, stock);

    ui->medNameInput->clear();
    ui->medCatInput->setCurrentIndex(0);
    ui->medDescInput->clear();
    ui->medPriceInput->setValue(0);
    ui->medStockInput->setValue(0);
}
