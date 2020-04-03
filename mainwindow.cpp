#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include "QTextCodec"
#include "secondwindow.h"
#include <QTextStream>
#include <QString>
#include "md5.h"

using namespace std;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->pass->setEchoMode(QLineEdit::Password);
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    db.setDatabaseName("libdatabase");
    db.setHostName("");
    db.setUserName("userlibrary");
    db.setPassword("235973");

    if (!db.open())
    {
        QMessageBox::warning(this, "Error", db.lastError().text());// Как оповещение о неудаче
        exit(2);
    }
    QMessageBox::information(this, "OK", QString::fromLocal8Bit("PostgreSQL успешно подключен!"));// Как оповещение о успехе подключения

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{

    QTextCodec::setCodecForLocale(QTextCodec::codecForName("Windows-1251"));
    QString login = ui->login->text();
    QString password = ui->pass->text();

    QSqlQuery query;
    query.exec("SELECT * FROM passwords");
    const int STR_EQUAL=0;
    bool ok = false;

    while (query.next())
    {        
        if((QString::compare(login, query.value(1).toString(), Qt::CaseInsensitive) == STR_EQUAL) &&
                (md5(password.toStdString()) == query.value(2).toString().toStdString()))
        {

            hide();
            SecondWindow window;
            window.setWindowTitle(QString::fromLocal8Bit("Работа с данными"));
            window.setModal(true);
            window.exec();
            ok = true;


        }

    }

    if (ok == false)
    {
        QMessageBox::warning(this, QString::fromLocal8Bit("Авторизация_ИЗМЕНЕНИЕ"), QString::fromLocal8Bit("Вы не авторизовались!"));
    }


}
