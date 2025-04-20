/********************************************************************************
** Form generated from reading UI file 'receipt.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECEIPT_H
#define UI_RECEIPT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Receipt
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *itemNameInReceipt;
    QLineEdit *receiptClientName;
    QPushButton *receiptSaleItemAdd;
    QFrame *line;
    QLCDNumber *lcdNumber;

    void setupUi(QDialog *Receipt)
    {
        if (Receipt->objectName().isEmpty())
            Receipt->setObjectName("Receipt");
        Receipt->resize(845, 532);
        label = new QLabel(Receipt);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 10, 351, 61));
        label_2 = new QLabel(Receipt);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(60, 130, 151, 21));
        label_3 = new QLabel(Receipt);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(480, 130, 131, 21));
        label_4 = new QLabel(Receipt);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(220, 330, 111, 51));
        itemNameInReceipt = new QLineEdit(Receipt);
        itemNameInReceipt->setObjectName("itemNameInReceipt");
        itemNameInReceipt->setGeometry(QRect(60, 160, 251, 21));
        receiptClientName = new QLineEdit(Receipt);
        receiptClientName->setObjectName("receiptClientName");
        receiptClientName->setGeometry(QRect(440, 160, 191, 21));
        receiptSaleItemAdd = new QPushButton(Receipt);
        receiptSaleItemAdd->setObjectName("receiptSaleItemAdd");
        receiptSaleItemAdd->setGeometry(QRect(130, 200, 100, 32));
        line = new QFrame(Receipt);
        line->setObjectName("line");
        line->setGeometry(QRect(370, 150, 3, 61));
        line->setFrameShape(QFrame::Shape::VLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);
        lcdNumber = new QLCDNumber(Receipt);
        lcdNumber->setObjectName("lcdNumber");
        lcdNumber->setGeometry(QRect(350, 310, 181, 91));

        retranslateUi(Receipt);

        QMetaObject::connectSlotsByName(Receipt);
    } // setupUi

    void retranslateUi(QDialog *Receipt)
    {
        Receipt->setWindowTitle(QCoreApplication::translate("Receipt", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Receipt", "<html><head/><body><p><span style=\" font-size:36pt;\">Receipt Creation</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("Receipt", "<html><head/><body><p><span style=\" font-size:18pt; font-weight:700;\">Sale Item Name</span></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("Receipt", "<html><head/><body><p><span style=\" font-size:18pt; font-weight:700;\">Client Name</span></p></body></html>", nullptr));
        label_4->setText(QCoreApplication::translate("Receipt", "<html><head/><body><p><span style=\" font-size:24pt; font-weight:700;\">Total</span></p></body></html>", nullptr));
        receiptSaleItemAdd->setText(QCoreApplication::translate("Receipt", "Add Item", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Receipt: public Ui_Receipt {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECEIPT_H
