/********************************************************************************
** Form generated from reading UI file 'medui.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MEDUI_H
#define UI_MEDUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_MedUI
{
public:
    QLabel *label;
    QLineEdit *medNameInput;
    QLabel *label_2;
    QLabel *label_3;
    QTextEdit *medDescInput;
    QLabel *label_4;
    QComboBox *medCatInput;
    QLabel *label_5;
    QSpinBox *medPriceInput;
    QSpinBox *medStockInput;
    QLabel *label_6;
    QPushButton *addMed;

    void setupUi(QDialog *MedUI)
    {
        if (MedUI->objectName().isEmpty())
            MedUI->setObjectName("MedUI");
        MedUI->resize(858, 480);
        label = new QLabel(MedUI);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 10, 361, 51));
        medNameInput = new QLineEdit(MedUI);
        medNameInput->setObjectName("medNameInput");
        medNameInput->setGeometry(QRect(50, 110, 281, 21));
        label_2 = new QLabel(MedUI);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(50, 80, 71, 21));
        label_3 = new QLabel(MedUI);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(50, 160, 101, 21));
        medDescInput = new QTextEdit(MedUI);
        medDescInput->setObjectName("medDescInput");
        medDescInput->setGeometry(QRect(50, 190, 281, 111));
        label_4 = new QLabel(MedUI);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(510, 80, 101, 21));
        medCatInput = new QComboBox(MedUI);
        medCatInput->addItem(QString());
        medCatInput->addItem(QString());
        medCatInput->addItem(QString());
        medCatInput->setObjectName("medCatInput");
        medCatInput->setGeometry(QRect(500, 100, 161, 41));
        label_5 = new QLabel(MedUI);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(510, 190, 141, 21));
        medPriceInput = new QSpinBox(MedUI);
        medPriceInput->setObjectName("medPriceInput");
        medPriceInput->setGeometry(QRect(640, 190, 51, 21));
        medStockInput = new QSpinBox(MedUI);
        medStockInput->setObjectName("medStockInput");
        medStockInput->setGeometry(QRect(640, 260, 51, 21));
        label_6 = new QLabel(MedUI);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(510, 260, 141, 21));
        addMed = new QPushButton(MedUI);
        addMed->setObjectName("addMed");
        addMed->setGeometry(QRect(380, 350, 100, 32));

        retranslateUi(MedUI);

        addMed->setDefault(true);


        QMetaObject::connectSlotsByName(MedUI);
    } // setupUi

    void retranslateUi(QDialog *MedUI)
    {
        MedUI->setWindowTitle(QCoreApplication::translate("MedUI", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("MedUI", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'.AppleSystemUIFont'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:36pt; font-weight:700;\">Add a new Medicine</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("MedUI", "<html><head/><body><p><span style=\" font-size:18pt; font-weight:700;\">Name</span></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("MedUI", "<html><head/><body><p><span style=\" font-size:18pt; font-weight:700;\">Description</span></p></body></html>", nullptr));
        label_4->setText(QCoreApplication::translate("MedUI", "<html><head/><body><p><span style=\" font-size:18pt; font-weight:700;\">Category</span></p></body></html>", nullptr));
        medCatInput->setItemText(0, QCoreApplication::translate("MedUI", "Painkiller", nullptr));
        medCatInput->setItemText(1, QCoreApplication::translate("MedUI", "Antibiotics", nullptr));
        medCatInput->setItemText(2, QCoreApplication::translate("MedUI", "Vitamins", nullptr));

        label_5->setText(QCoreApplication::translate("MedUI", "<html><head/><body><p><span style=\" font-size:18pt; font-weight:700;\">Price per unit</span></p></body></html>", nullptr));
        label_6->setText(QCoreApplication::translate("MedUI", "<html><head/><body><p><span style=\" font-size:18pt; font-weight:700;\">Items in Stock</span></p></body></html>", nullptr));
        addMed->setText(QCoreApplication::translate("MedUI", "Add Medicine", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MedUI: public Ui_MedUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MEDUI_H
