#include "newmeta.h"
#include "ui_newmeta.h"
#include "sql.h"


NewMeta::NewMeta(QWidget *parent, QString name) :
    QDialog(parent), user_name(name),
    ui(new Ui::NewMeta)
{
    ui->setupUi(this);
    QSqlQuery query;
    query.exec("SELECT * FROM disciplines");
    while (query.next())
    {
    ui->discip->addItem(query.value(1).toString());
    }

    query.exec("SELECT * FROM publication_languages");
    while (query.next())
    {
    ui->publ_lng->addItem(query.value(1).toString());
    }

    query.exec("SELECT * FROM country");
    while (query.next())
    {
    ui->cntr->addItem(query.value(1).toString());
    }

    query.exec("SELECT * FROM view_type");
    while (query.next())
    {
    ui->view_type->addItem(query.value(1).toString());
    }

    ui->oper_name->addItem(user_name);


}

NewMeta::~NewMeta()
{
    delete ui;
}

void NewMeta::on_pushButton_discip_clicked()
{
    QSqlQuery query;
    QString discip_id;
    QString discip = ui->discip->currentText();
    query.exec("SELECT d_id FROM disciplines WHERE d_name ='" +discip+ "'" );
    while (query.next())
    {
    discip_id = query.value(0).toString();
    }

    query.exec("SELECT * FROM types_of_observations WHERE d_id =" +discip_id+ "");
    ui->type_of_obs->clear();
    while (query.next())
    {
        ui->type_of_obs->addItem(query.value(2).toString());

    }
}

void NewMeta::on_pushButton_obs_clicked()
{

    QString obs = ui->type_of_obs->currentText();
    QString obs_id;
    QSqlQuery query;
    query.exec("SELECT obs_id FROM types_of_observations WHERE obs_name ='" +obs+ "'" );
    while (query.next())
    {
    obs_id = query.value(0).toString();
    }

    query.exec("SELECT * FROM options WHERE obs_id =" +obs_id+ "");
    while (query.next())
    {
        ui->option->addItem(query.value(2).toString());

    }


}
