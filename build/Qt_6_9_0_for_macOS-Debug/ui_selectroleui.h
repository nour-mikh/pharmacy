/********************************************************************************
** Form generated from reading UI file 'selectroleui.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECTROLEUI_H
#define UI_SELECTROLEUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_SelectRoleUI
{
public:
    QLabel *label;
    QLabel *label_2;
    QLineEdit *emailInputLogin;
    QLabel *label_3;
    QLineEdit *passwordInputLogin;
    QComboBox *roleInputLogin;
    QLabel *label_4;
    QPushButton *loginButton;

    void setupUi(QDialog *SelectRoleUI)
    {
        if (SelectRoleUI->objectName().isEmpty())
            SelectRoleUI->setObjectName("SelectRoleUI");
        SelectRoleUI->resize(842, 533);
        label = new QLabel(SelectRoleUI);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 20, 361, 51));
        label_2 = new QLabel(SelectRoleUI);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(70, 110, 121, 41));
        emailInputLogin = new QLineEdit(SelectRoleUI);
        emailInputLogin->setObjectName("emailInputLogin");
        emailInputLogin->setGeometry(QRect(70, 160, 271, 31));
        label_3 = new QLabel(SelectRoleUI);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(70, 230, 121, 41));
        passwordInputLogin = new QLineEdit(SelectRoleUI);
        passwordInputLogin->setObjectName("passwordInputLogin");
        passwordInputLogin->setGeometry(QRect(70, 280, 271, 31));
        roleInputLogin = new QComboBox(SelectRoleUI);
        roleInputLogin->addItem(QString());
        roleInputLogin->addItem(QString());
        roleInputLogin->addItem(QString());
        roleInputLogin->setObjectName("roleInputLogin");
        roleInputLogin->setGeometry(QRect(440, 200, 191, 61));
        label_4 = new QLabel(SelectRoleUI);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(450, 170, 121, 41));
        loginButton = new QPushButton(SelectRoleUI);
        loginButton->setObjectName("loginButton");
        loginButton->setGeometry(QRect(160, 360, 100, 32));

        retranslateUi(SelectRoleUI);

        loginButton->setDefault(true);


        QMetaObject::connectSlotsByName(SelectRoleUI);
    } // setupUi

    void retranslateUi(QDialog *SelectRoleUI)
    {
        SelectRoleUI->setWindowTitle(QCoreApplication::translate("SelectRoleUI", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("SelectRoleUI", "<html><head/><body><p><span style=\" font-size:36pt; font-weight:700;\">Select Role | Login</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("SelectRoleUI", "<html><head/><body><p><span style=\" font-size:24pt; font-weight:700;\">Email</span></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("SelectRoleUI", "<html><head/><body><p><span style=\" font-size:24pt; font-weight:700;\">Password</span></p></body></html>", nullptr));
        roleInputLogin->setItemText(0, QCoreApplication::translate("SelectRoleUI", "Client", nullptr));
        roleInputLogin->setItemText(1, QCoreApplication::translate("SelectRoleUI", "Employee", nullptr));
        roleInputLogin->setItemText(2, QCoreApplication::translate("SelectRoleUI", "Manager", nullptr));

        label_4->setText(QCoreApplication::translate("SelectRoleUI", "<html><head/><body><p><span style=\" font-size:24pt; font-weight:700;\">Role</span></p></body></html>", nullptr));
        loginButton->setText(QCoreApplication::translate("SelectRoleUI", "Login", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SelectRoleUI: public Ui_SelectRoleUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECTROLEUI_H
