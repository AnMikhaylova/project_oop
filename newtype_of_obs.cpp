#include "newtype_of_obs.h"
#include "ui_newtype_of_obs.h"



newtype_of_obs::newtype_of_obs(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::newtype_of_obs)
{
    ui->setupUi(this);
    //установка размеров выпадающих списков
    ui->comboBox->setSizeAdjustPolicy(QComboBox::AdjustToMinimumContentsLength);
    //Добавление соотвествующих полей и всплывающих подсказок к ним в выпадающие списки для дисциплины
    QSqlQuery query;
    query.exec("SELECT * FROM disciplines");
    int i = 0;
    while (query.next())
    {
    ui->comboBox->addItem(query.value(1).toString());
    ui->comboBox->setItemData(i, query.value(1).toString(), Qt::ToolTipRole);
    i++;
    }
    //установка горячей клавиши для кнопки добавления вида наблюдения
    ui->pushButton_2->setShortcut(Qt::Key_Return);
}

newtype_of_obs::~newtype_of_obs()
{
    delete ui;
}


//слот для обработки нажатия на кнопку выбора дисциплины
void newtype_of_obs::on_pushButton_clicked()
{
    //поиск соответсвующего id для дисциплины
    ui->listWidget->clear();
    QString discip = ui->comboBox->currentText();
    QSqlQuery query;
    query.exec("SELECT d_id FROM disciplines WHERE d_name ='" +discip+ "'" );
    while (query.next())
    {
    d_id = query.value(0).toString();
    }

    //вывод в окно информации об имеющихся видах наблюдения для выбранной дисциплины
    query.exec("SELECT * FROM types_of_observations WHERE d_id =" +d_id+ "");
    while (query.next())
    {
        ui->listWidget->addItem(query.value(2).toString());

    }
}


//слот для обработки нажатия на кнопку добавления вида наблюдения
void newtype_of_obs::on_pushButton_2_clicked()
{
    QSqlQuery query;
    QString obs_name = ui->type_of_obs->text();
    query.prepare("INSERT INTO types_of_observations (d_id, obs_name) VALUES (?, ?)");
    query.addBindValue(d_id);
    query.addBindValue(obs_name);
    //в случае неудачного запроса,выводится сообщение с содержанием ошибки
    if (!query.exec())
    {
        QMessageBox::warning(this, QString::fromLocal8Bit("Ошибка"), query.lastError().text());
    }
    //в случае успешного выполнения запроса, выводится соответствующее сообщение
    else
    {

        QMessageBox::information(this, "OK", QString::fromLocal8Bit("Новый вид наблюдения успешно добавлен"));
    }
}
