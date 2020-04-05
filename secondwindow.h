#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QDialog>

namespace Ui {
class SecondWindow;
}

class SecondWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SecondWindow(QWidget *parent = nullptr);
    ~SecondWindow();

private slots:
    void on_pushButton_operator_clicked();

    void on_pushButton_type_of_obs_clicked();

    void on_pushButton_discip_clicked();

    void on_option_clicked();

private:
    Ui::SecondWindow *ui;
};

#endif // SECONDWINDOW_H
