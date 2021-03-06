#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->pass->setEchoMode(QLineEdit::Password);
    //����������� � ���� ������
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    db.setDatabaseName("libdb");
    db.setHostName("");
    db.setUserName("userlibrary");
    db.setPassword("235973");

    //���� ����������� �����������, ��������� ��������������� ���������, � ��������� ������, ��������� ��������� � ����������� ������
    if (!db.open())
    {
        QMessageBox::warning(this, QString::fromLocal8Bit("������"), db.lastError().text());
        exit(2);
    }
    QMessageBox::information(this, "OK", QString::fromLocal8Bit("PostgreSQL ������� ���������!"));
    //��������� ������� ������� ��� ������ �����������
    ui->pushButton->setShortcut(Qt::Key_Return);

}

MainWindow::~MainWindow()
{
    delete ui;
}

//���� ��� ��������� ������� �� ������ �����������
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
        //� ������ ���������� ������ � ������
        if((QString::compare(login, query.value(1).toString(), Qt::CaseInsensitive) == STR_EQUAL) &&
                (md5(password.toStdString()) == query.value(2).toString().toStdString()))
        {

            user_name = query.value(3).toString();

            if(query.value(4).toString().toStdString()=="adm")

            {
                //�������� ���� ������ � ������� ��� ��������������

                hide();
                window = new WorkWindowAdm(nullptr,user_name);
                window->setWindowTitle(QString::fromLocal8Bit("������ � �������"));
                window->show();
                ok = true;
            }

            if (query.value(4).toString().toStdString()=="oper")
            {
                //�������� ���� ������ � ������� ��� ���������

                hide();
                window_op = new WorkWindowOper(nullptr,user_name);
                window_op->setWindowTitle(QString::fromLocal8Bit("������ � �������"));
                window_op->show();
                ok = true;
            }

        }

    }

    //����� ��������� �� ������ �����������
    if (!ok)
    {
        QMessageBox::warning(this, QString::fromLocal8Bit("�����������"), QString::fromLocal8Bit("�� �� ��������������!"));
    }


}


