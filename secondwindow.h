#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QDialog>
#include "newoperator.h"
#include "newtype_of_obs.h"
#include "newdiscipline.h"
#include "newoption.h"
#include "newmeta.h"

namespace Ui {
class SecondWindow;
}

class SecondWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SecondWindow(QWidget *parent = nullptr, QString name = "");
    ~SecondWindow();

private slots:

    void on_pushButton_type_of_obs_clicked();

    void on_pushButton_discip_clicked();

    void on_option_clicked();

    void on_operator_2_clicked();

    void on_new_meta_clicked();

private:
    QString user_name;
    Ui::SecondWindow *ui;

};

#endif // SECONDWINDOW_H
