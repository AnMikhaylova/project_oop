#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->pass->setEchoMode(QLineEdit::Password);
    //подклбчение к базе данных
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    db.setDatabaseName("libdb");
    db.setHostName("");
    db.setUserName("userlibrary");
    db.setPassword("235973");

    //если подключение произведено, выводится соответствующее сооющение, в противном случае, выводится сообщение с содержанием ошибки
    if (!db.open())
    {
        QMessageBox::warning(this, QString::fromLocal8Bit("Ошибка"), db.lastError().text());
        exit(2);
    }
    QMessageBox::information(this, "OK", QString::fromLocal8Bit("PostgreSQL успешно подключен!"));
    //установка горячей клавиши для кнопки авторизации
    ui->pushButton->setShortcut(Qt::Key_Return);

}

MainWindow::~MainWindow()
{
    delete ui;
}

//слот для обработки нажатия на кнопку авторизации
void MainWindow::on_pushButton_clicked()
{

    QTextCodec::setCodecForLocale(QTextCodec::codecForName("Windows-1251"));
    QString login = ui->login->text();
    QString password = ui->pass->text();

    QSqlQuery query;
    query.exec("SELECT * FROM verify");
    const int STR_EQUAL=0;
    bool ok = false;

    while (query.next())
    {
        //в случае совпадения логина и пароля
        if((QString::compare(login, query.value(1).toString(), Qt::CaseInsensitive) == STR_EQUAL) &&
                (md5(password.toStdString()) == query.value(2).toString().toStdString()))
        {

            user_name = query.value(3).toString();

            if(query.value(4).toString().toStdString()=="adm")

            {
                //открытие окна работы с данными для администратора

                hide();
                window = new WorkWindowAdm(nullptr,user_name);
                window->setWindowTitle(QString::fromLocal8Bit("Работа с данными"));
                window->show();
                ok = true;
            }

            if (query.value(4).toString().toStdString()=="oper")
            {
                //открытие окна работы с данными для оператора

                hide();
                window_op = new WorkWindowOper(nullptr,user_name);
                window_op->setWindowTitle(QString::fromLocal8Bit("Работа с данными"));
                window_op->show();
                ok = true;
            }

        }

    }

    //вывод сообщения об ошибке авторизации
    if (!ok)
    {
        QMessageBox::warning(this, QString::fromLocal8Bit("Авторизация"), QString::fromLocal8Bit("Вы не авторизовались!"));
    }


}


