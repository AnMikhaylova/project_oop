#ifndef CONNECT_SQL_H
#define CONNECT_SQL_H

#include <QDialog>

namespace Ui {
class connect_sql;
}

class connect_sql : public QDialog
{
    Q_OBJECT

public:
    explicit connect_sql(QWidget *parent = nullptr);
    ~connect_sql();

private slots:
    void on_pushButton_clicked();

private:
    Ui::connect_sql *ui;
};

#endif // CONNECT_SQL_H
