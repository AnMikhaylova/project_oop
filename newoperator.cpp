#include "newoperator.h"
#include "ui_newoperator.h"

NewOperator::NewOperator(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewOperator)
{
    ui->setupUi(this);
    //установка горячей клавиши для кнопки добавления нового оператора
    ui->pushButton->setShortcut(Qt::Key_Return);
}

NewOperator::~NewOperator()
{
    delete ui;
}

//слот для обработки нажатия на кнопку добавления оператора
void NewOperator::on_pushButton_clicked()
{
    //считывание введенных в окне данных
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("Windows-1251"));
    QString login_db = ui->login->text();
    QString password_db = ui->password->text();
    QString name_db = ui->name->text();


    //хеширование пароля
    QString qpass = QString::fromStdString(md5(password_db.toStdString()));

    //добавление нового оператора
    QSqlQuery query;
    query.exec("SELECT * FROM verify");
    const int STR_EQUAL=0;
    bool ok = true;

    while (query.next())
    {
        //проверка на совпадение логина или имени с существующими в базе данных
        if((QString::compare(login_db, query.value(1).toString(), Qt::CaseInsensitive) == STR_EQUAL) ||
                (QString::compare(name_db,query.value(3).toString()))== STR_EQUAL)
        {
            QMessageBox::warning(this, QString::fromLocal8Bit("Ошибка"),
                                 QString::fromLocal8Bit("Логин или имя оператора совпадают с существующими в базе данных"));

            ok = false;
        }
    }


    //при несовпадении логина или имени, выполняем запрос на добавление оператора
    if(ok)
    {
        QSqlQuery query1;
        query1.prepare("INSERT INTO verify (login, password, name, role) VALUES (?, ?, ?, ?)");
        query1.addBindValue(login_db);
        query1.addBindValue(qpass);
        query1.addBindValue(name_db);
        query1.addBindValue("oper");

        //в случае неудачного запроса,выводится сообщение с содержанием ошибки
        if (!query1.exec())
        {
            QMessageBox::warning(this, QString::fromLocal8Bit("Ошибка"), query.lastError().text());
        }
        //в случае успешно выполнения запроса, выводится соответствующее сообщение
        else
        {

            QMessageBox::information(this, "OK", QString::fromLocal8Bit("Новый оператор успешно добавлен"));
        }
    }




}
