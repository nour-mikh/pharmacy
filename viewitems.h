#ifndef VIEWITEMS_H
#define VIEWITEMS_H

#include <QDialog>
#include <QSqlQueryModel>
#include "DatabaseManager.h"

namespace Ui {
class ViewItems;
}

class ViewItems : public QDialog
{
    Q_OBJECT

public:
    explicit ViewItems(QWidget *parent = nullptr);
    ~ViewItems();

private slots:
    void showClients();
    void showEmployees();
    void showManagers();
    void showMedicines();

private:
    Ui::ViewItems *ui;
    DatabaseManager dbManager;
};

#endif // VIEWITEMS_H
