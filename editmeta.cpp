#include "editmeta.h"
#include "ui_editmeta.h"


EditMeta::EditMeta(QWidget *parent, ClassMeta *SomeMeta) :
    QDialog(parent), MetaObj(SomeMeta),
    ui(new Ui::EditMeta)
{
    ui->setupUi(this);

    QSqlQuery query;
    query.exec("SELECT * FROM disciplines");
    while (query.next())
    {
    ui->discip->addItem(query.value(1).toString());
    }

    query.exec("SELECT * FROM publication_languages");
    while (query.next())
    {
    ui->publ_lng->addItem(query.value(1).toString());
    }

    query.exec("SELECT * FROM country");
    while (query.next())
    {
    ui->cntr->addItem(query.value(1).toString());
    }

    query.exec("SELECT * FROM view_type");
    while (query.next())
    {
    ui->view_type->addItem(query.value(1).toString());
    }

    ui->udc->setText(MetaObj->get_udc());
    ui->invent_num->setText(MetaObj->get_invent_num());
    ui->title->setText(MetaObj->get_title());

    int d_index =  ui->discip->findText(MetaObj->get_discipline());
    ui->discip->setCurrentIndex(d_index);


    query.exec("SELECT d_id FROM disciplines WHERE d_name ='" +MetaObj->get_discipline()+ "'" );
    while (query.next())
    {
    d_id = query.value(0).toString();
    }
    query.exec("SELECT * FROM types_of_observations WHERE d_id =" +d_id+ "");
    ui->type_of_obs->clear();
    while (query.next())
    {
        ui->type_of_obs->addItem(query.value(2).toString());

    }
    int obs_index =  ui->type_of_obs->findText(MetaObj->get_type_of_obs());
    ui->type_of_obs->setCurrentIndex(obs_index);


    query.exec("SELECT obs_id FROM types_of_observations WHERE obs_name ='" +MetaObj->get_type_of_obs()+ "'" );
    while (query.next())
    {
    obs_id = query.value(0).toString();
    }
    query.exec("SELECT * FROM options WHERE obs_id =" +obs_id+ "");
    while (query.next())
    {
        ui->option->addItem(query.value(2).toString());

    }
    int op_index =  ui->option->findText(MetaObj->get_option());
    ui->option->setCurrentIndex(op_index);

    ui->cop_mark->setText(MetaObj->get_cop_mark());
    ui->authors->setText(MetaObj->get_authors());

    int lng_index =  ui->publ_lng->findText(MetaObj->get_publ_language());
    ui->publ_lng->setCurrentIndex(lng_index);

    int cntr_index =  ui->cntr->findText(MetaObj->get_country());
    ui->cntr->setCurrentIndex(cntr_index);

    ui->place_of_publ->setText(MetaObj->get_place_of_publ());
    ui->year_of_publ->setText(MetaObj->get_year_of_publ());

    int v_index =  ui->view_type->findText(MetaObj->get_view_type());
    ui->view_type->setCurrentIndex(v_index);

    ui->num_of_pages->setText(MetaObj->get_num_of_pages());
    ui->start_of_obs->setText(MetaObj->get_start_of_obs());
    ui->end_of_obs->setText(MetaObj->get_end_of_obs());
    ui->obs_area->setText(MetaObj->get_obs_area());
    ui->volume->setText(MetaObj->get_volume());
    ui->realease->setText(MetaObj->get_realease());
    ui->series->setText(MetaObj->get_series());
    ui->part->setText(MetaObj->get_part());

    int acc_index =  ui->access->findText(MetaObj->get_access());
    ui->access->setCurrentIndex(acc_index);

    int prod_index =  ui->product_method->findText(MetaObj->get_prod_method());
    ui->product_method->setCurrentIndex(prod_index);

}

EditMeta::~EditMeta()
{
    delete ui;
}

QString EditMeta::currentDate()
{
    char buffer[80];
    time_t seconds = time(NULL);
    tm* timeinfo = localtime(&seconds);
    char* format = "%d-%m-%Y";
    strftime(buffer, 80, format, timeinfo);
    QString date = buffer;
    return date;
}


