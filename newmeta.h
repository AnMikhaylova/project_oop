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
    explicit NewMeta(QWidget *parent = nullptr);
    ~NewMeta();

private:
    Ui::NewMeta *ui;
};

#endif // NEWMETA_H
