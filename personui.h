#ifndef PERSONUI_H
#define PERSONUI_H

#include <QDialog>

namespace Ui {
class PersonUI;
}

class PersonUI : public QDialog
{
    Q_OBJECT

public:
    explicit PersonUI(QWidget *parent = nullptr);
    ~PersonUI();

private:
    Ui::PersonUI *ui;

private slots:
    void handleCreateUser();
};

#endif // PERSONUI_H
