#include "meta.h"
#include "ui_meta.h"

Meta::Meta(QWidget *parent, QString name) :
    QDialog(parent), user_name(name),
    ui(new Ui::Meta)
{
    ui->setupUi(this);
    //выборка инвентарных номеров мета-описаний в соответствии с ролью пользователя
    QSqlQuery query;
    if (user_name == "admin")
        query.exec("SELECT invent_num FROM meta"); //выборка всех инвентарных номеров для администратора
    else
        query.exec("SELECT invent_num FROM meta WHERE oper_name = '" + user_name+ "'"); //выборка инвентарных номеров
    //в соответствии с именем пользователя дляоператора
    int i = 0;
    while (query.next())
    {
        ui->comboBox_meta->addItem(query.value(0).toString());
        ui->comboBox_meta->setItemData(i, query.value(0).toString(), Qt::ToolTipRole);
        i++;
    }
}

Meta::~Meta()
{
    delete ui;
}

//слот для обработки нажатия на кнопку удаления мета-описания
void Meta::on_pushButton_delete_clicked()
{

    QSqlQuery query;
    query.prepare("DELETE FROM meta WHERE invent_num = ?");
    query.addBindValue(delete_meta);
    //в случае успешно выполнения запроса, выводится соответствующее сообщение
    if (!query.exec())
    {
        QMessageBox::warning(this, QString::fromLocal8Bit("Ошибка"), query.lastError().text());
    }
    //в другом случае, выводится сообщение с содержанием ошибки
    else
    {

        QMessageBox::information(this, "OK", QString::fromLocal8Bit("Мета-описание успешно удалено"));
    }

}

