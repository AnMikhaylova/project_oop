#include "newoperator.h"
#include "ui_newoperator.h"

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
    query.exec("SELECT * FROM verify");
    const int STR_EQUAL=0;
    bool ok = true;

    while (query.next())
    {
        if((QString::compare(login_db, query.value(1).toString(), Qt::CaseInsensitive) == STR_EQUAL) ||
                (QString::compare(name_db,query.value(3).toString()))== STR_EQUAL)
        {
            QMessageBox::warning(this, QString::fromLocal8Bit("Ошибка"),
                                 QString::fromLocal8Bit("Логин или имя оператора совпадают с существующими в базе данных"));

            ok = false;
        }
    }


    if(ok)
    {
        QSqlQuery query1;
        query1.prepare("INSERT INTO verify (login, password, name, role) VALUES (?, ?, ?, ?)");
        query1.addBindValue(login_db);
        query1.addBindValue(qpass);
        query1.addBindValue(name_db);
        query1.addBindValue("oper");

        if (!query1.exec())
        {
            QMessageBox::warning(this, QString::fromLocal8Bit("Ошибка"), query.lastError().text());
        }
        else
        {

            QMessageBox::information(this, "OK", QString::fromLocal8Bit("Новый оператор успешно добавлен"));
        }
    }




}
