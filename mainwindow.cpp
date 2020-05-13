#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->pass->setEchoMode(QLineEdit::Password);
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    db.setDatabaseName("libdb");
    db.setHostName("");
    db.setUserName("userlibrary");
    db.setPassword("235973");

    if (!db.open())
    {
        QMessageBox::warning(this, "Error", db.lastError().text());
        exit(2);
    }
    QMessageBox::information(this, "OK", QString::fromLocal8Bit("PostgreSQL успешно подключен!"));
    ui->pushButton->setShortcut(Qt::Key_Return);

}

MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::get_username() const
{
    return user_name;
}


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
        if((QString::compare(login, query.value(1).toString(), Qt::CaseInsensitive) == STR_EQUAL) &&
                (md5(password.toStdString()) == query.value(2).toString().toStdString()))
        {
            user_name = query.value(3).toString();

            if(query.value(4).toString().toStdString()=="adm")

            {

                hide();
                SecondWindow window(this, user_name);
                window.setWindowTitle(QString::fromLocal8Bit("Работа с данными"));
                window.setModal(true);
                window.exec();
                ok = true;
            }

            if (query.value(4).toString().toStdString()=="oper")
            {

                hide();
                SecondWindowOper window;
                window.setWindowTitle(QString::fromLocal8Bit("Работа с данными"));
                window.setModal(true);
                window.exec();
                ok = true;
            }


        }

    }

    if (!ok)
    {
        QMessageBox::warning(this, QString::fromLocal8Bit("Авторизация"), QString::fromLocal8Bit("Вы не авторизовались!"));
    }


}


