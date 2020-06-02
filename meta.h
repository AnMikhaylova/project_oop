#ifndef META_H
#define META_H

#include <QDialog>
#include "sql.h"
#include "classmeta.h"
#include "editmeta.h"

namespace Ui {
class Meta;
}

class Meta : public QDialog
{
    Q_OBJECT

public:
    explicit Meta(QWidget *parent = nullptr, QString name = "");
    ~Meta();

private slots:
    void on_pushButton_delete_clicked();

    void on_pushButton_choose_clicked();

    void on_pushButton_edit_clicked();

private:
    QString user_name, delete_meta;
    ClassMeta *NewMeta;
    EditMeta *windowEditMeta;
    Ui::Meta *ui;

};

#endif // META_H
