#ifndef MEDUI_H
#define MEDUI_H

#include <QDialog>

namespace Ui {
class MedUI;
}

class MedUI : public QDialog
{
    Q_OBJECT

public:
    explicit MedUI(QWidget *parent = nullptr);
    ~MedUI();

private:
    Ui::MedUI *ui;

private slots:
    void handleCreateMedicine();
};

#endif // MEDUI_H
