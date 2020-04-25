#ifndef EDITVOCABULARY_H
#define EDITVOCABULARY_H

#include <QDialog>

namespace Ui {
class EditVocabulary;
}

class EditVocabulary : public QDialog
{
    Q_OBJECT

public:
    explicit EditVocabulary(QWidget *parent = nullptr);
    ~EditVocabulary();

private:
    Ui::EditVocabulary *ui;
};

#endif // EDITVOCABULARY_H
