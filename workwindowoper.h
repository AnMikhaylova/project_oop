#ifndef WORKWINDOWOPER_H
#define WORKWINDOWOPER_H

#include <QWidget>
#include "newdiscipline.h"
#include "newtype_of_obs.h"
#include "newoption.h"
#include "newmeta.h"
#include "meta.h"
#include "editvocabulary.h"


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
    void on_new_meta_clicked();

    void on_meta_clicked();

    void on_edit_vocab_clicked();

    void on_discip_clicked();

    void on_type_of_obs_clicked();

    void on_option_clicked();

private:
    QString user_name;
    NewMeta *windowNewMeta;
    Meta *windowMeta;
    EditVocabulary *windowEditVocabulary;
    NewDiscipline *windowNewDiscipline;
    newtype_of_obs *windowNewObs;
    NewOption *windowNewOption;
    Ui::WorkWindowOper *ui;
};

#endif // WORKWINDOWOPER_H
