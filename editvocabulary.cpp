#include "editvocabulary.h"
#include "ui_editvocabulary.h"

EditVocabulary::EditVocabulary(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditVocabulary)
{
    ui->setupUi(this);
}

EditVocabulary::~EditVocabulary()
{
    delete ui;
}
