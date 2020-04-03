#ifndef NEWVOCABULARY_H
#define NEWVOCABULARY_H

#include <QDialog>

namespace Ui {
class NewVocabulary;
}

class NewVocabulary : public QDialog
{
    Q_OBJECT

public:
    explicit NewVocabulary(QWidget *parent = nullptr);
    ~NewVocabulary();

private slots:
    void on_pushButton_clicked();

private:
    Ui::NewVocabulary *ui;
};

#endif // NEWVOCABULARY_H
