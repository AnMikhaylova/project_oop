#ifndef SECONDWINDOWOPER_H
#define SECONDWINDOWOPER_H

#include <QDialog>

namespace Ui {
class SecondWindowOper;
}

class SecondWindowOper : public QDialog
{
    Q_OBJECT

public:
    explicit SecondWindowOper(QWidget *parent = nullptr);
    ~SecondWindowOper();

private:
    Ui::SecondWindowOper *ui;
};

#endif // SECONDWINDOWOPER_H
