#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "cuuho.h"
#include "vipham.h"
#include "ungpho.h"
#include "khac.h"

#include<QtSql/QSql>
#include<QtSql>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QDebug>

#include "dialog_xuatfile.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    bool status = false;


private slots:


    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:

    Ui::MainWindow *ui;
    CuuHo *mWindowCuuHo;
    ViPham *mWindowViPham;
    UngPho *mWindowUngPho;
    Khac *mWindowKhac;

};
#endif // MAINWINDOW_H
