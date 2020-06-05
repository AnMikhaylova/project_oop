#include "workwindowadm.h"
#include "ui_workwindowadm.h"

WorkWindowAdm::WorkWindowAdm(QWidget *parent, QString name) :
    QWidget(parent), user_name(name),
    ui(new Ui::WorkWindowAdm)
{
    ui->setupUi(this);
}

WorkWindowAdm::~WorkWindowAdm()
{
    delete ui;
}

//слот для обработки нажатия на кнопку добавления нового мета-описания
void WorkWindowAdm::on_new_meta_clicked()
{
    //создание нового окна
    windowNewMeta = new NewMeta(this, user_name);
    windowNewMeta->setWindowTitle(QString::fromLocal8Bit("Добавление нового мета-описания"));
    windowNewMeta->setWindowFlags(windowNewMeta->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    //делаем окно модальным
    windowNewMeta->setModal(true);
    windowNewMeta->exec();

}

//слот для обработки нажатия на кнопку редактирования/удаления мета-описания
void WorkWindowAdm::on_meta_clicked()
{
    //создание нового окна
    windowMeta = new Meta (this, user_name);
    windowMeta->setWindowTitle(QString::fromLocal8Bit("Редактирование и удаление мета-опсианий"));
    windowMeta->setWindowFlags(windowMeta->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    //делаем окно модальным
    windowMeta->setModal(true);
    windowMeta->exec();

}

//слот для обработки нажатия на кнопку редактирования метеорологических словарей
void WorkWindowAdm::on_edit_vocab_clicked()
{
    //создание нового окна
    windowEditVocabulary = new EditVocabulary ;
    windowEditVocabulary->setWindowTitle(QString::fromLocal8Bit("Редактирвоание словарей"));
    windowEditVocabulary->setWindowFlags(windowEditVocabulary->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    //делаем окно модальным
    windowEditVocabulary->setModal(true);
    windowEditVocabulary->exec();

}

//слот для обработки нажатия на кнопку добавления дисциплины
void WorkWindowAdm::on_discip_clicked()
{
    //создание нового окна
    windowNewDiscipline = new NewDiscipline ;
    windowNewDiscipline->setWindowTitle(QString::fromLocal8Bit("Добавление новой дисциплины"));
    windowNewDiscipline->setWindowFlags(windowNewDiscipline->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    //делаем окно модальным
    windowNewDiscipline->setModal(true);
    windowNewDiscipline->exec();

}

//слот для обработки нажатия на кнопку добавления вида наблюдения
void WorkWindowAdm::on_type_of_obs_clicked()
{
    //создание нового окна
    windowNewObs = new newtype_of_obs ;
    windowNewObs->setWindowTitle(QString::fromLocal8Bit("Добавление нового вида наблюдения"));
    windowNewObs->setWindowFlags(windowNewObs->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    //делаем окно модальным
    windowNewObs->setModal(true);
    windowNewObs->exec();

}

//слот для обработки нажатия на кнопку добавления параметра
void WorkWindowAdm::on_option_clicked()
{
    //создание нового окна
    windowNewOption = new NewOption ;
    windowNewOption->setWindowTitle(QString::fromLocal8Bit("Добавление нового параметра"));
    windowNewOption->setWindowFlags(windowNewOption->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    //делаем окно модальным
    windowNewOption->setModal(true);
    windowNewOption->exec();

}

//слот для обработки нажатия на кнопку добавления оператора
void WorkWindowAdm::on_operator_2_clicked()
{
    //создание нового окна
    windowNewOperator = new NewOperator ;
    windowNewOperator->setWindowTitle(QString::fromLocal8Bit("Добавление нового оператора"));
    windowNewOperator->setWindowFlags(windowNewOperator->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    //делаем окно модальным
    windowNewOperator->setModal(true);
    windowNewOperator->exec();
}
