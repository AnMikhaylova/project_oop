#include "connect_sql.h"
#include "ui_connect_sql.h"
#include "sql.h"
#include "mainwindow.h"

connect_sql::connect_sql(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::connect_sql)
{
    ui->setupUi(this);
}

connect_sql::~connect_sql()
{
    delete ui;
}

void connect_sql::on_pushButton_clicked()
{
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
    QMessageBox::information(this, "OK", QString::fromLocal8Bit("Успешно!"));// Как оповещение о успехе подключения
    hide();
    MainWindow window;
    window.setWindowTitle(QString::fromLocal8Bit("Авторизация"));
    window.show();

}
