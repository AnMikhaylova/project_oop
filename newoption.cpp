#include "newoption.h"
#include "ui_newoption.h"


NewOption::NewOption(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewOption)
{
    ui->setupUi(this);
    //установка размеров выпадающих списков
    ui->comboBox_discipline->setSizeAdjustPolicy(QComboBox::AdjustToMinimumContentsLength);
    ui->comboBox_obs->setSizeAdjustPolicy(QComboBox::AdjustToMinimumContentsLength);
    //ƒобавление соотвествующих полей и всплывающих подсказок к ним в выпадающие списки дл€ дисциплины
    QSqlQuery query;
    query.exec("SELECT * FROM disciplines");
    int i = 0;
    while (query.next())
    {
    ui->comboBox_discipline->addItem(query.value(1).toString());
    ui->comboBox_discipline->setItemData(i, query.value(1).toString(), Qt::ToolTipRole);
    i++;
    }
    //установка гор€чей клавиши дл€ кнопки добавлени€ параметра
    ui->pushButton_2->setShortcut(Qt::Key_Return);
}

NewOption::~NewOption()
{
    delete ui;
}


//слот дл€ обработки нажати€ на кнопку выбора дисциплины

void NewOption::on_discipline_clicked()
{
    //поиск соответсвующего id дл€ дисциплины
    QSqlQuery query;
    QString discip_id;
    QString discip = ui->comboBox_discipline->currentText();
    query.exec("SELECT d_id FROM disciplines WHERE d_name ='" +discip+ "'" );
    while (query.next())
    {
    discip_id = query.value(0).toString();
    }

    //ƒобавление соотвествующих полей и всплывающих подсказок к ним в выпадающие списки дл€ вида наблюдени€ по id дисциплины
    query.exec("SELECT * FROM types_of_observations WHERE d_id =" +discip_id+ "");
    ui->comboBox_obs->clear();
    int i = 0;
    while (query.next())
    {
        ui->comboBox_obs->addItem(query.value(2).toString());
        ui->comboBox_obs->setItemData(i, query.value(2).toString(), Qt::ToolTipRole);
        i++;

    }

}


//слот дл€ обработки нажати€ на кнопку выбора вида наблюдени€
void NewOption::on_obs_clicked()
{
    //поиск соответсвующего id дл€ вида наблюдени€
    ui->listWidget->clear();
    QString obs = ui->comboBox_obs->currentText();
    QSqlQuery query;
    query.exec("SELECT obs_id FROM types_of_observations WHERE obs_name ='" +obs+ "'" );
    while (query.next())
    {
    obs_id = query.value(0).toString();
    }

    //вывод в окно информации об имеющихс€ параметрах дл€ выбранного вида наблюдени€
    query.exec("SELECT * FROM options WHERE obs_id =" +obs_id+ "");
    while (query.next())
    {
        ui->listWidget->addItem(query.value(2).toString());

    }
}

//слот дл€ обработки нажати€ на кнопку добавлени€ параметра
void NewOption::on_pushButton_2_clicked()
{
    QSqlQuery query;
    QString op_name = ui->option->text();
    query.prepare("INSERT INTO options (obs_id, op_name) VALUES (?, ?)");
    query.addBindValue(obs_id);
    query.addBindValue(op_name);
     //в случае неудачного запроса,выводитс€ сообщение с содержанием ошибки
    if (!query.exec())
    {
        QMessageBox::warning(this, QString::fromLocal8Bit("ќшибка"), query.lastError().text());
    }
    //в случае успешного выполнени€ запроса, выводитс€ соответствующее сообщение
    else
    {


        QMessageBox::information(this, "OK", QString::fromLocal8Bit("Ќовый параметр успешно добавлен"));
    }
}
