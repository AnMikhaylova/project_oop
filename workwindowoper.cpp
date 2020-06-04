#include "workwindowoper.h"
#include "ui_workwindowoper.h"

WorkWindowOper::WorkWindowOper(QWidget *parent, QString name) :
    QWidget(parent), user_name(name),
    ui(new Ui::WorkWindowOper)
{
    ui->setupUi(this);
}

WorkWindowOper::~WorkWindowOper()
{
    delete ui;
}

void WorkWindowOper::on_new_meta_clicked()
{
    windowNewMeta = new NewMeta(this, user_name);
    windowNewMeta->setWindowTitle(QString::fromLocal8Bit("Добавление нового мета-описания"));
    windowNewMeta->setWindowFlags(windowNewMeta->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    windowNewMeta->setModal(true);
    windowNewMeta->exec();

}

void WorkWindowOper::on_meta_clicked()
{
    windowMeta = new Meta (this, user_name);
    windowMeta->setWindowTitle(QString::fromLocal8Bit("Редактирование и удаление мета-опсианий"));
    windowMeta->setWindowFlags(windowMeta->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    windowMeta->setModal(true);
    windowMeta->exec();

}

void WorkWindowOper::on_edit_vocab_clicked()
{
    windowEditVocabulary = new EditVocabulary ;
    windowEditVocabulary->setWindowTitle(QString::fromLocal8Bit("Редактирвоание словарей"));
    windowEditVocabulary->setWindowFlags(windowEditVocabulary->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    windowEditVocabulary->setModal(true);
    windowEditVocabulary->exec();

}

void WorkWindowOper::on_discip_clicked()
{
    windowNewDiscipline = new NewDiscipline ;
    windowNewDiscipline->setWindowTitle(QString::fromLocal8Bit("Добавление новой дисциплины"));
    windowNewDiscipline->setWindowFlags(windowNewDiscipline->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    windowNewDiscipline->setModal(true);
    windowNewDiscipline->exec();

}

void WorkWindowOper::on_type_of_obs_clicked()
{
    windowNewObs = new newtype_of_obs ;
    windowNewObs->setWindowTitle(QString::fromLocal8Bit("Добавление нового вида наблюдения"));
    windowNewObs->setWindowFlags(windowNewObs->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    windowNewObs->setModal(true);
    windowNewObs->exec();

}

void WorkWindowOper::on_option_clicked()
{
    windowNewOption = new NewOption ;
    windowNewOption->setWindowTitle(QString::fromLocal8Bit("Добавление нового параметра"));
    windowNewOption->setWindowFlags(windowNewOption->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    windowNewOption->setModal(true);
    windowNewOption->exec();

}

