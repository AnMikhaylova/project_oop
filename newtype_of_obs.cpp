#include "newtype_of_obs.h"
#include "ui_newtype_of_obs.h"
QString d_id;

newtype_of_obs::newtype_of_obs(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::newtype_of_obs)
{
    ui->setupUi(this);
    QSqlQuery query;
    query.exec("SELECT * FROM disciplines");
    while (query.next())
    {
    ui->comboBox->addItem(query.value(1).toString());
    }
}

newtype_of_obs::~newtype_of_obs()
{
    delete ui;
}

void newtype_of_obs::on_pushButton_clicked()
{
    QString discip = ui->comboBox->currentText();
    QSqlQuery query;
    query.exec("SELECT d_id FROM disciplines WHERE d_name ='" +discip+ "'" );
    while (query.next())
    {
    d_id = query.value(0).toString();
    }

}

void newtype_of_obs::on_pushButton_2_clicked()
{

    QString obs_name = ui->type_of_obs->text();
    QSqlQuery query;
    query.prepare("INSERT INTO types_of_observations (d_id, obs_name) VALUES (?, ?)");
    query.addBindValue(d_id);
    query.addBindValue(obs_name);
    if (!query.exec())
    {
        QMessageBox::warning(this, "Error", query.lastError().text());
    }
    else
    {

        QMessageBox::information(this, "OK", "Successfull!");
    }
}