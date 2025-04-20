#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "DatabaseManager.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_personPage_clicked();
    void on_receiptPage_clicked();
    void on_selectRoleWelcome_clicked();
    void on_medPage_clicked();
    void on_viewItems_clicked();
    void on_logOutWelcome_clicked();
    void handleLogout();

private:
    Ui::MainWindow *ui;
    DatabaseManager db;
};
#endif // MAINWINDOW_H
