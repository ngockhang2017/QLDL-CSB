#ifndef VIPHAM_H
#define VIPHAM_H

#include <QMainWindow>

#include<QtSql/QSql>
#include<QtSql>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QDebug>
#include<QString>
#include<QMessageBox>

#include"dialog_xuatfile.h"
#include<QAxObject>
#include<QFile>
#include<QFileDialog>


namespace Ui {
class ViPham;
}

class ViPham : public QMainWindow
{
    Q_OBJECT

public:
    explicit ViPham(QWidget *parent = nullptr);
    ~ViPham();
    QSqlDatabase db;
    bool ok;
    int ID_DoubleCLick;

private slots:
    void on_pushButton_22_clicked();

    void on_pushButton_7_clicked();

    void SectionDoubleClick(int row, int column);


    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_23_clicked();

private:
    Ui::ViPham *ui;
    Dialog_XuatFile *mdialog_XuatFile;
};

#endif // VIPHAM_H
