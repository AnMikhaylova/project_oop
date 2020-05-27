#ifndef EDITVOCABULARY_H
#define EDITVOCABULARY_H

#include <QDialog>
#include "sql.h"

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
    void on_discipline_clicked();

    void on_obs_clicked();

    void on_op_clicked();

    void on_discipline_change_clicked();

    void on_obs_change_clicked();

    void on_op_change_clicked();

private:
    QString discip_id, obs_id, op_id;
    Ui::EditVocabulary *ui;
};

#endif // EDITVOCABULARY_H
