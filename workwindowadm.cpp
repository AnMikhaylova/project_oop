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

void WorkWindowAdm::on_new_meta_clicked()
{
    windowNewMeta = new NewMeta(this, user_name);
    windowNewMeta->setWindowTitle(QString::fromLocal8Bit("���������� ������ ����-��������"));
    windowNewMeta->setModal(true);
    windowNewMeta->exec();

}

void WorkWindowAdm::on_meta_clicked()
{
    windowMeta = new Meta (this, user_name);
    windowMeta->setWindowTitle(QString::fromLocal8Bit("�������������� � �������� ����-��������"));
    windowMeta->setModal(true);
    windowMeta->exec();

}

void WorkWindowAdm::on_edit_vocab_clicked()
{
    windowEditVocabulary = new EditVocabulary ;
    windowEditVocabulary->setWindowTitle(QString::fromLocal8Bit("�������������� ��������"));
    windowEditVocabulary->setModal(true);
    windowEditVocabulary->exec();

}

void WorkWindowAdm::on_discip_clicked()
{
    windowNewDiscipline = new NewDiscipline ;
    windowNewDiscipline->setWindowTitle(QString::fromLocal8Bit("���������� ����� ����������"));
    windowNewDiscipline->setModal(true);
    windowNewDiscipline->exec();

}

void WorkWindowAdm::on_type_of_obs_clicked()
{
    windowNewObs = new newtype_of_obs ;
    windowNewObs->setWindowTitle(QString::fromLocal8Bit("���������� ������ ���� ����������"));
    windowNewObs->setModal(true);
    windowNewObs->exec();

}

void WorkWindowAdm::on_option_clicked()
{
    windowNewOption = new NewOption ;
    windowNewOption->setWindowTitle(QString::fromLocal8Bit("���������� ������ ���������"));
    windowNewOption->setModal(true);
    windowNewOption->exec();

}

void WorkWindowAdm::on_operator_2_clicked()
{
    windowNewOperator = new NewOperator ;
    windowNewOperator->setWindowTitle(QString::fromLocal8Bit("���������� ������ ���������"));
    windowNewOperator->setModal(true);
    windowNewOperator->exec();
}
