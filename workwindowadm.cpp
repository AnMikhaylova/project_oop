#include "workwindowadm.h"
#include "ui_workwindowadm.h"

WorkWindowAdm::WorkWindowAdm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WorkWindowAdm)
{
    ui->setupUi(this);
}

WorkWindowAdm::~WorkWindowAdm()
{
    delete ui;
}
