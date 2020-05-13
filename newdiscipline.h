#ifndef NEWDISCIPLINE_H
#define NEWDISCIPLINE_H

#include <QDialog>
#include <QTextCodec>
#include "sql.h"

namespace Ui {
class NewDiscipline;
}

class NewDiscipline : public QDialog
{
    Q_OBJECT

public:
    explicit NewDiscipline(QWidget *parent = nullptr);
    ~NewDiscipline();

private slots:
    void on_pushButton_clicked();

private:
    Ui::NewDiscipline *ui;
};

#endif // NEWDISCIPLINE_H
