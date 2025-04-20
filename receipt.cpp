// Receipt.cpp
#include "receipt.h"
#include "ui_receipt.h"
#include <QMessageBox>
#include <QDate>
#include <QFileDialog>
#include <QHeaderView>
#include <QSqlQuery>

Receipt::Receipt(QWidget *parent)
    : QDialog(parent), ui(new Ui::Receipt) {
    ui->setupUi(this);

    // Connect buttons
    connect(ui->receiptSaleItemAdd, &QPushButton::clicked, this, &Receipt::handleAddItem);
    connect(ui->finalizeSaleButton, &QPushButton::clicked, this, &Receipt::handleFinalizeSale);
    connect(ui->exportSalesButton, &QPushButton::clicked, this, &Receipt::handleExportSales);

    // Set up receipt item table
    ui->receiptItemsTable->setColumnCount(4);
    ui->receiptItemsTable->setHorizontalHeaderLabels(QStringList() << "Name" << "Quantity" << "Unit Price" << "Subtotal");
    ui->receiptItemsTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // Populate medicine dropdown
    QSqlQuery medQuery("SELECT Name FROM Medicines");
    while (medQuery.next()) {
        ui->comboMedicineList->addItem(medQuery.value(0).toString());
    }

    // Populate client dropdown
    QSqlQuery clientQuery("SELECT Name FROM Clients");
    while (clientQuery.next()) {
        ui->comboClientList->addItem(clientQuery.value(0).toString());
    }
}

Receipt::~Receipt() {
    delete ui;
}

void Receipt::handleFinalizeSale() {
    QString clientName = ui->comboClientList->currentText();

    QSqlQuery query;
    query.prepare("SELECT ID FROM Clients WHERE Name = :name");
    query.bindValue(":name", clientName);

    if (query.exec() && query.next()) {
        int clientId = query.value(0).toInt();
        QString date = QDate::currentDate().toString("yyyy-MM-dd");

        if (db.addSale(clientId, date)) {
            currentSaleId = query.lastInsertId().toInt();
            currentTotal = 0;
            ui->lcdNumber->display(currentTotal);
            ui->receiptItemsTable->setRowCount(0);
            QMessageBox::information(this, "Sale Created", "Sale ID: " + QString::number(currentSaleId));
        } else {
            QMessageBox::warning(this, "Error", "Failed to create sale.");
        }
    } else {
        QMessageBox::warning(this, "Client Not Found", "Please select a valid client.");
    }
}

void Receipt::handleAddItem() {
    if (currentSaleId == -1) {
        QMessageBox::warning(this, "No Sale", "Please finalize a sale first.");
        return;
    }

    QString medName = ui->comboMedicineList->currentText();
    int quantity = ui->itemQuantityInput->value();

    QSqlQuery query;
    query.prepare("SELECT PricePerUnit FROM Medicines WHERE Name = :name");
    query.bindValue(":name", medName);

    if (!query.exec() || !query.next()) {
        QMessageBox::warning(this, "Error", "Medicine not found.");
        return;
    }

    double unitPrice = query.value(0).toDouble();

    if (db.addSalesItem(currentSaleId, medName, quantity, unitPrice)) {
        double subtotal = quantity * unitPrice;
        currentTotal += subtotal;
        ui->lcdNumber->display(currentTotal);

        int row = ui->receiptItemsTable->rowCount();
        ui->receiptItemsTable->insertRow(row);
        ui->receiptItemsTable->setItem(row, 0, new QTableWidgetItem(medName));
        ui->receiptItemsTable->setItem(row, 1, new QTableWidgetItem(QString::number(quantity)));
        ui->receiptItemsTable->setItem(row, 2, new QTableWidgetItem(QString::number(unitPrice, 'f', 2)));
        ui->receiptItemsTable->setItem(row, 3, new QTableWidgetItem(QString::number(subtotal, 'f', 2)));

        QMessageBox::information(this, "Item Added", QString("Added %1 x%2").arg(medName).arg(quantity));
    } else {
        QMessageBox::warning(this, "Stock Error", "Not enough stock or invalid medicine.");
    }
}

void Receipt::handleExportSales() {
    QString path = QFileDialog::getSaveFileName(this, "Export Sales CSV", "", "CSV Files (*.csv)");
    if (!path.isEmpty()) {
        if (db.exportSalesToCSV(path)) {
            QMessageBox::information(this, "Export Complete", "Sales exported to: " + path);
        } else {
            QMessageBox::warning(this, "Export Failed", "Could not export sales.");
        }
    }
}
