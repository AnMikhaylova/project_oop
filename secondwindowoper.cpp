#include "secondwindowoper.h"
#include "ui_secondwindowoper.h"

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
