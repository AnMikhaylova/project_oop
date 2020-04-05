#include "secondwindow.h"
#include "ui_secondwindow.h"
#include "newvocabulary.h"
#include "newoperator.h"
#include "newtype_of_obs.h"
#include "newdiscipline.h"
#include "newoption.h"


SecondWindow::SecondWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SecondWindow)
{
    ui->setupUi(this);
}

SecondWindow::~SecondWindow()
{
    delete ui;
}



void SecondWindow::on_pushButton_operator_clicked()
{
    NewOperator windowNewOperator;
    windowNewOperator.setWindowTitle(QString::fromLocal8Bit("Добавление нового оператора"));
    windowNewOperator.setModal(true);
    windowNewOperator.exec();
}




void SecondWindow::on_pushButton_type_of_obs_clicked()
{
    newtype_of_obs windowNewObs;
    windowNewObs.setWindowTitle(QString::fromLocal8Bit("Добавление нового вида наблюдения"));
    windowNewObs.setModal(true);
    windowNewObs.exec();

}

void SecondWindow::on_pushButton_discip_clicked()
{
    NewDiscipline windowNewDiscipline;
    windowNewDiscipline.setWindowTitle(QString::fromLocal8Bit("Добавление новой дисциплины"));
    windowNewDiscipline.setModal(true);
    windowNewDiscipline.exec();
}

void SecondWindow::on_option_clicked()
{
    NewOption windowNewOption;
    windowNewOption.setWindowTitle(QString::fromLocal8Bit("Добавление нового параметра"));
    windowNewOption.setModal(true);
    windowNewOption.exec();
}
