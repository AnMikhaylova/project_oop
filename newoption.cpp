#include "newoption.h"
#include "ui_newoption.h"


NewOption::NewOption(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewOption)
{
    ui->setupUi(this);
    ui->comboBox_discipline->setSizeAdjustPolicy(QComboBox::AdjustToMinimumContentsLength);
    ui->comboBox_obs->setSizeAdjustPolicy(QComboBox::AdjustToMinimumContentsLength);
    QSqlQuery query;
    query.exec("SELECT * FROM disciplines");
    int i = 0;
    while (query.next())
    {
    ui->comboBox_discipline->addItem(query.value(1).toString());
    ui->comboBox_discipline->setItemData(i, query.value(1).toString(), Qt::ToolTipRole);
    i++;
    }
    ui->pushButton_2->setShortcut(Qt::Key_Return);
}

NewOption::~NewOption()
{
    delete ui;
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
    int i = 0;
    while (query.next())
    {
        ui->comboBox_obs->addItem(query.value(2).toString());
        ui->comboBox_obs->setItemData(i, query.value(2).toString(), Qt::ToolTipRole);
        i++;

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

void NewOption::on_pushButton_2_clicked()
{
    QSqlQuery query;
    QString op_name = ui->option->text();
    query.prepare("INSERT INTO options (obs_id, op_name) VALUES (?, ?)");
    query.addBindValue(obs_id);
    query.addBindValue(op_name);
    if (!query.exec())
    {
        QMessageBox::warning(this, QString::fromLocal8Bit("Ошибка"), query.lastError().text());
    }
    else
    {

        QMessageBox::information(this, "OK", QString::fromLocal8Bit("Новый параметр успешно добавлен"));
    }
}
