#ifndef NEWOPTION_H
#define NEWOPTION_H

#include <QDialog>

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


    void on_pushButton_2_clicked();

    void on_discipline_clicked();

    void on_obs_clicked();

private:
    Ui::NewOption *ui;
};

#endif // NEWOPTION_H
