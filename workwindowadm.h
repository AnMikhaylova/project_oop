#ifndef WORKWINDOWADM_H
#define WORKWINDOWADM_H

#include <QWidget>

#include "newdiscipline.h"
#include "newtype_of_obs.h"
#include "newoption.h"
#include "newmeta.h"
#include "meta.h"
#include "editvocabulary.h"
#include "newoperator.h"

namespace Ui {
class WorkWindowAdm;
}

class WorkWindowAdm : public QWidget
{
    Q_OBJECT

public:
    explicit WorkWindowAdm(QWidget *parent = nullptr, QString name = "");
    ~WorkWindowAdm();

private slots:
    void on_new_meta_clicked();

    void on_meta_clicked();

    void on_edit_vocab_clicked();

    void on_discip_clicked();

    void on_type_of_obs_clicked();

    void on_option_clicked();

    void on_operator_2_clicked();

private:
    QString user_name;
    NewMeta *windowNewMeta;
    Meta *windowMeta;
    EditVocabulary *windowEditVocabulary;
    NewDiscipline *windowNewDiscipline;
    newtype_of_obs *windowNewObs;
    NewOption *windowNewOption;
    NewOperator *windowNewOperator;
    Ui::WorkWindowAdm *ui;
};

#endif // WORKWINDOWADM_H
