#ifndef NEWTYPE_OF_OBS_H
#define NEWTYPE_OF_OBS_H

#include <QDialog>
#include "sql.h"

//Окно добавления нового вида наблюдения

namespace Ui {
class newtype_of_obs;
}

class newtype_of_obs : public QDialog
{
    Q_OBJECT

public:
    explicit newtype_of_obs(QWidget *parent = nullptr);
    ~newtype_of_obs();

private slots:


    //слот для обработки нажатия на кнопку добавления вида наблюдения
    void on_pushButton_2_clicked();

    //слот для обработки нажатия на кнопку выбора дисциплины
    void on_pushButton_clicked();

private:
    //строка для хранения id выбранной дисциплины
    QString d_id;
    Ui::newtype_of_obs *ui;
};

#endif // NEWTYPE_OF_OBS_H
