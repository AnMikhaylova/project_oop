#ifndef NEWMETA_H
#define NEWMETA_H

#include <QDialog>
#include "sql.h"
#include <QTextCodec>

#include <ctime>
#include <QFileDialog>

//окно добавления нового мета-описания

namespace Ui {
class NewMeta;
}

class NewMeta : public QDialog
{
    Q_OBJECT

public:
    explicit NewMeta(QWidget *parent = nullptr, QString name = "");
    ~NewMeta();
private slots:
    //слот для обработки нажатия на кнопку выбора дисциплины
    void on_pushButton_discip_clicked();
    //слот для обработки нажатия на кнопку выбора вида наблюдения
    void on_pushButton_obs_clicked();
    //слот для обработки нажатия на кнопку добавления в базу данных
    void on_add_db_clicked();
    //слот для обработки нажатия на кнопку выбора прикрепляемого файла
    void on_choose_clicked();



private:
    //функция-член, возвращающая текущую дату. тип возвращаемого значения - QString
    QString currentDate();
    //строки для хранения имени пользователя, id дисциплины, вида наблюдения, параметра и пр.
    QString user_name, d_id, obs_id, op_id, lng_id, cntr_id, v_id, access,
    prod_method, meta_creation_date, last_modif_date, directory, file;
    Ui::NewMeta *ui;

};

#endif // NEWMETA_H
