#include "secondwindowoper.h"
#include "ui_secondwindowoper.h"

SecondWindowOper::SecondWindowOper(QWidget *parent, QString name) :
    QDialog(parent), user_name(name),
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

void SecondWindowOper::on_new_meta_clicked()
{
    NewMeta windowNewMeta(this, user_name);
    windowNewMeta.setWindowTitle(QString::fromLocal8Bit("Добавление нового мета-описания"));
    windowNewMeta.setModal(true);
    windowNewMeta.exec();
}

void SecondWindowOper::on_meta_clicked()
{
    Meta windowMeta(this, user_name);
    windowMeta.setWindowTitle(QString::fromLocal8Bit("Редактирование и удаление мета-опсианий"));
    windowMeta.setModal(true);
    windowMeta.exec();
}