//слот для обработки нажатия на кнопку выбора мета-описания
void Meta::on_pushButton_choose_clicked()
{
    //на экран выводится вся информация о мета-описании
    //это такие поля, как удк, инвентарный номер, название книги, дисциплина и пр.
    ui->pushButton_edit->setEnabled(true);
     ui->pushButton_delete->setEnabled(true);

    delete_meta = ui->comboBox_meta->currentText();
    ui->listWidget_meta->clear();
    QSqlQuery query;
    query.exec("SELECT * FROM meta WHERE invent_num ='" + delete_meta + "'");


    while (query.next())
    {
        QString d, obs, op, lng, cntr, v;
        NewMeta = new ClassMeta;
        NewMeta->set_id(query.value(0).toString());

        ui->listWidget_meta->addItem(QString::fromLocal8Bit("удк:"));
        ui->listWidget_meta->addItem(query.value(1).toString());
        NewMeta->set_udc(query.value(1).toString());

        ui->listWidget_meta->addItem(QString::fromLocal8Bit("инвентарный номер:"));
        ui->listWidget_meta->addItem(query.value(2).toString());
        NewMeta->set_invent_num(query.value(2).toString());

        ui->listWidget_meta->addItem(QString::fromLocal8Bit("название книги:"));
        ui->listWidget_meta->addItem(query.value(3).toString());
        NewMeta->set_title(query.value(3).toString());

        ui->listWidget_meta->addItem(QString::fromLocal8Bit("дисциплина:"));
        QSqlQuery query1;
        query1.exec("SELECT d_name FROM disciplines WHERE d_id =" +query.value(4).toString()+ "" );

        while (query1.next())
        {
         ui->listWidget_meta->addItem(query1.value(0).toString());
         NewMeta->set_discipline(query1.value(0).toString());
        }

        ui->listWidget_meta->addItem(QString::fromLocal8Bit("вид наблюдений:"));
        QSqlQuery query2;
        query2.exec("SELECT obs_name FROM types_of_observations WHERE obs_id =" +query.value(5).toString()+ "" );
        while (query2.next())
        {
         ui->listWidget_meta->addItem(query2.value(0).toString());
         NewMeta->set_type_of_obs(query2.value(0).toString());
        }

        ui->listWidget_meta->addItem(QString::fromLocal8Bit("параметр:"));
        QSqlQuery query3;
        query3.exec("SELECT op_name FROM options WHERE op_id =" +query.value(6).toString()+ "" );
        while (query3.next())
        {
         ui->listWidget_meta->addItem(query3.value(0).toString());
         NewMeta->set_option(query3.value(0).toString());
        }

        ui->listWidget_meta->addItem(QString::fromLocal8Bit("авторский знак:"));
        ui->listWidget_meta->addItem(query.value(7).toString());
        NewMeta->set_cop_mark(query.value(7).toString());

        ui->listWidget_meta->addItem(QString::fromLocal8Bit("авторы/редакторы:"));
        ui->listWidget_meta->addItem(query.value(8).toString());
        NewMeta->set_authors(query.value(8).toString());

        ui->listWidget_meta->addItem(QString::fromLocal8Bit("язык издания:"));
        QSqlQuery query4;
        query4.exec("SELECT lng_name FROM publication_languages WHERE lng_id =" +query.value(9).toString()+ "" );
        while (query4.next())
        {
         ui->listWidget_meta->addItem(query4.value(0).toString());
         NewMeta->set_publ_language(query4.value(0).toString());
        }

        ui->listWidget_meta->addItem(QString::fromLocal8Bit("страна:"));
        QSqlQuery query5;
        query5.exec("SELECT cntr_name FROM country WHERE cntr_id =" +query.value(10).toString()+ "" );
        while (query5.next())
        {
         ui->listWidget_meta->addItem(query5.value(0).toString());
         NewMeta->set_country(query5.value(0).toString());
        }

        ui->listWidget_meta->addItem(QString::fromLocal8Bit("место издания/издательство:"));
        ui->listWidget_meta->addItem(query.value(11).toString());
        NewMeta->set_place_of_publ(query.value(11).toString());

        ui->listWidget_meta->addItem(QString::fromLocal8Bit("год издания:"));
        ui->listWidget_meta->addItem(query.value(12).toString());
        NewMeta->set_year_of_publ(query.value(12).toString());

        ui->listWidget_meta->addItem(QString::fromLocal8Bit("вид представления:"));
        QSqlQuery query6;
        query6.exec("SELECT v_name FROM view_type WHERE v_id =" +query.value(13).toString()+ "" );
        while (query6.next())
        {
         ui->listWidget_meta->addItem(query6.value(0).toString());
         NewMeta->set_view_type(query6.value(0).toString());
        }

        ui->listWidget_meta->addItem(QString::fromLocal8Bit("количество страниц/листов:"));        
        ui->listWidget_meta->addItem(query.value(14).toString());
        NewMeta->set_num_of_pages(query.value(14).toString());

        ui->listWidget_meta->addItem(QString::fromLocal8Bit("начало наблюдений:"));
        ui->listWidget_meta->addItem(query.value(15).toString());
        NewMeta->set_start_of_obs(query.value(15).toString());

        ui->listWidget_meta->addItem(QString::fromLocal8Bit("конец наблюдений:"));
        ui->listWidget_meta->addItem(query.value(16).toString());
        NewMeta->set_end_of_obs(query.value(16).toString());

        ui->listWidget_meta->addItem(QString::fromLocal8Bit("район наблюдений:"));
        ui->listWidget_meta->addItem(query.value(17).toString());
        NewMeta->set_obs_area(query.value(17).toString());

        ui->listWidget_meta->addItem(QString::fromLocal8Bit("том:"));
        ui->listWidget_meta->addItem(query.value(18).toString());
        NewMeta->set_volume(query.value(18).toString());

        ui->listWidget_meta->addItem(QString::fromLocal8Bit("выпуск:"));
        ui->listWidget_meta->addItem(query.value(19).toString());
        NewMeta->set_realease(query.value(19).toString());

        ui->listWidget_meta->addItem(QString::fromLocal8Bit("серия:"));
        ui->listWidget_meta->addItem(query.value(20).toString());
        NewMeta->set_series(query.value(20).toString());

        ui->listWidget_meta->addItem(QString::fromLocal8Bit("часть:"));
        ui->listWidget_meta->addItem(query.value(21).toString());
        NewMeta->set_part(query.value(21).toString());

        ui->listWidget_meta->addItem(QString::fromLocal8Bit("доступ:"));
        ui->listWidget_meta->addItem(query.value(22).toString());
        NewMeta->set_access(query.value(22).toString());

        ui->listWidget_meta->addItem(QString::fromLocal8Bit("способ получения:"));
        ui->listWidget_meta->addItem(query.value(23).toString());
        NewMeta->set_prod_method(query.value(23).toString());

        ui->listWidget_meta->addItem(QString::fromLocal8Bit("дата создания описания:"));
        ui->listWidget_meta->addItem(query.value(24).toString());
        NewMeta->set_meta_cr_date(query.value(24).toString());

        ui->listWidget_meta->addItem(QString::fromLocal8Bit("имя опреатора:"));
        ui->listWidget_meta->addItem(query.value(25).toString());
        NewMeta->set_oper_name(query.value(25).toString());

        ui->listWidget_meta->addItem(QString::fromLocal8Bit("дата последнего изменения:"));
        ui->listWidget_meta->addItem(query.value(26).toString());
        NewMeta->set_last_modif_date(query.value(26).toString());

        NewMeta->set_directory(query.value(27).toString());

    }

}

//слот для обработки нажатия на кнопку изменения мета-описания
void Meta::on_pushButton_edit_clicked()
{
    //открывается окно редактирования мета-описания, в которое передается имя пользователя и информация о выбранном мета-описании
    windowEditMeta = new EditMeta(nullptr, NewMeta);
    windowEditMeta->setWindowTitle(QString::fromLocal8Bit("Редактирование мета-описания"));
    windowEditMeta->setWindowFlags(windowEditMeta->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    windowEditMeta->setModal(true);
    windowEditMeta->exec();
}
