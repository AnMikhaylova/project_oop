#ifndef WORKWINDOWOPER_H
#define WORKWINDOWOPER_H

#include <QWidget>
#include "newdiscipline.h"
#include "newtype_of_obs.h"
#include "newoption.h"
#include "newmeta.h"
#include "meta.h"
#include "editvocabulary.h"

//рабочее окно для оператора

namespace Ui {
class WorkWindowOper;
}

class WorkWindowOper : public QWidget
{
    Q_OBJECT

public:
    explicit WorkWindowOper(QWidget *parent = nullptr, QString name = "");
    ~WorkWindowOper();

private slots:
    //слот для обработки нажатия на кнопку добавления нового мета-описания
    void on_new_meta_clicked();

    //слот для обработки нажатия на кнопку редактирования/удаления мета-описания
    void on_meta_clicked();

    //слот для обработки нажатия на кнопку редактирования метеорологических словарей
    void on_edit_vocab_clicked();

    //слот для обработки нажатия на кнопку добавления дисциплины
    void on_discip_clicked();

    //слот для обработки нажатия на кнопку добавления вида наблюдения
    void on_type_of_obs_clicked();

    //слот для обработки нажатия на кнопку добавления параметра
    void on_option_clicked();

private:
    //строка для хранения имени пользователя
    QString user_name;
    /*-------указатели на соответсвующие окна-----*/
    //новое мета описание
    NewMeta *windowNewMeta;
    //редактирование и удаление мета описания
    Meta *windowMeta;
    //редактирование гидрометеорологического словаря
    EditVocabulary *windowEditVocabulary;
    //новая дисциплина
    NewDiscipline *windowNewDiscipline;
    //новый вид наблюдения
    newtype_of_obs *windowNewObs;
    //новый параметр
    NewOption *windowNewOption;
    Ui::WorkWindowOper *ui;
};

#endif // WORKWINDOWOPER_H
