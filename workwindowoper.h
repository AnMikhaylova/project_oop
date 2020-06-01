#ifndef WORKWINDOWOPER_H
#define WORKWINDOWOPER_H

#include <QWidget>

namespace Ui {
class WorkWindowOper;
}

class WorkWindowOper : public QWidget
{
    Q_OBJECT

public:
    explicit WorkWindowOper(QWidget *parent = nullptr);
    ~WorkWindowOper();

private:
    Ui::WorkWindowOper *ui;
};

#endif // WORKWINDOWOPER_H
