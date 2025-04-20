/********************************************************************************
** Form generated from reading UI file 'personui.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PERSONUI_H
#define UI_PERSONUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_PersonUI
{
public:
    QLineEdit *nameInput;
    QLineEdit *numberPhoneInput;
    QLineEdit *emailInput;
    QLineEdit *passInput;
    QLineEdit *addressInput;
    QLabel *personName;
    QLabel *personName_2;
    QLabel *personName_3;
    QLabel *personName_4;
    QLabel *personName_5;
    QDateEdit *dateInput;
    QLabel *personName_6;
    QComboBox *comboPersonRole;
    QLabel *personName_7;
    QPushButton *addPersonButton;

    void setupUi(QDialog *PersonUI)
    {
        if (PersonUI->objectName().isEmpty())
            PersonUI->setObjectName("PersonUI");
        PersonUI->resize(862, 534);
        nameInput = new QLineEdit(PersonUI);
        nameInput->setObjectName("nameInput");
        nameInput->setGeometry(QRect(80, 70, 181, 21));
        numberPhoneInput = new QLineEdit(PersonUI);
        numberPhoneInput->setObjectName("numberPhoneInput");
        numberPhoneInput->setGeometry(QRect(80, 130, 181, 21));
        emailInput = new QLineEdit(PersonUI);
        emailInput->setObjectName("emailInput");
        emailInput->setGeometry(QRect(80, 190, 181, 21));
        passInput = new QLineEdit(PersonUI);
        passInput->setObjectName("passInput");
        passInput->setGeometry(QRect(80, 260, 181, 21));
        addressInput = new QLineEdit(PersonUI);
        addressInput->setObjectName("addressInput");
        addressInput->setGeometry(QRect(380, 70, 171, 41));
        personName = new QLabel(PersonUI);
        personName->setObjectName("personName");
        personName->setGeometry(QRect(80, 50, 58, 16));
        personName_2 = new QLabel(PersonUI);
        personName_2->setObjectName("personName_2");
        personName_2->setGeometry(QRect(80, 110, 91, 16));
        personName_3 = new QLabel(PersonUI);
        personName_3->setObjectName("personName_3");
        personName_3->setGeometry(QRect(80, 170, 91, 16));
        personName_4 = new QLabel(PersonUI);
        personName_4->setObjectName("personName_4");
        personName_4->setGeometry(QRect(80, 240, 91, 16));
        personName_5 = new QLabel(PersonUI);
        personName_5->setObjectName("personName_5");
        personName_5->setGeometry(QRect(380, 50, 58, 16));
        dateInput = new QDateEdit(PersonUI);
        dateInput->setObjectName("dateInput");
        dateInput->setGeometry(QRect(380, 170, 161, 22));
        personName_6 = new QLabel(PersonUI);
        personName_6->setObjectName("personName_6");
        personName_6->setGeometry(QRect(380, 140, 151, 16));
        comboPersonRole = new QComboBox(PersonUI);
        comboPersonRole->addItem(QString());
        comboPersonRole->addItem(QString());
        comboPersonRole->addItem(QString());
        comboPersonRole->setObjectName("comboPersonRole");
        comboPersonRole->setGeometry(QRect(370, 250, 161, 32));
        personName_7 = new QLabel(PersonUI);
        personName_7->setObjectName("personName_7");
        personName_7->setGeometry(QRect(390, 230, 151, 16));
        addPersonButton = new QPushButton(PersonUI);
        addPersonButton->setObjectName("addPersonButton");
        addPersonButton->setGeometry(QRect(270, 300, 100, 32));

        retranslateUi(PersonUI);

        addPersonButton->setDefault(true);


        QMetaObject::connectSlotsByName(PersonUI);
    } // setupUi

    void retranslateUi(QDialog *PersonUI)
    {
        PersonUI->setWindowTitle(QCoreApplication::translate("PersonUI", "Dialog", nullptr));
        personName->setText(QCoreApplication::translate("PersonUI", "Name", nullptr));
        personName_2->setText(QCoreApplication::translate("PersonUI", "Phone Number", nullptr));
        personName_3->setText(QCoreApplication::translate("PersonUI", "Email", nullptr));
        personName_4->setText(QCoreApplication::translate("PersonUI", "Password", nullptr));
        personName_5->setText(QCoreApplication::translate("PersonUI", "Address", nullptr));
        personName_6->setText(QCoreApplication::translate("PersonUI", "Date of Birth", nullptr));
        comboPersonRole->setItemText(0, QCoreApplication::translate("PersonUI", "Client", nullptr));
        comboPersonRole->setItemText(1, QCoreApplication::translate("PersonUI", "Employee", nullptr));
        comboPersonRole->setItemText(2, QCoreApplication::translate("PersonUI", "Manager", nullptr));

        personName_7->setText(QCoreApplication::translate("PersonUI", "Role", nullptr));
        addPersonButton->setText(QCoreApplication::translate("PersonUI", "Add Person", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PersonUI: public Ui_PersonUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PERSONUI_H
