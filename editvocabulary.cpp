#include "editvocabulary.h"
#include "ui_editvocabulary.h"

EditVocabulary::EditVocabulary(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditVocabulary)
{
    ui->setupUi(this);
    QSqlQuery query;
    query.exec("SELECT * FROM disciplines");
    while (query.next())
    {
    ui->comboBox_discipline->addItem(query.value(1).toString());
    }
}

EditVocabulary::~EditVocabulary()
{
    delete ui;
}

void EditVocabulary::on_discipline_clicked()
{
    ui->comboBox_obs->clear();
    ui->comboBox_op->clear();
    QSqlQuery query;
    QString discip = ui->comboBox_discipline->currentText();
    query.exec("SELECT d_id FROM disciplines WHERE d_name ='" +discip+ "'" );
    while (query.next())
    {
    discip_id = query.value(0).toString();
    }

    ui->textEdit_discipline->setText(discip);

    query.exec("SELECT * FROM types_of_observations WHERE d_id =" +discip_id+ "");
    ui->comboBox_obs->clear();
    while (query.next())
    {
        ui->comboBox_obs->addItem(query.value(2).toString());

    }
}

void EditVocabulary::on_obs_clicked()
{
    ui->comboBox_op->clear();
    QString obs = ui->comboBox_obs->currentText();
    QSqlQuery query;
    query.exec("SELECT obs_id FROM types_of_observations WHERE obs_name ='" +obs+ "'" );
    while (query.next())
    {
    obs_id = query.value(0).toString();
    }

    ui->textEdit_obs->setText(obs);

    query.exec("SELECT * FROM options WHERE obs_id =" +obs_id+ "");
    while (query.next())
    {
        ui->comboBox_op->addItem(query.value(2).toString());

    }
}

void EditVocabulary::on_op_clicked()
{
    QString op = ui->comboBox_op->currentText();
    QSqlQuery query;
    query.exec("SELECT op_id FROM options WHERE op_name ='" +op+ "'" );
    while (query.next())
    {
    op_id = query.value(0).toString();
    }

    ui->textEdit_op->setText(op);
}

void EditVocabulary::on_discipline_change_clicked()
{

    QString changed_discip = ui->textEdit_discipline->toPlainText();
    QSqlQuery query;
    query.prepare("UPDATE disciplines SET d_name = ? WHERE d_id = ?");
    query.addBindValue(changed_discip);
    query.addBindValue(discip_id);
    if (!query.exec())
    {
        QMessageBox::warning(this, "Error", query.lastError().text());
    }
    else
    {

        QMessageBox::information(this, "OK", "Successfull!");
    }

}

void EditVocabulary::on_obs_change_clicked()
{
    QString changed_obs = ui->textEdit_obs->toPlainText();
    QSqlQuery query;
    query.prepare("UPDATE types_of_observations SET obs_name = ? WHERE obs_id = ?");
    query.addBindValue(changed_obs);
    query.addBindValue(obs_id);
    if (!query.exec())
    {
        QMessageBox::warning(this, "Error", query.lastError().text());
    }
    else
    {

        QMessageBox::information(this, "OK", "Successfull!");
    }
}

void EditVocabulary::on_op_change_clicked()
{
    QString changed_op = ui->textEdit_op->toPlainText();
    QSqlQuery query;
    query.prepare("UPDATE options SET op_name = ? WHERE op_id = ?");
    query.addBindValue(changed_op);
    query.addBindValue(op_id);
    if (!query.exec())
    {
        QMessageBox::warning(this, "Error", query.lastError().text());
    }
    else
    {

        QMessageBox::information(this, "OK", "Successfull!");
    }

}
