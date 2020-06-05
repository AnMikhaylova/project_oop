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

//Главное окно, содержащее модуль авторизации
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
    //слот для обработки нажатия на кнопку авторизации
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    //строка для сохранения имени пользователя для последующих манипуляций с мета-описаниями
    QString user_name;
    //указатели на рабочик окна для администратора и оператора
    WorkWindowAdm *window;
    WorkWindowOper *window_op;
};
#endif // MAINWINDOW_H
