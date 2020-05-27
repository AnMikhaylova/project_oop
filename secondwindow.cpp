#include "secondwindow.h"
#include "ui_secondwindow.h"


SecondWindow::SecondWindow(QWidget *parent, QString name ) :
    QDialog(parent), user_name(name),
    ui(new Ui::SecondWindow)
{
    ui->setupUi(this);
}

SecondWindow::~SecondWindow()
{
    delete ui;
}


void SecondWindow::on_pushButton_type_of_obs_clicked()
{
    newtype_of_obs windowNewObs;
    windowNewObs.setWindowTitle(QString::fromLocal8Bit("���������� ������ ���� ����������"));
    windowNewObs.setModal(true);
    windowNewObs.exec();

}

void SecondWindow::on_pushButton_discip_clicked()
{
    NewDiscipline windowNewDiscipline;
    windowNewDiscipline.setWindowTitle(QString::fromLocal8Bit("���������� ����� ����������"));
    windowNewDiscipline.setModal(true);
    windowNewDiscipline.exec();
}

void SecondWindow::on_option_clicked()
{
    NewOption windowNewOption;
    windowNewOption.setWindowTitle(QString::fromLocal8Bit("���������� ������ ���������"));
    windowNewOption.setModal(true);
    windowNewOption.exec();
}


void SecondWindow::on_operator_2_clicked()
{
    NewOperator windowNewOperator;
    windowNewOperator.setWindowTitle(QString::fromLocal8Bit("���������� ������ ���������"));
    windowNewOperator.setModal(true);
    windowNewOperator.exec();
}

void SecondWindow::on_new_meta_clicked()
{
    NewMeta windowNewMeta(this, user_name);
    windowNewMeta.setWindowTitle(QString::fromLocal8Bit("���������� ������ ���������"));
    windowNewMeta.setModal(true);
    windowNewMeta.exec();
}

void SecondWindow::on_pushButton_2_clicked()
{
    EditVocabulary windowEditVocabulary;
    windowEditVocabulary.setWindowTitle(QString::fromLocal8Bit("�������������� ��������"));
    windowEditVocabulary.setModal(true);
    windowEditVocabulary.exec();
}
