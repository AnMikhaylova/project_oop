#include "newdiscipline.h"
#include "ui_newdiscipline.h"
#include <QTextCodec>


NewDiscipline::NewDiscipline(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewDiscipline)
{
    ui->setupUi(this);
    QSqlQuery query;
    query.exec("SELECT * FROM disciplines" );
    while (query.next())
    {
        ui->listWidget->addItem(query.value(1).toString());

    }


}

NewDiscipline::~NewDiscipline()
{
    delete ui;
}

void NewDiscipline::on_pushButton_clicked()
{
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("Windows-1251"));
    QString discip_name = ui->discip_name->text();
    QSqlQuery query;
    query.prepare("INSERT INTO disciplines (d_name) VALUES (?)");
    query.addBindValue(discip_name);

    if (!query.exec())
    {
        QMessageBox::warning(this, "Error", query.lastError().text());
    }
    else
    {

        QMessageBox::information(this, "OK", "Successfull!");
    }

}
