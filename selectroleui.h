#ifndef SELECTROLEUI_H
#define SELECTROLEUI_H

#include <QDialog>

namespace Ui {
class SelectRoleUI;
}

class SelectRoleUI : public QDialog
{
    Q_OBJECT

public:
    explicit SelectRoleUI(QWidget *parent = nullptr);
    ~SelectRoleUI();

private:
    Ui::SelectRoleUI *ui;

private slots:
    void handleLogin();

signals:
    void loginSuccessful(const QString& userName);
};

#endif // SELECTROLEUI_H
