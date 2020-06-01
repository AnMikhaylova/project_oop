#ifndef WORKWINDOWADM_H
#define WORKWINDOWADM_H

#include <QWidget>

namespace Ui {
class WorkWindowAdm;
}

class WorkWindowAdm : public QWidget
{
    Q_OBJECT

public:
    explicit WorkWindowAdm(QWidget *parent = nullptr);
    ~WorkWindowAdm();

private:
    Ui::WorkWindowAdm *ui;
};

#endif // WORKWINDOWADM_H
