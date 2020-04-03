#include "newvocabulary.h"
#include "ui_newvocabulary.h"
#include <QTextCodec>
#include "sql.h"

NewVocabulary::NewVocabulary(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewVocabulary)
{
    ui->setupUi(this);
}

NewVocabulary::~NewVocabulary()
{
    delete ui;
}

void NewVocabulary::on_pushButton_clicked()
{
     QTextCodec::setCodecForLocale(QTextCodec::codecForName("Windows-1251"));
     QString disc = ui->discipline->text();
     QString obs = ui->type_of_observations->text();

     QSqlQuery query1;
     QSqlQuery q1, q2, q3, q4;

     const int STR_EQUAL=0;
     bool ok = false;

     query1.exec("SELECT dic_id, dic_name FROM disciplin");
     while (query1.next())
     {
         if(QString::compare(disc, query1.value(1).toString(), Qt::CaseInsensitive) == STR_EQUAL)
         {

             q1.prepare("INSERT INTO type_of_observations (dic_id, obs_name) VALUES (?, ?)");
             q1.addBindValue(query1.value(0).toString());
             q1.addBindValue(obs);
             q1.exec();
             ok = true;

         }

     }


     if (!ok)
     {
         q2.prepare("INSERT INTO disciplin (dic_name) VALUES (?)");
         q2.addBindValue(disc);
         q2.exec();

         q3.exec("SELECT dic_id FROM disciplin WHERE dic_name = '" + disc + "'");
         QString id;
         while (q3.next())
         {
             QMessageBox::warning(this, "Error", q3.value(0).toString());
             id = q3.value(0).toString();


         }
         q4.prepare("INSERT INTO type_of_observations (dic_id, obs_name) VALUES (?, ?) ");
         q4.addBindValue(id);
         q4.addBindValue(obs);
         q4.exec();

         ok = true;

     }
//     bool ex = true;
//     if(!query1.exec())
//     {
//         ex = false;

//     }

//     if (!ex)
//     {
//         QMessageBox::warning(this, "Error", query1.lastError().text());
//     }
//     else
//     {

//         QMessageBox::information(this, "OK", "Successfull!");
//     }




}
