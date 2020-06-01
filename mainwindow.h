#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QMessageBox"
#include "QTextCodec"
#include "workwindowadm.h"
#include "workwindowoper.h"
#include <QTextStream>
#include <QString>
#include "md5.h"
#include "sql.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QString get_username() const;

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QString user_name;
    WorkWindowAdm *window;
    WorkWindowOper *window_op;
};
#endif // MAINWINDOW_H
