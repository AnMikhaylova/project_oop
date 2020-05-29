#ifndef NEWMETA_H
#define NEWMETA_H

#include <QDialog>
#include "sql.h"
#include <QTextCodec>

#include <ctime>
#include <QFileDialog>

namespace Ui {
class NewMeta;
}

class NewMeta : public QDialog
{
    Q_OBJECT

public:
    explicit NewMeta(QWidget *parent = nullptr, QString name = "");
    ~NewMeta();
    QString currentDate();
private slots:
    void on_pushButton_discip_clicked();

    void on_pushButton_obs_clicked();

    void on_add_db_clicked();

    void on_choose_clicked();

private:
    QString user_name, d_id, obs_id, op_id, lng_id, cntr_id, v_id, access,
    prod_method, meta_creation_date, last_modif_date, directory, file;
    Ui::NewMeta *ui;

};

#endif // NEWMETA_H
