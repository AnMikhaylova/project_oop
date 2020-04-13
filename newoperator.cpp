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
    ui->pushButton->setShortcut(Qt::Key_Return);
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


    QString qpass = QString::fromStdString(md5(password_db.toStdString()));
    QSqlQuery query;
    query.prepare("INSERT INTO verify (login, password, name, role) VALUES (?, ?, ?, ?)");
    query.addBindValue(login_db);
    query.addBindValue(qpass);
    query.addBindValue(name_db);
    query.addBindValue("oper");


    if (!query.exec())
    {
        QMessageBox::warning(this, "Error", query.lastError().text());
    }
    else
    {

        QMessageBox::information(this, "OK", "Successfull!");
    }

}
