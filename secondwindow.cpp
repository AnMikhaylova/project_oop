#include "secondwindow.h"
#include "ui_secondwindow.h"
#include "newvocabulary.h"
#include "newoperator.h"


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

void SecondWindow::on_pushButton_clicked()
{
    NewVocabulary windowNewVocabluary;
    windowNewVocabluary.setWindowTitle(QString::fromLocal8Bit("Добавление нового словаря"));
    windowNewVocabluary.setModal(true);
    windowNewVocabluary.exec();
}

void SecondWindow::on_pushButton_3_clicked()
{
    NewOperator windowNewOperator;
    windowNewOperator.setWindowTitle(QString::fromLocal8Bit("Добавление нового оператора"));
    windowNewOperator.setModal(true);
    windowNewOperator.exec();
}



