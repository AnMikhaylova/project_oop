#include "newoption.h"
#include "ui_newoption.h"
#include "sql.h"
#include <QTextCodec>
QString obs_id;

NewOption::NewOption(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewOption)
{
    ui->setupUi(this);
    QSqlQuery query;
    query.exec("SELECT * FROM disciplines");
    while (query.next())
    {
    ui->comboBox_discipline->addItem(query.value(1).toString());
    }
}

NewOption::~NewOption()
{
    delete ui;
}



void NewOption::on_pushButton_2_clicked()
{
    QSqlQuery query;
    QString op_name = ui->option->text();
    query.prepare("INSERT INTO options (obs_id, op_name) VALUES (?, ?)");
    query.addBindValue(obs_id);
    query.addBindValue(op_name);
    if (!query.exec())
    {
        QMessageBox::warning(this, "Error", query.lastError().text());
    }
    else
    {

        QMessageBox::information(this, "OK", "Successfull!");
    }
}

void NewOption::on_discipline_clicked()
{
    QSqlQuery query;
    QString discip_id;
    QString discip = ui->comboBox_discipline->currentText();
    query.exec("SELECT d_id FROM disciplines WHERE d_name ='" +discip+ "'" );
    while (query.next())
    {
    discip_id = query.value(0).toString();
    }

    query.exec("SELECT * FROM types_of_observations WHERE d_id =" +discip_id+ "");
    ui->comboBox_obs->clear();
    while (query.next())
    {
        ui->comboBox_obs->addItem(query.value(2).toString());

    }

}

void NewOption::on_obs_clicked()
{
    ui->listWidget->clear();
    QString obs = ui->comboBox_obs->currentText();
    QSqlQuery query;
    query.exec("SELECT obs_id FROM types_of_observations WHERE obs_name ='" +obs+ "'" );
    while (query.next())
    {
    obs_id = query.value(0).toString();
    }

    query.exec("SELECT * FROM options WHERE obs_id =" +obs_id+ "");
    while (query.next())
    {
        ui->listWidget->addItem(query.value(2).toString());

    }
}
