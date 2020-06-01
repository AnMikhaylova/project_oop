#include "workwindowoper.h"
#include "ui_workwindowoper.h"

WorkWindowOper::WorkWindowOper(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WorkWindowOper)
{
    ui->setupUi(this);
}

WorkWindowOper::~WorkWindowOper()
{
    delete ui;
}
