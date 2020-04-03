#ifndef NEWOPERATOR_H
#define NEWOPERATOR_H

#include <QDialog>

namespace Ui {
class NewOperator;
}

class NewOperator : public QDialog
{
    Q_OBJECT

public:
    explicit NewOperator(QWidget *parent = nullptr);
    ~NewOperator();

private slots:
    void on_pushButton_clicked();

private:
    Ui::NewOperator *ui;
};

#endif // NEWOPERATOR_H
