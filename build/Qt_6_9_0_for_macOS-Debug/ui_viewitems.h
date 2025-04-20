/********************************************************************************
** Form generated from reading UI file 'viewitems.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEWITEMS_H
#define UI_VIEWITEMS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_ViewItems
{
public:
    QTableView *tableView;
    QPushButton *clientShow;
    QPushButton *employeeShow;
    QPushButton *managerShow;
    QPushButton *medicineShow;
    QLabel *label;

    void setupUi(QDialog *ViewItems)
    {
        if (ViewItems->objectName().isEmpty())
            ViewItems->setObjectName("ViewItems");
        ViewItems->resize(792, 506);
        tableView = new QTableView(ViewItems);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(70, 180, 671, 291));
        clientShow = new QPushButton(ViewItems);
        clientShow->setObjectName("clientShow");
        clientShow->setGeometry(QRect(150, 120, 100, 32));
        employeeShow = new QPushButton(ViewItems);
        employeeShow->setObjectName("employeeShow");
        employeeShow->setGeometry(QRect(280, 120, 100, 32));
        managerShow = new QPushButton(ViewItems);
        managerShow->setObjectName("managerShow");
        managerShow->setGeometry(QRect(410, 120, 100, 32));
        medicineShow = new QPushButton(ViewItems);
        medicineShow->setObjectName("medicineShow");
        medicineShow->setGeometry(QRect(530, 120, 100, 32));
        label = new QLabel(ViewItems);
        label->setObjectName("label");
        label->setGeometry(QRect(70, 50, 211, 51));

        retranslateUi(ViewItems);

        clientShow->setDefault(true);
        managerShow->setDefault(true);


        QMetaObject::connectSlotsByName(ViewItems);
    } // setupUi

    void retranslateUi(QDialog *ViewItems)
    {
        ViewItems->setWindowTitle(QCoreApplication::translate("ViewItems", "Dialog", nullptr));
        clientShow->setText(QCoreApplication::translate("ViewItems", "Clients", nullptr));
        employeeShow->setText(QCoreApplication::translate("ViewItems", "Employees", nullptr));
        managerShow->setText(QCoreApplication::translate("ViewItems", "Managers", nullptr));
        medicineShow->setText(QCoreApplication::translate("ViewItems", "Medicines", nullptr));
        label->setText(QCoreApplication::translate("ViewItems", "<html><head/><body><p><span style=\" font-size:24pt; font-weight:700;\">View Items</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ViewItems: public Ui_ViewItems {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEWITEMS_H
