#include "secondwindowoper.h"
#include "ui_secondwindowoper.h"
#include "newdiscipline.h"
#include "newtype_of_obs.h"
#include "newoption.h"

SecondWindowOper::SecondWindowOper(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SecondWindowOper)
{
    ui->setupUi(this);
}

SecondWindowOper::~SecondWindowOper()
{
    delete ui;
}


void SecondWindowOper::on_pushButton_discip_oper_clicked()
{
    NewDiscipline windowNewDiscipline_op;
    windowNewDiscipline_op.setWindowTitle(QString::fromLocal8Bit("Добавление новой дисциплины"));
    windowNewDiscipline_op.setModal(true);
    windowNewDiscipline_op.exec();
}

void SecondWindowOper::on_pushButton_type_of_obs_oper_clicked()
{
    newtype_of_obs windowNewObs_op;
    windowNewObs_op.setWindowTitle(QString::fromLocal8Bit("Добавление нового вида наблюдения"));
    windowNewObs_op.setModal(true);
    windowNewObs_op.exec();
}

void SecondWindowOper::on_pushButton_option_oper_clicked()
{
    NewOption windowNewOption_op;
    windowNewOption_op.setWindowTitle(QString::fromLocal8Bit("Добавление нового параметра"));
    windowNewOption_op.setModal(true);
    windowNewOption_op.exec();
}
