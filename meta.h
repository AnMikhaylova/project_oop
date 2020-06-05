#ifndef META_H
#define META_H

#include <QDialog>
#include "sql.h"
#include "classmeta.h"
#include "editmeta.h"

//Окно редактирования для выбора мета-описания для удаоения или изменения
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
    //слот для обработки нажатия на кнопку удаления мета-описания
    void on_pushButton_delete_clicked();
    //слот для обработки нажатия на кнопку выбора мета-описания
    void on_pushButton_choose_clicked();
    //слот для обработки нажатия на кнопку изменения мета-описания
    void on_pushButton_edit_clicked();

private:
    //строки для хранения имени пользователя и инвентарного номера выбранного мета-описания
    QString user_name, delete_meta;
    //указатель на объект типа ClassMetа для хранения информации о выбранном мета-описании
    ClassMeta *NewMeta;
    //указательна окно для редактирования мета-описания
    EditMeta *windowEditMeta;
    Ui::Meta *ui;

};

#endif // META_H
