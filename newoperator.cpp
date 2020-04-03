#include "newoperator.h"
#include "ui_newoperator.h"
#include <QTextCodec>
#include "sql.h"
#include <QMessageBox>
#include "md5.h"

NewOperator::NewOperator(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewOperator)
{
    ui->setupUi(this);
}

NewOperator::~NewOperator()
{
    delete ui;
}

void NewOperator::on_pushButton_clicked()
{
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("Windows-1251"));
    QString login_db = ui->login->text();
    QString password_db = ui->password->text();
    QString name_db = ui->name->text();

    QSqlQuery query;
    QString qpass = QString::fromStdString(md5(password_db.toStdString()));
    query.prepare("INSERT INTO passwords (login, password, name) VALUES (?, ?, ?)");
    query.addBindValue(login_db);
    query.addBindValue(qpass);
    query.addBindValue(name_db);


    if (!query.exec())
    {
        QMessageBox::warning(this, "Error", query.lastError().text());
    }
    else
    {

        QMessageBox::information(this, "OK", "Successfull!");
    }

}
