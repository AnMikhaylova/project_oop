#ifndef NEWMETA_H
#define NEWMETA_H

#include <QDialog>

namespace Ui {
class NewMeta;
}

class NewMeta : public QDialog
{
    Q_OBJECT

public:
    explicit NewMeta(QWidget *parent = nullptr, QString name = "");
    ~NewMeta();

private slots:
    void on_pushButton_discip_clicked();

    void on_pushButton_obs_clicked();

private:
    QString user_name;
    Ui::NewMeta *ui;

};

#endif // NEWMETA_H
