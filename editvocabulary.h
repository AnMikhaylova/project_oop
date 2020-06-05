#ifndef EDITVOCABULARY_H
#define EDITVOCABULARY_H

#include <QDialog>
#include "sql.h"

//Окно редактирвоания гидрометеорологических словарей

namespace Ui {
class EditVocabulary;
}

class EditVocabulary : public QDialog
{
    Q_OBJECT

public:
    explicit EditVocabulary(QWidget *parent = nullptr);
    ~EditVocabulary();

private slots:
    //слот для обработки нажатия на кнопку выбора дисциплины
    void on_discipline_clicked();
    //слот для обработки нажатия на кнопку выбора вида наблюдения
    void on_obs_clicked();
    //слот для обработки нажатия на кнопку выбора параметра
    void on_op_clicked();
    //слот для обработки нажатия на кнопку изменения дисциплины
    void on_discipline_change_clicked();
    //слот для обработки нажатия на кнопку изменения вида наблюдения
    void on_obs_change_clicked();
    //слот для обработки нажатия на кнопку изменения параметра
    void on_op_change_clicked();

private:
    //строки для хранения id выбранных дисциплины, вида наблюдения, параметра
    QString discip_id, obs_id, op_id;
    Ui::EditVocabulary *ui;
};

#endif // EDITVOCABULARY_H
