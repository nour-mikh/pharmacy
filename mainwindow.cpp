#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "DatabaseManager.h"
#include "personui.h"
#include "receipt.h"
#include "selectroleui.h"
#include "viewitems.h"
#include "medui.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    if (!db.openDatabase()) {
        qDebug() << "Failed to open database!";
    } else {
        qDebug() << "Database opened successfully.";
    }
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_personPage_clicked() {
    PersonUI *personWindow = new PersonUI(this);
    personWindow->setModal(true);
    personWindow->show();
}

void MainWindow::on_receiptPage_clicked() {
    Receipt *receiptWindow = new Receipt(this);
    receiptWindow->setModal(true);
    receiptWindow->show();
}

void MainWindow::on_selectRoleWelcome_clicked() {
    SelectRoleUI *roleWindow = new SelectRoleUI(this);

    connect(roleWindow, &SelectRoleUI::loginSuccessful, this, [=](const QString& name){
        ui->loggedInName->setText(name);
    });

    roleWindow->setModal(true);
    roleWindow->exec();
}

void MainWindow::on_medPage_clicked() {
    MedUI *medWinodw = new MedUI(this);
    medWinodw->setModal(true);
    medWinodw->show();
}

void MainWindow::on_viewItems_clicked(){
    ViewItems *viewItems = new ViewItems(this);
    viewItems->setModal(true);
    viewItems->show();
}

void MainWindow::on_logOutWelcome_clicked(){
    handleLogout();
}

void MainWindow::handleLogout()
{
    ui->loggedInName->setText("No one");
}
