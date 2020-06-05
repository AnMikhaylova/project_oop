#ifndef EDITMETA_H
#define EDITMETA_H

#include <QDialog>
#include "sql.h"
#include "classmeta.h"
#include <QTextCodec>
#include <QMessageBox>

//Окно для редактирования мета-описания

namespace Ui {
class EditMeta;
}

class EditMeta : public QDialog
{
    Q_OBJECT

public:
    //конструктор по умолчанию, принимающий родительский виджет и объект типа ClassMeta, содержащий информацию о редактируемом мета-описании
    explicit EditMeta(QWidget *parent = nullptr, ClassMeta *SomeMeta = new ClassMeta());
    ~EditMeta();



private slots:
     //слот для обработки нажатия на кнопку выбора дисциплины
     void on_pushButton_discip_clicked();
     //слот для обработки нажатия на кнопку выбора вида наблюдения
     void on_pushButton_obs_clicked();
     //слот для обработки нажатия на кнопку добавления в базу данных
     void on_add_db_clicked();

private:
     //функция-член, возвращающая текущую дату. тип возвращаемого значения - QString
     QString currentDate();
     //указатель на объект типа ClassMeta
     ClassMeta *MetaObj;
     //строки для хранения id выбранных дисциплины, вида наблюдения,
     //параметра, языка издания, страны и вида представления, необходимые для занесения в базу данных
     QString d_id, obs_id, op_id, lng_id, cntr_id, v_id;
     Ui::EditMeta *ui;

};

#endif // EDITMETA_H
