#ifndef SECONDWINDOWOPER_H
#define SECONDWINDOWOPER_H

#include <QDialog>

namespace Ui {
class SecondWindowOper;
}

class SecondWindowOper : public QDialog
{
    Q_OBJECT

public:
    explicit SecondWindowOper(QWidget *parent = nullptr);
    ~SecondWindowOper();

private slots:

    void on_pushButton_discip_oper_clicked();

    void on_pushButton_type_of_obs_oper_clicked();

    void on_pushButton_option_oper_clicked();

private:
    Ui::SecondWindowOper *ui;
};

#endif // SECONDWINDOWOPER_H
