#ifndef EDITMETA_H
#define EDITMETA_H

#include <QDialog>
#include "sql.h"
#include "classmeta.h"
#include <QTextCodec>
#include <QMessageBox>

namespace Ui {
class EditMeta;
}

class EditMeta : public QDialog
{
    Q_OBJECT

public:
    explicit EditMeta(QWidget *parent = nullptr, ClassMeta *SomeMeta = new ClassMeta());
    ~EditMeta();
     QString currentDate();

private slots:
     void on_pushButton_discip_clicked();

     void on_pushButton_obs_clicked();

     void on_add_db_clicked();

private:
    ClassMeta *MetaObj;
    QString d_id, obs_id, op_id, lng_id, cntr_id, v_id;
    Ui::EditMeta *ui;

};

#endif // EDITMETA_H
