#ifndef SECONDWINDOWOPER_H
#define SECONDWINDOWOPER_H

#include <QDialog>
#include "newdiscipline.h"
#include "newtype_of_obs.h"
#include "newoption.h"
#include "newmeta.h"
#include "meta.h"

namespace Ui {
class SecondWindowOper;
}

class SecondWindowOper : public QDialog
{
    Q_OBJECT

public:
    explicit SecondWindowOper(QWidget *parent = nullptr,QString name = "");
    ~SecondWindowOper();

private slots:

    void on_pushButton_discip_oper_clicked();

    void on_pushButton_type_of_obs_oper_clicked();

    void on_pushButton_option_oper_clicked();

    void on_new_meta_clicked();

    void on_meta_clicked();

private:
    QString user_name;
    Ui::SecondWindowOper *ui;
};

#endif // SECONDWINDOWOPER_H
