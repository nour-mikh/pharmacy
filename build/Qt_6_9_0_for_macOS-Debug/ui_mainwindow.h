/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *receiptPage;
    QPushButton *personPage;
    QPushButton *medPage;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *selectRoleWelcome;
    QPushButton *logOutWelcome;
    QPushButton *viewItems;
    QLabel *label_2;
    QLabel *loggedInName;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(210, 80, 361, 131));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(230, 260, 353, 32));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        receiptPage = new QPushButton(layoutWidget);
        receiptPage->setObjectName("receiptPage");
        receiptPage->setAutoDefault(false);
        receiptPage->setFlat(false);

        horizontalLayout->addWidget(receiptPage);

        personPage = new QPushButton(layoutWidget);
        personPage->setObjectName("personPage");
        personPage->setAutoDefault(false);
        personPage->setFlat(false);

        horizontalLayout->addWidget(personPage);

        medPage = new QPushButton(layoutWidget);
        medPage->setObjectName("medPage");
        medPage->setAutoDefault(false);
        medPage->setFlat(false);

        horizontalLayout->addWidget(medPage);

        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(290, 330, 192, 32));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        selectRoleWelcome = new QPushButton(layoutWidget1);
        selectRoleWelcome->setObjectName("selectRoleWelcome");
        selectRoleWelcome->setAutoDefault(false);
        selectRoleWelcome->setFlat(false);

        horizontalLayout_2->addWidget(selectRoleWelcome);

        logOutWelcome = new QPushButton(layoutWidget1);
        logOutWelcome->setObjectName("logOutWelcome");
        logOutWelcome->setAutoDefault(false);
        logOutWelcome->setFlat(false);

        horizontalLayout_2->addWidget(logOutWelcome);

        viewItems = new QPushButton(centralwidget);
        viewItems->setObjectName("viewItems");
        viewItems->setEnabled(true);
        viewItems->setGeometry(QRect(690, 40, 81, 71));
        viewItems->setAutoFillBackground(false);
        viewItems->setAutoDefault(false);
        viewItems->setFlat(false);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(290, 400, 111, 21));
        loggedInName = new QLabel(centralwidget);
        loggedInName->setObjectName("loggedInName");
        loggedInName->setGeometry(QRect(410, 400, 61, 21));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 37));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        receiptPage->setDefault(true);
        personPage->setDefault(true);
        medPage->setDefault(true);
        selectRoleWelcome->setDefault(false);
        logOutWelcome->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:48pt; font-weight:700;\">Welcome to our</span></p><p align=\"center\"><span style=\" font-size:48pt; font-weight:700;\">Pharmacy</span></p></body></html>", nullptr));
        receiptPage->setText(QCoreApplication::translate("MainWindow", "New Receipt", nullptr));
        personPage->setText(QCoreApplication::translate("MainWindow", "New Person", nullptr));
        medPage->setText(QCoreApplication::translate("MainWindow", "New Medicine", nullptr));
        selectRoleWelcome->setText(QCoreApplication::translate("MainWindow", "Select Role", nullptr));
        logOutWelcome->setText(QCoreApplication::translate("MainWindow", "Log Out", nullptr));
        viewItems->setText(QCoreApplication::translate("MainWindow", "View Items", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:18pt; font-weight:700;\">Logged in as:</span></p></body></html>", nullptr));
        loggedInName->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:18pt; font-weight:700; color:#ff2113;\">No one</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
