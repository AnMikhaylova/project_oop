#include "newdiscipline.h"
#include "ui_newdiscipline.h"


NewDiscipline::NewDiscipline(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewDiscipline)
{
    ui->setupUi(this);
    QSqlQuery query;
    //Вывод на экран имеющихся дисциплин
    query.exec("SELECT * FROM disciplines" );
    while (query.next())
    {
        ui->listWidget->addItem(query.value(1).toString());

    }
    //Установка горячей клавиши для кнопки добавления в базу данных

    ui->pushButton->setShortcut(Qt::Key_Return);


}

NewDiscipline::~NewDiscipline()
{
    delete ui;
}

//слот для обработки нажатия на кнопку добавления в базу данных
void NewDiscipline::on_pushButton_clicked()
{
    //добавления новой дисциплины в базу данных
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("Windows-1251"));
    QString discip_name = ui->discip_name->text();
    QSqlQuery query;
    query.prepare("INSERT INTO disciplines (d_name) VALUES (?)");
    query.addBindValue(discip_name);

    //в случае успешно выполнения запроса, выводится соответствующее сообщение
    if (!query.exec())
    {
        QMessageBox::warning(this, QString::fromLocal8Bit("Ошибка"), query.lastError().text());
    }
    //в другом случае, выводится сообщение с содержанием ошибки
    else
    {

        QMessageBox::information(this, "OK", QString::fromLocal8Bit("Новая дисциплина успешно добавлена"));
    }

}
