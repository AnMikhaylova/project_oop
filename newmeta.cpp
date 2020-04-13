#include "newmeta.h"
#include "ui_newmeta.h"

NewMeta::NewMeta(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewMeta)
{
    ui->setupUi(this);
}

NewMeta::~NewMeta()
{
    delete ui;
}