void EditMeta::on_pushButton_discip_clicked()
{
    QSqlQuery query;
    QString discip = ui->discip->currentText();
    query.exec("SELECT d_id FROM disciplines WHERE d_name ='" +discip+ "'" );
    while (query.next())
    {
    d_id = query.value(0).toString();
    }

    query.exec("SELECT * FROM types_of_observations WHERE d_id =" +d_id+ "");
    ui->type_of_obs->clear();
    while (query.next())
    {
        ui->type_of_obs->addItem(query.value(2).toString());

    }

}

void EditMeta::on_pushButton_obs_clicked()
{
    QString obs = ui->type_of_obs->currentText();
    QSqlQuery query;
    query.exec("SELECT obs_id FROM types_of_observations WHERE obs_name ='" +obs+ "'" );
    while (query.next())
    {
    obs_id = query.value(0).toString();
    }

    query.exec("SELECT * FROM options WHERE obs_id =" +obs_id+ "");
    ui->option->clear();
    while (query.next())
    {
        ui->option->addItem(query.value(2).toString());

    }
}

void EditMeta::on_add_db_clicked()
{
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("Windows-1251"));
    QString option, lng, cntr, view_type;
    option = ui->option->currentText();
    lng = ui->publ_lng->currentText();
    cntr = ui->cntr->currentText();
    view_type = ui->view_type->currentText();
    QSqlQuery query;
    query.exec("SELECT op_id FROM options WHERE op_name ='" +option+ "'" );
    while (query.next())
    {
    op_id = query.value(0).toString();
    }

    query.exec("SELECT lng_id FROM publication_languages WHERE lng_name ='" +lng+ "'" );
    while (query.next())
    {
    lng_id = query.value(0).toString();
    }

    query.exec("SELECT cntr_id FROM country WHERE cntr_name ='" +cntr+ "'" );
    while (query.next())
    {
    cntr_id = query.value(0).toString();
    }

    query.exec("SELECT v_id FROM view_type WHERE v_name ='" +view_type+ "'" );
    while (query.next())
    {
    v_id = query.value(0).toString();
    }


    QSqlQuery query1;
    query1.prepare("UPDATE meta SET udc = ?, invent_num = ?, title_of_the_book = ?, discipline = ?, type_of_obs = ?, option = ?, "
                   "copyright_mark = ?, authors = ?, publ_language = ?, country = ?, place_of_publ = ?, year_of_publ = ?, "
                   "view_type = ?, num_of_pages = ?, start_of_obs = ?, end_of_obs = ?, obs_area = ?, volume = ?, realease = ?, "
                   "series = ?, part = ?, access = ?, prod_method = ?, last_modif_date = ? WHERE meta_id = ?");
    query1.addBindValue(ui->udc->text());
    query1.addBindValue(ui->invent_num->text());
    query1.addBindValue(ui->title->text());
    query1.addBindValue(d_id);
    query1.addBindValue(obs_id);
    query1.addBindValue(op_id);
    query1.addBindValue(ui->cop_mark->text());
    query1.addBindValue(ui->authors->text());
    query1.addBindValue(lng_id);
    query1.addBindValue(cntr_id);
    query1.addBindValue(ui->place_of_publ->text());
    query1.addBindValue(ui->year_of_publ->text());
    query1.addBindValue(v_id);
    query1.addBindValue(ui->num_of_pages->text());
    query1.addBindValue(ui->start_of_obs->text());
    query1.addBindValue(ui->end_of_obs->text());
    query1.addBindValue(ui->obs_area->text());
    query1.addBindValue(ui->volume->text());
    query1.addBindValue(ui->realease->text());
    query1.addBindValue(ui->series->text());
    query1.addBindValue(ui->part->text());
    query1.addBindValue(ui->access->currentText());
    query1.addBindValue(ui->product_method->currentText());
    query1.addBindValue(this->currentDate());
    query1.addBindValue(MetaObj->get_id());

    if (!query1.exec())
    {
        QMessageBox::warning(this, "Error", query1.lastError().text());
    }
    else
    {

         QMessageBox::information(this, "OK", "Successfull edited!");
    }

}
