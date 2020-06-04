#include "newmeta.h"
#include "ui_newmeta.h"


NewMeta::NewMeta(QWidget *parent, QString name) :
    QDialog(parent), user_name(name),
    ui(new Ui::NewMeta)
{
    ui->setupUi(this);
    QSqlQuery query;
    query.exec("SELECT * FROM disciplines");
    int i = 0;
    while (query.next())
    {
    ui->discip->addItem(query.value(1).toString());
    ui->discip->setItemData(i, query.value(1).toString(), Qt::ToolTipRole);
    i++;
    }

    query.exec("SELECT * FROM publication_languages");
    int j = 0;
    while (query.next())
    {
    ui->publ_lng->addItem(query.value(1).toString());
    ui->publ_lng->setItemData(j, query.value(1).toString(), Qt::ToolTipRole);
    j++;
    }

    query.exec("SELECT * FROM country");
    int k = 0;
    while (query.next())
    {
    ui->cntr->addItem(query.value(1).toString());
    ui->cntr->setItemData(k, query.value(1).toString(), Qt::ToolTipRole);
    k++;
    }

    query.exec("SELECT * FROM view_type");
    int m = 0;
    while (query.next())
    {
    ui->view_type->addItem(query.value(1).toString());
    ui->view_type->setItemData(m, query.value(1).toString(), Qt::ToolTipRole);
    m++;

    }

    ui->access->setItemData(0,QString::fromLocal8Bit("Открытый"),Qt::ToolTipRole);
    ui->access->setItemData(1,QString::fromLocal8Bit("Закрытый"),Qt::ToolTipRole);

    ui->product_method->setItemData(0,QString::fromLocal8Bit("Платный"),Qt::ToolTipRole);
    ui->product_method->setItemData(1,QString::fromLocal8Bit("Бесплатный"),Qt::ToolTipRole);

    ui->add_db->setShortcut(Qt::Key_Return);



}

NewMeta::~NewMeta()
{
    delete ui;
}

void NewMeta::on_pushButton_discip_clicked()
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
    int i = 0;
    while (query.next())
    {
        ui->type_of_obs->addItem(query.value(2).toString());
        ui->type_of_obs->setItemData(i, query.value(2).toString(), Qt::ToolTipRole);
        i++;

    }
}

void NewMeta::on_pushButton_obs_clicked()
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
    int i = 0;
    while (query.next())
    {
        ui->option->addItem(query.value(2).toString());
        ui->option->setItemData(i, query.value(2).toString(), Qt::ToolTipRole);
        i++;

    }


}

QString NewMeta::currentDate()
{
    char buffer[80];
    time_t seconds = time(NULL);
    tm* timeinfo = localtime(&seconds);
    char* format = "%d-%m-%Y";
    strftime(buffer, 80, format, timeinfo);
    QString date = buffer;
    return date;
}

void NewMeta::on_add_db_clicked()
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

    access = ui->access->currentText();
    prod_method = ui->product_method->currentText();
    meta_creation_date = this->currentDate();
    last_modif_date = this->currentDate();
    directory = "A:/work directory";

    if (ui->invent_num->text() == "" || d_id == "" || obs_id == "" || op_id == "")
    {
         QMessageBox::warning(this, QString::fromLocal8Bit("Ошибка"), QString::fromLocal8Bit("Проверьте заполнение обязательных полей"));

    }
    else
    {

    QSqlQuery query1;
    query1.prepare("INSERT INTO meta (udc, invent_num, title_of_the_book, discipline, type_of_obs, option, copyright_mark, "
                   "authors, publ_language, country, place_of_publ, year_of_publ, view_type, num_of_pages, start_of_obs, "
                   "end_of_obs, obs_area, volume, realease, series, part, access, prod_method, meta_creation_date, oper_name, "
                   "last_modif_date, directory) VALUES (?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?)");
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
    query1.addBindValue(access);
    query1.addBindValue(prod_method);
    query1.addBindValue(meta_creation_date);
    query1.addBindValue(user_name);
    query1.addBindValue(last_modif_date);
    query1.addBindValue(directory);

    QFileInfo fileInfo(file);
    directory = QString("A:/work directory/") + fileInfo.fileName();

    bool copy = QFile::copy(file, directory);
    if (!copy)
    {
        QMessageBox::warning(this, QString::fromLocal8Bit("Ошибка"), QString::fromLocal8Bit("Невозможно скопировать файл"));
    }
    else
    {

         QMessageBox::information(this, "OK", QString::fromLocal8Bit("Файл успешно скопирован"));

         if (!query1.exec())
         {
             QMessageBox::warning(this, QString::fromLocal8Bit("Ошибка"), query1.lastError().text());
             QFile::remove(directory);
         }
         else
         {

              QMessageBox::information(this, "OK", QString::fromLocal8Bit("Мета-описание успешно добавлено"));
         }

    }

    }


}

void NewMeta::on_choose_clicked()
{

    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                      "/home",
                                                      tr("PDF doc (*.pdf)"));
    if (fileName != "")
    {

        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly))
        {
            QMessageBox::critical(this, QString::fromLocal8Bit("Ошибка"), QString::fromLocal8Bit("Невозможно открыть файл"));
        }
        else
        {
            QMessageBox::information(this, "OK", QString::fromLocal8Bit("Файл успешно открыт"));
            ui->label_directory->setText(fileName);
            this->file = fileName;
            ui->add_db->setEnabled(true);

        }
    }


}
