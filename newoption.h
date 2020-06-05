#ifndef NEWOPTION_H
#define NEWOPTION_H

#include <QDialog>
#include "sql.h"
#include <QTextCodec>

//окно добавления нового параметра

namespace Ui {
class NewOption;
}

class NewOption : public QDialog
{
    Q_OBJECT

public:
    explicit NewOption(QWidget *parent = nullptr);
    ~NewOption();

private slots:

    //слот для обработки нажатия на кнопку добавления параметра
    void on_pushButton_2_clicked();
    //слот для обработки нажатия на кнопку выбора дисциплины
    void on_discipline_clicked();
    //слот для обработки нажатия на кнопку выбора вида наблюдения
    void on_obs_clicked();

private:
    //Строка для хранения id выбранного вида наблюдения
    QString obs_id;
    Ui::NewOption *ui;
};

#endif // NEWOPTION_H
