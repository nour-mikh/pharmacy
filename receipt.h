#ifndef RECEIPT_H
#define RECEIPT_H

#include <QDialog>
#include "DatabaseManager.h"

namespace Ui {
class Receipt;
}

class Receipt : public QDialog
{
    Q_OBJECT

public:
    explicit Receipt(QWidget *parent = nullptr);
    ~Receipt();

private slots:
    void handleFinalizeSale();    // Finalize sale with client
    void handleAddItem();         // Add item with quantity
    void handleExportSales();     // Export CSV file

private:
    Ui::Receipt *ui;
    DatabaseManager db;
    int currentSaleId = -1;       // Sale ID from DB
    double currentTotal = 0.0;    // Running total to display in LCD
};

#endif // RECEIPT_H
