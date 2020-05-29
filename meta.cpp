#include "meta.h"
#include "ui_meta.h"

Meta::Meta(QWidget *parent, QString name) :
    QDialog(parent), user_name(name),
    ui(new Ui::Meta)
{
    ui->setupUi(this);
    QSqlQuery query;
    if (user_name == "admin")
        query.exec("SELECT invent_num FROM meta");
    else
        query.exec("SELECT invent_num FROM meta WHERE oper_name = '" + user_name+ "'");
    while (query.next())
    {
        ui->comboBox_meta->addItem(query.value(0).toString());
    }
}

Meta::~Meta()
{
    delete ui;
}

void Meta::on_pushButton_delete_clicked()
{

    QSqlQuery query;
    query.prepare("DELETE FROM meta WHERE invent_num = ?");
    query.addBindValue(delete_meta);
    if (!query.exec())
    {
        QMessageBox::warning(this, "Error", query.lastError().text());
    }
    else
    {

        QMessageBox::information(this, "OK", "Successfull!");
    }

}

void Meta::on_pushButton_choose_clicked()
{
    delete_meta = ui->comboBox_meta->currentText();
    ui->listWidget_meta->clear();
    QSqlQuery query;
    query.exec("SELECT * FROM meta WHERE invent_num ='" + delete_meta + "'");

    while (query.next())
    {
        ui->listWidget_meta->addItem(QString::fromLocal8Bit("удк:"));
        ui->listWidget_meta->addItem(query.value(1).toString());
        ui->listWidget_meta->addItem(QString::fromLocal8Bit("инвентарный номер:"));
        ui->listWidget_meta->addItem(query.value(2).toString());
        ui->listWidget_meta->addItem(QString::fromLocal8Bit("название книги:"));
        ui->listWidget_meta->addItem(query.value(3).toString());
        ui->listWidget_meta->addItem(QString::fromLocal8Bit("дисциплина:"));
        QSqlQuery query1;
        query1.exec("SELECT d_name FROM disciplines WHERE d_id =" +query.value(4).toString()+ "" );
        while (query1.next())
        {
         ui->listWidget_meta->addItem(query1.value(0).toString());
        }
        ui->listWidget_meta->addItem(QString::fromLocal8Bit("вид наблюдений:"));
        QSqlQuery query2;
        query2.exec("SELECT obs_name FROM types_of_observations WHERE obs_id =" +query.value(5).toString()+ "" );
        while (query2.next())
        {
         ui->listWidget_meta->addItem(query2.value(0).toString());
        }
        ui->listWidget_meta->addItem(QString::fromLocal8Bit("параметр:"));
        QSqlQuery query3;
        query3.exec("SELECT op_name FROM options WHERE op_id =" +query.value(6).toString()+ "" );
        while (query3.next())
        {
         ui->listWidget_meta->addItem(query3.value(0).toString());
        }
        ui->listWidget_meta->addItem(QString::fromLocal8Bit("авторский знак:"));
        ui->listWidget_meta->addItem(query.value(7).toString());
        ui->listWidget_meta->addItem(QString::fromLocal8Bit("авторы/редакторы:"));
        ui->listWidget_meta->addItem(query.value(8).toString());
        ui->listWidget_meta->addItem(QString::fromLocal8Bit("язык издания:"));
        QSqlQuery query4;
        query4.exec("SELECT lng_name FROM publication_languages WHERE lng_id =" +query.value(9).toString()+ "" );
        while (query4.next())
        {
         ui->listWidget_meta->addItem(query4.value(0).toString());
        }
        ui->listWidget_meta->addItem(QString::fromLocal8Bit("страна:"));
        QSqlQuery query5;
        query5.exec("SELECT cntr_name FROM country WHERE cntr_id =" +query.value(10).toString()+ "" );
        while (query5.next())
        {
         ui->listWidget_meta->addItem(query5.value(0).toString());
        }
        ui->listWidget_meta->addItem(QString::fromLocal8Bit("место издания/издательство:"));
        ui->listWidget_meta->addItem(query.value(11).toString());
        ui->listWidget_meta->addItem(QString::fromLocal8Bit("год издания:"));
        ui->listWidget_meta->addItem(query.value(12).toString());
        ui->listWidget_meta->addItem(QString::fromLocal8Bit("вид представления:"));
        QSqlQuery query6;
        query6.exec("SELECT v_name FROM view_type WHERE v_id =" +query.value(13).toString()+ "" );
        while (query6.next())
        {
         ui->listWidget_meta->addItem(query6.value(0).toString());
        }
        ui->listWidget_meta->addItem(QString::fromLocal8Bit("количество страниц/листов:"));
        ui->listWidget_meta->addItem(query.value(14).toString());
        ui->listWidget_meta->addItem(QString::fromLocal8Bit("начало наблюдений:"));
        ui->listWidget_meta->addItem(query.value(15).toString());
        ui->listWidget_meta->addItem(QString::fromLocal8Bit("конец наблюдений:"));
        ui->listWidget_meta->addItem(query.value(16).toString());
        ui->listWidget_meta->addItem(QString::fromLocal8Bit("район наблюдений:"));
        ui->listWidget_meta->addItem(query.value(17).toString());
        ui->listWidget_meta->addItem(QString::fromLocal8Bit("том:"));
        ui->listWidget_meta->addItem(query.value(18).toString());
        ui->listWidget_meta->addItem(QString::fromLocal8Bit("выпуск:"));
        ui->listWidget_meta->addItem(query.value(19).toString());
        ui->listWidget_meta->addItem(QString::fromLocal8Bit("серия:"));
        ui->listWidget_meta->addItem(query.value(20).toString());
        ui->listWidget_meta->addItem(QString::fromLocal8Bit("часть:"));
        ui->listWidget_meta->addItem(query.value(21).toString());
        ui->listWidget_meta->addItem(QString::fromLocal8Bit("доступ:"));
        ui->listWidget_meta->addItem(query.value(22).toString());
        ui->listWidget_meta->addItem(QString::fromLocal8Bit("способ получения:"));
        ui->listWidget_meta->addItem(query.value(23).toString());
        ui->listWidget_meta->addItem(QString::fromLocal8Bit("дата создания описания:"));
        ui->listWidget_meta->addItem(query.value(24).toString());
        ui->listWidget_meta->addItem(QString::fromLocal8Bit("имя опреатора:"));
        ui->listWidget_meta->addItem(query.value(25).toString());
        ui->listWidget_meta->addItem(QString::fromLocal8Bit("дата последнего изменения:"));
        ui->listWidget_meta->addItem(query.value(26).toString());
    }

}
